#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int k;
        cin >> k;
        int count = k - 1, temp = 0, track = 1;
        //if(k==1){cout<<0<<endl;continue;}
        do
        {
            temp = count;
            track++;
            if (k % track == 0)
                count = int(k / track) + track - 2;
            else
                count = int(k / track) + track - 1;
        } while (count <= temp);
        cout << temp << endl;
    }
}