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
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
    }
    set<int> st;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans++;
        int g = a[i].F*a[i].S;
        int l = a[i].S;
        int y = l;
        while(i+1<n){
            int y = l;
            g = gcd(g,a[i+1].F*a[i+1].S);
            l = l*a[i+1].S/gcd(l,a[i+1].S);
            if(g%l==0)i++; else break;
        }
        st.insert(l);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}