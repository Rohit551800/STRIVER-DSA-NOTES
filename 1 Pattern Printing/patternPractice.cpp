#include<bits/stdc++.h>
using namespace std;
void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void pattern5(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"* "<<" ";
        }
        cout<<endl;
    }
}
void pattern7(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern8(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*n-(2*i)-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void pattern9(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*n-(2*i)-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern10(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern11(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if((i+j)%2 == 0)cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
void pattern12(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        for(int j=0;j<2*n - 2*(i+1);j++){
            cout<<"  ";
        }
        for(int j=i;j>=0;j--){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void pattern13(int n){
    int counter = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<counter<<" ";
            counter++;
        }
        cout<<endl;
    }
}
void pattern14(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<char(j + 'A')<<" ";
        }
        cout<<endl;
    }
}
void pattern15(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<char(j + 'A')<<" ";
        }
        cout<<endl;
    }
}
void pattern16(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<char(i+'A')<<" ";
        }
        cout<<endl;
    }
}
void pattern17(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<"  ";
        }
        for(int j=0;j<=i;j++){
            cout<<char(j + 'A')<<" ";
        }
        for(int j=i-1;j>=0;j--){
            cout<<char(j + 'A')<<" ";
        }
        cout<<endl;
    }
}
void pattern18(int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            cout<<char(n - j - 1 + 'A')<<" ";
        }
        cout<<endl;
    }
}
void pattern19(int n){
    int counter = 'A';
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<char(counter + 'A')<<" ";
            counter++;
        }
        cout<<endl;
    }
}
void patternx(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*i+1;j++){
            if(j == 0 || j == 2*i || i == n-1) cout<<"* ";
            else cout<<"  ";
        }
        cout<<endl;
    }
}
int main(){
    int row = 5;
    pattern1(row);
    pattern2(row);
    pattern3(row);
    pattern4(row);
    pattern5(row);
    // pattern6(row);
    pattern7(row);
    pattern8(row);
    pattern9(row);
    pattern10(row);
    pattern11(row);
    pattern12(row);
    pattern13(row);
    pattern14(row);
    pattern15(row);
    pattern16(row);
    pattern17(row);
    pattern18(row);
    pattern19(row);
    // patternx(row);
    return 0;
}