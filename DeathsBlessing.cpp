#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int n,m;
bool check(int x,vector<int> a){
    int st = 0, en = n-1;
    while(x!=0 && st<=en){
        if(st<n && a[st]<=x){
            st++; a[en]+=x;
            x--; en--;
        }
        else st++;
    }
    return x==0;
};

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll sum = 0;
        for(int i=0;i<n;i++){
            int k; cin>>k;
            sum+=k;
        }
        int brr[n];
        int l = 0, r = n-1;
        int done[n-1]{};
        for(int i=0;i<n;i++)cin>>brr[i];
        set<pair<int,int>> st;
        st.insert({brr[0],0});
        for(int i=1;i<n-1;i++){
            st.insert({brr[i]*2,i});
        }
        if(n!=1){
            st.insert({brr[n-1],n-1});
        }
        while(!st.empty()){
            auto [dist,now] = *st.begin();
            sum+=dist; st.erase({dist,now});
            done[now] = 1;
            if(now==l){
                while(l<n && done[l]){
                    l++;
                }
                if(l>=r)break;
                else{
                    st.erase({brr[l]*2,l});
                    st.insert({brr[l],l});
                }
            }
            else if(now==r){
                while(r>=0 && done[r])r--;
                if(l>=r)break;
                else{
                    st.erase({brr[r]*2,r});
                    st.insert({brr[r],r});
                }
            }
        }
        cout<<sum<<endl;
    }
}