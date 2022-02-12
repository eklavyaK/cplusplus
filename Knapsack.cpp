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
        int n,count=0; bool detect = true;long long w,sum=0l; cin>>n>>w; vector<int> v;vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++) {cin>>a[i].first;a[i].second=i+1;}sort(a.begin(),a.end());
        for(int i = n-1; i>=1; i--) 
        {
            if(sum+a[i].first<=w){if(sum+a[i].first>=w/2+w%2){v.emplace_back(a[i].second);count++;detect = false;break;}
            if(sum+a[i].first+a[0].first<=w) {sum+=a[i].first;v.emplace_back(a[i].second);count++;if(sum+a[0].first>=w/2+w%2) {v.emplace_back(a[0].second);detect = false;count++;break;}}}
        }
        if(detect && !(sum+a[0].first<=w && sum+a[0].first>=w/2+w%2)) cout<<-1<<endl;
        else if(detect && sum+a[0].first<=w && sum+a[0].first>=w/2+w%2){v.emplace_back(a[0].second);cout<<++count<<endl; for(int i = 0; i<count; i++) cout<<v[i]<<" ";cout<<endl;}
        else {cout<<count<<endl; for(int i = 0; i<count; i++) cout<<v[i]<<" ";cout<<endl;}
    }
    return 0;
}