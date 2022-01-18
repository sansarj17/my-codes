#include <iostream>
using namespace std;

void countSort(int *arr,int n){
    int countArr[3] = {0,0,0};
    
    for(int i=0; i<n; i++){
        countArr[*(arr+i)]++;
    }
    
    for(int i=0;i<3;i++){
        for(int j = 0; j<countArr[i]; j++){
            cout << i << " | ";
        }
    }
}

int main() {
    int arr[] = {0,1,2,2,1,0,2,1,0,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    for (int i=0; i<n; i++){
        cout << arr[i] << " | " ;
    }
    cout << endl << endl;
    
    countSort(arr,n);
    
    return 0;
}
