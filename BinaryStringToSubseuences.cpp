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
        int n, c=1; cin>>n;
        string s; cin>>s;
        vector<char> m(n);
        vector<int> in(n);
        for(int i = 0; i<n; i++){
            int temp = 1;in[i]=1;m[0]=s[i];
            while(i+1<n && s[i+1]==s[i]){
                temp++;
                while(m[temp-1]==s[i])temp++;
                m[temp-1]=s[i];in[i+1]=temp;i++;
            }
            c=max(temp,c);
        }
        cout<<c<<endl;
        for(auto i : in) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}