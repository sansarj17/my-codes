#include <iostream>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *arr,int n){
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n; i++){
            if(*(arr+i) > *(arr+i+1)){
                cout << "Swapped" << *(arr+i) << " | " << *(arr+i+1) << endl;
                swap(arr+i,arr+i+1);
            }
        }
    }
}

int main() {
    int arr[] = {5,3,6,2,4,1};
    int n = 6;
    
    bubbleSort(arr,n);
    
    for (int i=0; i<n; i++){
        cout << arr[i] << " | " ;
    }

    return 0;
}
