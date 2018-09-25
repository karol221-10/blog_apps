#include <iostream>
#include <memory>

using namespace std;
class patient
{
    public:
    patient() {
        cout<<"Patient constructor"<<endl;
    }
    ~patient() {
        cout<<"Patient destructor"<<endl;
    }
    string name;
    string surname;
};
void foo(shared_ptr<patient> pat) {
    cout<<"Foo function"<<endl;
    cout<<pat->name<<endl;
    cout<<pat->surname<<endl;
    cout<<"Reference counter: "<<pat.use_count()<<endl<<endl;
}
void foo_reference(shared_ptr<patient>& pat) {
    cout<<"foo_reference function"<<endl;
    cout<<pat->name<<endl;
    cout<<pat->surname<<endl;
    cout<<"Reference counter: "<<pat.use_count()<<endl<<endl;
}
int main()
{
    shared_ptr<patient> fpat = make_shared<patient>();
    fpat->name = "Jan";
    fpat->surname = "Kowalski";
    cout<<"Read data from fpat shared_ptr"<<endl;
    cout<<fpat->name<<endl;
    cout<<fpat->surname<<endl;
    cout<<"Reference counter: "<<fpat.use_count()<<endl<<endl;

    foo(fpat);
    cout<<"After foo main function"<<endl;
    cout<<fpat->name<<endl;
    cout<<fpat->surname<<endl;
    cout<<"Reference counter: "<<fpat.use_count()<<endl<<endl;
    foo_reference(fpat);
    return 0;
}
