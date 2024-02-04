#include<bits/stdc++.h>
using namespace std;
int n,v[110][110],a[110];
int Try(int n,int m){
if(n==0){
    return 0;
}
if(v[n][m]!=-1){
    return v[n][m];
}
int res;
if(m>a[n-1]){
res=max(Try(n-1,m),Try(n-1,a[n-1])+1);
}
else{
    res=Try(n-1,m);
}
v[n][m]=res;
return res;
}
int main(){
   
    memset(v,-1,sizeof(v));
    cin >> n;
    int i=1;
    for( i=1 ;i<=n;i++){
        // cout<<i;
        cin >> a[i];
        // cout <<a[i];
    }
   cout<< Try(n,101);
    return 0;
}