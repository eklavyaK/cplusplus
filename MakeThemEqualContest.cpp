#include<bits/stdc++.h>
using namespace std;
int f[2001];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    memset(f,0x3f,sizeof f);
    f[1]=0;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
        f[i+i/j]=min(f[i+i/j],f[i]+1);
        }
    }
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k; cin>>n>>k; int b[n],c[n];
        for(int i = 0; i<n; i++) {cin>>b[i];b[i]=f[b[i]];}
        for(int i = 0; i<n; i++) cin>>c[i];
        k=min(k,n*12); int result[k+1]={0};for(int i = 0; i<n; i++) 
        for(int j=k;j>=b[i];j--){result[j]=max(result[j],result[j-b[i]]+c[i]);}
        cout<<result[k]<<endl;
    }
    return 0;
}