//// Reverse a String
// #include<bits/stdc++.h>
// using namespace std;
// string reverseStr(string &s){
//     int i = 0;
//     int j = s.size()-1;
//     while(i<=j){
//         swap(s[i],s[j]);
//         i++;
//         j--;
//     }
//     return s;
// }
// int main(){
//     string s = "Rohit";
//     cout<<reverseStr(s);
//     return 0;
// }

// //Calculating Size of String without s.size();
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s = "Rohit";
//     int size = 0;
//     while(s[size]!='\0'){
//         size++;
//     }
//     cout<<size;;
//     return 0;
// }

////Check the string is a Palindrome Or Not

#include<bits/stdc++.h>
using namespace std;
bool palindromeOrNot(string &s){
    int i =0;
    int j = s.size()-1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    string s = "RohhoR";
    if(palindromeOrNot(s)) cout<<"True";
    else cout<<"False"; 
    return 0;
}