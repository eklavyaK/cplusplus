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
        int a[10]={0};
        string s; cin>>s; int n=s.size();
        for(int i = 0; i<n; i++){
            a[s[i]-'0']++;
        }
        int c = *max_element(a,a+10);
        for(int i = 0; i<9; i++){
            for(int j = i+1; j<10; j++){
                bool k = true; int cnt = 0;
                for(int r = 0; r<n; r++){
                    if(s[r]-'0'==i && (k||!cnt)){
                        cnt++;k=false;
                    }
                    else if(s[r]-'0'==j && (!k||!cnt)){
                        cnt++;k=true;
                    }
                }
                c = max(c,cnt-cnt%2);
            }
        }
        cout<<n-c<<endl;
    }
    return 0;
}