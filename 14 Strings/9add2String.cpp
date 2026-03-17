#include<bits/stdc++.h>
using namespace std;
string add2String(string &s1 , string &s2){
    int n = s1.size() -1 , m = s2.size() - 1;
    string ans = "";
    int carry = 0;
    int x = 0 , y = 0;
    while(n >= 0 || m >=0 || carry){
        if(n >= 0 ){
            x = s1[n] - '0';
        }
        else {
            x = 0;
        }
        if(m >= 0 ){
            y = s2[m] - '0';
        }
        else {
            y = 0;
        }
        int sum = x + y + carry;
        ans.push_back((sum % 10) + '0');
        carry = (sum / 10);
        n--;
        m--;
    }
    reverse(ans.begin() , ans.end());
    return ans;

}
int main(){
    string s1 = "26583" , s2 = "698";
    cout<<add2String(s1 , s2);
    return 0;
}