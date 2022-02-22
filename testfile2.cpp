#include<bits/stdc++.h>
#define removezeros(s) s.erase(0,s.find("1")!=-1?s.find("1"):s.length()-1)
#define binary(n,k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n; cin>>n;
    int total = 1;for(int i = 2; i<=n; i++)total*=i;
	vector<vector<int>> v(total);                     //total number of permutations will be 24 because of size is 4

    for(int i = 0; i<4; i++) v[0].emplace_back(rand()%50); //initializing the first array whose permutations to be found

    int track = 1;                              //this variable helps to add new permutation to the list
	for(int i = 1; i<n; i++){                   //here n is the length of each array
		int t = track;
		for(int j = 0; j<t; j++){
			for(int k = 0; k<i; k++){
				vector<int> vtemp(v[j]);
				int temp = vtemp[i];
				vtemp[i]=vtemp[k];
				vtemp[k]=temp;
				v[track++]=vtemp;
			}
		}
	}
	for(int j = 0; j<total; j++) {
        for(int i = 0; i<n; i++) cout<<v[j][i]<<" ";
        cout<<endl;
    }
	return 0;
}