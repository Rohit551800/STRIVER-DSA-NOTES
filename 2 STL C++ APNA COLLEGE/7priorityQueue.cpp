#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue <int> pq; // -- initialization of priority_queue
    pq.push(5);
    pq.push(3);
    pq.push(10);   //// -- pushing elements in priority_queue
    pq.push(4);
    cout<<"Size of priority_queue:"<<pq.size()<<endl; // -- finds the size of priority_queue
    while(!pq.empty()){       // checks for the conditons weather the priority_queue is empty or not
        cout<<pq.top()<<" ";    // -- Print the top element of priority_queue until priority_queue become empty
        pq.pop();        // -- pop the top element 
    }
    cout<<endl;
    cout<<"Size of priority_queue:"<<pq.size()<<endl;
    return 0;
}