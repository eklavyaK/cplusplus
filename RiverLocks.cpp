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
    vector<int> v(n),rem(n+1);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=n-1;i>=0;i--)rem[i]=rem[i+1]+v[i];
    int t = 0, extra = 0, mx = 0;
    vector<pair<int,int>> mne;
    bool k = true;
    for(int i=0;i<n;i++){
        if(extra+t>=v[i]){
            extra = extra+t-v[i];
            mne.push_back({t,extra});
        }
        else{
            v[i]-=extra+t;
            t = t + v[i]/(i+1);
            extra = -(v[i]%(i+1));
            mne.push_back({t,extra});
        }
        if(t>mx){
            mx = t;
            if(extra<0)k=false;
            else k = true;
        }
        else if(t==mx && extra<0)k=false;
    }
    int q; cin>>q;
    while(q--){
        int f; cin>>f;
        if(f<mx){
            cout<<-1<<endl;
            continue;
        }
        else if(f==mx&&!k){
            cout<<-1<<endl;
            continue;
        }
        int l = 0, r = n-1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(ceil((ld)(max(0ll,rem[mid+1]-mne[mid].S))/(mid+1))+mne[mid].F<=f)r=mid-1;
            else l=mid+1;
        }
        if(r+2<=n)cout<<r+2<<endl;
        else cout<<-1<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}