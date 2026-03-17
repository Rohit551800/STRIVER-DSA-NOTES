// #include <bits/stdc++.h>
// using namespace std;
// bool isUnique(string &s, int i, int j)
// {
//     vector<int> vec(26, 0);
//     for (int x = i; x <= j; x++)
//     {
//         if (vec[s[x] - 'a'] == 1)
//             return false;
//         vec[s[x] - 'a'] = 1;
//     }
//     return true;
// }
// int longestSubstringWithUniqueCharacters(string s)
// {
//     int maxlen = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = i; j < s.size(); j++)
//         {
//             if (isUnique(s, i, j))
//             {
//                 int leng = j - i + 1;
//                 maxlen = max(maxlen, leng);
//             }
//         }
//     }
//     return maxlen;
// }  
// int main()
// {
//     string s = "ababc";
//     // cout<<longestSubstringWithUniqueCharacters(s);
//     cout << usingSlidingWindow(s);
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int usingSlidingWindow(string s)
{
    vector<int>vec(256,0);
    int first = 0 , second = 0 ;
    int maxlen = 0 ;
    while(second < s.size()){
        if(vec[s[second]] == 0){
            vec[s[second]] = 1;
            int len = second - first + 1;
            maxlen = max(len , maxlen);
            second++;
        }
        else{
            vec[s[first]] = 0;
            first++;
        }        
    }
    return maxlen;
}
int main()
{
    string s = "abcdebcadef";
    cout << usingSlidingWindow(s);
    return 0;
}
