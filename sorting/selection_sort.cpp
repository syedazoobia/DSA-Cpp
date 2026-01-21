// SELECTION SORT
#include <iostream>
using namespace std;
int main()
{
    int input[10] = {45, 65, 35, 7, 3, 54, 23, 43, 78, 1};
    int i, j, min, temp;

    for (j = 0; j < 9; j++)
    {
        min = j;
        for (i = j + 1; i < 10; i++)
        {

            if (input[min] > input[i])
            {
                min = i;
            }
        }

        temp = input[j];
        input[j] = input[min];
        input[min] = temp;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << input[i] << ", ";
    }

    return 0;
}