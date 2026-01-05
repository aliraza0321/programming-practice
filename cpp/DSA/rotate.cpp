

#include<iostream>
using namespace std;
template<class T>
	class Node
	{
	public:
		T data;
		Node<T>* next;

		Node(T d)
		{
			data = d;
			next = nullptr;
		}
	};
template<class T>

class SortedSet
{//for encapsolation 
	
	Node<T>* head;
	Node<T>* tail;
public:
	SortedSet()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insert(T d)
	{
		//insert  in case of empty 
		Node<T>* newNode = new Node<T>(d);
		if (head == nullptr)
		{
			head = tail = newNode;
			return;
		}
		if (d <= head->data)//insert at start
		{
			if (d == head->data)
			{
				return;//duplicate value
			}
			newNode->next = head;
			head = newNode;
			return;
		}
		if (d >= tail->data)//insert at last
		{
			if (d == tail->data)//same value at last
				return;
			tail->next = newNode;
			tail = newNode;
			return;
		}
		//in middle insertion
		Node<T>* temp = head;
		while (temp->next != nullptr && temp->next->data < d)
		{
			temp = temp->next;
		}
		if (temp->next != nullptr && temp->next->data == d)
			return;
		newNode->next = temp->next;
		temp->next = newNode;

	}
	void print()
	{
		if (head == nullptr)
			return;
		Node<T>* temp = head;
		while (temp != tail)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << temp->data << endl;
	}


	bool deleteItem(int index)
	{
		if (head == nullptr)
			return false;
		Node<T>* temp = head;
		for (int i = 1; i < index - 1; i++)
		{
			temp = temp->next;
		}
		if (temp == nullptr)
			return false;
		Node<T>* del = temp->next;
		temp->next = del->next;
		delete del;
		return true;
	}

	//Question no# 2 for rotating counter clock wise by k times
	void rotate(int num)
	{//in counter clock wise rotation we send  n nodes to the end of in reverse order 
		if (head == nullptr)
			return;
		Node<T>* temp = head;
		int size = 1;
		while (temp->next != nullptr)//getting size
		{
			temp = temp->next;
			size++;
		}
		num = num % size;//num=3,size=3 num will be 0 means no rotattion is required
		if (num == 0)
			return;
		Node<T>* temp1 = head;
		for (int i = 1; i < num; i++)
		{
			temp1 = temp1->next;
		}
		if (temp1 == nullptr)
			return;
		Node<T>* after = temp1->next;
		temp1->next = nullptr;
		temp->next = head;
		head = after;
		tail = temp1;
	}
	
	~SortedSet()
	{
		if (head == nullptr)
			return;
		Node<T>* temp1;
		Node<T>* temp2;
		temp1 = head;
		while (temp1 != nullptr)
		{
			temp2 = temp1->next;
			delete temp1;
			temp1 = temp2;
		}

	}
};
int main()
{
	SortedSet<int>* list = new SortedSet<int>;
	list->insert(5);
	list->insert(4);
	list->insert(3);
	list->insert(2);

	
	cout << "\nYour first list is: ";
	list->print();
	
	cout << list->deleteItem(3) << endl;//send index for deleting element
	cout << "\nAfter deleting element at 3 positon or 2 index ";
	list->print();
	int shift;
	cout << "\nEnter shift number for rotating list in counter clockwise must enter +ve value: ";
	cin >> shift;
	while (shift < 0)//always +ve value exits 
	{
		cout << "Kindly Enter +ve value only for this operation: ";
		cin >> shift;
	}
	list->rotate(shift);//send shift number that times our list will shift
	cout << "\nAfter rotating " << shift << " times to the counter clock wise updated list is :  ";
	list->print();

	
	delete list;
	
}