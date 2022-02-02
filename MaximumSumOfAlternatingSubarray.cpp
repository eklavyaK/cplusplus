#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k,l=0,count=0; cin>>n; long long sum=0l; vector<pair<int,long long>> v;
        for(int i = 0; i<n; i++) 
        {
            cin>>k; 
            if(l && ((l<0 && k<0) || (l>0 && k>0))) {v.emplace_back(make_pair(count,sum));sum=k;l=k;count=1;}
            else {sum+=k;l=k;count++;}
        }
        v.emplace_back(make_pair(count,sum));
        for(auto i : v) cout<<i.first<<" "<<i.second<<endl;
        l = v[0].first; sum = v[0].second;
        for(int i = 1; i<v.size(); i++) {if(v[i].first>l){l=v[i].first;sum=v[i].second;}else if(v[i].first==l && v[i].second>sum)sum=v[i].second;}
        cout<<sum<<endl;
    }
    return 0;
}