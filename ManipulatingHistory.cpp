#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pii pair<int,int>
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        string s;
        int n; cin>>n;
        int cnt[26]{};
        for(int i=0;i<2*n;i++){
            cin>>s;
            for(int j=0;j<s.size();j++){
                cnt[s[j]-'a']++;
            }
        }
        cin>>s;
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]&1){
                cout<<(char)('a'+i)<<endl;
                break;
            }
        }
    }
    return 0;
}