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
        string n; int s; cin>>n>>s;
        int k = n.length();
        int c=0;
        for(int i = 0; i<k; i++){
            c+=(n[i]-'0');
            if(c>s){
                cout<<pow(10,k-i)-stold(n.substr(i))<<endl;
                goto end;
            }
            else if(c==s){
                int r=i; i++;
                while(i<k && n[i]=='0')i++;
                if(i==k){
                    cout<<0<<endl;
                    goto end;
                }
                else{
                    cout<<pow(10,k-r)-stold(n.substr(r,k-r))<<endl;
                    goto end;
                }
            }
        }
        cout<<0<<endl;
        end:;
    }
    return 0;
}