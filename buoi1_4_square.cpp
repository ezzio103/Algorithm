#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int n, m;
int a[MAX][MAX];
int avg_max = 0;

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for (int j = 0; j < m; j++)
        {   cin >>a[i][j];
            /* code */
        }
        
       
    }
}
void solve(){
  
    bool check=true;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j<m-i; j++)
    {     int max1=0;
          for(int k=0;k<n;k++){
         
        for(int l=j;l<j+i+1;l++){
            if(a[k][l]==0)
                check=false;
            }
            if(!check){
                
                max1=0;
                check=true;
            }else{
                max1=max1+i+1;
                avg_max=max(max1,avg_max);
            }
            
        
    }
        /* code */
    }
    
    
    /* code */
  }
  
}

// void solve(){
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int max1 = 0;
//             bool check = true;
//             for (int k = 0; k < m - j; k++) {
//                 for (int l = j; l < j + i + 1; l++) {
//                     if (a[k][l] == 0) {
//                         check = false;
//                         break;
//                     }
//                 }
//                 if (!check) {
                    
//                     max1 = 0;
//                     check = true;
//                 } else {
//                     max1 += i + 1;avg_max = max(max1, avg_max);
//                 }
//             }
//         }
//     }
// }


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    cout << avg_max;
    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// const int MAX = 10000;
// int n, k;
// int a[MAX];
// double avg_max = 0.0;

// void input(){
//     cin >> n >> k;
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
// }

// double avg(int i, int j){
//     int sum = 0;
//     for(int k=i; k<=j; k++){
//         sum += a[k];
//     }

//     return (double) sum / (j-i+1);
// }

// void solve(){
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             double tmp = avg(i,j);

//             if((tmp > avg_max) && (j-i+1 >= k)) avg_max = tmp;
//         }
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     input();
//     solve();
//     printf("%.5lf", avg_max);
//     return 0;
// }