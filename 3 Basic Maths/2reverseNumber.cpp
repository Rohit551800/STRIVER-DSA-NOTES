//  Reverse of the number
#include<iostream>
using namespace std;
int reverse (int n){
    int rev = 0;
    while(n>0){
        int lastdigit = n%10;
        n = n/10;
        rev = (rev * 10) + lastdigit;
    }
    cout<<"Reverse of the given number is:"<<rev;
}
int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    reverse(n);
    return 0;
}