#include<bits/stdc++.h>
using namespace std;
int bruteforce(vector<vector<int>>&mat){
    int n = mat.size();
    vector<int>knowMe(n,0);
    vector<int>iKnow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(knowMe[i] == n-1 && iKnow[i] == 0){
            return i;
        }
    }
    return -1;
}
int optimalSolu(vector<vector<int>>&mat){
    int n = mat.size();
    int top = 0;
    int down = n-1;
    while(top < down){
        if(mat[top][down] == 1){
            top++;
        }
        else if(mat[down][top] == 1){
            down--;
        }
        else{
            top++;
            down--;
        }
    }
    if(top > down) return -1;
    for(int i=0;i<n;i++){
        if(i == top) continue;
        if(mat[top][i] == 0 && mat[i][top] == 1){}
        else return -1;
    }
    return top;
}
int main(){
    vector<vector<int>> mat = {
        {0 , 1 , 1 , 0},
        {0 , 0 , 0 , 0},
        {0 , 1 , 0 , 0},
        {1 , 1 , 0 , 0}
    };
  //  cout<<"Celebrity using bruteforce solu:"<<bruteforce(mat);
    cout<<"Celebrity using bruteforce solu:"<<optimalSolu(mat);
    return 0;
}