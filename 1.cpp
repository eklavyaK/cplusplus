#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif

struct triples{
    int g, x, y;
};
triples extendedEuclidean(int a, int b){
    triples ans;
    if(!b){
        ans.x = 1;
        ans.y = 0;
        ans.g = a;
        return ans;
    }
    triples curr = extendedEuclidean(b,a%b);
    ans.x = curr.y;
    ans.y = curr.x - curr.y*(a/b);
    ans.g = curr.g;
    return ans;
}
int merge(int a, int n, int b, int m, int lc){
    triples curr = extendedEuclidean(n,m);
    if((b-a) % curr.g != 0) return -1;
    int r = ((b-a)/curr.g) % (m/curr.g);
    curr.x = (curr.x % (m/curr.g) + (m/curr.g)) % (m/curr.g);
    int u = r * curr.x % (m/curr.g);
    int ans =  (a + u * n % lc) % lc;
    return (ans % lc + lc) % lc;
}
int CRT(vector<int> a, vector<int> m){    // remainders (a) when x is divided by values (m)
    int n = a.size();
    if(n==0) return -1;
    for(int i=0;i<n;i++){
        if(m[i]==0) return -1;
        a[i] = a[i]%m[i];
    }
    int r = a[0], lc = m[0];
    for(int i=1;i<n;i++){
        int lcm = lc*m[i]/gcd(lc,m[i]);
        r = merge(r,lc,a[i],m[i],lcm);
        if(r==-1) return -1;
        lc = lcm;
    }
    return r;
}


void code(int TC){
    int n; cin>>n;
    vector<int> a(n),m(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>m[i];
    }
    int ans =  CRT(m,a);
    cout<<"Case "<<TC<<": ";
    if(ans==-1) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
}


signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int TT = 1; cin>>TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}
/*
2
10
13 2
17 7
37 35
29 9
31 13
23 2
11 7
19 11
5 2
2 1
12
13 7
29 5
19 11
11 7
7 2
31 8
2 1
5 1
3 1
17 1
23 2
37 16
*/