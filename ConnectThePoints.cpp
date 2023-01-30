#include<bits/stdc++.h>
#define endl "\n"
#define f first
#define s second
typedef long double ld;
typedef long long ll;
using namespace std;
int x = 0, y = 0;
vector<int> ans;
vector<pair<int,int>> p(3);
void sett(int a, int b, int c, int d){
	vector<int> v({b,d,p[0].s});
	sort(v.begin(),v.end());
	y = v[1];
}
void compute(int a, int b, int c, int d){
	if(a==c){
		ans.push_back(c); ans.push_back(b);
		ans.push_back(c); ans.push_back(d);
		sett(c,b,c,d); x = c;
	}
	else if(b==d){
		ans.push_back(a); ans.push_back(b);
		ans.push_back(c); ans.push_back(d);
		x = a; y = b;
	}
	else{
		ans.push_back(a); ans.push_back(b);
		ans.push_back(a); ans.push_back(d);
		ans.push_back(a); ans.push_back(d);
		ans.push_back(c); ans.push_back(d);
		sett(a,b,a,d); x = a;
	}
}
void code(){
	for(int i=0;i<3;i++){
		cin>>p[i].f;
		cin>>p[i].s;
	}
	sort(p.begin(),p.end());
	compute(p[1].f,p[1].s,p[2].f,p[2].s);
	compute(p[0].f,p[0].s,x,y);
	cout<<ans.size()/4<<endl;
	for(int i=0;i<ans.size();i+=4){
		cout<<ans[i]<<' '<<ans[i+1]<<' '<<ans[i+2]<<' '<<ans[i+3]<<endl;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t=1; while(t--)code();
	return 0;
}