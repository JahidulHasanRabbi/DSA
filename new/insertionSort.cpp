#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;
    int element[n];

    for(int i=0; i<n; i++) {
        cin >> element[i];
    }

    for(int i=1; i<n; i++) {
        int value = element[i];
        int j = i - 1;

        while(value < element[j] && j >= 0)
        {
            element[j+1] = element [j];
            j--;
        }

        element[j+1] = value;
    }

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++) {
        cout << element[i] << " ";
    }
    cout << endl;

    return 0;
}