#include <iostream>
#include <memory>
using namespace std;

int main()
{
    shared_ptr<int> int_table(new int[10],default_delete<int[]>());
    for(size_t i = 0;i<10;i++) {
        int_table.get()[i] = i;
    }
    for(size_t i = 0;i<10;i++) {
        cout<<"int_table["<<i<<"] = "<<int_table.get()[i]<<endl;
    }
    return 0;
}
