#include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int a,b,f,m; //a nguoi, b keo, f keo da chia, m la so keo max chia cho 1 nguoi
int res[1000];
   
void in() {
    for (int i = 1; i <=a; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
void Try(int k){
    
    if(k==a){
        res[k]=b-f;
        in();
        return;
    }
    m= b-f-(a-k);
    for(int i=1;i<=m;++i){
        res[k]=i;
        f=f+i;
        Try(k+1);
        f=f-i;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i<1000;i++){
        res[i]=0;
        res[i]=1;
        
    }
    string z;
    cin >> a >>b;
   f=0;
   Try(1);
    
   

    return 0;
}
//
