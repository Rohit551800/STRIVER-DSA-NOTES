#include<bits/stdc++.h>
using namespace std;
void selectionSort(int n , int arr[]){
    int comparisons = 0, swaps = 0;

    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            comparisons++;
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
        swaps++;
    }
    cout<<"comparisons:"<<comparisons<<endl;
    cout<<"swaps:"<<swaps<<endl;

}
void bubbleSort(int n , int arr[]){
    for(int i=n-1;i>=0;i--){
        int didruns = 0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didruns = 1;
            }
        }
        if(didruns == 0) break;
        cout<<"Runs"<<endl;
    }
}
void insertionSort(int n , int arr[]){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(n , arr);
   // bubbleSort(n , arr);
   // insertionSort(n , arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}