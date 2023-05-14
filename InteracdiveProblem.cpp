#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
int n,x;
int query(int c){
    cout<<"+ "<<c<<endl<<flush;
    cin>>c; return c;
}
int code(int k){
    if(n<=10){
        for(int i=0;i<9;i++) if(query(1)) return n;
    }
    int curr = 0, q = query(k), mx = 0, c = 0;
    k>>=1;
    for(int i=0;i<9;i++,k++,k>>=1){
        if(q==curr) q = query(k), c+=k;
        else curr = q, q = query(n-k), c+=n-k;
        if(q>mx) mx = q, c = 0;
    }
    return n*mx+c;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    int ans = code(n/2);
    cout<<"! "<<ans<<endl;
    return 0;
}