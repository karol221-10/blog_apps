#include <iostream>
 
using namespace std;
 
int main()
{
    int a = 4, b = 6, c = 9;
    auto lam1 = [](){a+=6;};
    auto lam2 = [b](){cout<<b<<endl;};
    auto lam3 = [b](){b+=9;};
    auto lam4 = [&c](){c+=12;};
    auto lam5 = [&](){a+=3; b+=6;};
    return 0;
}
