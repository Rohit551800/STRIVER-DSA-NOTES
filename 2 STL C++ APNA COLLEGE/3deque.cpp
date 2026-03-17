#include<bits/stdc++.h>  // INCLUDES ALL HEADER FILES IN C++
//#include<deque>    -- header file used to include deque
using namespace std;
int main(){
    //Initialization of deque


    //deque<int> l (3,10);  -- 3 consicutive 10s in the deque
    deque<int> d1 ={11,22,33};
    deque<int> d (d1);
    //deque<int> l1;  // --No starting initialization
    d.push_back(1); // PUSH FROM RIGHT
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    d.push_front(7); // PUSH FROM LEFT
    d.pop_back();  // POP FROM RIGHT
    d.pop_front();  // POP FROM LEFT
    d.emplace_back(1);  // INSERT LAST ELEMENT FROM RIGHT
    d.emplace_front(0);  // INSERT LAST ELEMENT FORM LEFT

    // FOR EACH LOOP TO PRINT VALUES OF deque
    for(int val: d){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"Element at index 2 is:"<<d[2]; //-- Random access possible
    return 0;
}