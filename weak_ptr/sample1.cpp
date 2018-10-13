#include <iostream>
#include <memory>
#include <assert.h>
using namespace std;

int main()
{
    shared_ptr<int> shared_wsk1 = make_shared<int>(30);
    weak_ptr<int> weak1;
    weak_ptr<int> weak2;
    weak1 = shared_wsk1;
    {
        shared_ptr<int> shared_wsk2 = make_shared<int>(42);
        weak2 = shared_wsk2;
        cout<<"shared_wsk2 ref count: "<<shared_wsk2.use_count()<<endl;
        assert(!weak2.expired());
        shared_ptr<int> shared_wsk3 = weak2.lock();
        cout<<*weak2.lock()<<endl;
        cout<<"shared_wsk2 ref count: "<<shared_wsk2.use_count()<<endl;
    }
    assert(!weak1.expired());
    cout<<*weak1.lock()<<endl;
    assert(!weak2.expired());
    cout<<*weak2.lock()<<endl;
    return 0;
}
