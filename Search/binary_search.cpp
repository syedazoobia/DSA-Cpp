// BINARY SEARCH
#include <iostream>
using namespace std;

int main()
{
    int input[10] = {20, 28, 28, 28, 49, 56, 59, 61, 65, 78};
    int left, right, tosearch, mid;
    int flag = 0;

    cout << "\nENTER THE NUMBER TO FIND: ";
    cin >> tosearch;

    left = 0;
    right = 9;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (tosearch == input[mid])
        {
            flag = 1;
            cout << "FOUND AT INDEX: " << mid << endl;
            break;
        }
        else if (tosearch > input[mid])
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
