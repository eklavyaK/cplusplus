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
        int n; cin>>n; int u[n],s[n];
        long long sum=0l,track = 0;
        map<int,vector<int>> map;
        for(int i = 0; i<n; i++)cin>>u[i];
        for(int i = 0; i<n; i++){
            cin>>s[i];sum+=s[i];
            map[u[i]].push_back(s[i]);
        }
        vector<long long> result(n,0);
        for(auto i : map){
            sort(i.second.begin(),i.second.end(),greater<int>());
            int t=i.second.size();
            vector<long long> v(t);v[0]=i.second[0];
            for(int j = 1; j<t; j++){
                v[j]=v[j-1]+i.second[j];
            }
            for(int i = 1; i<=t; i++){
                int k = t%i;
                result[i-1]+=v[t-k-1];
            }
        }
        for(int j = 0; j<n; j++){
            cout<<result[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}