#include<bits/stdc++.h>
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
        int n;string s; cin>>n>>s;
        int track = -1,cnt = 0;
        char c = s[0];
        for(int i = 1; i<n; i++){
            if(c==s[i]){
                track = i;cnt++;
                if(i+1<n){
                    c=s[i+1];i++;
                }
                else break;
            }
            else if(c=='('){
                track=i;cnt++;
                if(i+1<n){
                    c=s[i+1];i++;
                }
                else break;
            }
        }
        cout<<cnt<<" "<<n-1-track<<endl;
    }
    return 0;
}