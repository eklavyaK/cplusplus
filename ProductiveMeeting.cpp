#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int sum=0;vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){cin>>v[i].first;sum+=v[i].first;v[i].second=i+1;}
        sort(v.begin(),v.end());if(sum%2){v[n-1].first--;sum--;}
        if(sum<2*v[n-1].first){v[n-1].first=(sum-v[n-1].first);sum=v[n-1].first*2;}
        int k = sum/2;cout<<k<<endl;
        vector<pair<int,int>> result(k);
        int count = 0,track=0;
        for(int i = 0; i<n; i++){
            while(v[i].first && count<k){
                result[count++].first=v[i].second;
                v[i].first--;
            }
            for(int j = 0; j<v[i].first && count==k; j++){
                result[track++].second=v[i].second;
            }
        }
        for(auto i : result)cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}