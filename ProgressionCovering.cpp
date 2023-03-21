#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    function<void()> compute = [&](){
        vector<int> places(n);
        int cnt = 0, curr = 0, ans = 0;
        for(int i=n-1;i>=k;i--){
            curr-=cnt;
            if(i+k<n)cnt-=places[i+k];
            if(curr<arr[i]){
                places[i] = (arr[i]-curr+k-1)/k;
                curr+=places[i]*k;
                ans+=places[i];
                cnt+=places[i];
            }
        }
        int get = 0;
        for(int i=k-1;i>=0;i--){
            curr-=cnt;
            if(i+k<n)cnt-=places[i+k];
            get = max(get,(arr[i]-curr+i)/(i+1));
        }
        cout<<ans+get<<endl;
    };
    compute();
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}