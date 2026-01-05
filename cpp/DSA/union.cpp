
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


	void unionSet(SortedSet<T>* obj)
	{


		Node<T>* temp1, * temp2;
		temp1 = head;
		temp2 = obj->head;
		while (temp2 != nullptr)
		{
			insert(temp2->data);
			temp2 = temp2->next;
		}
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
	list->insert(3);
	list->insert(2);
	list->insert(1);

	
	cout << "\nYour first list is: ";
	list->print();
	SortedSet<int>* list2 = new SortedSet<int>;
	list2->insert(1);
	list2->insert(4);

	cout << "\nYour list new list is : ";
	list2->print();
	list->unionSet(list2);
	cout << "\nUnion of two list is in sorted order : ";
	list->print();
	delete list;
	delete list2;
}