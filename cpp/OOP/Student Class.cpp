#include<iostream>
using namespace std;
class Student
{
	int rollno;
	float gpa;
public:
	Student():rollno(0),gpa(0)
	{
		cout << "Default is calling\n";
	}
	Student(int p,float s):rollno(p),gpa(s)
	{
		cout << "Parameterized is calling \n";
	}
	void print()
	{
		cout << "\nYour score is " << gpa;
		cout << "\nYour roll no is " << rollno;
		//return *(this);
	}
	int* display()
	{
		cout << "\nYour code is ended\n";
		return ;
	}
};
int main()
{
	int arr[] = { 40,78,65,73,56 };
	Student* S1=new Student(705, 3.6);
	S1->print();//->display();
}