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
        int n,m; cin>>n>>m;
        int a[n],b[n],c[m];
        map<int,map<int,int>> v;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<m;i++){
            cin>>c[i];
            v[c[i]][i]=1;
        }
        int x = 0;
        for(int i=0;i<n;i++){
            if(b[i]==c[m-1]){
                x=i+1;
            }
        }
        if(x==0){
            N();continue;
        }
        vector<int> res(m);
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(!v[b[i]].size()){
                    N();goto end;
                }
                else{
                    int k = v[b[i]].begin()->first;
                    v[b[i]].erase(k);
                    res[k]=i+1;
                }
            }
        }
        Y();
        x=(res[m-1]==0?x:res[m-1]);
        for(auto i : res){
            if(i==0){
                cout<<x<<' ';
            }
            else cout<<i<<' ';
        }
        cout<<endl;
        end:;
    }
    return 0;
}