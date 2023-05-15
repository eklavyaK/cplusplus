#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m,k; cin>>n>>m>>k;
    int bad = n%m, lim = n/m+1, c[n+1]{};
    deque<int> q;
    for(int i=1;i<=n;i++)q.push_back(i);
    int cn = 0, tempmx = 0, fnl = n - (m-bad)*(n/m);
    for(int i=0;i<k;i++){
        int cnt = 1, r = 0, mx = tempmx + 1*(cn<fnl);
        cn = 0, tempmx = 0;
        deque<int> temp;
        for(int j=0;j<n;j++){
            if(r==0){
                cout<<endl;
                cout<<lim-(cnt>bad)<<" ";
            }
            int curr = q.front(); q.pop_front();
            if(cnt<=bad) c[curr]++;
            c[curr]==mx?temp.push_back(curr):temp.push_front(curr);
            r++;
            if(r==lim-(cnt>bad)) r = 0, cnt++;
            cout<<curr<<" ";
            tempmx = max(tempmx, c[curr]);
        }
        q = temp;
        while(!temp.empty()){
            if(c[temp.front()]==tempmx) cn++;
            temp.pop_front();
        }
        cn = n-cn;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}