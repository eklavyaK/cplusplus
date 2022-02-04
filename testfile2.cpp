#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n,m; cin>>n; long long a[n],res, sum = 0l;
    for(int i = 0; i<n; i++) {cin>>a[i];sum+=a[i];}
    cin>>m;sort(a,a+n);while(m--) 
    { 
        long long x,y; res = upper_bound(a,a+n,x)-a;
		cout<<res<<endl;
	}
}