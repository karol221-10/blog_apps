#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class patient
{
    public:
    patient(string name,string surname) {
        this->name = name;
        this->surname = surname;
        cout<<"Patient "<<this->name<<" "<<this->surname<<" constructor"<<endl;
    }
    ~patient() {
        cout<<"Patient "<<this->name<<" "<<this->surname<<" destructor"<<endl;
    }
    void printNameSurname() {cout<<name<< " "<<surname;}
    string name;
    string surname;
};
void printPatientData(shared_ptr<patient> patient) {
    cout<<"printPatientData function"<<endl;
    patient->printNameSurname();
    cout<<endl<<"Reference counter: "<<patient.use_count()<<endl<<endl;
}
void modifyPatientData(shared_ptr<patient> patient,string name,string surname) {
    cout<<"modifyPatientData function"<<endl;
    patient->name = name;
    patient->surname = surname;
    patient->printNameSurname();
    cout<<endl<<"Reference counter: "<<patient.use_count()<<endl<<endl;
}
int main()
{
    vector<shared_ptr<patient>> vector_of_patients;
    vector_of_patients.push_back(make_shared<patient>("Adam","Nowak"));
    vector_of_patients.push_back(make_shared<patient>("Jan","Kowalski"));
    vector_of_patients.push_back(make_shared<patient>("Amadeusz","Mozart"));
    shared_ptr<patient> add_patient = vector_of_patients[2];
    printPatientData(vector_of_patients[0]);
    modifyPatientData(vector_of_patients[0],"Juliusz","Cezar");
    cout<<"Return to main"<<endl;
    vector_of_patients[0]->printNameSurname();
    cout<<endl<<"Reference counter: "<<vector_of_patients[0].use_count()<<endl;
    cout<<"Vector clear"<<endl;
    vector_of_patients.clear();
    cout<<"After vector clear"<<endl;
    return 0;
}
