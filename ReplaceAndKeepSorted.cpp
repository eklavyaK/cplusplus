#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    int n,q,k; cin>>n>>q>>k; int a[n];long long res[n];
    for(int i = 0; i<n; i++) cin>>a[i];
    if(n==1) res[0] = k-1;
    else {res[0] = res[1]-2; res[n-1] = k-res[n-2]-1;}
    long long sum = 0l; sum = res[0];
    for(int i = 1; i<n-1; i++) {sum += (a[i+1] - a[i-1]-2); res[i] = sum;}
    while(q-->0)
    {
        long long count = 0l;
        int l, r; cin>>l>>r;l--;r--;
        if(r-1>=l+1 && l+1>0 && r-1<n-1) count+=(res[r-1]-res[l]);
        if(l==r) count += (k-1);
        else if(r-l==1) count += (k+a[r]-a[l]-3);
        else count += (k + a[l+1] - a[r-1] - 3);
        cout<<count<<endl;
    }
    return 0;
}