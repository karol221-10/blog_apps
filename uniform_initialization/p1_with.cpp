#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;
 
int main()
{
    int tab[] {1,2,3,4,5};
    list<int> normal_list {1,2,3,4,5};
    map<int,string> normal_map {{0,"zero"},{1,"one"},{2,"two"}};
    vector<int> normal_vector {100,200,300};
    return 0;
}
