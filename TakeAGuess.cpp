#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

int query(int i, int j, bool r){
    cout<<(r?"or ":"and ")<<i<<" "<<j<<endl<<flush;
    int k; cin>>k; return k;
}

void code(){
    int n, k; cin>>n>>k;
    vector<int> arr(n+1);
    int or12 = query(1,2,1),and12 = query(1,2,0);
    int or13  = query(1,3,1),and13 = query(1,3,0);
    int or23 = query(2,3,1),and23 = query(2,3,0);
    for(int i=0;i<32;i++){
        if((1<<i)&and12){
            arr[1]+=(1<<i);
            arr[2]+=(1<<i);
            if((1<<i)&and13)arr[3]+=(1<<i);
        }
        else if(!((1<<i)&or12)){
            if((1<<i)&or13)arr[3]+=(1<<i);
        }
        else{
            if(((1<<i)&or23)&((1<<i)&or13)){
                arr[3]+=(1<<i);
                if((1<<i)&and13)arr[1]+=(1<<i);
                else arr[2]+=(1<<i);
            }
            else{
                if((1<<i)&or13)arr[1]+=(1<<i);
                else arr[2]+=(1<<i);
            }
        }
    }
    for(int i=4;i<=n;i++){
        int orr = query(i,i-1,1);
        int andd = query(i,i-1,0);
        for(int j=0;j<32;j++){
            if((1<<j)&arr[i-1]){
                if((1<<j)&andd)arr[i]+=(1<<j);
            }
            else if((1<<j)&orr)arr[i]+=(1<<j);
        }
    }
    sort(arr.begin(),arr.end());
    cout<<"finish "<<arr[k]<<endl;
}
//[1,6,4,2,3,5,4]
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=1; while(t--)code();
    return 0;
}