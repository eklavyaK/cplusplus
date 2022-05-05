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
        if(s[0]-'a'>=k){
            char c = s[0]-k;
            for(int i = 0; i<n; i++){
                if(s[i]>s[0]){
                    cout<<s[i];
                }
                else cout<<min(c,s[i]);
            }
        }
        else{
            char c = 'a';
            for(int i = 0; i<n; i++){
                c=max(c,s[i]);
            }
            if(k>=c-'a'){
                cout<<string(n,'a');
            }
            else{
                c='a';
                int loc = 0;
                for(int i = 0; i<n; i++){
                    if(s[i]-'a'>k){
                        loc = i;break;
                    }
                    else c=max(s[i],c);
                }
                k-=(c-'a');
                for(int i = 0; i<n; i++){
                    if(s[i]<=c){
                        s[i]='a';
                    }
                }
                c = s[loc];
                s[loc]=s[loc]-k;
                for(int i = loc+1; i<n; i++){
                    if(s[i]<=c && s[i]!='a'){
                        s[i]=min(s[i],s[loc]);
                    }
                }
                cout<<s;
            }
        }
        cout<<endl;
    }
    return 0;
}