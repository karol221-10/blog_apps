#include <iostream>
#include <memory>
#include <assert.h>
using namespace std;

int main()
{
    shared_ptr<int> wsk1 = make_shared<int>(20);
    assert(wsk1);
    cout<<"wsk1 value: "<<*wsk1<<endl;
    cout<<"wsk1 reference number: "<<wsk1.use_count();
    shared_ptr<int> wsk2 = move(wsk1);
    assert(wsk2);
    cout<<endl<<endl<<"After move wsk1 to wsk2"<<endl;
    cout<<"wsk2 value: "<<*wsk2<<endl;
    cout<<"wsk2 reference number: "<<wsk2.use_count()<<endl;
    assert(wsk1);
    cout<<"wsk1 value: "<<*wsk1<<endl;
    cout<<"wsk1 reference number: "<<wsk1.use_count();
    return 0;
}
