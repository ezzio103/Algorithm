#include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
string sKey[12] = {
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz",
    "", " ", ""
};
int t;
int a[100], b[100]; 
bool mark[100];   
   
void in() {
    for (int i = 0; i <t; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Try(int k){
    for(int i = 0;i<t;i++){
        if(mark[i]==false){
            mark[i]=true;
            a[k]=b[i];
        
        if(k==(t-1)){
            in();
        }else{Try(k+1);}
        mark[i]=false;}
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string z;
    cin >> t;
   
   
    
    for(int n=0;n<t;n++){
        cin >>b[n];
        mark[n]=false;
    }
    Try(0);

    return 0;
}
//
