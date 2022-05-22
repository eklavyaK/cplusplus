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
        string s; cin>>s;
        int n = s.length();
        vector<pair<int,int>> v(n);
        int x = 0, y = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                x++;
            }
            else if(s[i]=='L'){
                x--;
            }
            else if(s[i]=='U'){
                y++;
            }
            else y--;
            v[i].first=x;
            v[i].second=y;
        }
        for(int i=0;i<n;i++){
            x = v[i].first;
            y = v[i].second;
            int tx = 0, ty = 0; 
            for(int j=0;j<n;j++){
                if(s[j]=='R'){
                    tx++;
                    if(tx==x && ty==y)tx--;
                }
                else if(s[j]=='L'){
                    tx--;
                    if(tx==x && ty==y)tx++;
                }
                else if(s[j]=='U'){
                    ty++;
                    if(tx==x && ty==y)ty--;
                }
                else{
                    ty--;
                    if(tx==x && ty==y)ty++;
                }
            }
            if(tx==0 && ty==0){
                cout<<x<<' '<<y<<endl;
                goto end;
            }
        }
        cout<<0<<' '<<0<<endl;
        end:;
    }
    return 0;
}