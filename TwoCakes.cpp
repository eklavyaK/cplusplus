#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k; cin>>n; int a[n+1]={0},b[n+1]={0};
    for(int i = 0; i<2*n; i++) {cin>>k; if(a[k]==0) a[k]=i+1; else b[k]=i;}
    long long sum = 0l;sum+=(a[1]-1);for(int i = 2; i<n+1; i++) sum+=abs(a[i]-a[i-1]);
    for(int i = 1; i<n+1; i++) sum+=abs(b[i]-b[i-1]);cout<<sum<<endl;
    return 0;
}