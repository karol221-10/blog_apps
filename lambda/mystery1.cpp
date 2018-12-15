#include <iostream>
 
using namespace std;
 
int main()
{
    int a = 15;
    [a]mutable{a+=4;};
    cout<<"a: "<<a<<endl;
}
