#include<bits/stdc++.h>
//#include<map>
using namespace std;
int main(){
    map<string,int> m;
    m["Tv"] = 100;
    m["Laptop"] = 100;
    m["Headphones"] =50;
    m["Tablet"] =120;
    m["Watch"] =50;
    m.insert({"Camera",130}); //--bad practice
    m.emplace("Ps5" , 10);
    cout<<"Keys associated with Laptop"<<m.count("Laptop")<<endl; // --count the keys associated with Laptop
    m.erase("Tv");
    for(auto val : m){
        cout<<val.first<<" "<<val.second<<" ";
        cout<<endl;
    }
    cout<<endl;
    if(m.find("Laptop")!=m.end()){
        cout<<"found"<<endl;
    }else{
        cout<<"Not found"<<endl;
    };cout<<endl;
    cout<<"Count :"<<m["Laptop"]<<endl;
    return 0;
}
/*OUTPUT
Headphones 50 
Laptop 100
Tablet 120      //-- Map ka ouput k according sort hoke ata hai
Tv 100          //-- jaise ki yha pe ASCII value a according sorted hai
Watch 50
*/