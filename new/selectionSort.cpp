#include<iostream>

using namespace std;

void printarray (int array[], int n) {
    for(int i=0; i<n; i++) {
        cout << array[i] << " ";
        }

    cout << endl;
}

int main()
{
    int n, i;
    cout << "Enter Array Size : " ;
    cin >> n;
    
    int arr[n];

    for(i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(i=0; i<n; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        if(min != i) {
            swap(arr[min], arr[i]);
        }
    }

    printarray(arr, n);

    return 0;
}