#include <iostream>
#include <memory>
#include <assert.h>

using namespace std;
void foo(unique_ptr<int>& arg) {
    cout<<"foo: "<<*arg<<endl;
    // zmieńmy wartość arg
    *arg = 7;
}
void foo2(unique_ptr<int> arg) {
    cout<<"foo2: "<<*arg<<endl;
}
int main()
{
    unique_ptr<int> number = make_unique<int>(5);
    foo(number);
    foo2(move(number));
    assert(number); // Asercja prawdziwa - number jest równe null
    return 0;
}
