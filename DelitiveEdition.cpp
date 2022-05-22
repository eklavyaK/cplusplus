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
        string s, ans;
        cin>>s>>ans;
        int n = ans.size();
        map<char,int> m;
        for(int i=0;i<n;i++){
            m[ans[i]]++;
        }
        n=s.size();
        string temp = "";
        for(int i=n-1;i>=0;i--){
            if(m[s[i]]){
                temp=s[i]+temp;
                m[s[i]]--;
            }
        }
        temp==ans?Y():N();
    }
    return 0;
}