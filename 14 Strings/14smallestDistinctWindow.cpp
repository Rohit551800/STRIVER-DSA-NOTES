//Smallest Distinct window that contain all the characters

#include<bits/stdc++.h>
using namespace std;

int smallestDistinctWindow(string s){
    int len = s.size() , first = 0  , second = 0;
    vector<int>chars(256 , 0);

    // Calculate Diff
    int diff = 0;
    while(first < s.size()){
        if(chars[s[first]] == 0){
            diff++;
        }
        chars[s[first]]++;
        first++;
    }

    fill(chars.begin(), chars.end(), 0);
    first = 0;

    while(second < s.size()){
        // check diff exist krta hai
        while(diff && second < s.size()){
            if(chars[s[second]] == 0){
                diff--;
            }
            chars[s[second]]++;
            second++;
        }

        len = min(len , second - first);

        // diff ki value 1 na ho jae
        while(diff == 0){
            len = min(len , second - first);
            chars[s[first]]--;

            if(chars[s[first]] == 0){
                diff++;
            }
            first++;
        }
    }
    return len;
}
int main(){
    string s = "AABBBCBBAC";
    cout<<smallestDistinctWindow(s);
    return 0;
}