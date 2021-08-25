#include<iostream>  
  
using namespace std;

 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int s = m - l + 1; 
    int su =  r - m; 
  
    int brr[s], crr[su]; 
    
    for (i = 0; i < s; i++) {
        brr[i] = arr[l + i]; 
    }
    for (j = 0; j < su; j++) {
        crr[j] = arr[m + 1 + j]; 
  	}
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < s && j < su) 
    { 
        if(brr[i] <= crr[j]) { 
            arr[k] = brr[i]; 
            i++; 
        } 
        else { 
            arr[k] = crr[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < s) 
    { 
        arr[k] = brr[i]; 
        i++; 
        k++; 
    }
    while (j < su) 
    { 
        arr[k] = crr[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l+(r-l)/2; 

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r); 
   
        merge(arr, l, m, r); 
    } 
} 
  
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) {
    	cout << A[i] << " " ;
    }
    cout << endl;
    
} 
  

int main() 
{ 
    int arr[] = {12, 234, 97, 23, 19, 1009, 1000, 340, 11, 13, 5, 6, 7, 100, 200, 1, 2, 3}; 
    
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
  
  	cout << "Sorted Array is given below" << endl;
     
    printArray(arr, arr_size); 
    
    return 0; 
} 