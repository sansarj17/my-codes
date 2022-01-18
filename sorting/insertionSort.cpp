#include <iostream>
using namespace std;

void insertionSort(int *arr, int n){
    int key;
    int i,j;
    
    for(j = 1; j<n; j++){
        key = *(arr+j);
        i = j-1;
        while(*(arr+i) > key && i>=0){
            *(arr+i+1) = *(arr+i);
            i--;
        }
        *(arr+i+1) = key;
    }
}

int main() {
    
    int arr[] = {3,4,2,5,1,6};
    int n = 6;
    
    insertionSort(arr,n);
    
    for(int i=0; i<n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}
