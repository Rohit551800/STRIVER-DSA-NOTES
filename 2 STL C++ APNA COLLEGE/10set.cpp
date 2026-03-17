#include<iostream>
#include<set>
using namespace std;
int main(){
    set <int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout<<"Size of set :"<<s.size()<<endl;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    cout<<"Size of set :"<<s.size()<<endl; // -- Unique value hi store krta hai bs duplicate values insert hi nahi hoti
    for(auto val : s){
        cout<<val <<" "<<endl;
    }
    if(s.find(2) != s.end()){
        cout<<"Element Present in Set"<<endl;
    }else{
    cout<<"Element not Present in Set"<<endl ;
    }
    cout<<"Total number of elements:"<<s.count(3);
    return 0;
}


// -- As of maps we have multiset and unordered_set 
// -- Multisets can store data in organised manner and provides the output in sorted form but can store duplicate values in it
// -- Where as Unordered set cannot provide data in sorted order it store the data in a Random manner but duplicate values are not allowed


