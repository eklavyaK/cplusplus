#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc;cin>>tc;
    while(tc-->0)
    {
        int n; cin>>n; int a[n], b[n]; long long cost=0l; 
		vector<int> v1, v2; bool detect[n] = {false};
		for(int i = 0; i<n; i++) cin>>a[i];
        for(int i = 0; i<n; i++) cin>>b[i]; 
		for(int k = 0; k<n; k++) 
		{
			int m = 0, index = 0;
			for(int i = 0; i<n; i++) if(!detect[i]){if(a[i]>m){m=a[i];index = i;}if(b[i]>m){m=b[i];index=i;}}detect[index]=true;
			if(v1.empty()) {v1.emplace_back(max(a[index],b[index]));v2.emplace_back(min(a[index],b[index]));continue;}
			else
			{	
				long long temp1=0l,temp2=0l;
				for(int i = 0; i<v1.size(); i++) temp1+=pow(a[index]+v1[i],2);
				for(int i = 0; i<v1.size(); i++) temp1+=pow(b[index]+v2[i],2);
				for(int i = 0; i<v1.size(); i++) temp2+=pow(b[index]+v1[i],2);
				for(int i = 0; i<v1.size(); i++) temp2+=pow(a[index]+v2[i],2);
				if(temp2>temp1){v1.emplace_back(a[index]);v2.emplace_back(b[index]);cost+=temp1;}
				else {v1.emplace_back(b[index]);v2.emplace_back(a[index]);cost+=temp2;}
			}
		}
		for(auto i : v1) cout<<i<<" ";cout<<endl;
		for(auto i : v2) cout<<i<<" ";cout<<endl;
		cout<<cost<<endl;
	}
	return 0;
}