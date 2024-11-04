#include<<bits/stdc++.h>>
using namespace std;

// Base class
class Student {
public:
    string name;
    int id;
    float cgpa;
    int age;

    Student(string n, int i, float c, int a) : name(n), id(i), cgpa(c), age(a) {}

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived classes
class CSE : public Student {
public:
    CSE(string n, int i, float c, int a) : Student(n, i, c, a) {}

    void display() override {
        cout << "CSE Student:" << endl;
        Student::display();
    }
};

class BBA : public Student {
public:
    BBA(string n, int i, float c, int a) : Student(n, i, c, a) {}

    void display() override {
        cout << "BBA Student:" << endl;
        Student::display();
    }
};

class Civil : public Student {
public:
    Civil(string n, int i, float c, int a) : Student(n, i, c, a) {}

    void display() override {
        cout << "Civil Student:" << endl;
        Student::display();
    }
};

// Main function
int main() {
    vector<Student*> students;
    int choice;

    for (int i = 0; i < 10; i++) {
        cout << "Enter the type of student (1. CSE, 2. BBA, 3. Civil): ";
        cin >> choice;

        string name;
        int id;
        float cgpa;
        int age;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cout << "Enter age: ";
        cin >> age;

        Student* student = nullptr;

        switch(choice) {
            case 1:
                student = new CSE(name, id, cgpa, age);
                break;
            case 2:
                student = new BBA(name, id, cgpa, age);
                break;
            case 3:
                student = new Civil(name, id, cgpa, age);
                break;
            default:
                cout << "Invalid choice!" << endl;
                i--; // Invalid input, do not count this iteration
                continue;
        }

        students.push_back(student);
    }

    for (auto student : students) {
        student->display();
        cout << endl;
    }

    for (auto student : students) {
        delete student;
    }

    return 0;
}
