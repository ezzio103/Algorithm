#include<bits/stdc++.h>
using namespace std;
int n,p,a[100],res=0;
void Try(int k,int m,int tong){
    if(m==0){
        if(tong>=p&&tong%5==0){
            cout<<tong<<endl;
            res++;
            
        }
        return;
    }
    int z=m;
    for(int i=k;i<=n-z;i++){
        tong+=a[i];
        m-=1;
        Try(i+1,m,tong);
        m+=1;
        tong-=a[i];
    }

}

int main()
{
    cin >> n>>p;
    for (int i = 0; i < n; i++)
    {
       cin >> a[i];

    }
    for (int i = 1; i <= n; i++)
    {
        Try(0,i,0) ;       
    }
    cout << res;
    return 0;
} // namespace std

