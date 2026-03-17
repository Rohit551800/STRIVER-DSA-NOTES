#include<iostream>
#include<vector>
using namespace std;
int main(){
// METHOD 1 OF initialization of vector
    vector<int> vec = {1,2,3,4,5};

// METHOD 3 OF initialization of vector
    vector<int> vec1 (vec);


// >>>>>>>>>>>>>>>> ITERATORS IN VECTORS <<<<<<<<<<<<<<<<<<
 //  FORWORD LOOP

/*  vector <int> :: iterator it;
    for (it = vec1.begin() ; it !=vec1.end();it++){
        cout<<*(it)<<" ";
    }
*/
/*  BACKWORD LOOP*/
    // vector <int> ::reverse_iterator it;
    for (auto it = vec.rbegin(); it !=vec.rend();it++){
        cout<<*(it)<<" ";
    }
    return 0;
}