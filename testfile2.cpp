#include <iostream>  
#include <map>  
  
using namespace std;  
  
int main(void) {  
   map<char, int> m = {  
            {'b', 2},  
            {'c', 3},  
            {'d', 4},  
            };  
  
   //inserting element with the given position  
   m.insert(m.begin(), pair<char, int>('f', 1));    
   m.insert(m.end(), pair<char, int>('e', 5));  
  
   cout << "Map contains following elements" << endl;  
  
   for (auto it = m.begin(); it != m.end(); ++it)  
      cout << it->first << " = " << it->second << endl;  
  
   return 0;  
} 