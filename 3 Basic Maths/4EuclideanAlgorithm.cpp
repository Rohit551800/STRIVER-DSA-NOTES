#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	while(a>0 && b>0){
		if(a>b) a = a%b;
		else b = b%a;
	}
	if(a==0) return b; //if you want to see the ans change return to cout
	else return a;  // change here too
} 
int main(){
    int a ,b;
    cout<<"Enter the value of a and b:";
    cin>>a>>b;
    gcd(a,b);
}
