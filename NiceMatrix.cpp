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
        int n,m; cin>>n>>m; long long a[n][m]; long long count = 0l;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin>>a[i][j];
        for(int i = 0; i<n/2; i++) for(int j = 0; j<m/2; j++) 
        {
            vector<long long> v;
            v.emplace_back(a[i][j]);
            v.emplace_back(a[n-1-i][m-1-j]);
            v.emplace_back(a[i][m-1-j]);
            v.emplace_back(a[n-1-i][j]);
            sort(v.begin(),v.end()); count+=(v[3]-v[0]+v[2]-v[1]);
        }
        if(n%2)for(int i = 0; i<m/2; i++) count+=abs(a[n/2][i]-a[n/2][m-1-i]);
        if(m%2)for(int i = 0; i<n/2; i++) count+=abs(a[i][m/2]-a[n-1-i][m/2]);
        cout<<count<<endl;
    }
    return 0;
}