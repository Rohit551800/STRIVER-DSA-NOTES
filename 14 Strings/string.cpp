// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     // char arr[10] = {'R','o','h','i','t'};
//     // cout<<arr;
//     //output :Rohit


//     char arr[10];
//     cin>>arr;
//     //input :RohitSingh
//     arr[2] = '\0';
//     cout<<arr;
//     //Output:Ro
//     //Null k agge compiler read hi nahi karega
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     // string s;
//     // cin>>s;   //input:Rohit Singh
//     // cout<<s;  //output:Rohit  -- /*? cin>>read nahi karta after space/tab/enter use getline(cin,s); */
    

//     string s;
//     getline(cin , s);
//     cout<<s;
//     cout<<s.size();
//     return 0;
// }



//Combining two strings


#include<bits/stdc++.h>
using namespace std;
int main(){
    // string s1 , s2 , s3;
    // s1 = "Rohit";
    // s2 = "Mohit";
    // s3 = s1 + s2;
    // cout<<s3<<endl;

    // s1.push_back('P') ;
    //   or
    // s1 = s1 + "p";
    
    // cout<<s1<<endl;

    // s2.pop_back();
    // cout<<s2;
    // return 0;


    string s = "Rohit is \"Good\" boy";
    cout<<s; //Rohit is "Good" boy
    cout<<s.size(); //19
}