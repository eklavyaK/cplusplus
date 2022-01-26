#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,index; cin>>n>>k; vector<int> v;
        for(int i = 0; i<n; i++) {cin>>index; if(index%2) v.emplace_back(i);}
        if(v.size()<k || (v.size()-k)%2) cout<<"no"<<endl;
        else {cout<<"yes\n";for(int i = 0; i<k-1; i++) cout<<v[i]+1<<" ";cout<<n<<endl;}
    }
    return 0;
}