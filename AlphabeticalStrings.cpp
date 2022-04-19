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
        int c = 0;
        string s; cin>>s;
        int n = s.length();
        map<char,int> m;int k = 0;
        for(int i = 0; i<n; i++){
            if(m.count(s[i])){
                N();goto end;
            }
            m[s[i]]=i;
            if(s[i]=='a'){
                k=i;
            }
        }
        for(auto i : m){
            if(i.first!=(char)('a'+c)||abs(k-i.second)>c){
                N();goto end;
            }
            c++;
        }
        for(int i = 1; i<n; i++){
            if((i>k && s[i]<s[i-1])||(i<k && s[i]>s[i-1])){
                N();goto end;
            }
        } Y();
        end:;
    }
    return 0;
}