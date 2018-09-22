#include <iostream>
#include <memory>
using namespace std;
class stackNode {
    public:
    int actual;
    unique_ptr<stackNode> prev;
};
class stack {
    public:
    void push(int number) {
        if(firstStackNode==nullptr) {
            unique_ptr<stackNode> newStackNode = make_unique<stackNode>();
            newStackNode->actual = number;
            firstStackNode = move(newStackNode);
        }
        else {
            unique_ptr<stackNode> newStackNode = make_unique<stackNode>();
            newStackNode->actual = number;
            newStackNode->prev = move(firstStackNode);
            firstStackNode = move(newStackNode);
        }
    }
    int pop() {
        if(firstStackNode==nullptr) return -1;
        else {
            int number = firstStackNode->actual;
            firstStackNode = move(firstStackNode->prev);
            return number;
        }
    }
private:
    unique_ptr<stackNode> firstStackNode;
};
int main()
{
    stack st;
    st.push(5);
    st.push(4);
    st.push(6);
    cout<<st.pop()<<"\n";
    cout<<st.pop()<<"\n";
    return 0;
}
