// #include<bits/stdc++.h>
// using namespace std;
// class Queue{
// private:
//     static int size ;
//     int start;
//     int end;
//     int arrSize;
//     int* q;

// public:

//     Queue(){
//        start = -1;
//        end  = -1;
//        arrSize = 0;
//        q = new int[size];
//     }


//     // functions of queue

//     void pushVal(int val){
//         if(arrSize == size) {
//             cout<<"Queue is full:"<<endl;
//         }
//         else if (arrSize == 0){
//             start = 0;
//             end = 0;
//             q[end] = val;
//             arrSize++; 
//         }
//         else{
//             end = (end+1)%size;
//             q[end] = val;
//             arrSize++;            
//         }
//     }
//     int pop(){
//         if(arrSize == 0){
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }
//         int el = q[start];
//         if (arrSize == 1){
//             start = end = -1;
//             return el;
//         }
//         else {
//             start = (start + 1) % size;
//             arrSize--;
//             return el;
//         }
//     }
//     int peek(){
//         if(arrSize == 0) return 0;
//         else return q[start];
//     }
//     int curSize(){
//         return arrSize;
//     }
// };
// int Queue :: size = 4;
// int main(){
//     Queue q;
//     q.pushVal(10);
//     q.pushVal(20);
//     q.pushVal(30);
//     q.pushVal(40);

//     cout << "Front element: " << q.peek() << endl;
//     cout << "Popped: " << q.pop() << endl;
//     cout << "Front after pop: " << q.peek() << endl;

//     q.pushVal(50);  // check circular behavior
//     cout << "Front element now: " << q.peek() << endl;

//     return 0;
// }


// Implementation of Queue using LinkedList
#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
    struct Node{
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
    };
public:
    Node* start;
    Node* end;
    int counter;
    Queue(){
        start = nullptr;
        end = nullptr;
        counter = 0;
    }
    void pushVal(int val){
        if(start == nullptr){
            Node* firstNode = new Node(val);
            start = end = firstNode;
        }
        else{
            Node* temp = new Node(val);
            end->next = temp;
            end = temp;
        }
        counter++;
        cout<<val<<" Inserted Successfully"<<endl;
    }
    int popVal(){
        if(start == nullptr) return -1;
        Node* temp = start;
        start = start->next;
        int delElem = temp->data;
        delete temp;
        counter--;
        return delElem;
    }
    int frontVal(){
        return start->data;
    }
    int llSize(){
        return counter;
    }
};
int main(){
    Queue q;
    q.pushVal(2);
    cout<<q.llSize()<<endl;
    cout<<q.frontVal()<<endl;
    cout<<q.popVal();
    return 0;
}