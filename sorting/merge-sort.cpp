#include <iostream>
#include <limits.h>

using namespace std;

void merge(int *arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1+1];
    int R[n2+1];

    for(int i=0; i <= n1; i++)
        L[i] = *(arr + p + i);
    for(int i=0; i <= n2; i++)
        R[i] = *(arr + q + 1 + i);

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int k = 0;
    int i = 0;
    int j = 0;

    for(k=p; k<=r; k++){
        if(L[i] <= R[j]){
            *(arr+k)= L[i];
            i++;
        }
        else{
            *(arr+k) = R[j];
            j++;
        }
    }
}

void mergeSort(int *arr, int p, int r){
    if (p<r){
        int q;
        q = (p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    // 2 4 6 1 3 7

    int p = 0;
    int r = n-1;
    //merge(arr, p, q, r);

    mergeSort(arr,p,r);
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
