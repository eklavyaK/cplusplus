#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int x; cin>>x;
        double n = -0.5 + 0.5*sqrt(1+8*x);
        if(n==(int)n) {cout<<n<<endl;continue;} n = ceil(n);
        if(x==n*(n+1)/2-1) cout<<n+1<<endl;
        else cout<<n<<endl;
    }
    return 0;
}