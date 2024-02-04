#include<bits/stdc++.h>
using namespace std;
int n,k,a[100],s,b[100],check;

void Try(int sum,int dem,int dau){
    if(dem==k-1){
        check=1;
        return;
    }
    for(int i=dau;i<n;i++){
        if(b[i]==0){
            
            if(sum+a[i]<=s){
                sum+=a[i];
                b[i]=1;
                if(sum==s){
                    Try(0,dem+1,0);
                }else{
                   Try(sum,dem,dau+1); 
                }
                b[i]=0;
                sum-=a[i];
            }
            

        }
    }


    return;
}
int main(){
    cin >> n>>k;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s+=a[i];
        b[i]=0;
    }
    if(s%k!=0){
        cout << 0;
        return 0;
    }
    s/=k;
    Try(0,0,0);
    cout<< check;
    return 0;

}