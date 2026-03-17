// PATTERN PRINTING


/*--> For the outer loop , count the no. of lines
--> For the inner loop, focus on the columns and connect them somewhere to the rows
--> Print then '*' inside the for loop
--> Observe symmetry for certain patters [OPTIONAL]*/

/*

PATTERN 1

* * * * *
* * * * *
* * * * * 
* * * * *
* * * * *

PATTERN 2

*
* *
* * * 
* * * *
* * * * *

PATTERN 3

1
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5

PATTERN 4

1 
2 2 
3 3 3
4 4 4 4 
5 5 5 5 5

PATTERN 5
* * * * *
* * * *
* * *
* *
*

PATTERN 6
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1
*/

#include<iostream>
using namespace std;
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";\
        }
        cout<<endl;
    }
}
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void pattern5(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
} 
void pattern6(int n){
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pattern7(int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for( int j=0;j<2*i+1;j++){
            cout<<"*"<<"";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<"   ";
        }
        cout<<endl;
    }
}
void pattern8(int n){
   for (int i=0;i<n;i++){
        //SPACE
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        // STAR
        for( int j=0;j<2*n - (2*i+1);j++){
            cout<<"*"<<" ";
        }
        // SPACE
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern9(int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for( int j=0;j<2*i+1;j++){
            cout<<"*"<<"";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<"   ";
        }
        cout<<endl;
    }
    for (int i=1;i<n;i++){
        //SPACE
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        // STAR
        for( int j=0;j<2*n - (2*i+1);j++){
            cout<<"*"<<"";
        }
        // SPACE
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern10(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i+1;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern11(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if((i+j)%2){
                cout<<"0"<<" ";
            }
            else{
                cout<<"1"<<" ";
            }
        }
        cout<<endl;
    }
}

/*
1             1
1 2         2 1
1 2 3     3 2 1 
1 2 3 4 4 3 2 1

*/
void pattern12(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        for(int j=1;j<2*n-2*i+1;j++){
            cout<<" "<<" ";
        }
        for(int j=i;j>=1;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    } 
}
void pattern13(int n){
    int a=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}
void pattern14(int n){
    for(int i=0;i<=n;i++){
        for(char j ='A';j<'A'+i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
//            or
void pattern14a(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<(char)(j+65)<<" ";
        }
        cout<<endl;
    }
}
void pattern15(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<(char)(j+65)<<" ";
        }
        cout<<endl;
    }
}
void pattern16(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<(char)(i+65)<<" ";
        }
        cout<<endl;
    }
}
void pattern17(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<"*"<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<(char)(j+65)<<" ";
        }
        for(int j=i;j>=0;j--){
            cout<<(char)(j+65)<<" ";
        }
        for(int j=0;j<n-i-1;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern18(int n){
    for(int i=0;i<n;i++){
        for(char j='E'-i;j<='E';j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pattern19(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*"<<" ";
        }
        for(int j=0;j<2*i;j++){
            cout<<" "<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        for(int j=2;j<2*n-2*i;j++){
            cout<<" "<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern20(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        for(int j=0;j<2*n-2*i-2;j++){
            cout<<" "<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n-1;i++){
        for(int j=n-i-1;j>0;j--){
            cout<<"*"<<" ";
        }
        for(int j=0;j<=2*i+1;j++){
            cout<<" "<<" ";
        }
        for(int j=1;j<n-i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}
void pattern21(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==n-1 || i==0 || j==0 || j==n-1){
                cout<<"*"<<" ";
            }
            else {
                cout<<" "<<" ";
            }
        }
        cout<<endl;
    }
}
void pattern22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int down = (2*n-2)-j;
            int right =(2*n-2)-i;
            cout<<(n- min(min(top,down) , min( left,right)));
        }
        cout<<endl;
    }
}
int main(){
    int n;
    int t;
    cout<<"Enter value of t:";
    cin>>t;
    for(int i=0;i<t;i++){
    cout<<"Enter the value of n:";
    cin>>n;
    pattern7(n);
    }
    return 0;
}


