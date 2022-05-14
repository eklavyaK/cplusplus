#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int n,q; cin>>n>>q;
    map<int,int> x,y;
    for(int i = 1; i<=n; i++){
        x[i];y[i];
    }                                                       
    vector<int> cx(n,0),cy(n,0);
    while(q--){
        int r; cin>>r;                                                 
        if(r==1){
            int u,v;cin>>u>>v;
            if(x.count(u)){
                x.erase(u);
            }
            if(y.count(v)){
                y.erase(v);
            }
            cx[u-1]++;cy[v-1]++;
        }
        else if(r==2){
            int u,v;cin>>u>>v;
            cx[u-1]--;cy[v-1]--;
            if(cx[u-1]==0){
                x[u];
            }
            if(cy[v-1]==0){
                y[v];
            }
        }
        else{
            int s,t,u,v;
            cin>>s>>t>>u>>v;
            auto it1 = x.lower_bound(s);
            auto it2 = y.lower_bound(t);
            if(it1==x.end() || it2==y.end()){
                cout<<"Yes"<<endl;
            }
            else if(it1->first<=u && it2->first<=v){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}