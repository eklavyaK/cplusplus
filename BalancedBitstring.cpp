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
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int c1=0, c0=0, c=0;
        for(int i = 0; i<k; i++){
            if(s[i]=='1'){
                c1++;int in = i+k;
                while(in<n){
                    if(s[in]=='0'){
                        N();goto end;
                    }
                    else in+=k;
                }
            }
            else if(s[i]=='0'){
                c0++; int in = i+k;
                while(in<n){
                    if(s[in]=='1'){
                        N();goto end;
                    }
                    else in+=k;
                }
            }
            else{
                c++;
                int in = i+k;
                bool a = false;
                bool b = false;
                while(in<n){
                    if(s[in]=='0'){
                        if(!a){
                            c--;
                            c0++;
                        }
                        a = true;
                    }
                    else if(s[in]=='1'){
                        if(!b){
                            c--;
                            c1++;
                        }
                        b = true;
                    }
                    in+=k;
                    if(a&&b){
                        N();goto end;
                    }
                }
            }
        }
        if(c0>k/2 || c1>k/2){
            N(); goto end;
        }
        Y();
        end:;
    }
    return 0;
}