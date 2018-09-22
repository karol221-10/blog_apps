#include <iostream>
#include <memory>
using namespace std;

class fooObject {
    public:
    fooObject() {
        cout<<"Konstruktor fooObject"<<endl;
    }
    ~fooObject() {
        cout<<"Destruktor fooObject"<<endl;
    }
};
int main()
{
    unique_ptr<fooObject> object = make_unique<fooObject>();
    return 0;
}
