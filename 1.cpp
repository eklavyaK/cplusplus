#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

void print(bool k){
    cout<<(k?"YES":"NO")<<endl;
}

void code(){
    int n,q; cin>>n>>q;
    string s; cin>>s;
    set<int> forward, backward;
    function<void(int)> forwarrd = [&](int i){
        if(i!=n-1 && (s[i]!='(' || s[i+1]!=')'))forward.insert(i);
        else if(i==n-1) forward.insert(n-1);
    };
    function<void(int)> backwarrd = [&](int i){
        if(i && (s[i-1]!='(' || s[i]!=')')) backward.insert(i);
        else if(!i) backward.insert(0);
    };
    for(int i=0;i<n;i+=2) forwarrd(i);
    for(int i=n-1;i>=0;i-=2) backwarrd(i);
    while(q--){
        int k; cin>>k;
        k--;
        s[k] = (s[k]=='('?')':'(');
        forward.erase(k-(k&1));
        forwarrd(k-(k&1));
        backward.erase(k+((n-1-k)&1));
        backwarrd(k+((n-k-1)&1));
        if(n&1) print(0);
        else if(n==2 && s=="()") print(1);
        else if(n==2) print(0);
        else if(forward.empty()) print(1);
        else{
            bool f = true, e = true;
            int fid = *forward.begin(), eid = *backward.rbegin();
            if(fid==n-1 && s[n-1]==')') f = false;
            else if(fid!=n-1 && s[fid]!='(') f = false;
            if(e && s[eid]!=')') e = false;
            else if(e==0 && s[0]=='(') e = false;
            if(e&f) print(1);
            else print(0);
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}