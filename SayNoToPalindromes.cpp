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
    int n,tc; cin>>n>>tc;
    string s; cin>>s; int f[6][n+1];
    string c[6]={"abc","acb","cba","cab","bac","bca"};
    for(int j = 0; j<6; j++){
        int cnt = 0;f[j][0]=0;
        for(int i = 0; i<n; i++){
            if(s[i]!=c[j][i%3]){
                cnt++;
            }
            f[j][i+1]=cnt;
        }
    }
    while(tc-->0){
        int l,r;cin>>l>>r;
        int cost = INT_MAX;
        for(int i = 0; i<6; i++){
            cost = min(cost,f[i][r]-f[i][l-1]);
        }
        cout<<cost<<endl;
    }
    return 0;
}