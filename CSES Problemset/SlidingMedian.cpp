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
        for(auto [f,e] : a) cout<<f<<' ';exit(0);
    }
    if(k==2){
        for(int i=0;i<n-1;i++)
        cout<<min(a[i].F,a[i+1].F)<<' ';exit(0);
    }
    multiset<pair<int,int>> st;
    if(k%2){
        for(int i=0;i<k;i++){
            st.insert(a[i]);
        }
        auto it = st.begin();
        advance(it,k/2);
        cout<<it->F<<' ';
        for(int i=k;i<n;i++){
            st.insert(a[i]);
            if(it==st.lower_bound(a[i-k])){
                if(it->F<=a[i].F)it++;
                else it--;
            }
            else if(it->F<a[i-k].F && it->F>a[i].F)it--;
            else if(it->F<=a[i].F && it->F>=a[i-k].F)it++;
            st.erase(a[i-k]);
            cout<<it->F<<' ';
        }
    }
    else{
        for(int i=0;i<k;i++){
            st.insert(a[i]);
        }
        auto itf = st.begin();
        auto ite = st.begin();
        advance(itf,k/2-1);
        advance(ite,k/2);
        cout<<min(ite->F, itf->F)<<' ';
        for(int i=k;i<n;i++){
            st.insert(a[i]);
            if(itf==st.lower_bound(a[i-k])){
                if(a[i].F>=itf->F){
                    if(a[i].F>=ite->F)ite++,itf++;
                    else if(a[i].F<ite->F)itf++;
                }
                else itf--;
            }
            else if(ite==st.lower_bound(a[i-k])){
                if(a[i].F>=itf->F){
                    if(a[i].F<ite->F)ite--;
                    else if(a[i].F>=ite->F)ite++;
                }
                else ite--,itf--;
            }
            else{
                if(a[i].F<itf->F && a[i-k].F>ite->F)ite--,itf--;
                else if(a[i-k].F<=itf->F && a[i].F>=ite->F)ite++,itf++;
                else if(a[i].F<ite->F && a[i].F>=itf->F){
                    if(a[i-k].F<=itf->F) itf++;
                    else if(a[i-k].F>ite->F) ite--;
                }
            }
            st.erase(a[i-k]);
            cout<<min(ite->F,itf->F)<<' ';
        }
    }
    return 0;
}