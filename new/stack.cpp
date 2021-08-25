 #include<bits/stdc++.h>
 
 using namespace std;

 #define SIZE 5

 int top = -1;
 
 void Insert(int *array)
 {
	 if(top == SIZE-1) {
		 cout << "Stack is Full" << endl;
	 }
	 else {
		 int n;
		 cout << "Element : ";
		 cin >> n;
		 top++;
		 array[top] = n;
	}
 }
 
 void Delete(int *array)
 {
	 if(top == -1) {
		 cout << endl << "Stack is Empty" << endl;
	 }
	 else {
		 array[top]= -1;
		 top--;
	 }
 }
 
void Display(int *array)
{

	if(top == -1) {
		cout << endl << "STack is Empty" << endl;
	}
	else {
		for(int i = top ;i >= 0;i--)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
}
 
 
 int main(void)
 {
	 int n;
	 int array[SIZE];

		while(1)
		{
			cout << endl << "Select" << endl;
			cout << "1.insert element" << endl;
			cout << "2.delete element" << endl;
			cout << "3.Look in Stack" << endl;
			cout << "4.Exit" << endl;
			
			cin >> n;
			
			if(n == 1)
			{
				Insert(array);
			}
			
			else if (n == 2)
			{
				Delete(array);
			}
			else if (n == 3)
			{
				Display(array);
			}
			else if(n==4)
				break;
			else {
				cout << endl << "Select Option" << endl;
			}
		}
 	
 	return 0;
 }