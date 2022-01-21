#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,index=0; cin>>n; int a[n]; bool r=true;
        for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = n-2; i>=1; i--) {if(r){if(a[i]<a[i+1]) {i++; r=false;}} else if(a[i]<a[i-1]) {index = i; break;}}
        cout<<index<<endl;   
    }
    return 0;
}