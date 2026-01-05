//first enter 1,2,3,4,5
//again push 6
//then 6,2,3,4,5 but starting index at 1 and stack order is bottom to top is 2,3,4,5,6
//again continue this 
//if we pop element then top element will remove and size will decrease by 1
#include <iostream>
using namespace std;
class UndoStack 
{
	static const int MaxSize = 5;
	int size;
	int top;
	int firstIndex;
	int array[MaxSize];

public:
	UndoStack() 
	{
		top = -1;
		firstIndex = 0;
		size = 0;
	}

	void push(int value) 
	{
		if (size < MaxSize)
		{
			top = (top + 1) % MaxSize;
			array[top] = value;
			size++;
		}
		else 
		{
			firstIndex = (firstIndex + 1) % MaxSize;
			top = (top + 1) % MaxSize;//overwrite oldest element and store in circular manner
			array[top] = value;
		}
	}

	bool isempty() 
	{
		return size == 0;
	}

	bool isfull() 
	{
		return size == MaxSize;
	}

	void pop()
	{
		if (!isempty())
		{
			top = (top - 1 + MaxSize) % MaxSize;  // fixed negative index issue
			size--;
		}
		else 
		{
			cout << "Stack is empty.\n";
		}
	}

	int peek()  
	{
		if (!isempty())
		{
			return array[top];
		}
		
	}

	void display()  
	{
		if (!isempty())
		{
			cout << "\nStack (top to  bottom): ";
			for (int i = size - 1; i >= 0; i--)
			{
				int ind = (firstIndex + i) % MaxSize;//start frome firstIndex
				cout << array[ind] << " ";
			}
			cout << endl;
		}
		
	}
};


int main() 
{
	UndoStack s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.display();

	s1.push(60);
	s1.display();
	s1.push(70); 
	s1.display();

	cout << "\nTop element: " << s1.peek() << endl;

	s1.pop();
	s1.display();
}
