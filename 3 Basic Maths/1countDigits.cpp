#include<iostream>
using namespace std;
void count(int n){
    int count=0;
    while(n>0){
        int last_digit = n%10;
        n = n/10;
        count++;
        cout<<last_digit<<" ";
    }
    cout<<endl<<"Total number of digits:"<<count;
}
int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    count(n); 
    return 0;
}