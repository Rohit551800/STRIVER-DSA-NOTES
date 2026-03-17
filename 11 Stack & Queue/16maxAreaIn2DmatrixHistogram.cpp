#include<bits/stdc++.h>
using namespace std;
int maxAreaFunc(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int maxArea = 0;
    vector<vector<int>> preSumMat(n , vector<int>(m , 0));
    for(int j=0;j<m;j++){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += mat[i][j];
            if(mat[i][j] == 0) sum = 0;
            preSumMat[i][j] = sum;
        }
    }
    for(int i = 0;i<n;i++){
        stack<pair<int,int>>st;
        for(int j=0;j<m; j++){
            while(!st.empty() && st.top().first > preSumMat[i][j]){
                int elem = st.top().first;
                st.pop();
                int nsIndex = j;
                int psIndex = st.empty() ? -1 : st.top().second;
                maxArea = max(maxArea , elem * (nsIndex - psIndex -1));
            }
            st.push({preSumMat[i][j] , j});
        }
        while(!st.empty()){
            int elem = st.top().first;
            st.pop();
            int nsIndex = m;
            int psIndex =st.empty() ? -1 : st.top().second;
            maxArea = max(maxArea , elem * (nsIndex - psIndex - 1));
        }
    }
    return maxArea;
}
int main(){
    vector<vector<int>>mat = {
        {1 , 0 , 1 , 0 , 1},
        {1 , 0 , 1 , 1 , 1},
        {1 , 1 , 1 , 1 , 1},
        {1 , 0 , 0 , 1 , 0}
    };
    int maxArea = maxAreaFunc(mat);
    cout<<maxArea;
    return 0;
}