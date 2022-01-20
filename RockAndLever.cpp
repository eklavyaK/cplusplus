#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n; string s; int a[32]={0}; long long count = 0l;
        for(int i = 0; i<n; i++) {cin>>k; int j = 0; while(k>=pow(2,j)) j++; a[j]++;}
        for(int i = 0; i<32; i++) count += (long long)a[i]*(a[i]-1)/2;
        cout<<count<<endl;
    }
    return 0;
}