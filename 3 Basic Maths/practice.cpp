#include<bits/stdc++.h>
using namespace std;
void extractionOfNumber(int n){
    while(n>0){
    int last_number = n %10;
    n = n/10;
    cout<<last_number<<" ";
    }
}
int reverse(int x) {
    long long rev = 0;

    while (x != 0) {
        int digit = x % 10;
        rev = rev * 10 + digit;
        x /= 10;
        if (rev > INT_MAX || rev < INT_MIN)
            return 0;
    }

    return (int)rev;
}
int countDigits(int n){
    int count =0;
    while(n>0){
      int digit = n%10;
        n = n/10;
        count++;
    }
    return count;
}

 // OR
 int countDigitsA(int n){
    return log10(n) +1;
 }
bool palindrome(int n){
    int rev=0;
    int original_number = n;
    while(n>0){
        int last_number = n%10;
        n = n/10;
        rev = (rev * 10) + last_number;
    }
    if(original_number == rev){
        return true;
    }
    else return false;
}
int Armstrong(int n){
    int sum=0;
    while(n>0){
        int last_number = n%10;
        n = n/10;
        sum = sum + (last_number * last_number * last_number);
    }
    return sum;
}
void divisibleFactor(int n){
    vector<int> v;
    for(int i =1;i*i<=n;i++){
        if(n%i == 0){
            v.push_back(i);
        }
        if(n/i != i){
            v.push_back(n/i);
        }
    }
    sort(v.begin() , v.end());
    for(auto D : v){
        cout<<D<<" ";
    }
}
void checkPrime(int n){
    int count =0;
    for(int i=1;i*i<=n;i++){
        if (n % i == 0) {
            count++; 
            if (n / i != i) count++;
        }
    }
    if(count == 2){
        cout<<"Prime Number";
    }
    else cout<<"Not a Prime Number";
}
int gcd(int a , int b){
    for(int i=min(a,b);i>0;i++){
        if(a%i == 0 && b%i ==0) return i;
    }
}
int euclideanAlgorithm(int a , int b){
    while(a>0 && b>0){
        if(a>b) a = a%b;
        else b = b%a;
    }
    if(a==0) return b;
    else return a;
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int b;
    cout<<"Enter the value of b:";
    cin>>b;
   // extractionOfNumber(n);  
   // cout<<reverse(n);
   // cout<<countDigits(n);
   // cout<<countDigitsA(n);
   // cout<<Armstrong(n);
   // divisibleFactor(n);
   // checkPrime(n);
   // cout<<gcd(n , b);
   // cout<<euclideanAlgorithm( n , b);
   return 0;
}