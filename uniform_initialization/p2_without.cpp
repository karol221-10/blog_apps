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
    return pair<double,double>(v1.first*v2.first,v1.second*v2.second);
}
int main()
{
    //tworzenie obiektów za pomocą konstruktora domyślnego
    Foo fooObject;
    Foo fooObjectWithDefConstructor();
 
    //tworzenie obiektów za pomocą konstruktora własnego
    Foo FooObjectAggregate {3,3.5f};
    Bar BarObjectWithConstructor(3,3.5f);
 
    //trochę zabawy z vectorami
    vector<Bar> vectorOfBars;
    vectorOfBars.push_back(Bar(1,1));
    vectorOfBars.push_back(Bar(2,2));
    vectorOfBars.push_back(Bar(3,3));
    pair<double,double> result = multiplyVectors(pair<double,double>(2.0,2.0),pair<double,double>(3.0,4.0));
 
    //Tablice
    Foo arrOfFoos[] = {{1,1.0f},{2,2.0f},{3,3.0f}};
    Bar arrOfBars[] = {Bar(1,1.0f),Bar(2,2.0f),Bar(3,3.0f)};
    return 0;
}
