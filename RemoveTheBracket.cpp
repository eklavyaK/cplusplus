#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,s; 
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> x(n),y(n);
    for(int i=1;i<n-1;i++){
        if(s==arr[i]/2)x[i] = arr[i]/2,y[i] = arr[i]-x[i];
        else if(s>arr[i]/2)y[i] = min(arr[i],s),x[i] = arr[i] - y[i];
        else x[i] = s,y[i] = arr[i]-s;
    }
    int f[n-1][2];
    memset(f,0,sizeof(f));
    x[0] = y[0] = arr[0];
    y[n-1] = x[n-1] = arr[n-1];
    f[0][0] = x[0]*y[1];
    f[0][1] = x[1]*y[0];
    for(int i=1;i<n-1;i++){
        f[i][0] = min(f[i-1][0]+x[i]*y[i+1],f[i-1][1]+y[i]*y[i+1]);
        f[i][1] = min(f[i-1][0]+x[i]*x[i+1],f[i-1][1]+y[i]*x[i+1]);
    }
    cout<<min(f[n-2][0],f[n-2][1])<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}