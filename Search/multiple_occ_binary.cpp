#include <iostream>
using namespace std;

int main()
{
    int input[10] = {20, 22, 23, 24, 28, 28, 28, 59, 61, 78};
    int left, right, tosearch, mid, flag;

    left = 0;
    right = 9;
    flag = 0;

    cout << "\nENTER THE NUMBER TO FIND: ";
    cin >> tosearch;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (input[mid] == tosearch)
        {
            flag = 1;
            int i = mid;
            while (i >= 0 && input[i] == tosearch)
            {
                cout << "FOUND AT INDEX: " << i << endl;
                i--;
            }
            i = mid + 1;
            while (i <= 9 && input[i] == tosearch)
            {
                cout << "FOUND AT INDEX: " << i << endl;
                i++;
            }
            break;
        }
        else if (input[mid] < tosearch)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (flag == 0)
    {
        cout << "NOT FOUND" << endl;
    }

    return 0;
}