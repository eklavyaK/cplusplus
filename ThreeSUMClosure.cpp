#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
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
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/
map<ll,int> m;
bool ans = true;
vector<ll> c(3);
vector<int> arr;
void Combination(int start, int end, int index, int r){
   if(index==r){
        ll k = c[0]+c[1]+c[2];
        if(!m.count(k)){
            ans=false;
        }
        return;
   }
   for(int i=start; i<=end&&end-i+1>=r-index; i++){
      c[index]=arr[i];
      Combination(i+1,end,index+1,r);
   }
}

void codeforce(){
    ans = true;
    arr.clear();
    m.clear();
    fill(c.begin(),c.end(),0);
    int n;cin>>n; int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int neg=0,pos=0,zero;
    for(int i=0;i<n;i++){
        if(a[i]<0)neg++;
        else if(a[i]>0)pos++;
    }
    if(pos>2 || neg>2){
        N(); return;
    }
    else{
        int cnt = 0,k=0;
        for(int i=n-1;i>=0;i--){
            if(a[i]==0){
                if(cnt<2)cnt++;
                else continue;
            }
            arr.push_back(a[i]);
            m[a[i]];
        }
        Combination(0, arr.size()-1, 0, 3);
        if(ans)Y();
        else N();
    }
}