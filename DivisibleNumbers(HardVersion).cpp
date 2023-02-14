#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    vector<int> fa, fb;
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            fa.push_back(i);
            fa.push_back(a/i);
        }
    }
    for(int i=1;i*i<=b;i++){
        if(b%i==0){
            fb.push_back(i);
            fb.push_back(b/i);
        }
    }
    int n = fa.size(), m = fb.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int fac = fa[i]*fb[j];
            if((c/fac)*fac<=a)continue;
            int foc = a*b/fac;
            if((d/foc)*foc<=b)continue;
            cout<<(c/fac)*fac<<' '<<(d/foc)*foc<<endl;
            return;
        }
    }
    cout<<"-1 -1"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}