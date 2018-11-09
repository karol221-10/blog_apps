#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct Foo {
    int x;
    float y;
};
class Bar {
    public:
    Bar(int _x,float _y) : x(_x),y(_y) {}
    private:
    int x;
    float y;
};
pair<double,double> multiplyVectors(pair<double,double> v1,pair<double,double> v2) {
    return {v1.first*v2.first,v1.second*v2.second};
}
int main()
{
    //tworzenie obiektów za pomocą konstruktora domyślnego
    Foo fooObject {};
    //tworzenie obiektów za pomocą konstruktora własnego
    Foo FooObjectAggregate {3,3.5f};
    Bar BarObjectWithConstructor{3,3.5f};
 
    //trochę zabawy z vectorami
    vector<Bar> vectorOfBars {{1,1},{2,2},{3,3}};
    auto result = multiplyVectors({2.0,2.0},{3.0,3.0});
 
    //Tablice
    Foo arrOfFoos[] = {{1,1.0f},{2,2.0f},{3,3.0f}};
    Bar arrOfBars[] = {{1,1.0f},{2,2.0f},{3,3.0f}};
    return 0;
}
