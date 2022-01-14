#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n; cin>>n;
        int sq, sqq, c;
        sq = sqrt(n); c = cbrt(n); sqq = sqrt(c);
        cout<<(sq+c-sqq)<<endl;
    }
    return 0;
}