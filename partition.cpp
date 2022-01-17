#include <iostream>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void partition(int *arr, int p, int r){
    
    int key = *(arr+r);
    int i = p-1;
    int j = p;
    
    for( j = p; j < r; j++){
        if( *(arr+j) < key ){
            i++;
            swap(arr+j, arr+i);
        }
    }
    swap(arr+i+1, arr+r);
}

int main() {
    int arr[] = {6,3,8,1,7,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int p =0;
    int r = n-1;
    
    partition(arr,p,r);
    
    for(int i = 0; i< n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
