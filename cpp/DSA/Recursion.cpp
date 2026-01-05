//#include<iostream>
//using namespace std;
//int sum(int n)
//{
//
//	if (n == 0)
//		return 0;
//	else
//		return n + sum(n - 1);
//}
//int powFun(int x, int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return x * powFun(x, n - 1);
//}
//void print(int n)
//{
//	if (n == 0)
//		return ;
//	else
//	{
//		cout << n << " ";
//		print(n - 1);
//		
//	}
//	
//}
//bool isPalindrome( string str, int start, int end) 
//{
//	if (start >= end)
//		return true; // base case
//	if (str[start] != str[end])
//		return false; // not a palindrome
//	return isPalindrome(str, start + 1, end - 1); 
//}
//int sumArray(int arr[], int n) 
//{
//	if (n == 0)
//		return 0;
//	return arr[n - 1] + sumArray(arr, n - 1);
//}
//int fibonacci(int n) 
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	return fibonacci(n - 1) + fibonacci(n - 2);
//}
//void powerSet(string str, string current = "", int index = 0)
//{
//	if (index == str.length()) 
//	{
//		cout << current << endl;
//		return;
//	}
//	powerSet(str, current + str[index], index + 1); 
//	powerSet(str, current, index + 1);              
//}
//void generateParentheses(int open, int close, string current = "") 
//{
//	if (open == 0 && close == 0) 
//	{
//		cout << current << endl;
//		return;
//	}
//	if (open > 0)
//		generateParentheses(open - 1, close, current + "(");
//	if (close > open)
//		generateParentheses(open, close - 1, current + ")");
//}
//int menu()
//{
//	int choice;
//	cout << "\n\n\n ==== Recursion Lab Menu ====\n";
//	cout << "1.Sum of natural numbers \n";
//	cout << "2.Power function(x^y)\n";
//	cout << "3.Print numbers n to 1\n";
//	cout << "4.Check palindrome\n";
//	cout << "5.Sum of array elements\n";
//	cout << "7.Generater power set\n";
//	cout << "8.Generate valid parentheses\n";
//	cout << "0.exit\n";
//	cout << "Enter your choice: ";
//	cin >> choice;
//	return choice;
//}
//int main()
//{
//	int choice;
//	do
//	{
//		choice = menu();
//		if (choice == 1)
//		{
//			int num;
//			cout << "Enter any natural number : ";
//			cin >> num;
//			cout << "sum of natual number till " << num << " is :";
//			cout << sum(num);
//		}
//		else if (choice == 2)
//		{
//			int x, n;
//			cout << "Enter base of number: ";
//			cin >> x;
//			cout << "Enter power of number : ";
//			cin >> n;
//			cout << powFun(x, n);
//		}
//		else if (choice == 3)
//		{
//			int num;
//			cout << "Enter n for printing numbers :";
//			cin >> num;
//			print(num);
//		}
//		else if (choice == 4)
//		{
//			string num;
//			cout << "Enter any string for checking palindrome:";
//			cin >> num;
//			int first = 0;
//			int last = num.length()-1;
//			cout<<isPalindrome(num,first,last);
//		}
//		else if (choice == 5)
//		{
//			int array[10];//limit is 10 only 
//			for (int i = 0; i < 10; i++)
//			{
//				cin >> array[i];
//			}
//			sumArray(array, 10);
//		}
//		else if (choice == 6)
//		{
//			int n;
//			cout << "Enter n (term number): ";
//			cin >> n;
//			cout << "Fibonacci term F(" << n << ") = " << fibonacci(n) << endl;
//			
//		}
//		else if (choice == 7)
//		{
//			string str;
//			cout << "Enter string: ";
//			cin >> str;
//			cout << "Power set:\n";
//			powerSet(str);
//
//		}
//		else if (choice == 8)
//		{
//			int n;
//			cout << "Enter number of pairs: ";
//			cin >> n;
//			cout << "Valid parentheses combinations:\n";
//			generateParentheses(n, n);
//		}
//
//	} while (choice != 0);
//}