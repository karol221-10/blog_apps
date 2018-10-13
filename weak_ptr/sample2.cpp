#include <iostream>
#include <memory>
using namespace std;

int main()
{
    weak_ptr<int> w1;
    weak_ptr<int> w2;
    {
        shared_ptr<int> wsk1 = make_shared<int>(42);
        w1 = wsk1;
        cout<<"w1.lock() = "<<w1.lock()<<endl;
        cout<<"w2.lock() = "<<w2.lock()<<endl;
    }
    cout<<endl;
    cout<<"w1.lock() = "<<w1.lock()<<endl;
    cout<<"w2.lock() = "<<w2.lock()<<endl;
    return 0;
}
