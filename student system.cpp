#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string major;

    Student(int id, string name, int age, string major)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->major = major;
    }
};

bool idExists(const vector<Student>& students, int id)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            return true;
        }
    }

    return false;
}

void addStudent(vector<Student>& students)
{
    int id;
    int age;
    string name;
    string major;

    while (true)
    {
        cout << "Enter ID: ";
        cin >> id;

        if (cin.fail() || id <= 0)
        {
            cout << "Invalid ID. Enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (idExists(students, id))
        {
            cout << "This ID already exists.\n";
        }
        else
        {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true)
    {
        cout << "Enter Name: ";
        getline(cin, name);

        if (name.find_first_not_of(' ') == string::npos)
        {
            cout << "Name cannot be empty.\n";
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Enter Age: ";
        cin >> age;

        if (cin.fail() || age <= 0)
        {
            cout << "Invalid age. Enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true)
    {
        cout << "Enter Major: ";
        getline(cin, major);

        if (major.find_first_not_of(' ') == string::npos)
        {
            cout << "Major cannot be empty.\n";
        }
        else
        {
            break;
        }
    }

    students.push_back(Student(id, name, age, major));

    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Major: " << students[i].major << endl;
        cout << "-------------------\n";
    }
}

void searchStudent(const vector<Student>& students)
{
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    if (cin.fail() || id <= 0)
    {
        cout << "Invalid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << "Student Found!\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Major: " << students[i].major << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void updateStudent(vector<Student>& students)
{
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    if (cin.fail() || id <= 0)
    {
        cout << "Invalid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string name;
            string major;
            int age;

            while (true)
            {
                cout << "Enter New Name: ";
                getline(cin, name);

                if (name.find_first_not_of(' ') == string::npos)
                {
                    cout << "Name cannot be empty.\n";
                }
                else
                {
                    break;
                }
            }

            while (true)
            {
                cout << "Enter New Age: ";
                cin >> age;

                if (cin.fail() || age <= 0)
                {
                    cout << "Invalid age. Enter a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            while (true)
            {
                cout << "Enter New Major: ";
                getline(cin, major);

                if (major.find_first_not_of(' ') == string::npos)
                {
                    cout << "Major cannot be empty.\n";
                }
                else
                {
                    break;
                }
            }

            students[i].name = name;
            students[i].age = age;
            students[i].major = major;

            cout << "Student updated successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent(vector<Student>& students)
{
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    if (cin.fail() || id <= 0)
    {
        cout << "Invalid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students.erase(students.begin() + i);

            cout << "Student deleted successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main()
{
    vector<Student> students;

    int choice;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid choice.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1)
        {
            addStudent(students);
        }
        else if (choice == 2)
        {
            displayStudents(students);
        }
        else if (choice == 3)
        {
            searchStudent(students);
        }
        else if (choice == 4)
        {
            updateStudent(students);
        }
        else if (choice == 5)
        {
            deleteStudent(students);
        }
        else if (choice == 6)
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
```
