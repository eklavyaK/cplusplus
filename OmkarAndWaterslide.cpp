#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n; int a[n]; long long count = 0l;
        for(int i = 0; i<n; i++) cin>>a[i]; int max = a[n-1];
        for(int i = n-2; i>=0;i--) {if(a[i]>max) {count+=(a[i]-max); max=a[i];} else if(a[i]<max) max = a[i];}
        cout<<count<<endl;   
    }
    return 0;
}