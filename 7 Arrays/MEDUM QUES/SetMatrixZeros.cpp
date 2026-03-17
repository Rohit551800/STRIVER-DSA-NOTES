#include<bits/stdc++.h>
using namespace std;

//Brute force Solution 

void markRow( vector <vector<int>> &matrix , int i , int n){
    for(int j=0;j<n;j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void markCol( vector <vector<int>> &matrix , int j , int m){
    for(int i=0;i<m;i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void bruteforceSolu(vector<vector<int>> &matrix ,int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                markRow(matrix , i , n);
                markCol(matrix , j , m);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}

// Better Solution

void betterSolu(vector <vector <int>> &matrix , int n , int m){
    int row[n] = {0};
    int col[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] ==1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }
}

// Optimal Solution

void optimalSolu(vector <vector <int>> &matrix , int n , int m){
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] ==0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] =0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j] != 0 ){
                if(matrix[i][0] ==0 || matrix[0][j] ==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0; 
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
}
int main(){
    int n , m;
    cout<<"Enter the number of rows:";
    cin>>n;
    cout<<"Enter the number of columns:";
    cin>>m;
    vector <vector <int>> matrix;
    for(int i=0;i<n;i++){
        vector <int> row;
        for(int j=0;j<m;j++){
            int a;
            cout<<"Enter element"<<i<<j<<":";
            cin>>a;
            row.push_back(a);
        }
        matrix.push_back(row);
    }
   // bruteforceSolu(matrix , n , m);
    //betterSolu(matrix , n , m);
    optimalSolu(matrix , n , m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"|"<<matrix[i][j]<<"|";
        }
        cout<<endl;
    }
}