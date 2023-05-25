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
    string s; cin>>s;
    int a = 0, b = 0;
    bool f = true, g = true;
    deque<int> ids,ide;
    for(int i=0;i<n;i++){
        if(s[i]=='(') a++,ids.push_back(i);
        else b++,ide.push_back(i);
        if(a<b) f = false;
        if(b<a) g = false;
    }
    if((n&1) || a!=b){
        cout<<-1<<endl;
        return;
    }
    int ans[n];
    if(f || g){
        cout<<1<<endl;
        for(int i=0;i<n;i++)cout<<1<<' ';cout<<endl; return;
    }
    vector<int> one,two;
    while(!ide.empty()){
        if(ids.front()<ide.back()){
            ans[ids.front()] = ans[ide.back()] = 1;
        }
        else{
            ans[ids.front()] = ans[ide.back()] = 2;
        }
        ids.pop_front();
        ide.pop_back();
    }
    cout<<2<<endl;
    for(auto i : ans) cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}