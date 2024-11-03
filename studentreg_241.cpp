#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    string surname;
    int studentId;
    string department;

public:
    Student() {}
    Student(string name, string surname, int studentId, string department) 
        : name(name), surname(surname), studentId(studentId), department(department) {}

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    string getSurname() const {
        return surname;
    }

    void setSurname(const string& surname) {
        this->surname = surname;
    }

    int getStudentId() const {
        return studentId;
    }

    void setStudentId(int studentId) {
        this->studentId = studentId;
    }

    string getDepartment() const {
        return department;
    }

    void setDepartment(const string& department) {
        this->department = department;
    }

    void displayStudent() const {
        cout << "ID: " << studentId << ", Name: " << name << ", Surname: " << surname << ", Department: " << department << endl;
    }
};

Student readStudent() {
    string name, surname, dept;
    int id;

    cout << "New Student Entry \n" << endl;

    cout << "Enter the student's name: ";
    cin >> name;

    cout << "Enter the student's surname: ";
    cin >> surname;

    cout << "Enter the student's ID: ";
    cin >> id;

    cout << "Enter the student's department: ";
    cin >> dept;

    return Student(name, surname, id, dept);
}

class Course {
private:
    vector<Student> students;

    int findStudentIndex(int studentId) const {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].getStudentId() == studentId) {
                return i;
            }
        }
        return -1;
    }

public:
    void addStudent(const Student& newStudent) {
        students.push_back(newStudent);
    }

    bool removeStudent(int studentId) {
        int index = findStudentIndex(studentId);
        if (index != -1) {
            students.erase(students.begin() + index);
            return true;
        } else {
            return false;
        }
    }

    bool updateStudent(int studentID_to_be_updated, const Student& newStudent) {
        int index = findStudentIndex(studentID_to_be_updated);
        if (index != -1) {
            students[index] = newStudent;
            students[index].setStudentId(studentID_to_be_updated);
            return true;
        } else {
            return false;
        }
    }

    void printAllStudents() const {
        for (const auto& student : students) {
            student.displayStudent();
        }
    }
};

class Menu {
public:
    void displayMenu() const {
        cout << "1. Add Student\n2. Remove Student\n3. Update Student\n4. Print All Students\n5. Exit\n";
    }

    int getUserSelection() const {
        int choice;
        cout << "Choose an option: ";
        cin >> choice;
        return choice;
    }
};

int main() {
    Course course;
    Menu menu;
    bool running = true;

    while (running) {
        menu.displayMenu();
        int choice = menu.getUserSelection();

        switch (choice) {
            case 1: {
                Student newStudent = readStudent();
                course.addStudent(newStudent);
                break;
            }
            case 2: {
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                if (course.removeStudent(id)) {
                    cout << "Student removed." << endl;
                } else {
                    cout << "There is no student that have such an id." << endl;
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to update: ";
                cin >> id;
                Student updatedStudent = readStudent();  
                if (course.updateStudent(id, updatedStudent)) {
                    cout << "Student updated." << endl;
                } else {
                    cout << "There is no student that have such an id." << endl;
                }
                break;
            }
            case 4:
                course.printAllStudents();
                break;
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
