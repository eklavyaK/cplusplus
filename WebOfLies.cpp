#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n,m,u,v; cin>>n>>m;int cnt=n;
    int x[n+1]={0};
    for(int i = 0; i<m; i++){
        cin>>u>>v;
        int k = min(u,v);
        if(!x[k])cnt--;
        x[k]++;
    }
    int q;cin>>q;
    while(q--){
        int k; cin>>k;
        if(k==3){cout<<cnt<<endl;}
        else{
            int l,r;cin>>l>>r;
            if(k==1){
                int g = min(l,r);
                if(!x[g])cnt--;
                x[g]++;
            }
            if(k==2){
                int g = min(l,r);
                if(x[g]==1)cnt++;
                x[g]--;
            }
        }
    }
    return 0;
}