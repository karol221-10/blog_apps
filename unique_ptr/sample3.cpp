#include <iostream>
#include <memory>

using namespace std;
struct seriousStructure {
    float number1;
    int number2;
};
int main()
{
    unique_ptr<seriousStructure> object = make_unique<seriousStructure>();
    object->number1 = 3.4;
    object->number2 = 5;
    unique_ptr<seriousStructure> object2;
    object2 = move(object);
    return 0;
}
