#include<bits/stdc++.h>
using namespace std;
void optimalSolu(vector <vector <int>> &matrix){
    vector<int>ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0 , top = 0 , bottom = n-1 , right = m-1;
    while(left <= right && top <= bottom){
        for(int i=left ;i<=right;i++){
            ans.push_back(matrix[top][i]);
        };
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    for(auto it : ans){
        cout<<it;
    }
}
int main(){
    int n;
    cout<<"Enter the number of rows:";
    cin>>n;
    int m;
    cout<<"Enter the number of columns:";
    cin>>m;
    vector <vector <int>> matrix;
    for(int i=0;i<n;i++){
        vector <int> row;
        for(int j=0;j<m;j++){
            int a ;
            cout<<"Enter element "<<i<<j<<":";
            cin>>a;
            row.push_back(a);
        }
        matrix.push_back(row);
    }
    optimalSolu(matrix);
}