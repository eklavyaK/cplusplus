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
        int n,qr; cin>>n>>qr; int a[n+1];
        for(int i=1;i<=n;i++)cin>>a[i];
        a[0]=0;sort(a,a+n+1);
        ll sum[n+1]; sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        queue<pair<int,int>> q;
        map<ll,bool> m;
        q.push(make_pair(0,n));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            m[sum[y]-sum[x]]=true;
            int mid = (a[x+1]+a[y])/2;
            int k = upper_bound(a+x+1,a+y+1,mid)-a;
            if(k==y+1||y-x==1)continue;
            q.push(make_pair(x,k-1));
            q.push(make_pair(k-1,y));
        }
        while(qr--){
            int z; cin>>z;
            if(m.count(z)){
                cout<<"Yes"<<endl;
            }
            else cout<<"No"<<endl;
        }
    }
    return 0;
}