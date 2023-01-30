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
    vector<int> c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        if(i&1)continue;
        bool f = true;
        int k = c[i], mn = c[i];
        for(int j=i+1;j<n;j++){
            if(!(j&1))k+=c[j];
            else if(k<c[j]){
                if(f)ans+=mn,f=false;
                else ans+=mn+1;
                break;
            }
            else{
                k-=c[j];
                if(k<=mn){
                    if(f)ans+=mn-k,f=false;
                    else ans+=mn-k+1;
                }
                mn = min(mn,k);
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}