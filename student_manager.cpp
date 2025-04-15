#include <iostream>
#include <string>
using namespace std;

class StudentManager {
private:
    string students[100];
    int count;

public:
    StudentManager() {
        count = 0;
    }

    void addStudent(string name) {
        if (count < 100) {
            students[count] = name;
            count++;
        } else {
            cout << "Student list is full!" << endl;
        }
    }

    void removeStudent(string name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i] == name) {
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student not found!" << endl;
        }
    }

    void displayStudents() {
        cout << "Students:\n";
        for (int i = 0; i < count; i++) {
            cout << students[i] << endl;
        }
    }
};

int main() {
    StudentManager sm;

    sm.addStudent("RIDWANUL");
    sm.addStudent("ISLAM");
    sm.addStudent("PAVEL");

    sm.displayStudents();

    sm.removeStudent("RIDWANUL");

    cout << "\nAfter removing:\n";
    sm.displayStudents();

    return 0;
}
