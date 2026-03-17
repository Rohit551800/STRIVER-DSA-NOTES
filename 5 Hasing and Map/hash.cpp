// for interger hashing
#include<bits/stdc++.h>
using namespace std;
int hashh[10000000] = {0};
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // Pre storing
    // hash[10] = {0};
    for(int i=0;i<n;i++){
        hashh[arr[i]] += 1; 
    }
    int q;
    cout<<"Enter the value of q:";
    cin>>q;
    while(q--){
        int number ;
        cin>>number;
        //fetching
        cout<<hashh[number]<<endl;
    }
    return 0;
}


//for character hashing
#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cout<<"Enter the string :";
    cin>>a;
// pre storing 
    int hash[256] = {0};
    for(int i=0;i<a.size();i++){
        hash[a[i]]++; // hash is a integer and it auto cast it into its index value so no need of writing hash[a[i] - a]
    }
    int q;
    cout<<"Enter the number of characters you want to take:";
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetching
        cout<<hash[c]<<endl;
    }
    return 0;
}