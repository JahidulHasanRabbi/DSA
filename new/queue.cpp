#include<bits/stdc++.h>

using namespace std;

int SIZE=5;
int Front=-1,Rear=-1;


void EnQueue(int *array, int item)
{
	if(Front == -1) Front ++;
	if( Rear == SIZE - 1)
	{
		cout << "OVERFLOWED!!" << endl;
	}
	 
	else {
		Rear++;
		array[Rear]=item;
  }
}

void deQueue(int *array)
{
    if (Front == SIZE + 1)
    {
       cout << "UNDERFLOW!!" << endl;
    }
    
    else {
		int deleled = array[Front];
		array[Front] = 0;
		Front++;
		cout << deleled << " has been deleted from Queue" << endl;
	}
}



void Display(int *array)
{

	cout << endl;
	
	if(Front==-1 )
	{
		cout << "Empty!!" << endl;
	}

	if(Front <= Rear)
	 {
		for(int i=Front;i<=Rear;i++)
		{
		    cout << array[i] << " " ;
		}
	 }



}

int main (void)
{
	while(1)
	{
		int n;
		int array[SIZE];
		
		cout << endl << "What do you want to do?" << endl;
		cout << "1.Insert Element" << endl;
		cout << "2.Delete Element" << endl;
		cout << "3.Show Circular Queue" << endl;
		cout << "4.Exit" << endl;
		
		cin >> n;
		
		if(n == 4)		break;
		
		else if(n == 1)
		{
			cout << "Enter Elements [MAX size 5]" << endl;
			
			for(int i=0;i<5;i++)
			{
				int a;
				cout << "Enter element you want to insert:" << endl;
			
				cin >> a;
			
				EnQueue(array, a);
			}
		}
		
		else if(n == 2)
		{
			deQueue(array);
		}
		
		else if(n == 3)
		{
			Display(array); 
		}
	
	}
	
	
	return 0;
}