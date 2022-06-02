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
const int M = 1e6+5;
int dp[M];
bool check[M];
int main(){
    rapid_iostream;

    int n; cin>>n;
    queue<array<int,2>> q;
    q.push({n,0});
    while(!q.empty()){
        auto [x,c] = q.front();
        string s = to_string(x);
        for(int i=0;i<s.size();i++){
            int z = s[i]-'0';
            if(z!=0 && x-z>=0 && !check[x-z]){
                if(x-z==0){
                    print(c+1);
                    exit(0);
                }
                else{
                    q.push({x-z,c+1});
                    check[x-z]=true;
                }
            }
        }
        q.pop();
    }

    return 0;
}