#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int left = 0 , right = 0;
        while( left < n && right < m){
            if(g[left] <= s[right]){
                left++;
                right++;
            }
            else {
                right++;
            }
        }
        return left;
    }
};
int main(){
    Solution x;
    vector<int> g = {1 , 5 , 3 , 3, 4};
    vector<int> s = {4 , 2 , 1 , 2 , 1 , 3};
    int result = x.findContentChildren(g , s);
    cout<<result;
}