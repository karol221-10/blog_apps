#include <iostream>
 
using namespace std;
 
int main()
{
    auto lam1 = [](int arg1,int arg2){return arg1+arg2;};
    int wynik = lam1(5,3);
    cout<<"wynik: "<<wynik<<endl;
    return 0;
}
