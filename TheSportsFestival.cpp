#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int f[n][n];
    memset(f,0,sizeof(f));
    for(int i=0;i<n-1;i++){
        f[i][i+1] = arr[i+1]-arr[i];
    }
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            f[j][j+i] = min(f[j+1][j+i],f[j][j+i-1])+arr[j+i]-arr[j];
        }
    }
    cout<<f[0][n-1]<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}