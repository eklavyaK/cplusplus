#define PROGRAM int main(){rapid_iostream;int tc=1;cin>>tc;while(tc-->0){codeforce();}return 0;}
#define Compare(u) class Comp{public: bool operator() (u a, u b){return a.F < b.F;}};
#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define _pq(u) priority_queue<u,vector<u>, Comp>
#define binary(n,k) bitset<k>(n).to_string()
#define println(n) cout<<n<<'\n'
#define MAIN void codeforce();
#define Y() cout<<"YES"<<endl
#define print(n) cout<<n<<' '
#define N() cout<<"NO"<<endl
#define pii pair<int,int>
#define mod1 1000000007ll
#define pli pair<ll,int>
#define pil pair<int,ll>
#define mod2 998244353ll
#include<bits/stdc++.h>
#define pll pair<ll,ll>
typedef long double ld;
typedef long long ll;
#define mp make_pair
using namespace std;
#define endl '\n'
#define S second
#define F first
Compare(pii)
/***************************************************/ MAIN PROGRAM /*******************************************************/

int find(vector<int> arr){
    if(arr.size()==1){
        return arr[0];
    }
    if(arr.size()==2){
        cout<<'?'<<' '<<arr[0]<<' '<<arr[1]<<endl<<flush;
        int most; cin>>most; 
        if(most==1)return arr[0];
        else return arr[1];
    }
    vector<int> send;
    int n = arr.size();
    for(int i=0;i<n;i+=4){
        cout<<'?'<<' '<<arr[i]<<' '<<arr[i+2]<<endl<<flush;
        int most; cin>>most;
        if(most==0){
            cout<<'?'<<' '<<arr[i+1]<<' '<<arr[i+3]<<endl<<flush;
            int winner; cin>>winner;
            if(winner==1)send.push_back(arr[i+1]);
            else send.push_back(arr[i+3]);
        }
        else if(most==1){
            cout<<'?'<<' '<<arr[i]<<' '<<arr[i+3]<<endl<<flush;
            int winner; cin>>winner;
            if(winner==1)send.push_back(arr[i]);
            else send.push_back(arr[i+3]);
        }
        else{
            cout<<'?'<<' '<<arr[i+1]<<' '<<arr[i+2]<<endl<<flush;
            int winner; cin>>winner;
            if(winner==1)send.push_back(arr[i+1]);
            else send.push_back(arr[i+2]);
        }
    }
    return find(send);
}

void codeforce(){
    int n; cin>>n;
    vector<int> arr(1<<n);
    iota(arr.begin(),arr.end(),1);
    int ans = find(arr);
    cout<<'!'<<' '<<ans<<endl<<flush;
}