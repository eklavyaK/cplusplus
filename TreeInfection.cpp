#include<bits/stdc++.h>
#define mod2 998244353ll
#define mod1 1000000007ll
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(s,c,sizeofc) for(int i = 0; i<sizeofc; i++){s.emplace_back(c[i]);while(i+1<sizeofc && c[i+1]==c[i])i++;}
typedef long long ll;
typedef long double ld;
void Y(){std::cout<<"YES"<<std::endl;}
void N(){std::cout<<"NO"<<std::endl;}
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0){
        int n,k; cin>>n;
        int cnt = 0;map<int,int> m;
        for(int i = 0; i<n-1; i++){
            cin>>k;m[k]++;
        }
        m[0]=1;vector<int> v;
        for(auto i : m){
            v.push_back(i.second);
        }
        priority_queue<int> q;int sum = 0;
        sort(v.begin(),v.end(),greater<int>());
        int c=v.size();n=c;c--;
        for(int i = 0; i<n; i++){
            cnt++;v[i]--;
            v[i]=(v[i]>c?v[i]-c:0);
            c--;if(v[i]>0){
                q.push(v[i]);
                sum+=v[i];
            }
        }
        c=1;
        while(!q.empty()){
            k=q.top();q.pop();
            if(c<k){
                cnt++;q.push(k-1);c++;
            }
            else if(k!=c)break;
            else{cnt++;break;}
        }
        cout<<cnt<<endl;
    }
    return 0;
}