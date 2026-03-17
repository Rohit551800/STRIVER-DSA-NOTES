#include<bits/stdc++.h>
using namespace std;
string checknum(int &num){
    if(num >= 3000){
        num -= 3000;
        return "MMM";
     }
    else if(num >= 2000){
        num -= 2000;
        return "MM";
     }
    else if(num >= 1000){
        num -= 1000;
        return "M";
      }
    else if(num >= 900) {
        num -= 900;
        return "CM";
     }
    else if(num >= 800) {
        num -= 800;
        return "DCCC";
     }
    else if(num >= 700) {
        num -= 700;
        return "DCC";
     }
    else if(num >= 600) {
        num -= 600;
        return "DC";
     }
    else if(num >= 500) {
        num -= 500;
        return "D";
     }
    else if(num >= 400) {
        num -= 400;
        return "CD";
     }
    else if(num >= 300) {
        num -= 300;
        return "CCC";
     }
    else if(num >= 200) {
        num -= 200;
        return "CC";
    }
    else if(num >= 100) {
        num -= 100;
        return "C";
     }
    else if(num >= 90)  {
        num -= 90;
        return "XC";
    }
    else if(num >= 80)  {
        num -= 80;
        return "LXXX";
    }
    else if(num >= 70)  {
        num -= 70;
        return "LXX";
    }
    else if(num >= 60)  {
        num -= 60;
        return "LX";
    }
    else if(num >= 50)  {
        num -= 50;
        return "L";
    }
    else if(num >= 40)  {
        num -= 40;
        return "XL";
    }
    else if(num >= 30)  {
        num -= 30;
        return "XXX";
    }
    else if(num >= 20)  {
        num -= 20;
        return "XX";
    }
    else if(num >= 10){
        num -= 10;
        return "X";
    }
    else if(num == 9){
        num -= 9;
        return "IX";
        }
    else if(num == 8){
        num -= 8;
        return "VIII";
        }
    else if(num == 7){
        num -= 7;
        return "VII";
        }
    else if(num == 6){
        num -= 6;
        return "VI";
        }
    else if(num == 5){
        num -= 5;
        return "V";
        }
    else if(num == 4){
        num -= 4;
        return "IV";
        }
    else if(num == 3){
        num -= 3;
        return "III";
        }
    else if(num == 2){
        num -= 2;
        return "II";
        }
    else if(num == 1){
        num -= 1;
        return "I";
        }
}
string convert2Roman(int x){
    string ans = "";
    while(x){
        ans += checknum(x);
    }
    return ans;

}
int main(){
    int x = 1248;
    cout<<convert2Roman(x);
    return 0;
}


// METHOD 2
string convert2Roman(int x){
    string ans = "";
    vector<int> values = 
    {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbols = 
        {"M", "CM", "D", "CD", "C", "XC", "L", "XL", 
         "X", "IX", "V", "IV", "I"};

    for(int i=0;i<values.size();i++){
        while(x >= values[i]){
            ans += symbols[i];
            x -= values[i]; 
        }
    }
    return ans;
}