#include <iostream>
 
using namespace std;
 
int main()
{
    auto lam1 = [](int a,int b){return a<b;};
    auto lam2 = [](auto a,auto b){return a<b;};
    cout<<lam1(4,3)<<endl;
    cout<<lam2(4,3)<<endl;
    cout<<lam1("Bolek","Lolek")<<endl;
    cout<<lam2("Bolek","Lolek")<<endl;
    return 0;
}
