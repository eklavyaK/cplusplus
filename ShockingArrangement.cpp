#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

int n;
void code(){
    cin>>n;
    vector<int> positive,negative;
    int mx = -1e9, mn = 1e9;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        if(k>=0)positive.push_back(k);
        else negative.push_back(k);
        mn = min(mn,k); mx = max(mx,k);
    }
    sort(negative.begin(),negative.end(),greater<int>());
    sort(positive.begin(),positive.end());
    vector<int> ans;
    int l = 0, r = 0, curr = 0, c=mx-mn;
    while(true){
        int now = ans.size();
        for(;l<positive.size();l++){
            if(positive[l]+curr<c)curr+=positive[l],ans.push_back(positive[l]);
            else{
                break;
            }
        }
        for(;r<negative.size();r++){
            if(negative[r]+curr>=0)curr+=negative[r],ans.push_back(negative[r]);
            else {
                break;
            }
        }
        if(now==ans.size())break;
    }
    if(ans.size()!=n){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    for(auto i : ans)cout<<i<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}