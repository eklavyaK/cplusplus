#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int query(int l, int r){
    cout<<"? "<<l<<' '<<r<<endl<<flush;
    cin>>l; return l;
}
int t;
void code(){
    t++;
    int n; cin>>n;
    int tot = query(1,n), got = 0, last = 0, value = 0;
    function<bool(int,int)> check = [&](int x, int sum){
        if(!got){
            ld z1 = (1+sqrt((ld)1+8*sum))*0.5;
            if(z1==(int)z1 && query(1,x-1)==sum-z1+1){
                got = -1, last = x, value = z1;
            }
            else{
                sum = query(x,n);
                ld z2 = (1+sqrt((ld)1+8*sum))*0.5;
                got = 1, last = x, value = z2;
            }
            return true;
        }
        if(got==-1){
            ld z1 = (1+sqrt((ld)1+8*sum))*0.5;
            if(z1==(int)z1 && x-last==z1-value) return true;
            return false;
        }
        ld z2 = (1+sqrt((ld)1+8*sum))*0.5;
        if(z2==(int)z2 && x-last==value-z2) return true;
        return false;
    };
    int l = 1, r = n;
    while(l<=r){
        int mid = (l+r)>>1;
        int curr = 0;
        if(got==1) curr = query(mid,n);
        else curr = query(1,mid);
        if(curr){
            if(!got && curr==tot) r = mid-1;
            else if(check(mid,curr)){
                if(got==-1) l = mid+1;
                if(got==1) r = mid-1;
            }
            else{
                if(got==-1) r = mid-1;
                if(got==1) l = mid+1;
            }
        }
        else l = mid+1;
    }
    if(got==1) l = r+1;
    int sum = query(1,l);
    int z1 = (1+sqrt((ld)1+8*sum))*0.5;
    int z2 = (1+sqrt((ld)1+8*(tot-sum)))*0.5;
    cout<<"! "<<l-z1<<" "<<l<<" "<<l+z2-1<<endl<<flush;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}