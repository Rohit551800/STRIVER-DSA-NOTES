#include<bits/stdc++.h>
using namespace std;
class minStack1{
    stack<pair<int,int>>st;
public:
    void push(int val){
        if(st.empty()) st.push({val , val});
        else{
            st.push({val , min(val , st.top().second)});
        }
    }
    int pop(){
        int delElem = st.top().first;
        st.pop();
        return delElem;
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }
};
class minStack2{
    stack<int>st;
    int mini = INT_MAX;
public:
    void push(int val){
        if(st.empty()){
            st.push(val);
            mini = val;
        }  
        else if(val > mini){
            st.push(val);
        }
        else{
            st.push(2*val - mini);
            mini = val;
        }        
    }
    int pop(){
        if(st.empty()) return -1;
        int x = st.top();
        st.pop();
        if(x < mini){
            int del = mini;
            mini = 2 * mini - x;
            return del;
        }
        return x;
    }
    int top(){
        if(st.empty()) return -1;
        int x = st.top();
        if(x > mini) return x;
        else return mini;
    }
    int getmini(){
        return mini;
    }
};
int main(){
    // minStack1 min;
    // min.push(12);
    // min.push(15);
    // min.push(10);
    // cout<<"Minimum val is :"<<min.getMin()<<endl;
    // cout<<"Deleted element is :"<<min.pop()<<endl;
    // cout<<"Top element is :"<<min.top()<<endl;
    // cout<<"Minimum val is :"<<min.getMin()<<endl;


    minStack2 min;
    min.push(12);
    min.push(15);
    min.push(10);
    cout<<"Minimum val is :"<<min.getmini()<<endl;
    cout<<"Deleted element is :"<<min.pop()<<endl;
    cout<<"Top element is :"<<min.top()<<endl;
    cout<<"Minimum val is :"<<min.getmini()<<endl;
    return 0;
}