#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_io ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_io;
    int tc;cin>>tc;
    while(tc-->0){
        int n; cin>>n; int a[n];
        map<int,vector<int>> x;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            x[a[i]].push_back(i);
        }
        int track = 0;
        vector<int> v,res(n);
        for(int i = 1; i<=n; i++){
            if(!x.count(i)){
                v.push_back(i);
            }
        }
        for(auto i : x){
            res[i.second[0]]=i.first;
        }
        for(int i = 0; i<n; i++){
            if(res[i]==0){
                res[i]=v[track++];
            }
        }
        int t = true;
        while(t){
            t=false;
            for(int i = 0; i<n; i++){
                if(res[i]==i+1){
                    int k = x[a[i]].size();
                    int z = res[x[a[i]][k-1]];
                    for(int j=k-1;j>=1;j--){
                        res[x[a[i]][j]]=res[x[a[i]][j-1]];
                    }
                    res[x[a[i]][0]]=z;
                    t=true;
                }
            }
        }
        cout<<x.size()<<endl;
        for(auto i : res){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}