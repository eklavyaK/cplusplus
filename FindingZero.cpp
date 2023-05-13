#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int query(int i, int j, int k){
    cout<<"? "<<i<<' '<<j<<' '<<k<<endl<<flush;
    cin>>k; return k;
}

void code(){
    int n; cin>>n;
    int k = 3, mx = -1;
    vector<int> v;
    for(int i=3;i<=n;i++){
        int curr = query(1,2,i);
        v.push_back(curr);
        if(curr>=mx) mx = curr, k = i;
    }
    if(k==n && query(1,k,3)<mx && v==vector<int>(n-2,mx)){
        cout<<"! "<<1<<' '<<2<<endl<<flush;
        return;
    }
    int k1 = k; mx = -1;
    for(int i=2;i<=n;i++){
        if(i==k)continue;
        int curr = query(1,k,i);
        if(curr>=mx) mx = curr, k1 = i;
    }
    if(k1!=2){
        if(query(2,k1,k)<mx){
            cout<<"! "<<1<<' '<<k<<endl<<flush;
            return;
        }
    }
    cout<<"! "<<k<<' '<<k1<<endl<<flush;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}