#include<iostream> /***********************WILL BE UPDATED************************/
#include<set>
#include<vector>
using namespace std;
/* set is a associative container which keeps elements in ascending(or lexicographic) order and each element occurs only once  */
int main()
{
    //declaration and initialization
    set<int> sint;
    set<string> setring;
    cout<<sint.empty()<<endl;                 //checks whether set is empty or not
    sint = {1,1,2,3,4,6,6,6,5,3,5,5,0,10};
    for(auto i : sint) cout<<i<<" "; cout<<endl;
    vector<int> v{12,130,9,93,82,8,39823,88,83,882,89,983,8,9823};
    set<int> sint1(v.begin(),v.end());
    for(auto i : sint1) cout<<i<<" ";cout<<endl;
    int a[] = {2,5,6,8,2,5,8,0};
    set<int> sint2(a,a+sizeof(a)/sizeof(a[0]));
    for(auto i : sint2) cout<<i<<" ";cout<<endl;
    setring = {"messi","ronaldo","neymar","lewandowski","suarez","salah"};  //assignment operator copies the elements of the assigning set to the set
    for(auto i : setring) cout<<i<<" "; cout<<endl<<endl;
    set<int> sint3;
    
    cout<<sint.size()<<" "<<sint1.size()<<" "<<setring.size()<<endl<<endl; //size() is used to get the number of elements in the set

    auto it = setring.find("messi");   //find(key) returns the iterator pointing to the key in the set. If key is absent then it points to the end of the set
    cout<<*(++it)<<endl;
    it = setring.find("mbappe");
    if(it == setring.end()) cout<<"NOT FOUND"<<endl<<endl;
    else cout<<*it<<endl;

    cout<<sint.count(0)<<" "<<sint.count(100)<<endl<<endl;//count(key) returns 1 if keys is present else returns 0

    sint2 = sint;       //assignment operator copies the element of a sint1 to sint2. They are not same but different copies of sets
    for(auto i : sint) cout<<i<<" ";cout<<endl;
    for(auto i : sint2) cout<<i<<" ";cout<<endl<<endl;;
    sint.erase(0);          //erasing by value
    sint1.erase(sint1.find(130),sint1.end());    //erasing by range
    sint1.erase(sint1.begin());    //erasing by iterator
    for(auto i : sint) cout<<i<<" ";cout<<endl;
    for(auto i : sint1) cout<<i<<" ";cout<<endl;
    for(auto i : sint2) cout<<i<<" ";cout<<endl<<endl;  //we can see sint2 doens't change when we change sint

    sint.emplace(7);    //emplace(arg) method is used to insert a element to set
    for(auto i : sint) cout<<i<<" ";cout<<endl;
    sint.insert(8);      //like emplace insert(arg) is used to insert element to set
    for(auto i : sint) cout<<i<<" ";cout<<endl;
    sint3.insert(sint.find(1),sint.end()); //insert(inputiterator first,inputiterator last) is used to insert a element in a set
    for(auto i : sint3) cout<<i<<" ";cout<<endl;
    sint3.insert(v.begin(),v.end());
    for(auto i : sint3) cout<<i<<" ";cout<<endl<<endl;

    for(int i = 0; i<10; i++) sint.insert(9);   //we can use this which taking input to insert elements to set, we can also use emplace
    for(auto i : sint)  cout<<i<<" "; cout<<endl<<endl;

    sint.swap(sint3);
    for(auto i : sint) cout<<i<<" "; cout<<endl;
    for(auto i : sint3) cout<<i<<" ";cout<<endl;cout<<endl;

    auto iter = sint.end();
    for(int i = 0; i<100; i++) cout<<*iter++<<" ";cout<<endl<<endl; /*The element at set.end() is size of the set, then on incrementing
    it actually decrements iterator to set.end()-1 then again increments it. */ 
    for(int i = 0; i<100; i++) cout<<*iter--<<" ";cout<<endl<<endl; /*on decrementing set.begin() takes you to set.end() and it starts a cycle */ 
    
    cout<<sint1.size()<<" "<<*sint1.end()<<endl;
    
    return 0;
}
/*Output:

1
0 1 2 3 4 5 6 10
8 9 12 82 83 88 89 93 130 882 983 9823 39823
0 2 5 6 8
lewandowski messi neymar ronaldo salah suarez

8 13 6

neymar
NOT FOUND

1 0

0 1 2 3 4 5 6 10
0 1 2 3 4 5 6 10

1 2 3 4 5 6 10
9 12 82 83 88 89 93
0 1 2 3 4 5 6 10

1 2 3 4 5 6 7 10
1 2 3 4 5 6 7 8 10
1 2 3 4 5 6 7 8 10
1 2 3 4 5 6 7 8 9 10 12 82 83 88 89 93 130 882 983 9823 39823

1 2 3 4 5 6 7 8 9 10

1 2 3 4 5 6 7 8 9 10 12 82 83 88 89 93 130 882 983 9823 39823
1 2 3 4 5 6 7 8 9 10

21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 
39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823 21 39823

21 39823 9823 983 882 130 93 89 88 83 82 12 10 9 8 7 6 5 4 3 2 1 21 39823 9823 983 882 130 93 89 88 83 82 12 10 9 8 7 6 5 4 3 2 1 21 39823 9823 983 882 130 93 89 88 
83 82 12 10 9 8 7 6 5 4 3 2 1 21 39823 9823 983 882 130 93 89 88 83 82 12 10 9 8 7 6 5 4 3 2 1 21 39823 9823 983 882 130 93 89 88 83 82 12

7 7
*/