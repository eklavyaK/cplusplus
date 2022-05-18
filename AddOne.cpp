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
ll dp[200001];
int main(){
    rapid_iostream;
    for(int i = 0; i<=8; i++){
        dp[i]=2;
    }
    dp[9]=3;
    for(int i = 10; i<200001; i++){
        dp[i]=(dp[i-9]+dp[i-10])%mod1;
    }
    int tc;cin>>tc;
    while(tc-->0){
        ll result = 0;
        string s; cin>>s;
        int m; cin>>m;
        for(int i = 0; i<s.size(); i++){
            int k = s[i]-'0';
            if(10-k<=m){
                int x = m+k-10;
                result=(result+dp[x])%mod1;
            }
            else result++;
        }
        cout<<result%mod1<<endl;
    }
    return 0;
}