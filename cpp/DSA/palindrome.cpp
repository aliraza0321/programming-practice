#include<iostream>
#include<stack>
using namespace std;
//function will be implemented in stack class

void balancebrak(stack<char>&s)
	{
		string str; 
		cout << "Enter parenthesis: ";
	    cin >> str;
		for (int i = 0; i<=str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			{
				s.push(str[i]);
			}
			else if( (s.top() == '(' && str[i] == ')') || ((s.top() == '[' && str[i] == ']')) || (s.top() == '{' && str[i] == '}'))
			{
				s.pop();
			}
			
		}
		if (s.empty())
		{
			cout << "\nBalanced\n";
		}
		else
		{
			cout << "Unbalanced";
		}
	}
int main()
{
    stack<char>s;
    balancebrak(s);
}