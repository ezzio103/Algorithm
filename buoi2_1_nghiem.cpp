#include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int a,b,f; //a so bien, b tong gia tri, f tong gia tri da chia, m la so  max chia cho 1 bien
int res[1000];
   int heSo[1000];
   int cx=0;
void in() {
    for (int i = 0; i <a; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
void Try(int k){
    if(k==a-1){if(( b-f) % heSo[k]==0)
        // res[k]=b-f;
        // in();
       cx++;
        return;
    }
    int tong=0;
    for (int i = k+1; i < a; i++)
    {   tong+=heSo[i];
        /* code */
    }
    
    int m= b-f-tong;
    // cout << k << m<< endl;
    // for(int j=1;j<=m;j++){
       
        
    //     if(heSo[k]*j<=m){
    //         f+=heSo[k]*j; 
    //         res[k]=j;
    //     Try(k+1);
    //     f-=heSo[k]*j;
    //     }
    // }
    for (int j = 1; j <= m; j++) {
    if (heSo[k] * j <= m) {
        f += heSo[k] * j;
        res[k] = j;
        Try(k + 1);
        f -= heSo[k] * j;
    }
}


};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
   
    cin >> a >>b;
    for(int i = 0; i<a;i++){
        cin >> heSo[i];
        
        
    }
   f=0;
   Try(0);
    
    cout << cx;

    return 0;
}
//
