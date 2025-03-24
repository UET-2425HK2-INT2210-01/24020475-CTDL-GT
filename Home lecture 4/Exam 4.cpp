#include <iostream>
using namespace std;

struct student{
    int ID;
    string name;
    string Class;
    student* next;
    student(int i, string n, string c){
        ID = i;
        name = n;
        Class = c;
        next = nullptr;
    }
};

class studentmap{
private:
    student* head;
public:
    studentmap(){
        head = nullptr;
    }

    void insert(int id, string student_name, string student_class){
        student* newstudent = new student(id, student_name, student_class);

        if(head == nullptr){
            head = newstudent;
            return;
        }

        else{
            student* current = head;
            while(current != nullptr){
            if(newstudent->ID == current->ID){
                current->name = newstudent->name;
                current->Class = newstudent->Class;
                delete newstudent;
                return;
            }
            if(current->next == nullptr){
                current->next = newstudent;
                return;
            }
            current = current->next;
            }
        }
    }

    void deleted(int id){
        if(head == nullptr){
            return;
        }
        else{
            student* current = head;
            while(current!=nullptr){
                if(current->next->ID == id){
                    student* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    break;
                }
                current = current->next;
            }
        }
    }

    void infor(int id){
        if(head == nullptr){
            cout << "NA,NA" << endl;
            return;
        }
        else{
            student* current = head;
            while(current!=nullptr){
                if(current->ID == id){
                    cout << current->name << "," << current->Class << endl;
                    return;
                }
                current = current->next;
            }
                    cout << "NA,NA" << endl;
        }
    }
};

int main(){
    studentmap list;
    string operation;
    while(true){
        getline(cin, operation);
        if(operation.find("Insert")==0){
            int idstart = operation.find("(")+1;
            int idend = operation.find(",");
            int id = stoi(operation.substr(idstart, idend-idstart));

            int namestart = idend+1;
            int nameend = operation.find(",", namestart);
            string name = operation.substr(namestart, nameend-namestart);

            int classstart = nameend+1;
            int classend = operation.find(")", classstart);
            string Class = operation.substr(classstart, classend-classstart);

            list.insert(id, name, Class);
        }
        else if(operation.find("Delete")==0){
            int idstart = operation.find("(")+1;
            int idend = operation.find(")");
            int id = stoi(operation.substr(idstart, idend-idstart));
            list.deleted(id);
        }
        else if(operation.find("Infor")==0){
            int idstart = operation.find("(")+1;
            int idend = operation.find(")");
            int id = stoi(operation.substr(idstart, idend-idstart));
            list.infor(id);
        }
        else{
            break;
        }
    }
    return 0;
}
