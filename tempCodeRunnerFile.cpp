			long long L = p[l] - 1;
			L = min(L, (long long)r);
			string high = to_string(L);
			int sz = high.size();
			for(int i = 0; i < (1 << sz); i += 1){
			if(2 * __builtin_popcount(i) != sz) continue;
			vector<vector<long long>> dp(2, vector<long long> (k));