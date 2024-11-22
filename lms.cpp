#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
bool isValidCourseCode(string code)
{
    if (code.length() == 5)
    {
        if ((code[0] >= 'a' || code[0] <= 'z') || (code[0] >= 'A' || code[0] <= 'Z'))
        {
            if ((code[1] >= 'a' || code[1] <= 'z') || (code[1] >= 'A' || code[1] <= 'Z'))
            {
                if (code[2] >= 0 || code[2] <= 9)
                {
                    if (code[3] >= 0 || code[3] <= 9)
                    {
                        if (code[4] >= 0 || code[4] <= 9)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
        return false;
}

bool isValidCreditHours(int crehour)
{
    if (crehour >= 0 || crehour <= 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidCourseName(string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != ' ')
        {
            return false;
        }
        else if (i < name.length() - 2)
        {
            continue;
        }
        return true;
    }
    return false;
}

bool isValidSemester(int sem)
{
    if (sem >= 1 || sem <= 9)
    {
        return true;
    }
    else
        return false;
}

void AddCourse(string code, int crehour, int sem, string name, string courseCode[], int creditHour[], int semester[], string courseName[])
{
    for (int i = 0; i < 100; i++)
    {
        if (courseCode[i] == " ")
        {
            courseCode[i] = code;
            courseName[i] = name;
            creditHour[i] = crehour;
            semester[i] = sem;
            break;
        }
    }
}

bool InputFailure()
{
    if (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        return true;
    }
    else
        return false;
}

void EditCourse(string editCode, string courseCode[], int creditHour[], int semester[], string courseName[], string code, string name, int crehour, int sem)
{
    bool check = false;
    for (int i = 0; i < 100; i++)
    {
        if (editCode == courseCode[i])
        {
            cout << "Enter the new details of the course: ";
            cin >> code;
            check = isValidCourseCode(code);
            while (check == 0)
            {
                cin.ignore();
                cout << "Invalid Course Code" << endl;
                cout << "Enter the details of the course: ";
                cin >> code;
                check = isValidCourseCode(code);
            }
            cin >> crehour;
            check = isValidCreditHours(crehour);
            while (check == 0)
            {
                cin.ignore();
                cout << "Invalid Credit Hour" << endl;
                cout << "Enter the details of the course: ";
                cin >> crehour;
                check = isValidCreditHours(crehour);
            }

            cin >> sem;
            check = isValidSemester(sem);
            while (check == 0)
            {
                cin.ignore();
                cout << "Invalid Semester" << endl;
                cout << "Enter the details of the course: ";
                cin >> sem;
                check = isValidSemester(sem);
            }
            getline(cin, name);
            check = isValidCourseName(name);
            while (check == 0)
            {
                cin.ignore();
                cout << "Invalid Course Name" << endl;
                cout << "Enter the details of the course: ";
                getline(cin, name);
                check = isValidCourseName(name);
            }
            // AddCourse(code, crehour, sem, name, courseCode, creditHour, semester, courseName);
            courseCode[i] = code;
            courseName[i] = name;
            creditHour[i] = crehour;
            semester[i] = sem;
            cout << "Course has been edited successfully" << endl;
            break;
        }
    }
}

void DeleteCourse(string deleteCode, string courseCode[], string courseName[], int creditHour[], int semester[])
{
    for (int i = 0; i < 100; i++)
    {
        if (deleteCode == courseCode[i])
        {
            courseCode[i] = " ";
            courseName[i] = " ";
            creditHour[i] = 0;
            semester[i] = 0;
            cout << "Course has been deleted successfully" << endl;
            break;
        }
    }
}

void ViewCourses(string courseCode[], string courseName[], int creditHour[], int semester[])
{
    system("cls");
    cout << left;
    cout << setw(21) << "Course Code" << setw(39) << "Name" << setw(20) << "Credit Hours" << setw(20) << "Semester" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (courseCode[i] != " ")
        {
            cout << setw(20) << courseCode[i] << setw(40) << courseName[i] << setw(20) << creditHour[i] << setw(20) << semester[i] << endl;
        }
    }
    cout.unsetf(ios::left);
    cout << endl
         << endl;
}

void SemesterCourses(int semestercheck, string courseCode[], string courseName[], int creditHour[], int semester[])
{
    system("cls");
    cout << left;
    cout << setw(21) << "Course Code" << setw(39) << "Name" << setw(20) << "Credit Hours" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (semestercheck == semester[i])
        {

            cout << setw(20) << courseCode[i] << setw(40) << courseName[i] << setw(20) << creditHour[i] << endl;
        }
    }
    cout.unsetf(ios::left);
    cout << endl
         << endl;
}

bool saveCourses(string courseCode[], string courseName[], int creditHour[], int semester[])

{
    ofstream fout;
    fout.open("Courses.txt");

    if (!fout)
    {
        cout << "File does not exist" << endl;
        return false;
    }

    for (int i = 0; i < 100; i++)
    {
        if (courseCode[i] != " ")
        {
            fout << courseCode[i] << "," << courseName[i] << "," << creditHour[i] << "," << semester[i] << endl;
        }
    }
    fout.close();
    return true;
}

bool loadCourses(string courseCode[], string courseName[], int creditHour[], int semester[])

{
    ifstream fin;
    fin.open("Courses.txt");
    string fullline;

    int tokenIndex = 0;

    if (!fin)
    {
        cout << "File not found!" << endl;
        return false;
    }
    while (getline(fin, fullline))
    {

        int count = 0;
        string array = "";

        for (int i = 0; i < fullline.length(); i++)
        {
            if (fullline[i] != ',')
            {
                array += fullline[i];
            }

            else
            {
                if (count == 0)
                {
                    courseCode[tokenIndex] = array;
                }
                else if (count == 1)
                {
                    courseName[tokenIndex] = array;
                }
                else if (count == 2)
                {

                    creditHour[tokenIndex] = stoi(array);
                }

                array = "";
                count++;
            }
        }
        if (count == 3)
        {
            semester[tokenIndex] = stoi(array);
        }
        tokenIndex++;
    }

    fin.close();
    return true;
}

int main()
{
    int input = 10;
    string courseCode[100], courseName[100];
    int creditHour[100], semester[100];
    string code, name;
    int crehour, sem;
    string editCode;
    string deleteCode;
    int semestercheck;

    for (int i = 0; i < 100; i++)
    {
        courseCode[i] = " ";
        courseName[i] = " ";
        creditHour[i] = 0;
        semester[i] = 0;
    }
    loadCourses(courseCode, courseName, creditHour, semester);

    while (input != 0 && cin)
    {
        // system("cls");
        cout << "** Welcome to university Learning Management System **" << endl;
        cout << "Choose the following option" << endl;
        cout << "1     " << "Add Course" << endl;
        cout << "2     " << "Update Course" << endl;
        cout << "3     " << "Delete Course" << endl;
        cout << "4     " << "View All Course" << endl;
        cout << "5     " << "View Courses of a Semester" << endl;
        cout << "0     " << "Exit Program" << endl
             << endl;
        cout << "Choose the option: ";
        cin >> input;

        while (input > 5 || input < 0 || InputFailure())
        {

            cout << "Invalid Detail" << endl;
            cout << "Choose the option: ";
            cin >> input;
        }

        switch (input)
        {
        case 1:
        {
            system("cls");
            bool flag = false;
            cout << "Enter the details of the course: ";
            cin >> code;
            flag = isValidCourseCode(code);

            while (flag == 0)
            {
                cin.ignore();
                cout << "Invalid Course Code" << endl;
                cout << "Enter the details of the course: ";
                cin >> code;
                flag = isValidCourseCode(code);
            }
            cin >> crehour;
            while (InputFailure())
            {

                cout << "Invalid Credit Hour" << endl;
                cout << "Enter the details of the course: ";
                cin >> crehour;
            }
            flag = isValidCreditHours(crehour);
            while (flag == 0)
            {
                cin.ignore();
                cout << "Invalid Credit Hour" << endl;
                cout << "Enter the details of the course: ";
                cin >> crehour;
                flag = isValidCreditHours(crehour);
                // cin.ignore();
            }

            cin >> sem;
            while (InputFailure())
            {
                cout << "Invalid Credit Hour" << endl;
                cout << "Enter the details of the course: ";
                cin >> crehour;
            }
            flag = isValidSemester(sem);
            while (flag == 0)
            {
                cin.ignore();
                // cin.clear();
                cout << "Invalid Semester" << endl;
                cout << "Enter the details of the course: ";
                cin >> sem;
                flag = isValidSemester(sem);
                // cin.ignore();
            }
            getline(cin, name);
            flag = isValidCourseName(name);
            while (flag == 0)
            {
                cin.ignore();
                cout << "Invalid Course Name" << endl;
                cout << "Enter the details of the course: ";
                getline(cin, name);
                flag = isValidCourseName(name);
            }
            AddCourse(code, crehour, sem, name, courseCode, creditHour, semester, courseName);
            cout << "Course has been added successfully" << endl;
            break;
        }

        case 2:
        {
            system("cls");
            bool flag = false;
            cout << "Enter the course code to edit: ";
            cin >> editCode;
            flag = isValidCourseCode(editCode);
            while (flag == 0)
            {
                cin.ignore();
                cout << "Invalid Course Code" << endl;
                cout << "Enter the details of the course: ";
                cin >> code;
                flag = isValidCourseCode(editCode);
            }
            EditCourse(editCode, courseCode, creditHour, semester, courseName, code, name, crehour, sem);
            break;
        }

        case 3:
        {
            system("cls");
            bool flag = false;
            cout << "Enter the course code to delete: ";
            cin >> deleteCode;
            flag = isValidCourseCode(deleteCode);
            while (flag == 0)
            {
                cin.ignore();
                cout << "Invalid Course Code" << endl;
                cout << "Enter the details of the course: ";
                cin >> code;
                flag = isValidCourseCode(deleteCode);
            }
            DeleteCourse(deleteCode, courseCode, courseName, creditHour, semester);
        }
        case 4:
        {
            ViewCourses(courseCode, courseName, creditHour, semester);
            break;
        }
        case 5:
        {
            cout << "Enter the semester: ";
            cin >> semestercheck;
            SemesterCourses(semestercheck, courseCode, courseName, creditHour, semester);
        }
        } // switch end bracket

    } // while loop
    bool courseCheck = saveCourses(courseCode, courseName, creditHour, semester);
    if (courseCheck == 1)
    {
        cout << "Your data has been stored" << endl;
    }
}