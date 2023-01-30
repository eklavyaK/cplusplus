#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    map<int,int> m;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            m[i]++;
        }
    }
    if(n>1)m[n]++;
    int ans = 0;
    while(!m.empty()){
        int k = 1;
        vector<int> c;
        for(auto i : m){
            k*=i.first;
            m[i.first]--;
            if(m[i.first]==0)c.push_back(i.first);
        }
        ans+=k;
        for(auto j:c){
            m.erase(j);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}