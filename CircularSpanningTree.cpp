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
        int n; cin>>n;
        string s; cin>>s;
        int c0=0, c1=0;
        vector<int> c(n);
        vector<int> v0,v1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                c0++;
                v0.push_back(i+1);
            }
            else{
                c1++;
                v1.push_back(i+1);
            }
        }
        if(c1==0 || c1%2){
            N();continue;
        }
        Y(); 
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                cout<<i<<' '<<i+1<<endl;
                c[i]++;c[i-1]++; 
            }
        }
        if(s[0]=='0'){
            c[0]++;c[n-1]++;
            cout<<1<<' '<<n<<endl;
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s[i]=='1'&&c[i]%2==0){
                v.push_back(i);
            }
            else if(s[i]=='0'&&c[i]%2){
                v.push_back(i);
            }
        }
        int k = -1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'&&c[i]%2==0){
                k = i;
            }
            else if(s[i]=='0'&&c[i]%2){
                k = i;
            }
            if(k!=-1){
                for(auto j : v){
                    if(j!=k){
                        cout<<k+1<<' '<<j+1<<endl;
                    }
                }
                break;
            }
        }
        end:; 
    }
    return 0;
}