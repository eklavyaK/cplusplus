#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

//vector<int> f(2000010);

void code(){
    int n; cin>>n;
    int arr[n];
    map<int,int> m;
    bool check = false;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    sort(arr,arr+n);
    for(auto i : m){
        if(i.S>=n/2){
            cout<<-1<<endl;
            return;
        }
    }
    set<int> st;
    for(int i=0;i<=n/2;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i])st.insert(arr[j]-arr[i]);
        }
    }
    set<int> con;
    for(auto i : st){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                con.insert(j);
                con.insert(i/j);
            }
        }
    }
    int ans = 1;
    vector<bool> done;
    for(auto k:con){
        done.resize(n);
        for(int i=0;i<=n/2;i++){
            if(done[i])continue;
            int cnt = 1;
            for(int j=i+1;j<n;j++){
                if((arr[j]-arr[i])%k==0)cnt++,done[j]=1;
            }
            if(cnt>=n/2)ans = k;
        }
        done.clear();
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}