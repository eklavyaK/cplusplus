#include<iostream>     /**********************WILL BE UPDATED************************/
#include<map>
/*                        map in c++ are sorted in increasing order of keys                                 */
using namespace std; 
/*           by default int values of a map is initialized to 0, and string values are initialized to ""                  */
int main()
{
    //declaration and initializations
    map<string,string> fruits; 
    map<int,int> graph;
    map<int,int> m{{1,2},{2,4},{3,6},{4,8},{5,10}};
    for(auto i : m) cout<<i.second<<" "; cout<<endl;       
    fruits["mango"] = "summer";
    fruits["banana"] = "perrenial";             
    fruits["grapes"] = "spring";
    fruits["orange"] = "winter";
    fruits["apple"] = "autumn";
    map<int,int> k{{1,2},{2,4},{3,6},{4,8},{5,10}};
    k = {{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}}; //assigning a map to another map reaplaces all the values of the map and replaces with new one
    map<int,int> a(k);  //this constructor takes a map and copies everything to the declared map
    map<int,int> b(move(m));  //this constructor moves the entire elements of the m to b, this should be done at the time of declaration itself
    cout<<m[1]<<endl;  //this prints 0 because all the it's elements have been moved, this should be done at the time of declaratoin itself
    for(int i = 0; i<10;) graph[++i] = i*10;
    for(auto i : fruits) cout<<i.second<<" ";cout<<endl;
    for(auto i : k) cout<<i.second<<" "; cout<<endl;
    for(auto i : a) cout<<i.second<<" "; cout<<endl;
    for(auto i : b) cout<<i.second<<" "; cout<<endl;
    for(int i = 0; i<10; i++) cout<<graph[i+1]<<" ";cout<<endl<<endl;

    cout<<fruits.empty()<<endl; //returns boolean value depending presence of elements in the map
    cout<<fruits.size()<<endl; //returns the number of keys in the map
    cout<<fruits.max_size()<<endl; //returns the maximum no of elements the map can hold
    cout<<graph.max_size()<<endl;cout<<endl;

    //iterator
    map<string,string>::iterator itr;
    for(itr = fruits.begin(); itr!=fruits.end();itr++) cout<<itr->first<<" "<<itr->second<<endl;cout<<endl;
    itr--;
    //itr->first = "watermelon"; ---------> this throws error because we can't directy change a key in map
    itr->second = "rainy";
    for(itr = fruits.begin(); itr!=fruits.end();itr++) cout<<itr->first<<" "<<itr->second<<endl;cout<<endl;

    m.clear(); //clear() function is used to clear all the elements of the map and sets its size to 0
    cout<<m.size()<<endl<<endl;      //prints: 0

    //find(key) method returns the iterator pointing to a particular key-value pair.
    //If key is not present then it returns the end() iterator of the map
    auto it = fruits.find("grapes");
    cout<<it->first<<" "<<it->second<<endl;
    it = fruits.find("berry");
    if(it!=fruits.end()) cout<<it->first<<" "<<it->second<<endl;
    else cout<<"NOT FOUND"<<endl<<endl;

    it = fruits.find("banana");
    fruits.erase(it); //erasing by iterator
    for(auto i : fruits) cout<<i.first<<" "<<i.second<<endl;cout<<endl;
    fruits.erase("apple"); //erasing by key
    for(auto i : fruits) cout<<i.first<<" "<<i.second<<endl;cout<<endl;
    auto it1 = graph.find(4), it2 = graph.find(7);
    graph.erase(it1,it2);  //erasing by range. Note: the range excludes it2
    for(auto i : graph) cout<<i.second<<" ";cout<<endl; cout<<endl;

    map<int,int> graph1;
    graph1 = graph;        //assignment operator only copies the pairs of a map to another nothing changes, thereby both maps are different
    graph1.emplace(4,40);  //emplace() is used to insert pairs in the map
    graph1.emplace(5,50);
    graph1.emplace(7,60);  //if element is already present then it is not replaced
    for(auto i : graph1) cout<<i.second<<" ";cout<<endl; //we can see that 7 is not replaced
    for(auto i : graph) cout<<i.second<<" ";cout<<endl;cout<<endl;
    //insert() method is also used to insert elements to the map
    graph.insert(pair<int,int>(4,40)); 
    graph.insert(pair<int,int>(7,60)); 
    graph.insert({5,50}); //if element is already present then it is not replaced
    graph.insert({8,80}); //if element is already present then it is not replaced
    for(auto i : graph) cout<<i.second<<" "; cout<<endl;
    it1 = graph.begin();it2 = graph.end();
    map<int,int> c;
    c.emplace(11,100);
    c.emplace(6,60);
    c.emplace(12,120);
    c.insert(it1,it2);
    for(auto i : c) cout<<i.second<<" ";cout<<endl<<endl;

    graph1.swap(c);   //swap method is used to swap the two maps
    for(auto i : graph1) cout<<i.second<<" ";cout<<endl;
    for(auto i : c) cout<<i.second<<" ";cout<<endl;

    return 0;
}
/*Output:

2 4 6 8 10 
0
autumn perrenial spring summer winter
1 2 3 4 5 6
1 2 3 4 5 6
2 4 6 8 10
10 20 30 40 50 60 70 80 90 100 

0
5
67108863
178956970

apple autumn
banana perrenial
grapes spring
mango summer
orange winter

apple autumn
banana perrenial
grapes spring
mango summer
orange rainy

0

grapes spring
NOT FOUND

apple autumn
grapes spring
mango summer
orange rainy

grapes spring
mango summer
orange rainy

10 20 30 70 80 90 100

10 20 30 40 50 70 80 90 100
10 20 30 70 80 90 100

10 20 30 40 50 70 80 90 100
10 20 30 40 50 60 70 80 90 100 100 120

10 20 30 40 50 60 70 80 90 100 100 120
10 20 30 40 50 70 80 90 100
*/