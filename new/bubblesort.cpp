#include<iostream>
#include<algorithm>

using namespace std;

void Sorting(int array[], int Size)
{
    for(int i=0; i<Size-1; i++) {
        for(int j=0; j<Size-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;
    int elements[n];

    for(int i=0; i<n; i++) {
        cin >> elements[i];
    }
    
    Sorting(elements, n);

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++) {
        cout << elements[i] << " ";
    }
    cout << endl;

    return 0;
}