#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;
ll cost = 0;
int main(){
    rapid_iostream;

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].F;
        a[i].S=i;
    }
    if(k==1){
        for(int i=0;i<n;i++)cout<<0<<' ';exit(0);
    }
    if(k==2){
        for(int i=0;i<n-1;i++)cout<<abs(a[i].F-a[i+1].F)<<' ';exit(0);
    }
    multiset<pair<int,int>> st;
    for(int i=0;i<k;i++){
        st.insert(a[i]);
    }
    auto it = st.begin();
    advance(it,k/2);
    if(k%2==0)it--;
    for(int i=0;i<k;i++){
        cost+=abs(a[i].F-it->F);
    }
    cout<<cost<<' ';
    int curr_med = it->F;
    for(int i=k;i<n;i++){
        st.insert(a[i]);
        if(it==st.lower_bound(a[i-k])){
            if(it->F<=a[i].F)it++;
            else it--;
        }
        else if(it->F<a[i-k].F && it->F>a[i].F)it--;
        else if(it->F<=a[i].F && it->F>=a[i-k].F)it++;
        st.erase(a[i-k]);
        if(k%2) cost+=(abs(it->F-a[i].F)-abs(curr_med-a[i-k].F));
        else cost+=(curr_med-it->F+abs(it->F-a[i].F)-abs(curr_med-a[i-k].F));
        cout<<cost<<' '; curr_med = it->F;
    }
    return 0;
}