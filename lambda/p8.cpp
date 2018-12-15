#include <iostream>
 
using namespace std;
class Foo {
    public:
    void bar(float arg) {
        auto lamb = [](float c,Foo& f){f.a+=c;};
        lamb(arg,*this);
    }
    void print() {
        cout<<"a: "<<a<<endl<<"b: "<<b<<endl;
    }
    private:
    float a = 4;
    float b = 6;
};
int main()
{
    Foo cl;
    cl.print();
    cout<<endl;
    cl.bar(4);
    cl.print();
    return 0;
}
