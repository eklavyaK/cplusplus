#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        sort(a,a+n);int count = 0, track = 0;
        for(int i = 0; i<n; i++) 
            if(a[i]<=i+1-track) {count++;track=i+1;}
        cout<<count<<endl;
    }
    return 0;
}