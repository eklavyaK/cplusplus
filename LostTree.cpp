#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int n;
vector<int> query(int node){
    cout<<"? "<<node<<endl<<flush;
    vector<int> ret(n);
    for(int i=0;i<n;i++)cin>>ret[i];
    return ret;
}

void code(){
    cin>>n;
    vector<pair<int,int>> ans;
    vector<int> curr = query(1);
    int cnt_odd = 0, cnt_even = 0;
    vector<int> odd, even;
    for(int i=0;i<n;i++){
        if(curr[i]==1){
            ans.push_back({i+1,1});
        }
        if(curr[i]&1)odd.push_back(i+1);
        else if(curr[i]!=0) even.push_back(i+1);
    }
    if(even.size()<=odd.size()){
        for(auto j : even){
            curr = query(j);
            for(int i=0;i<n;i++){
                if(curr[i]==1)ans.push_back({i+1,j});
            }
        }
    }
    else{
        for(auto j : odd){
            curr = query(j);
            for(int i=1;i<n;i++){
                if(curr[i]==1)ans.push_back({i+1,j});
            }
        }
    }
    cout<<"!"<<endl;
    for(auto i : ans){
        cout<<i.F<<' '<<i.S<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}