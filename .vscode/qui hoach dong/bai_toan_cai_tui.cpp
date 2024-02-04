#include<bits/stdc++.h>
using namespace std;
int n,m,w[100],v[100],bMark[100][100];
int Try(int n,int m){
    if(n==0||m==0){
        return 0;
    }
    if(bMark[n][m]!=-1){
        return bMark[n][m];
    }
    int res;
    if(m-w[n]>=0)
     res= max(Try(n-1,m),Try(n-1,m-w[n])+v[n]);
     else{res=Try(n-1,m);}
    bMark[n][m]=res;
    return res;
}
int main(){
    memset(bMark,-1,sizeof(bMark));
    cin >> n >>m;
    for(int i=1;i<=n;i++){
        cin >> w[i]>>v[i];
    }
   cout<< Try(n,m);
    return 0;
}