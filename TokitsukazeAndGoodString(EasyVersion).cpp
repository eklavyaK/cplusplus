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
        int n; cin>>n; 
        string s; cin>>s;
        vector<int> v;
        for(int i = 0; i<n; i++){
            int k = 1;
            while(i+1<n && s[i+1]==s[i]){
                i++;k++;
            }
            v.push_back(k%2?0:1);
        }
        n = v.size(); int cnt = 0;
        int k = -1;
        for(int i = 0; i<n; i++){
            if(v[i]==0){
                if(k==-1){
                    k=i;
                }
                else{
                    cnt+=(i-k);
                    k=-1;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}