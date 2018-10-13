#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // normalne użycie
    int* wsk = nullptr;
    int* data = new int(25);
    wsk = data;
    cout<<"*wsk = "<<*wsk<<endl;
    delete data;
    data = nullptr;
   // cout<<"*wsk = "<<*wsk<<endl; //nieprawidłowe odwołanie - data zostało zwolnione, lecz wsk dalej wskazuje na zwolnioną przestrzeń w pamięci. Crash gwarantowany

   //Jak to rozwiązać za pomocą inteligentnych wskaźników?
    weak_ptr<int> weakwsk1;
    shared_ptr<int> shwsk1 = make_shared<int>(25);
    weakwsk1 = shwsk1;
    if(weakwsk1.lock()!=nullptr) {
        cout<<"*weakwsk1.lock() = "<<*weakwsk1.lock()<<endl;
    } else {
        cout<<"*weakwsk1 is expired"<<endl;
    }
    shwsk1.reset(); // zwalniamy pamięć przypisaną do shwsk1
    weakwsk1 = shwsk1;
    if(weakwsk1.lock()!=nullptr) {
        cout<<"*weakwsk1.lock() = "<<*weakwsk1.lock()<<endl;
    } else {
        cout<<"*weakwsk1 is expired"<<endl;
    }
    return 0;
}
