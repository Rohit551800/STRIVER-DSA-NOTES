// Multimap

#include<bits/stdc++.h>
using namespace std;
int main(){
    multimap <string,int> m;
    m.emplace("Tv"  , 100);
    m.emplace("Tv"  , 100);
    m.emplace("Tv"  , 100);
    m.emplace("Tv"  , 100);
    m.emplace("Tv"  , 100);
    m.erase(m.find("Tv"));  // -- m.erase(Tv); will delete all the Tv keys in the map SO use find along with erase
    for(auto val : m) {
        cout<< val.first <<" "<<val.second<< " "<<endl;
    }      
    return 0;
}




// Unorderd map
#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map <string,int> m;
    m.emplace("Laptop"  , 100);
    m.emplace("Tv"  , 100);
    m.emplace("Camera"  , 100);
    m.emplace("Ps5"  , 100);
    m.emplace("Watch"  , 100);
    m.erase(m.find("Tv"));  // -- m.erase(Tv); will delete all the Tv keys in the map SO use find along with erase
    for(auto val : m) {
        cout<< val.first <<" "<<val.second<< " "<<endl;
    }      
    return 0;
}