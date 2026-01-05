#include <iostream>
using namespace std;
template <class T>
class InvertibleStack
{
   int MaxSize;
   int size;
   int front; // points to the oldest element
   int rear;  // points to the newest element (top)
   T* array;
   int direction; // +1 = normal, -1 = flipped

public:
   InvertibleStack()
   {
       MaxSize = 5;
       size = 0;
       front = 0;
       rear = -1;
       direction = 1;
       array = new T[MaxSize];
   }

   bool isFull() 
   { 
       return size == MaxSize;
   }
   bool isEmpty() 
   { 
       return size == 0;
   }

   void grow()
   {
       int newSize = MaxSize * 2;//double it 
       T* temp = new T[newSize];
       for (int i = 0; i < size; i++)
           temp[i] = array[(front + i) % MaxSize];//copy all elements till size in circular manner
       delete[] array;
       array = temp;//update array
       MaxSize = newSize;//update size;
       front = 0;
       rear = size - 1;//now array is double and rear at size -1 means last element
   }

   void half()
   {
       if (MaxSize <= 1)//no need to half 1  
           return;
       int newSize = MaxSize / 2;
       T* temp = new T[newSize];
       for (int i = 0; i < size; i++)
           temp[i] = array[(front + i) % MaxSize];
       delete[] array;
       array = temp;
       MaxSize = newSize;
       front = 0;
       rear = size - 1;
   }

   void push(T value)
   {
       if (isFull())
           grow();

       if (direction == 1)//if not flipped so push normal manner
           rear = (rear + 1) % MaxSize;
       else
           rear = (rear - 1 + MaxSize) % MaxSize; //otherwise push in start of flipped array

       array[rear] = value;
       size++;
   }

   void pop()
   {
       if (isEmpty())
       {
           cout << "Stack is empty!\n";
           return;
       }

       if (direction == 1)
           rear = (rear - 1 + MaxSize) % MaxSize;//if normall then remove element at start
       else
           rear = (rear + 1) % MaxSize;//otherwise move rear by 1 in circular manner

       size--;

       if (size <= MaxSize / 2)
           half();
   }

   T top()
   {
       if (!isEmpty())
       {
           return array[rear];
       }
      
   }

   void flipStack()
   {//swap front and rear 
       int temp = front;
       front = rear;
       rear = temp;
       direction *= -1; // reverse the push/pop direction
   }

   void display()
   {
       if (!isEmpty())
       {
           cout << "Stack (top to bottom): ";
           if (direction == 1)//normal
           {
               for (int i = 0; i < size; i++)
                   cout << array[(rear - i + MaxSize) % MaxSize] << " ";
           }
           else
           {
               for (int i = 0; i < size; i++)//flipped
                   cout << array[(rear + i) % MaxSize] << " ";//display in circular manner
           }
           cout << "\n";
       }
       
   }

   int getCapacity()  
   { 
       return MaxSize; 
   }

   ~InvertibleStack()
   {
       delete[] array;
   }
};


int main()
{
   InvertibleStack<int> s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   s.push(50);
   s.display();
   cout << "Top is poped\n";
   s.pop();
   cout << "Top: " << s.top() << endl;
   s.display();
   s.push(70);
   s.push(90);
   s.display();
   s.flipStack();
   cout << "After flip:\n";
   s.display();
   s.push(80);
   s.push(60);
   s.display();
   cout << "Top is poped\n";
   s.pop();
   s.display();
   s.flipStack();
   cout << "After 2nd flip:\n";
   s.display();

   cout << "Is empty: " << s.isEmpty() << endl;
   cout << "Maximum  capacity: " << s.getCapacity() << endl;
   s.pop();
   s.pop();
   s.pop();
   cout << "After three elements removed\n";
   s.display();
   cout << "Now current maximum capacity of array: " << s.getCapacity();
   s.pop();
   s.pop();
   cout << endl;
   s.display();
   cout << "Now current maximum capacity of array: " << s.getCapacity();
}
