#include<iostream>
#include<utility> /*pair is available in utillity stl. Maps are generally faster than pair arrays*/
#include<vector>
#include<algorithm>
using namespace std;
inline bool sortbysec(pair<int,int> &a, pair<int,int> &b) {return a.second<b.second;}
inline bool des(pair<int,int> &a, pair<int,int> &b) {return a.first>b.first;}
int main()
{
    //declaration and initialization
    pair<int,int> p;           //by default int is initialized to 0
    pair<int,string> ps;       //by default string is initialized to ""
    pair<int,char> pc;         //by default char is initialized to ''
    cout<<p.first<<" "<<p.second<<endl;
    cout<<ps.first<<" "<<ps.second<<endl;
    cout<<pc.first<<" "<<pc.second<<endl;
    p.first = 10;
    p.second = 100;
    cout<<p.first<<" "<<p.second<<endl;
    pair<int,int> p1(p);       //passing a pair at the timem of declaration initializes the pair with the passed pair
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,string> ps1(10,"messi");  //passing a pair at the timem of declaration initializes the pair with the passed pair
    cout<<ps1.first<<" "<<ps1.second<<endl;
    pair<int,char> pc1 = make_pair(65, 'A');  //make_pair(arg1,arg2) takes two arguments and returns their pair in the same order
    cout<<pc1.first<<" "<<pc1.second<<endl;
    pc = {97,'a'};    //assigning a pair to another replaces it with the new assigned pair
    cout<<pc.first<<" "<<pc.second<<endl;
    ps = make_pair(32,"Eklavya Kumar");
    cout<<ps.first<<" "<<ps.second<<endl<<endl;

    ps1.swap(ps);        //swap() method swaps the contests of the pairs
    cout<<ps1.first<<" "<<ps1.second<<endl;
    cout<<ps.first<<" "<<ps.second<<endl;cout<<endl;

    pair<int,int> a[10]; //we can also make pair arrays where each element behaves like a pair
    for(int i = 0; i<10; i++) a[i] = {i+1, (i+1)*(i+1)};
    for(int i = 0; i<10; i++) cout<<a[i].first<<" "<<a[i].second<<endl;
    cout<<"\n";

    vector<pair<int,int>> v; int n = 10;   //declaring vector of type pair
    for(int i = 0; i<n; i++) v.emplace_back(make_pair(i+1,(n-i)*(i+1)));
    for(int i = 0; i<n; i++) cout<<v[i].first<<" "<<v[i].second<<endl;cout<<endl;
    sort(v.begin(),v.end());      //by simply writing this only first element of the pairs are compared for ascending order
    for(auto i : v) cout<<i.first<<" "<<i.second<<endl;cout<<endl;
    sort(v.begin(),v.end(),des);  //here we have applied conditional sorting to sort the first element of pairs in descending order
    for(auto i : v) cout<<i.first<<" "<<i.second<<endl;cout<<endl;
    sort(v.begin(),v.end(), sortbysec);  //here we have sorted the second elements of the pairs in ascending order
    for(auto i : v) cout<<i.first<<" "<<i.second<<endl;cout<<endl;

    pair<int,char> pc2,pc3;
    pc2 = pc1;           //assigning a pair to another copies the elements of a pair to the assigned pair
    pc3 = pc1;
    pc3.second = 'B';
    cout<<pc2.first<<" "<<pc2.second<<endl;
    cout<<pc1.first<<" "<<pc1.second<<endl;
    cout<<pc3.first<<" "<<pc3.second<<endl;
    cout<<'\n';
    cout<<(pc1==pc2)<<endl;
    cout<<(pc1==pc3)<<endl;
    cout<<(pc1!=pc2)<<endl;       //these are some relational operations we can perform on the pairs
    cout<<(pc1<pc2)<<endl;
    cout<<(pc1>=pc2)<<endl;
    cout<<(pc1>=pc3)<<endl;
    cout<<(pc1>pc3)<<endl;
    cout<<(pc1<pc3)<<endl;
    pc3.first = 64;
    cout<<(pc1<pc3)<<endl;
    pc3.second = '0';
    cout<<(pc1<pc3)<<endl;
    pc3.first = 65;            
    cout<<(pc1<pc3)<<endl;
    pc3.first = 605;
    cout<<(pc1<pc3)<<endl;         //it seems that pair.first is compared first then pair.second is compared

    return 0;
}
/*Output:

0 0
0
0
10 100
10 100
10 messi
65 A
97 a
32 Eklavya Kumar

32 Eklavya Kumar
10 messi

1 1
2 4
3 9
4 16
5 25
6 36
7 49
8 64
9 81
10 100

1 10
2 18
3 24
4 28
5 30
6 30
7 28
8 24
9 18
10 10

1 10
2 18
3 24
4 28
5 30
6 30
7 28
8 24
9 18
10 10

10 10
9 18
8 24
7 28
6 30
5 30
4 28
3 24
2 18
1 10

10 10
1 10
9 18
2 18
8 24
3 24
7 28
4 28
6 30
5 30

65 A
65 A
65 B

1
0
0
0
1
0
0
1
0
0
0
1
*/