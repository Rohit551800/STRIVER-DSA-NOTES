#include<bits/stdc++.h>
using namespace std;
int main(){
    queue <int> q; // -- initialization of queue
    q.push(1);
    q.push(2);   //// -- pushing elements in queue
    q.push(3);
    cout<<"Size of queue:"<<q.size()<<endl; // -- finds the size of queue
    while(!q.empty()){       // checks for the conditons weather the queue is empty or not
        cout<<q.front()<<" ";    // -- Print the top element of queue until queue become empty
        q.pop();        // -- pop the top element 
    }
    cout<<endl;
    cout<<"Size of queue:"<<q.size()<<endl;
    return 0;
}