//19 Jan 2022
#include <iostream>
#include <limits.h>
using namespace std;

//MergeSort
void merge(int *arr, int p, int q,int r){
    
    int num1 = q-p+1;
    int num2 = r-q;
    
    int L[num1+1];
    int R[num2+1];
    
    for(int i=0; i<num1; i++){
        L[i] = *(arr+p+i);
    }
    for(int i=0; i<num2; i++){
        R[i] = *(arr+q+1+i);
    }
    
    L[num1] = R[num2] = INT_MAX;
    
    int i,j,k;
    i = j = 0;
    
    for(k = p; k<=r; k++){
        if(L[i] <= R[j]){
            *(arr+k) = L[i];
            i++;
        } else{
            *(arr+k) = R[j];
            j++;
        }
    }
}
void mergeSort(int *arr, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

//QuickSort
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *arr, int p, int r){
    
    int key = *(arr+r);
    
    int i = p-1;
    int j = p;
    
    for(j=p; j<r; j++){
        if(*(arr+j) < key){
            i++;
            swap(arr+j, arr+i);
        }
    }
    swap(arr+i+1, arr+r);
    return i+1;
}
void quickSort(int *arr, int p,int r){
    if(p<r){
        int q = partition(arr,p,r);
        cout << q << endl;
        for(int i=p; i<=r; i++){
            cout << *(arr+i) << " | ";
        }
        cout << endl;
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

//InsertionSort
void insertionSort(int *arr, int n){
    
    int key,i,j;
    
    for(i = 1; i<n; i++){
        key = *(arr+i);
        j = i-1;
        
        while(*(arr+j) > key && j>=0){
            *(arr+j+1) = *(arr+j);
            j--;
        }
        
        *(arr+j+1) = key;
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,0,3,2,1,11,4};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int p = 0;
    int r = n-1;
    //int q = (p+r)/2;
    
    //merge(arr,p,q,r);
    //mergeSort(arr,p,r);
    
    //int q = partition(arr,p,r);
    // quickSort(arr,p,r);
    
    //insertionSort(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " | ";
    }
    // cout << endl << "q = " << q;

    return 0;
}
