#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <fstream>
using namespace std;

class hostel
{
    string name, enrollment_no, email, mobile_no, course, room_number;
    void book();
    void checkout();
    void display();
    void search();
    void modify();

public:
    void menu();
};

void hostel::menu()
{
    while (true)
    {
        system("cls");
        cout << "\t\t\t\t--------------------------" << endl;
        cout << "\t\t\t\t|Hostel Management System|" << endl;
        cout << "\t\t\t\t--------------------------" << endl;
        cout << "\t\t\t\t    1. Book a room" << endl;
        cout << "\t\t\t\t    2. Checkout" << endl;
        cout << "\t\t\t\t    3. Display" << endl;
        cout << "\t\t\t\t    4. Search" << endl;
        cout << "\t\t\t\t    5. Modify" << endl;
        cout << "\t\t\t\t    6. Quit" << endl
             << endl;
        cout << "\t\t\t\tEnter your choice[1/2/3/4/5/6]: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            char book_another;
            do
            {
                book();
                cout << "\t\t\t\t Book another one[Y/N]: ";
                cin >> book_another;
            } while (book_another == 'y' || book_another == 'Y');
            break;
        case 2:
            checkout();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            modify();
            break;
        case 6:
            exit(0);
        default:
            break;
        }
        cout << "\t\t\t\tPress any key...";
        getch();
    }
}

void hostel::book()
{
    system("cls");
    fstream file;
    cout << "\t\t\t---------------------------ADD DETAILS---------------------------" << endl;
    cout << "\t\t\t-----------------------------------------------------------------" << endl
         << endl;
    cout << "\t\t\t\t\t1. Student's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\t\t\t\t2. Enrollment number: ";
    cin >> enrollment_no;
    cout << "\t\t\t\t\t3. Email address: ";
    cin >> email;
    cout << "\t\t\t\t\t4. Mobile number: ";
    cin >> mobile_no;
    cout << "\t\t\t\t\t5. Course: ";
    cin >> course;
    cout << "\t\t\t\t\t6. Room number: ";
    cin >> room_number;
    cout << endl;
    file.open("student record.txt", ios::app);
    file << enrollment_no << " " << name << " " << email << " " << mobile_no << " " << course << " " << room_number << endl;
    file.close();
}

void hostel::checkout()
{
    system("cls");
    cout << "\t\t\t---------------------------DELETE RECORDS---------------------------" << endl;
    cout << "\t\t\t--------------------------------------------------------------------" << endl
         << endl;
    fstream readfile, writefile;
    readfile.open("student record.txt", ios::in);
    if (!readfile)
    {
        cout << "\t\t\t\trecord is empty......." << endl;
        readfile.close();
    }
    else
    {
        string temproll, first, last;
        bool flag = 0;
        cout << "\t\t\t\tEnter the enrollment number of student: ";
        cin >> temproll;
        writefile.open("record.txt", ios::app);
        readfile >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        while (!readfile.eof())
        {
            if (enrollment_no == temproll)
            {
                flag = 1;
                readfile >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
                continue;
            }
            writefile << enrollment_no << " " << first << " " << last << " " << email << " " << mobile_no << " " << course << " " << room_number << endl;
            readfile >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        }
        readfile.close();
        writefile.close();
        if (flag)
        {
            cout << "\t\t\t\t\trecord deleted successfully........." << endl;
        }
        else
        {
            cout << "\t\t\t\t\tNo record found........" << endl;
        }
        remove("student record.txt");
        rename("record.txt", "student record.txt");
    }
}

void hostel::display()
{
    system("cls");
    fstream file;
    cout << "\t\t\t-------------------------SHOWING RECORDS-------------------------" << endl;
    cout << "\t\t\t-----------------------------------------------------------------" << endl
         << endl;

    file.open("student record.txt", ios::in);
    int count = 1;
    if (!file.is_open())
    {
        cout << "record is empty......." << endl;
        file.close();
    }
    else
    {
        string first, last;
        file >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        while (!file.eof())
        {
            name = first + " " + last;
            cout << "\t\t\t\t\tstudent no. " << count++ << endl;
            cout << "\t\t\t\t\tstudent's name: " << name << endl;
            cout << "\t\t\t\t\tEnrollment no.: " << enrollment_no << endl;
            cout << "\t\t\t\t\tEmail address: " << email << endl;
            cout << "\t\t\t\t\tMobile number: " << mobile_no << endl;
            cout << "\t\t\t\t\tcourse: " << course << endl;
            cout << "\t\t\t\t\tRoom number: " << room_number << endl
                 << endl;
            file >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        }
        file.close();
        if (count == 1)
        {
            cout << "record is empty......." << endl;
        }
    }
}

