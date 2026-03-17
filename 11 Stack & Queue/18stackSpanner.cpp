// #include<bits/stdc++.h>
// using namespace std;
// class stockSpanner{
//     public:
//     vector<int>arr;
//     stockSpanner(){

//     }
//     //optimizing bruteforce solution
//     vector<int>prevGreaterIndex(vector<int>arr){
//         int n = arr.size();
//         stack<int>st;
//         vector<int>pge(n);
//         for(int i=0;i<n;i++){
//             while(!st.empty() && arr[st.top()] <= arr[i]){
//                 st.pop();
//             }
//             if(st.empty()) pge[i] = -1;
//             else pge[i] = st.top();
//             st.push(i);
//         }
//         return pge;
//     }
//     //Optimizing bruteforce Solution
//     int next1(int val){
//         arr.push_back(val);
//         int n = arr.size();
//         vector<int>pge = prevGreaterIndex(arr);
//         int elemIndex = arr.size() - 1;
//         int prevIndex = pge[n-1];
//         int ans = elemIndex - prevIndex;
//         return ans;
//     }
//     //Bruteforce method
//     int next(int val){
//         arr.push_back(val);
//         int counter = 1; 
//         int n = arr.size();
//         for(int i = n-2;i>=0;i--){
//             if(arr[i] <= val) counter++;
//             else break;
//         }
//         return counter;
//     }

// };
// int main(){
//     stockSpanner ss;

//     vector<int> prices = {7 , 2 , 1 , 3 , 3 , 1 , 8};

//     cout << "Using optimized next1():" << endl;
//     for (int p : prices) {
//         cout << ss.next1(p) << " ";
//     }
//     cout << endl;

//     stockSpanner ss2;
//     cout << "Using brute-force next():" << endl;
//     for (int p : prices) {
//         cout << ss2.next(p) << " ";
//     }
//     cout << endl;
//     return 0;
// }



//Optimal Solution method 1

// #include<bits/stdc++.h>
// using namespace std;
// class stockSpanner{
//     public:
//     stack<pair<int,int>>st;
//     stockSpanner(){
//     }
//     int next1(int val){
//         int span = 1;
//         while(!st.empty() && st.top().first <= val){
//             span += st.top().second;
//             st.pop();
//         }
//         st.push({val , span});
//         return span;
//     }
// };
// int main(){
//     stockSpanner ss;

//     vector<int> prices = {7 , 2 , 1 , 3 , 3 , 1 , 8};

//     cout << "Using optimized next1():" << endl;
//     for (int p : prices) {
//         cout << ss.next1(p) << " ";
//     }
//     cout << endl;
//     return 0;
// }



// optimal Solution 2


#include<bits/stdc++.h>
using namespace std;
class stockSpanner{
    public:
    stack<pair<int,int>>st;
    int index = -1;
    stockSpanner(){
    }
    int next2(int val){
        index = index + 1;
        while(!st.empty() && st.top().first <= val){
            st.pop();
        }
        int ans  = index - (st.empty() ? -1 : st.top().second);
        st.push({val , index});
        return ans;
    }
};
int main(){
    stockSpanner ss2;
    vector<int> prices = {7 , 2 , 1 , 3 , 3 , 1 , 8};

    cout << "Using Optimal SOlution method 2 next():" << endl;
    for (int p : prices) {
        cout << ss2.next2(p) << " ";
    }
    cout << endl;
    return 0;
}
