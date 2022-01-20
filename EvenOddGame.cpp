#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t-->0)
    {
        int n,k; cin>>n; long long suma = 0l, sumb = 0l;
        vector<int> ve, vo;
        for(int i = 0; i<n; i++) {cin>>k; if(k%2) vo.emplace_back(k); else ve.emplace_back(k);}
        sort(ve.begin(),ve.end()); sort(vo.begin(),vo.end()); int tracke = ve.size()-1, tracko = vo.size()-1;
        for(int i = 0; i<n; i++) 
        {
            if(i%2)
            {if(tracko>=0 && tracke>=0 && vo[tracko]>=ve[tracke]) {sumb+=vo[tracko];tracko--;}
            else if(tracko>=0 && tracke>=0 && vo[tracko]<ve[tracke]) tracke--;
            else if(tracko==-1) tracke--;
            else if(tracke==-1) {sumb+=vo[tracko];tracko--;}}
            else
            {if(tracko>=0 && tracke>=0 && vo[tracko]>ve[tracke]) tracko--;
            else if(tracko>=0 && tracke>=0 && vo[tracko]<=ve[tracke]) {suma+=ve[tracke];tracke--;}
            else if(tracko==-1) {suma+=ve[tracke];tracke--;}
            else if(tracke==-1) tracko--;}
        }
        if(suma-sumb==0)cout<<"Tie"<<endl;
        else if(suma-sumb>0)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}