#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
void swapp(int&a,int&b){int t=a;a=b;b=t;}
#define println(n) cout<<n<<'\n'
#define Y() cout<<"YES"<<endl
#define N() cout<<"NO"<<endl
#define MAIN void codeforce();
#define print(n) cout<<n<<' '
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/

int rem[1000];
void codeforce(){
    int n,k; cin>>n>>k;
    int a[n];
    ll cost = 0;
    fill(rem,rem+k+5,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        cost+=(a[i]/k);
        rem[a[i]%k]++;
    }
    for(int i=k;i<2*k-1;i++){
        for(int j=i-k+1;j<k;j++){
            if(i-j>=k) continue;
            if(i-j==j){
                cost+=rem[j]/2;
                rem[j]=rem[j]%2;
                continue;
            }
            int c = rem[j],b = rem[i-j];
            cost+=min(c,b);
            rem[j]=max(0,c-b);
            rem[i-j]=max(0,b-c);
        }
    }
    cout<<cost<<endl;
}