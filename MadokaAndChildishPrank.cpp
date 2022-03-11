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
		int n,m;cin>>n>>m;string s[n];
		for(int i = 0; i<n; i++)cin>>s[i];
		vector<array<int,4>> v;
		if(s[0][0]=='1') {cout<<-1<<endl;continue;}
		for(int i = n-1;i>=0;i--){
			for(int j=m-1;j>=0;j--){
				if(s[i][j]=='1'){
					if(j>0){
						array<int,4> arr;
						arr[0]=i+1;
						arr[1]=j;
						arr[2]=i+1;
						arr[3]=j+1;
						v.emplace_back(arr);
					}
					else if(j==0){
						array<int,4> arr;
						arr[0]=i;
						arr[1]=j+1;
						arr[2]=i+1;
						arr[3]=j+1;
						v.emplace_back(arr);
					}
				}
			}
		}
		cout<<v.size()<<endl;
		for(auto i : v){cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<" "<<i[3]<<endl;}
	}
	return 0;
}