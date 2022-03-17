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
    while(tc-->0){
        int n,m,x; cin>>n>>m>>x;vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){cin>>v[i].first;v[i].second=i;}
        sort(v.begin(),v.end());long long t[m]={0},res[n];int cnt=0;
        for(int i = n-1; i>=0; i--){
            if((cnt/m)%2==0){
                t[cnt%m]+=v[i].first;res[v[i].second]=(cnt++)%m+1;
            }
            else{
                t[m-1-(cnt%m)]+=v[i].first;res[v[i].second]=(cnt++)%m+1;
            }
        }
        if(((*max_element(t,t+m))-(*min_element(t,t+m)))>x){cout<<"NO"<<endl;}
        else {cout<<"YES"<<endl;for(auto i : res) cout<<i<<" ";cout<<endl;}
    }
    return 0;
}