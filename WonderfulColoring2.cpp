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
        int n,k,l,r; cin>>n>>k; 
        int cnt[n+1]={0},res[n]={0};
        vector<pair<int,int>> a;int track = 0;
        for(int i = 0; i<n; i++){cin>>l;if(cnt[l]==k)continue;cnt[l]++;a.emplace_back(make_pair(l,i));track++;}
        sort(a.begin(),a.end());n=track;track=0;
        while(true){
            if(n>=k){
                for(int i = 1; i<=k; i++){
                    res[a[track++].second]=i;
                }
                n-=k;
            }
            else{
                break;
            }
        }
        for(auto i : res) cout<<i<<" ";cout<<endl;
    }
    return 0;
}