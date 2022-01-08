#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    for(int i = 0; i<10; i++)
        v.push_back(i+1);
    v.push_back(23);
    v.push_back(9823);
    vector<int>::iterator itr;
    //itr = v.begin();
    itr = v.end();
    cout<<*--itr<<endl;
    cout<<*--itr<<endl;
    cout<<(*itr)<<endl;

    return 0;
}