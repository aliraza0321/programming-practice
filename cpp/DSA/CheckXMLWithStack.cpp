 #include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <class T>
class Stack 
{
   //for encaspulation
   class Node 
   {
   public:
       T data;
       Node* next;
       Node(T d) 
       {
           data = d;
           next = nullptr;
       }
   };

   Node* top; // pointer to top element

public:
   Stack() 
   {
       top = nullptr;
   }

   bool isEmpty()
   { 
       return top == nullptr;
   }

   void push(T val)
   {
       Node* newNode = new Node(val);
       newNode->next = top;
       top = newNode;
   }

   void pop() {

       if (!isEmpty()) 
       {
           Node* temp = top;
           top = top->next;
           delete temp;
       }
   }

   T peek()
   {
       return top->data;
   }

   ~Stack() 
   {
       while (!isEmpty())
           pop();
   }
};
//for taginfo
class Tag 
{
public:
   string name;
   int line;
   Tag(string n = "", int l = -1)
   {
       name = n;
       line = l;
   }
};

// Helper Functions 
bool isSpace(char ch)
{
   return (ch == ' ' || ch == '\t' || ch == '\n');
}

bool isAlphaNum(char ch)
{
   return ((ch >= 'A' && ch <= 'Z') ||(ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
}

class XMLValidator
{
   Stack<Tag> tags;

public:
   // Skip <!-- comments -->
   void skipComment(ifstream& myfile, int& line)
   {
       char prev = 0, curr = 0, next;
       while (myfile.get(curr))//till reach at the end of comment
       {
           if (curr == '\n')
               line++;
           if (prev == '-' && curr == '-') 
           {
               myfile.get(next);
               if (next == '>') 
                   return;
           }
           prev = curr;
       }
   }

   // Skip <?xml ... ?>
   void skipHeader(ifstream& myfile, int& line) 
   {
       char prev = 0, curr;
       while (myfile.get(curr))
       {
           if (curr == '\n') 
               line++;
           if (prev == '?' && curr == '>')//move in my file till reach at last of header
               return;
           prev = curr;
       }
   }

   // Main validation function
   void validate(const string& fileName)
   {
       ifstream myfile(fileName);
       if (!myfile.is_open()) 
       {
           cout << "File not found!\n";
           return;
       }

       bool error = false;
       int line = 1;
       char ch;

       while (myfile.get(ch)) 
       {
           if (ch == '\n') 
               line++;

           // Start of a tag
           if (ch == '<')
           {
               char peek;
               if (!myfile.get(peek))
                   break;

               // Comment
               if (peek == '!')
               {
                   string temp = "";
                   for (int i = 0; i < 2; i++) 
                   {
                       char t;
                       if (!myfile.get(t)) 
                           break;
                       temp += t;
                   }
                   if (temp == "--") 
                   {
                       skipComment(myfile, line);
                       continue;
                   }
                   
               }

               // Header like <?xml ?> just skip all header when <? occur 
               else if (peek == '?')
               {
                   skipHeader(myfile, line);//myfile cursor will move after end of header this will skip
                   continue;
               }

               // Closing tag
               else if (peek == '/')
               {
                   string tagName = "";
                   while (myfile.get(ch) && ch != '>')
                       tagName += ch;//add closing tag 

                   if (!tags.isEmpty()) 
                   {
                       Tag openTag = tags.peek();
                       if (openTag.name == tagName)//checking matching tags
                           tags.pop();
                       else 
                       {
                           cout << "Tag mismatch: <" << openTag.name << "> (line " << openTag.line<< ") \n";
                           tags.pop();
                           error = true;
                       }
                   }
                   else 
                   {
                       cout << "Extra closing tag </" << tagName << "> at line " << line << "\n";
                       error = true;
                   }
               }

               // Opening tag or self-closing tag
               else
               {
                   string tagText = "";
                   bool selfClose = false;
                   tagText += peek;
                   while (myfile.get(ch) && ch != '>')
                   {//this is first opening tag so add tagname
                       tagText += ch;
                       if (ch == '/')
                       {
                           selfClose = true;
                       }
                   }                                    
                   int i = 0;
                   while (i < tagText.size() && isSpace(tagText[i])) 
                       i++;

                   string tagName = "";
                   while (i < tagText.size() && tagText[i] != ' ' &&tagText[i] != '/' && tagText[i] != '\t')
                       tagName += tagText[i++];

                   if (!tagName.empty()&&!selfClose) //if tag is selfclose then no need to push on stack
                   {
                       Tag temp(tagName, line);
                       tags.push(temp);//this is tag so push it on stack
                   }

                   // Attribute checking
                   while (i < tagText.size())
                   {//check attribute's =,quote both starting starting and closing 
                       while (i < tagText.size() && isSpace(tagText[i])) 
                           i++;
                       if (i >= tagText.size())
                           break;

                       string attribute = "";
                       while (i < tagText.size() && isAlphaNum(tagText[i]))
                       {
                           attribute += tagText[i];
                           i++;
                       }
                       if (attribute.empty())
                           break;

                       while (i < tagText.size() && isSpace(tagText[i]))
                           i++;

                       if (i >= tagText.size() || tagText[i] != '=')
                       {
                           cout << "Missing '=' after attribute \"" << attribute << "\" in tag <" << tagName << "> at line " << line << "\n";
                           error = true;
                           break;
                       }
                       // i at == position
                       i++; // skip '='
                       while (i < tagText.size() && isSpace(tagText[i])) //skip space
                           i++;
                       //after == will be opeing quotes here 
                       if (i >= tagText.size() || (tagText[i] != '"' && tagText[i] != '\'')) //missing quote
                       {
                           cout << "Missing quote after '=' for attribute \"" << attribute
                               << "\" in tag <" << tagName << "> at line " << line << "\n";
                           error = true;
                           break;
                       }
                       //take text of quote till at first index of quote will be opening tag
                       char quote = tagText[i];
                       i++;//move next char of quote after ",'
                       while (i < tagText.size() && tagText[i] != quote) 
                           i++;
                       if (i >= tagText.size() || tagText[i] != quote)//reach closing tag or not
                       {
                           cout << "Missing closing quote for attribute \"" << attribute << "\" in tag <" << tagName << "> at line " << line << "\n";
                           error = true;
                           break;
                       }
                       i++;//as this is for closing quote so move next char in tagtext
                   }
               }
           }
       }

       // Unmatched tags
       while (!tags.isEmpty()) 
       {
           Tag t = tags.peek();
           cout << "Unmatched tag: <" << t.name << "> at line " << t.line << "\n";
           tags.pop();
           error = true;
       }

       if (!error)
           cout << "XML is valid.\n";
   }
};

int main()
{
   string file = "input.xml";
   XMLValidator validator;
   validator.validate(file);

  
}
