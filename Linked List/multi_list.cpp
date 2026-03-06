#include <iostream>
#include <cstdlib>
using namespace std;

struct s_node
{
    int seat_no;
    s_node *next;
};

struct c_node
{
    int course_no;
    c_node *next;
    s_node *std_list;
};

c_node *course_list = NULL;

void insert_course(int c_no)
{
    c_node *newnode = new c_node;
    newnode->course_no = c_no;
    newnode->next = NULL;
    newnode->std_list = NULL;

    if (course_list == NULL)
    {
        course_list = newnode;
    }
    else
    {
        c_node *current = course_list;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newnode;
    }
}

void delete_course(int no)
{
    if (course_list == NULL)
    {
        cout << "course list is empty";
        return;
    }

    c_node *temp = course_list;
    if (temp->course_no == no)
    {
        course_list = course_list->next;
        cout << "DELETE SUCCESSFULLY";
        delete (temp);
        return;
    }

    c_node *prev = course_list;
    temp = course_list->next;

    while (temp != NULL)
    {
        if (no == temp->course_no)
        {
            prev->next = temp->next;
            delete (temp);
            cout << "DELETE SUCCESSFULLY";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "VALUE DOES NOT EXIST";
}

void search_course(int no)
{
    if (course_list == NULL)
    {
        cout << "COURSE LIST IS EMPTY";
        return;
    }

    c_node *temp = course_list;

    while (temp != NULL)
    {
        if (no == temp->course_no)
        {
            cout << "course found";
            return;
        }
        temp = temp->next;
    }
    cout << "course not found";
}

void display_course()
{
    if (course_list == NULL)
    {
        cout << "course list is empty";
        return;
    }

    c_node *temp = course_list;
    while (temp != NULL)
    {
        cout << temp->course_no << "   ";
        temp = temp->next;
    }
}

void insert_student(int seat_no, int c_no)
{
    c_node *course_current = course_list;

    while (course_current != NULL)
    {
        if (c_no == course_current->course_no)
        {
            s_node *newnode = new s_node;
            newnode->seat_no = seat_no;
            newnode->next = NULL;

            if (course_current->std_list == NULL)
            {
                course_current->std_list = newnode;
            }
            else
            {
                s_node *std_current = course_current->std_list;

                while (std_current->next != NULL)
                {
                    std_current = std_current->next;
                }
                std_current->next = newnode;
            }
            return;
        }
        course_current = course_current->next;
    }
}

void delete_std_course(int seat, int course)
{
    if (course_list == NULL)
    {
        cout << "course list is empty";
        return;
    }

    c_node *course_current = course_list;
    while (course_current != NULL && course_current->course_no != course)
    {
        course_current = course_current->next;
    }

    if (course_current == NULL)
    {
        cout << "Course not found!" << endl;
        return;
    }

    s_node *std_current = course_current->std_list;
    s_node *prev = NULL;

    while (std_current != NULL)
    {
        if (std_current->seat_no == seat)
        {
            if (prev == NULL)
            {
                course_current->std_list = std_current->next;
            }
            else
            {
                prev->next = std_current->next;
            }

            delete std_current;
            cout << "Student deleted successfully from Course " << course << "!" << endl;
            return;
        }

        prev = std_current;
        std_current = std_current->next;
    }

    cout << "Student not found in this course!" << endl;
}

void delete_std(int seat)
{
    if (course_list == NULL)
    {
        cout << "course list is empty";
        return;
    }

    c_node *course_current = course_list;

    while (course_current != NULL)
    {
        s_node *std_current = course_current->std_list;
        s_node *prev = NULL;

        while (std_current != NULL)
        {

            if (std_current->seat_no == seat)
            {
                if (prev == NULL)
                {
                    course_list->std_list = std_current->next;
                }
                else
                {
                    prev->next = std_current->next;
                }
                delete (std_current);
                cout << "Student deleted successfully" << endl;
                return;
            }
            prev = std_current;
            std_current = std_current->next;
        }
        course_current = course_current->next;
    }
    cout << "Student not found";
}

void search_std_course(int seat, int course)
{
    if (course_list == NULL)
    {
        cout << "course list is empty";
        return;
    }

    c_node *course_current = course_list;
    while (course_current != NULL && course_current->course_no != course)
    {
        course_current = course_current->next;
    }

    if (course_current == NULL)
    {
        cout << "Course not found!" << endl;
        return;
    }

    s_node *std_current = course_current->std_list;

    while (std_current != NULL)
    {
        if (std_current->seat_no == seat)
        {
            cout << "Student found in this Course " << course << "!" << endl;
            return;
        }
        std_current = std_current->next;
    }

    cout << "Student not found in this course!" << endl;
}

void search_std(int seat)
{

    if (course_list == NULL)
    {
        cout << "Course list is empty!" << endl;
        return;
    }

    c_node *course_current = course_list;

    while (course_current != NULL)
    {
        s_node *std_current = course_current->std_list;
        while (std_current != NULL)
        {
            if (std_current->seat_no == seat)
            {
                cout << "Student found!" << endl;
                cout << "Enrolled in Course: " << course_current->course_no << endl;
                return;
            }
            std_current = std_current->next;
        }
        course_current = course_current->next;
    }

    cout << "Student not found!" << endl;
}

void display_std_course(int course)
{
    if (course_list == NULL)
    {
        cout << "Course list is empty!" << endl;
        return;
    }
    c_node *course_current = course_list;
    while (course_current != NULL && course_current->course_no != course)
    {
        course_current = course_current->next;
    }

    if (course_current == NULL)
    {
        cout << "Course not found!" << endl;
        return;
    }
    s_node *std_current = course_current->std_list;
    if (std_current == NULL)
    {
        cout << "No students enrolled in this course!" << endl;
        return;
    }
    cout << "Student list of Course " << course << ":" << endl;
    while (std_current != NULL)
    {
        cout << "Seat No: " << std_current->seat_no << endl;
        std_current = std_current->next;
    }
}

void display_all()
{
    if (course_list == NULL)
    {
        cout << "LIST IS EMPTY";
        return;
    }

    c_node *temp = course_list;

    while (temp != NULL)
    {
        cout << "CS-" << temp->course_no << "\t";

        s_node *std = temp->std_list;

        while (std != NULL)
        {
            cout << std->seat_no << "\t";
            std = std->next;
        }

        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    int sel, flag = 0, num, seat, course;

    while (flag == 0)
    {
        cout << "\n\nSELECT FROM MENU" << endl
             << "1. Add a Course" << endl
             << "2. Delete a course" << endl
             << "3. Search a course" << endl
             << "4. Display list of a course" << endl
             << "5. Add a Student" << endl
             << "6. Delete a std from course" << endl
             << "7. Delete a student" << endl
             << "8. Search a student in a course" << endl
             << "9. Search a student" << endl
             << "10. Display student list of a course" << endl
             << "11. Display ALL" << endl
             << "12. Exit" << endl
             << "Enter the number (1-12): ";
        cin >> sel;

        switch (sel)
        {
        case 1:
            cout << "\nEnter course number to insert: ";
            cin >> num;
            insert_course(num);
            break;

        case 2:
            cout << "\nEnter course number to delete: ";
            cin >> num;
            delete_course(num);
            break;

        case 3:
            cout << "\nEnter course number to search: ";
            cin >> num;
            search_course(num);
            break;

        case 4:
            cout << "\nDISPLAY COURSE LIST\n";
            display_course();
            break;

        case 5:
            cout << "\nEnter student seat number: ";
            cin >> seat;
            cout << "Enter course number: ";
            cin >> course;
            insert_student(seat, course);
            break;

        case 6:
            cout << "\nEnter Student seat no to delete: ";
            cin >> seat;
            cout << "\nEnter course no: ";
            cin >> course;
            delete_std_course(seat, course);
            break;

        case 7:
            cout << "\nEnter seat no to delete: ";
            cin >> seat;
            delete_std(seat);
            break;

        case 8:
            cout << "\nEnter seat no to search: ";
            cin >> seat;
            cout << "\nEnter course no: ";
            cin >> course;
            search_std_course(seat, course);
            break;

        case 9:
            cout << "\nEnter seat no to search: ";
            cin >> seat;
            search_std(seat);
            break;

        case 10:
            cout << "\nDISPLAY STUDENT LIST OF A COURSE: ";
            cin >> course;
            display_std_course(course);
            break;

        case 11:
            cout << "\nDISPLAY ALL COURSES WITH STUDENTS\n";
            display_all();
            break;

        case 12: // Exit
            flag = 1;
            cout << "\nProgram exiting...";
            break;

        default:
            cout << "\nInvalid choice. Please try again.";
        }
    }
    return 0;
}
