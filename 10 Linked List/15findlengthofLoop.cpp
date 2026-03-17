#include <bits/stdc++.h>

using namespace std;

// Node class represents a node
// in a linked list
class Node {
public:
    // Data stored in the node
    int data;      
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* DetectLoop(Node* head){
    if(head == nullptr || head->next == nullptr)return nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)return slow;
    }
    return nullptr;
}
int findlengthOfLoop(Node* head){
    Node* intersection = DetectLoop(head);
    Node* slow = intersection;
    int counter = 1;
    while(slow->next != intersection){
        counter++;
        slow = slow->next;
    }
    return counter;
}
int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;
    int ans = findlengthOfLoop(head);
    cout<<ans;

    
    return 0;
}