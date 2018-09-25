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
int main()
{
    shared_ptr<patient> fpat = make_shared<patient>();
    fpat->name = "Jan";
    fpat->surname = "Kowalski";
    cout<<"Read data from fpat shared_ptr"<<endl;
    cout<<fpat->name<<endl;
    cout<<fpat->surname<<endl;
    cout<<"Reference counter: "<<fpat.use_count()<<endl<<endl;
    return 0;
}
