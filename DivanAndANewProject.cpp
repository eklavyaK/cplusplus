#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; vector<pair<int,int>> v(n);long long result = 0;
        for(int i = 0; i<n; i++){cin>>v[i].first;v[i].second=i;} vector<int> res(n);
        sort(v.begin(),v.end());long long track = 1,count=1; for(int i = n-1; i>=0; i--){
            if(count++%2){res[v[i].second]=-track;result+=track*v[i].first;}
            else {result+=track*v[i].first;res[v[i].second]=track++;}
        }
        cout<<2*result<<endl<<0<<" ";for(auto i : res) cout<<i<<" ";cout<<endl;
    }
    return 0;
}