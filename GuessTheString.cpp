#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
char query(int idx){
    cout<<"? 1 "<<idx<<endl<<flush;
    char c; cin>>c; return c;
}
int query(int l, int r){
    cout<<"? 2 "<<l<<" "<<r<<endl<<flush;
    int k; cin>>k; return k;
}

void code(){
    int n; cin>>n;
    set<char> st;
    vector<char> ans(n+1,'0');
    for(int i=1;i<=n;i++){
        int curr = st.size();
        int nxt = query(1,i);
        if(curr!=nxt){
            char c = query(i);
            st.insert(c);
            ans[i] = c;
        }
    }
    for(int i=2;i<=n;i++){
        if(ans[i]=='0')ans[i] = ans[1];
        else break;
    }
    vector<int> prev(26);
    for(int i=1;i<=n;i++){
        if(ans[i]=='0'){
            vector<int> bs;
            for(auto i : prev)if(i)bs.push_back(i);
            sort(bs.begin(),bs.end(),greater<int>());
            int l = 0, r = bs.size()-1;
            while(l<=r){
                int mid = (l+r)>>1;
                if(query(bs[mid],i)==mid+2)l=mid+1;
                else r = mid-1;
            }
            ans[i] = ans[bs[l]];
        }
        prev[ans[i]-'a']=i;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<ans[i];
    cout<<endl<<flush;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}