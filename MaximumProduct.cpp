#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k=0; cin>>n; vector<int> vp,vn; long long product = 0l;
        for(int i = 0; i<n; i++){cin>>k; if(k<0) vn.emplace_back(k); else vp.emplace_back(k);}
        sort(vn.begin(),vn.end()); sort(vp.begin(),vp.end());
        if(n==5){product = 1; for(int i = 0; i<vp.size(); i++)product*=vp[i]; for(int i = 0; i<vn.size(); i++) product*=vn[i];}
        else if(vp.size() == 0) {product = 1;for(int i = 1; i<=5; i++) product *= vn[vn.size()-i];}
        else
        {
            if(vp.size()>=1 && vn.size()>=4)
            {product = 1;product *= vp[vp.size() - 1]; for(int i = 0; i<4; i++) product *= vn[i];}
            if(vp.size()>=3 && vn.size()>=2)
            {long long temp = 1l; for(int i = 1; i<=3; i++) temp *= vp[vp.size()-i]; for(int i = 0; i<2; i++) temp *= vn[i];
            if(temp>product)product = temp;}
            if(vp.size()>=5)
            {long long temp = 1l; for(int i = 1; i<=5; i++) temp*= vp[vp.size()-i]; if(temp>product) product = temp;}
        }
        cout<<product<<endl;
    }
    return 0;
}