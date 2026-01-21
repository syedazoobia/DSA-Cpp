// MULTIPLE OCCURENCE LINEAR SEARCH
#include <iostream>
using namespace std;
int main()
{
    int input[10] = {23, 28, 87, 28, 89, 65, 45, 28, 87, 89};
    int tosearch, i, flag = 0;

    cout << "\nENTER THE NUMBER TO FIND: ";
    cin >> tosearch;

    for (int i = 0; i < 10; i++)
    {
        if (tosearch == input[i])
        {
            flag = 1;
            cout << "FOUND AT INDEX:  " << i << endl;
        }
    }

    if (flag == 0)
    {
        cout << "NOT FOUND" << endl;
    }
}
