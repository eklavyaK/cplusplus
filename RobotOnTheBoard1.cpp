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
        int n,m;cin>>n>>m;
        string s; cin>>s;
        int k = s.size();
        int l=0,r=0,u=0,d=0;
        int L=0,R=0,U=0,D=0;
        for(int i = 0; i<k; i++){
            if(s[i]=='U'){
                u++;U=max(U,u);
            }
            else if(s[i]=='D'){
                u--;D=min(D,u);
            }
            else if(s[i]=='R'){
                r++;R=max(R,r);
            }
            else{
                r--;L=min(L,r);
            }
            if(U-D==n){
                if(s[i]=='U'){
                    cout<<U<<' '<<m-R<<endl;
                }
                else cout<<U+1<<' '<<m-R<<endl;
                goto end;
            }
            else if(R-L==m){
                if(s[i]=='R'){
                    cout<<U+1<<' '<<m-R+1<<endl;
                }
                else cout<<U+1<<' '<<m-R<<endl;
                goto end;
            }
        }
        cout<<U+1<<' '<<m-R<<endl;
        end:;
    }
    return 0;
}