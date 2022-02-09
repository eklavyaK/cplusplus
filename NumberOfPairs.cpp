#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,l,r; long long count=0; cin>>n>>l>>r; int a[n], sum = 0;
        for(int i = 0; i<n; i++) cin>>a[i];sort(a,a+n); n = upper_bound(a,a+n,r)-a;
        for(int i = 0; i<n; i++) 
        {
            int x = max(i+1,(int)(lower_bound(a,a+n,l-a[i])-a)), y = max(i+1,(int)(upper_bound(a,a+n,r-a[i])-a));
            if(x<y) count+=(y-x);
        }
        cout<<count<<endl;
    }
    return 0;
}