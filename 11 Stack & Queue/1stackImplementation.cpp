//Stack Implemenatation using Arrays


// #include<iostream>
// using namespace std;
// class Stack{
//     int top ;
//     int arr[10];
// public:
//     Stack(){
//         top = -1;
//     }
//     void pushVal(int val){
//         if(top >= 9){
//             cout<<"Stack is overflow"<<endl;
//         }
//         else {
//             top++;
//             arr[top] = val;
//             cout<<"Value inserted successfully"<<endl;
//         }
//     }
//     void pop(){
//         if(top == -1){
//             cout<<"Stack is Empty"<<endl;
//         }
//         else{
//             top--;
//             cout<<"Value deleted successfully"<<endl;

//         }
//     }
//     int topVal(){
//         if(top == -1){
//             cout<<"Stack is empty"<<endl;
//             return -1;
//         }
//         else{
//             return arr[top];
//         }
//     }
//     int size(){
//         return top+1;
//     }
// };
// int main(){
//     Stack s;
//     // int val;
//     // cout<<"Enter the value to push in stack:"<<endl;
//     // cin>>val;
//     s.pushVal(4);cout<<endl;
//     s.pop();cout<<endl;
//     cout<<s.topVal();cout<<endl;
//     s.pushVal(5);cout<<endl;
//     s.pushVal(6);cout<<endl;
//     s.pushVal(10);cout<<endl;
//     cout<<s.topVal()<<endl;
//     cout<<s.size();cout<<endl;
//     return 0;
// }


// Stack Implemenatation using LinkedList

// #include<bits/stdc++.h>
// using namespace std;
// class StackLL{
// public:
//     struct Node{
//         int data ;
//         Node* next;
//         Node(int val){
//         data = val;
//         next = nullptr;
//         }
//     };
//     Node* top;
//     int counter;

//     StackLL(){
//         top = nullptr;
//         counter = 0;
//     }
//     void pushVal(int val){
//         Node* temp = new Node(val);
//         temp->next = top;
//         top = temp;
//         counter++;
//         cout<<val<<" Pushed in the stack:"<<endl;
//     }
//     int pop(){
//         if(top == nullptr) return 0;
//         Node* temp = top;
//         top = top->next;
//         int el = temp->data;
//         delete temp;
//         counter--;
//         return el;
//     }
//     int topVal(){
//         return top->data;
//     }
//     int stackSize(){
//         return counter;
//     }
// };
// int main(){
//     StackLL s;
//     s.pushVal(2);
//     cout<<s.topVal()<<endl;
//     cout<<s.stackSize()<<endl;
//     cout<<s.pop();
//     return 0;
// }



// Stack Implementation using Queue

#include<iostream>
#include<queue>
using namespace std;
class Queue{
    private:
    queue<int>q;
public:
    void pushVal(int x){
        int size = q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
        cout<<x<<" is Inserted Successfully"<<endl;
    }
    void popVal(){
        cout<<q.front()<<" Deleted Successfully"<<endl;
        q.pop();
    }
    int topVal(){
        if(q.empty()) return 0;
        return q.front();
    }
};
int main(){
    Queue q;
    q.pushVal(2);
    q.popVal();
    cout<<"Top Val is "<<q.topVal()<<endl;
}