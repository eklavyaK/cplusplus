#include <bits/stdc++.h>
#define removezeros(s) s.erase(0, s.find("1") != -1 ? s.find("1") : s.length() - 1)
#define binary(n, k) bitset<k>(n).to_string()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n, x, k;
		cin >> n >> x;
		int track = 0, count = 0;
		vector<pair<int, int>> v;
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			if (!m[k])
			{
				track++;
				v.emplace_back(make_pair(k, 1));
				m[k] = track;
			}
			else
				v[m[k] - 1].second++;
		}
		sort(v.begin(), v.end());
		for(int i = 0; i<track; i++)m[v[i].first]=i+1;
		for (int i = 0; i < track; i++)
		{
			if (m[v[i].first * x])
			{
				if(v[i].second>0){
				int temp = m[v[i].first * x]-1;
				if (v[temp].second < v[i].second)
				{
					count += (v[i].second-v[temp].second);
					v[temp].second = 0;
				}
				else
				{
					v[temp].second -= v[i].second;
				}
				}
			}
			else if(v[i].second>0)
				count += v[i].second;
		}
		cout << count << endl;
	}
	return 0;
}