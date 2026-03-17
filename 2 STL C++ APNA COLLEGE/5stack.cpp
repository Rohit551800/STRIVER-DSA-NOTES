#include<bits/stdc++.h>
using namespace std;
int main(){
    stack <int> s; // -- initialization of stack
    s.push(1);
    s.push(2);   //// -- pushing elements in stack
    s.push(3);
    cout<<"Size of stack:"<<s.size()<<endl; // -- finds the size of stack
    while(!s.empty()){       // checks for the conditons weather the stack is empty or not
        cout<<s.top()<<" ";    // -- Print the top element of stack until stack become empty
        s.pop();        // -- pop the top element 
    }
    cout<<endl;
    cout<<"Size of stack:"<<s.size()<<endl;
    return 0;
}

// Swap function()

#include<bits/stdc++.h>
using namespace std;
int main(){
    stack <int> s; // -- initialization of stack
    s.push(1);
    s.push(2);   //// -- pushing elements in stack
    s.push(3);
    cout<<"Size of stack:"<<s.size()<<endl; // -- finds the size of stack s
    
    stack <int> s2;    // -- initialization of second stack
    s2.swap(s);
    cout<<"Size of stack:"<<s2.size()<<endl; // -- finds the size of stack s2
    cout<<"Elements of stack s"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"Elements of stack s2"<<endl;
    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl;
    cout<<"Size of stack s:"<<s.size()<<endl;
    cout<<"Size of stack s2:"<<s2.size()<<endl;
    return 0;
}