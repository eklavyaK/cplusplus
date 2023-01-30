#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    vector<int> v(n);
    map<int,int> m;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        m[k]++;
    }
    bool ans = 0;
    while(!m.empty()){
        auto [key,cnt] = *m.begin();
        if(key>=x){
            ans = 1; 
            break;
        }
        m.erase(key);
        if(cnt%(key+1)==0){
            m[key+1]+=cnt/(key+1);
        }
        else break;
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
    return 0;
}