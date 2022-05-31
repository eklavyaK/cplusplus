#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    rapid_iostream;
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int c = -1, d = n;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                d = i;
                break;
            }
        }
        if(c==-1){
            cout<<0<<endl;
            continue;
        }
        else if(c==d){
            if(k>=n-1-c){s[c]='0'; s[n-1]='1';}
            else if(k>=c){s[c]='0';s[0]='1';}
        }
        else{
            if(k>=n-1-d + c){
                s[c]='0';s[0]='1';
                s[d]='0';s[n-1]='1';
            }
            else if(k>=n-1-d){
                s[d]='0';s[n-1]='1';
            }
            else if(k>=c){
                s[c]='0';s[0]='1';
            }
        }
        ll sum = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                sum++;
            }
            else if(s[i]=='1' && s[i+1]=='0'){
                sum+=10;
            }
            else if(s[i]=='1' && s[i+1]=='1'){
                sum+=11;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}