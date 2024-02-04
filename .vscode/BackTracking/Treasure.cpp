#include<bits/stdc++.h>
using namespace std;

int n,m;
long long res = 0;
long long a[1002][1002];
bool b[1002][1002];
int p[]={1,0,1};
int z[]={0,1,1};
char t[]={'R','D','C'};
string s="",road="";
void Try(int x,int y,long long tong){
    if(x==n-1&&y==m-1){
        // tong+=a[n-1][n-1];
        if(tong>res){
            res=tong;
            road=s;
        }
        
            
         return;
    }
   
   for(int i=0;i<3;i++){
    
    if(x+z[i]<n && y+p[i]<m  && b[x+z[i]][p[i]+y]==false){
        b[x+z[i]][p[i]+y]=true;
        tong+= a[x+z[i]][p[i]+y];
        s.push_back(t[i]);
        Try(x+z[i],y+p[i],tong);
        s.pop_back();
        tong -=a[x+z[i]][p[i]+y];
        b[x+z[i]][p[i]+y]=false;
        
    }
   }
   
   return;
}
int main(){
    int x1,y1,z1;
    memset(b,false,sizeof(b));
    memset(a,0,sizeof(a));
    cin>>n;
    int n1=0;
    m=0;
    // for(int i=0;i<n;i++){
    //     for(int j=0; j<m;j++)
    //     cin>> a[i][j];
    // }
    for (int i = 0; i < n; i++){
        cin>>x1>>y1>>z1;
        a[x1-1][y1-1]=z1;
        n1=max(n1,x1);
        m=max(m,y1);
    }
    n=n1;
    
    Try(0,0,a[0][0]);
   
    if(res>0){
        cout<<res<<" "<<road;
    }
    else{
        cout<<-1;
    }
 
    return 0;
}