#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
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
        int n,x; cin>>n>>x; int a[n];
        for(int i = 0; i<n; i++)cin>>a[i];
        sort(a,a+n);int cnt = 0,c=1;
        for(int i=n-1;i>=0;i--){
            if((ll)a[i]*c>=x){
                cnt++;c=1;
            }
            else c++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}