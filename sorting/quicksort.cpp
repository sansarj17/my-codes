#include <iostream>
#include <random>

using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int p,int r){
    
    int key = *(arr+r);
    int i=p-1;
    
    int j;
    
    for( j = p; j<r; j++){
        if(*(arr+j) <= key){
            i++;
            swap(arr+i,arr+j);
        }
    }
    
    swap(arr+i+1, arr+r);
    return i+1;
}

void quickSort(int *arr,int p, int r){
    if(p<r){
        int q = partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }
}

int main() {
    
    int arr[100];
    
    for(int i=0; i<100; i++){
        arr[i] = rand() % 100 +1;
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Unsorted" << endl;
    
    for(int i = 0; i<n; i++){
        cout << arr[i] << " | ";
        
        if((i+1)%10 == 0){
            cout << endl;
        }
    }
    
    int p = 0;
    int r = n-1;
    
    quickSort(arr,p,r);
    
    cout << "Quick Sorted" << endl;
    
    for(int i = 0; i<n; i++){
        cout << arr[i] << " | ";
        
        if((i+1)%10 == 0){
            cout << endl;
        }
    }

    return 0;
}
