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
    int tc;cin>>tc;
    while(tc-->0){
        int n,m; cin>>n>>m;
        string s[n];
        for(int i = 0; i<n; i++){
            cin>>s[i];
        }
        int c = INT_MAX;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                int temp = 0;
                for(int k = 0; k<m; k++){
                    temp+=abs(s[i][k]-s[j][k]);
                }
                c=min(temp,c);
            }
        }
        cout<<c<<endl;
    }
    return 0;
}