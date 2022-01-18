#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n>>k; int mod = n;
        for(int i = 0; i<k-1; i++) mod = ((long long)mod*n)%1000000007;
        cout<<mod<<endl;
    }
    return 0;
}