void hostel::search()
{
    system("cls");
    cout << "\t\t\t---------------------------SEARCH RECORDS---------------------------" << endl;
    cout << "\t\t\t--------------------------------------------------------------------" << endl
         << endl;
    fstream file;
    file.open("student record.txt", ios::in);
    if (!file)
    {
        cout << "\t\t\t\tNo record found.........." << endl;
        file.close();
    }
    else
    {
        string temproll, first, last;
        bool flag = 0;
        cout << "\t\t\t\tEnter the enrollment number of student you want to find: ";
        cin >> temproll;
        file >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        while (!file.eof())
        {
            if (enrollment_no == temproll)
            {
                cout << "\t\t\t\t------------RECORD FOUND------------" << endl;
                cout << "\t\t\t\tstudent's name: " << first << " " << last << endl;
                cout << "\t\t\t\tEnrollment no.: " << enrollment_no << endl;
                cout << "\t\t\t\tEmail address: " << email << endl;
                cout << "\t\t\t\tMobile number: " << mobile_no << endl;
                cout << "\t\t\t\tcourse: " << course << endl;
                cout << "\t\t\t\tRoom number: " << room_number << endl
                     << endl;
                flag = 1;
                break;
            }
            file >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        }
        if (!flag)
        {
            cout << "\t\t\t\t\tNo record found........" << endl;
        }
        file.close();
    }
}

void hostel::modify()
{
    system("cls");
    cout << "\t\t\t---------------------------MODIFY RECORDS---------------------------" << endl;
    cout << "\t\t\t--------------------------------------------------------------------" << endl
         << endl;
    fstream readfile, writefile;
    readfile.open("student record.txt", ios::in);
    if (!readfile)
    {
        cout << "\t\t\t\trecord is empty......." << endl;
        readfile.close();
    }
    else
    {
        string temproll, first, last;
        bool flag = 0;
        cout << "\t\t\t\tEnter the enrollment number of student you want to modify: ";
        cin >> temproll;
        writefile.open("record.txt", ios::app);
        readfile >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        while (!readfile.eof())
        {
            if (enrollment_no == temproll)
            {
                cout << "\t\t\t\t------------CURRENT RECORD------------" << endl;
                cout << "\t\t\t\tstudent's name: " << first << " " << last << endl;
                cout << "\t\t\t\tEnrollment no.: " << enrollment_no << endl;
                cout << "\t\t\t\tEmail address: " << email << endl;
                cout << "\t\t\t\tMobile number: " << mobile_no << endl;
                cout << "\t\t\t\tcourse: " << course << endl;
                cout << "\t\t\t\tRoom number: " << room_number << endl
                     << endl;
                cout << "\t\t\t\t------------SET NEW RECORD------------" << endl;
                cout << "\t\t\t\tStudent's name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\t\tEmail address: ";
                cin >> email;
                cout << "\t\t\t\tMobile number: ";
                cin >> mobile_no;
                cout << "\t\t\t\tCourse: ";
                cin >> course;
                cout << "\t\t\t\tRoom number: ";
                cin >> room_number;
                cout << endl;
                writefile << enrollment_no << " " << first << " " << last << " " << email << " " << mobile_no << " " << course << " " << room_number << endl;
                readfile >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
                flag = 1;
                continue;
            }
            writefile << enrollment_no << " " << first << " " << last << " " << email << " " << mobile_no << " " << course << " " << room_number << endl;
            readfile >> enrollment_no >> first >> last >> email >> mobile_no >> course >> room_number;
        }
        readfile.close();
        writefile.close();
        if (flag)
        {
            cout << "\t\t\t\t\trecord modified successfully........." << endl;
        }
        else
        {
            cout << "\t\t\t\t\tNo record found........" << endl;
        }
        remove("student record.txt");
        rename("record.txt", "student record.txt");
    }
}

int main()
{
    hostel object;
    object.menu();
    return 0;
}