#include <iostream>
using namespace std;
class IFoo {
    public:
    IFoo(int a) {
        this->x = a;
        this->y = a;
        this->z = a;
    }
    IFoo(initializer_list<int> l) {
        initializer_list<int>::iterator i = l.begin();
        if(i!=l.end()) {
            x = *i;
            i++;
        }
        if(i!=l.end()) {
            y = *i;
            i++;
        }
        if(i!=l.end()) {
            z = *i;
            i++;
        }
    }
    void print() {
        cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
    }
    private:
    int x = 0;
    int y = 0;
    int z = 0;
};
int main()
{
    IFoo ob {1,2,3};
    IFoo ob2 {1};
    IFoo ob3(1);
    cout<<"ob: ";
    ob.print();
    cout<<"ob2: ";
    ob2.print();
    cout<<"ob3: ";
    ob3.print();
    return 0;
}
