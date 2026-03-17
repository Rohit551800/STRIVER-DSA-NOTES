#include<bits/stdc++.h>  // INCLUDES ALL HEADER FILES IN C++
//#include<list>    -- header file used to include list 
using namespace std;
int main(){
    //Initialization of list

    //list<int> l (3,10);  -- 3 consicutive 10s in the list
    list<int> l1 ={11,22,33};
    list<int> l (l1);
    //list<int> l1;  // --No starting initialization
    l.push_back(1); // PUSH FROM RIGHT
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_front(7); // PUSH FROM LEFT
    l.pop_back();  // POP FROM RIGHT
    l.pop_front();  // POP FROM LEFT
    l.emplace_back(1);  // INSERT LAST ELEMENT FROM RIGHT
    l.emplace_front(0);  // INSERT LAST ELEMENT FORM LEFT

    // FOR EACH LOOP TO PRINT VALUES OF LIST
    for(int val: l){
        cout<<val<<" ";
    }

    // l[2]; -- Random access not possible
    return 0;
}