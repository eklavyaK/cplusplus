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
        string s, t;
        cin >> s >> t;
        int count, detect = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == t[0])
            {
                int k = i;count = 0;
                while (count < t.size() && k < s.size() && t[count] == s[k])
                {
                    k++;
                    count++; int temp = k, tempcount = count;k -= 2;
                    while (count < t.size() && k >= 0 && t[count] == s[k])
                    {
                        k--;
                        count++;
                    }
                    if (count == t.size())
                    {
                        detect = 1;
                        break;
                    }
                    else {k = temp; count = tempcount;}
                }
                if(detect) break;
            }
        }
        detect ? cout << "yes" << endl : cout << "no" << endl;
    }
    return 0;
}