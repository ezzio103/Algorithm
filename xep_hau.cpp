#include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int a,b[8][8]; //a so quan hau,b danh dau, c la co the dat duoc
int c[8][8];

   
void in() {
    for (int i = 0; i <8; i++) {
        for(int j=0; j<8;j++){
            if(b[i][j]==1){
                cout << i << j <<endl;
            }
        }
    }
    cout << endl;
}
void Try(int k){
    for(int n=k;n<(8-(a-k-1));n++){
    for(int i=0 ;i<8;i++ ){
        if(c[n][i]==1){
            b[n][i]=1;
            if(k==(a-1)){
                in();
                b[n][i]=0;
                continue;
            }
            for(int j=n+1;j<8;j++){
                c[j][i]=0;
                if(i+(j-n)<8){
                    c[j][i+(j-n)]=0;
                };
                if(i-(j-n)>=0){
                    c[j][i-(j-n)]=0;
                };
            }
            Try(k+1);
            b[n][i]=0;
            for(int j=n+1;j<8;j++){
                c[j][i]=1;
                if(i+(j-n)<8){
                    c[j][i+(j-n)]=1;
                };
                if(i-(j-n)>=0){
                    c[j][i-(j-n)]=1;
                };
            }
        }
    }
    }
    ////
    
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    for (int i = 0; i <8; i++) {
        for(int j=0; j<8;j++){
           c[i][j]=1;
           b[i][j]=0;
        }
    }
    
    cin >> a;
  
   Try(0);
    
   

    return 0;
}
//
