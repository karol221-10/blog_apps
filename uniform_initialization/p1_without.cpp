#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
 
int main()
{
    int tab[] = {1,2,3,4,5};
    list<int> normal_list;
    for(int i = 0;i<5;i++) normal_list.push_front(i+1);
    map<int,string> normal_map;
    normal_map[0] = "zero";
    normal_map[1] = "one";
    normal_map[20] = "two";
    vector<int> vec;
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    return 0;
}
