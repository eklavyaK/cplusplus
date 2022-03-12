#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(28);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n,k; cin>>n>>k;int a[n];k++;
        for(int i = 0; i<n; i++)cin>>a[i];
        if(n==1){cout<<k<<endl;continue;}
        else{
            string s = "";
            for(int i = 0; i<n-1; i++){
                int temp=a[i+1]-a[i];
                temp = pow(10,temp)-1;
                if(k<=temp){
                    s=to_string(k)+s;
                    k=0;
                    break;
                }
                else{
                    s=to_string(temp)+s;
                    k-=temp;
                }
            }
            if(k>0){
                s=to_string(k)+s;
            }
            cout<<s<<endl;
        }
    }
    return 0;
}