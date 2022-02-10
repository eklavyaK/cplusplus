#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;
int mod = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[n]; 
        for(int i = 0; i<n; i++) cin>>a[i]; 
        if(n==1) {cout<<0<<endl; continue;} cout<<n-1<<endl;
        int m = 1000000000+n;int t = *min_element(a,a+n); while(gcd(m-(n-2),t) !=1) m++;
        int k = min(a[n-1],a[n-2]);cout<<n-1<<" "<<n<<" "<<k<<" "<<m--<<endl;
        for(int i = n-2; i>=1; i--) 
        {
            k = min(k,a[i-1]);
            cout<<i<<" "<<i+1<<" "<<k<<" "<<m--<<endl;
        }
    }
    return 0;
}