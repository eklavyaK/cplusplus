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
        string s; cin>>s; 
        int x; cin>>x;
        int n = s.length();
        vector<char> w(n);
        for(int i = 0; i<n; i++){
            if(s[i]=='0'){
                if(i-x>=0){
                    w[i-x]='0';
                }
                if(i+x<n){
                    w[i+x]='0';
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(s[i]=='1'){
                if(i-x>=0 && i+x<n){
                    if(w[i-x]=='0' && w[i+x]=='0'){
                        cout<<-1<<endl;goto end;
                    }
                    else if(w[i-x]=='0'){
                        w[i+x]='1';
                    }
                    else if(w[i+x]=='0'){
                        w[i-x]='1';
                    }
                    else{
                        w[i-x]='1';
                        w[i+x]='1';
                    }
                }
                else if(i-x>=0 && i+x>=n){
                    if(w[i-x]=='0'){
                        cout<<-1<<endl;goto end;
                    }
                    else w[i-x]='1';
                }
                else if(i+x<n && i-x<0){
                    if(w[i+x]=='0'){
                        cout<<-1<<endl; goto end;
                    }
                    else w[i+x]='1';
                }
                else{
                    cout<<-1<<endl; goto end;
                }
            }
        }
        for(auto i : w){
            if(i=='1'||i=='0')cout<<i;
            else cout<<1;
        }
        cout<<endl;
        end:;
    }
    return 0;
}