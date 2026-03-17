#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec; //0
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.emplace_back(6);
    vec.pop_back();
    cout<<vec.at(4)<<endl; //5
    //to print values 
    for(int val: vec){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<vec.size()<<endl;//3
    cout<<vec.capacity()<<endl; //4

    cout<<"front element:"<<vec.front()<<endl;;
    cout<<"Back element:"<<vec.back()<<endl;;

    return 0;
}