#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
#define makeset(_set, _collection, size_of_collection) for(int i = 0; i<size_of_collection; i++){_set.emplace_back(_collection[i]);while(i+1<size_of_collection && _collection[i+1]==_collection[i])i++;}
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int tc;cin>>tc;
	while(tc-->0)
	{
		int n,k,d; cin>>n>>k>>d; map<int,int> map;
		int a[n];for(int i = 0; i<n; i++)cin>>a[i];
		int track=0,count=0,min = k; for(int i = 0; i<n; i++){
			if(i<d) {if(!map[a[i]])count++;map[a[i]]++;}
			else{
				if(count<min)min=count;
				map[a[track]]--;if(!map[a[track]])count--;
				track++;if(!map[a[i]])count++;map[a[i]]++;
			}
		}
		cout<<(min<count?min:count)<<endl;
	}
	return 0;
}