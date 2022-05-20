#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        unordered_map<int,map<int,int>> v;
        int n,m; cin>>n>>m;
        vector<int> c(n+1);
        for(int i=0;i<m;i++){
            int k; cin>>k;
            for(int j=0;j<k;j++){
                int t; cin>>t;
                v[i][t]=1; c[t]++;
            }
        }
        ll x = ceil((ld)m/2), y=0;
        for(int i=0;i<=n;i++){
            if(c[i]>x){
                y=i;
            }
        }
        vector<int> res(m);
        if(y!=0){
            int cnt = 0;
            for(int i=0;i<m;i++){
                if(v[i].size()==1 && v[i].count(y)){
                    res[i]=y;cnt++;
                }
            }
            if(cnt>x){
                N();goto end;
            }
            else{
                for(int i=0;i<m;i++){
                    if(res[i]==0){
                        if(v[i].count(y) && cnt<x){
                            res[i]=y;cnt++;
                            
                        }
                        else{
                            for(auto j : v[i]){
                                if(j.first!=y){
                                    res[i]=j.first;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int i=0;i<m;i++){
                res[i]=v[i].begin()->first;
            }
        }
        Y();
        for(auto i : res)cout<<i<<' ';cout<<endl;
        end:;
    }
    return 0;
}