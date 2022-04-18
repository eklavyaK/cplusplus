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
        int n, k; cin>>n>>k;
        string s; cin>>s;
        vector<int> v(n,0),res(n);int c = k;
        for(int i = 0; i<n && c>0; i++){
            if(s[i]=='1' && (k&1)){
                v[i]++;c--;
            }
            else if(s[i]=='0' && !(k&1)){
                v[i]++;c--;
            }
        }
        if(c>0){
            v[n-1]+=c;
        }
        for(int i = 0; i<n; i++){
            if((k-v[i])&1){
                cout<<(s[i]=='1'?'0':'1');
            }
            else{
                cout<<s[i];  
            }
        }
        cout<<endl;
        for(auto i : v){
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return 0;
}