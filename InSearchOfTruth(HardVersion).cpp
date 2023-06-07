#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int query(int k){
    cout<<"+ "<<k<<endl<<flush;
    cin>>k; return k;
}
void print(int n){
    cout<<"! "<<n<<endl<<flush;
    return;
}
void code(){
    int mx; cin>>mx;
    int idx = 1;
    map<int,int> m;
    m[mx] = idx;
    for(int i=0;i<250;i++){
        idx++;
        int now = query(1);
        if(m.count(now)){
            print(idx-m[now]);
            return;
        }
        m[now] = idx;
        mx = max(mx,now);
    }
    for(int i=0;i<490;i++){
        int x = rand()%1000000;
        idx+=x;
        mx = max(mx,query(x));
    }
    cout<<"- "<<idx-1<<endl<<flush;
    cin>>idx;
    int nxt = query(mx-1);
    idx = mx;
    if(m.count(nxt)){
        print(idx-m[nxt]);
        return;
    }
    for(int i=0;i<250;i++){
        idx+=250;
        nxt = query(250);
        if(m.count(nxt)){
            print(idx-m[nxt]);
            return;
        }
    }
    print(mx);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}