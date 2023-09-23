#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif


long double dist(pair<long double,long double>a, pair<long double,long double>b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
bool check(vector<pair<long double,long double>>A, int B,long double d){
    d*=d;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
           // pair<long double,long double> A[i] = A[i], A[j] = A[j];
            long double h = dist(A[i],A[j]);
            long double D = (4*d-h)/h;
            if(4*d-h>=0.0){
                int cn1=0,cn2=0;
                pair<long double,long double>x,y;
                x.first = ((A[i].first+A[j].first)+sqrt(D)*(A[i].second-A[j].second))/2;
                x.second = ((A[i].second+A[j].second)+sqrt(D)*(A[j].first-A[i].first))/2;
                y.first = ((A[i].first+A[j].first)-sqrt(D)*(A[i].second-A[j].second))/2;
                y.second = ((A[i].second+A[j].second)-sqrt(D)*(A[j].first-A[i].first))/2;
                for(int k=0;k<A.size();k++){
                    if(dist(x,A[k])<=d+0.1)cn1++;
                    if(dist(y,A[k])<=d+0.1)cn2++;
                }
                if(cn1>=B){
                    return true;
                }
                if(cn2>=B){
                    return true;
                }
            }
        }
    }
    return false;
}
int solve(vector<vector<int> > &A, int B) {
    vector<pair<long double,long double>>C;
    int r = 0, l=0;
    for(int i=0;i<A.size();i++){
        long double xcoor=A[i][0]*(1.0);
        long double ycoor=A[i][1]*(1.0);
        r=max({r,A[i][0],A[i][1]});
        C.push_back({xcoor,ycoor});
    }
    while(l<=r){
        int mid = l + (r-l)/2;
        if(check(C,B,mid))
            r = mid-1;
        else l = mid+1;
    }
    return l;
}




void code(int TC){
    vector<vector<int>> A{
  {762888, 842056},
  {943296, 205226},
  {528530, 840859},
  {490975, 305681},
  {784949, 795242},
  {364631, 24977},
  {335193, 566499},
  {175628, 435361},
  {394134, 454625},
  {130339, 131963},
  {62547, 401942},
  {101919, 622627},
  {667354, 263679},
  {704772, 951888},
  {183983, 927405},
  {192090, 610510},
  {573528, 118235},
  {156736, 580620},
  {507137, 194840},
  {665701, 508127},
  {26162, 42107},
	};
	int B = 20;
    cout << solve(A, B) << endl;

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    cout.precision(30);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}