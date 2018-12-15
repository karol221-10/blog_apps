#include <iostream>
 
using namespace std;
 
int main()
{
    int a = 0,b=4,c=0;
    a=[&a]{return a+5;}();
    b=[=]{return a+b;}();
    [=,&c]{c=a+b;};
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    return 0;
}
