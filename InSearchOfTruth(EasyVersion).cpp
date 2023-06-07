#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int query(int k){
    cout<<"+ "<<' '<<k<<endl<<flush;
    cin>>k; return k;
}
void print(int n){
    cout<<"! "<<n<<endl<<flush;
    return;
}
void code(){
    int x; cin>>x;
    map<int,int> m;
    m[x] = 1;
    int cnt = 1;
    for(int i=0;i<1003;i++){
        x = query(1);
        cnt++;
        if(m.count(x)){
            print(cnt-m[x]);
            return;
        }
        m[x] = cnt;
    }
    for(int i=0;i<1000;i++){
        x = query(999);
        cnt+=999;
        if(m.count(x)){
            print(cnt-m[x]);
            return;
        }
        m[x] = cnt;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; while(t--)code();
    return 0;
}