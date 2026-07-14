#include <iostream>
using namespace std;

int array[] = {34, 56, 43, 67, 32, 78, 32, 56, 32, 1};
int pivot_index;

int setpivot(int left, int right)
{
    pivot_index = (left + right) / 2;

    while (left < right)
    {

        while (pivot_index > left)

        {
            if (array[pivot_index] < array[left])
            {
                swap(array[pivot_index], array[left]);
                pivot_index = left;
                break;
            }
            else
            {
                left++;
            }
        }

        while (pivot_index < right)
        {
            if (array[pivot_index] > array[right])
            {
                swap(array[pivot_index], array[right]);
                pivot_index = right;
                break;
            }
            else
            {
                right--;
            }
        }
    }
    return pivot_index;
}

void quick_sort(int left, int right)
{
    if (left < right)
    {
        pivot_index = setpivot(left, right);
        quick_sort(left, pivot_index - 1);
        quick_sort(pivot_index + 1, right);
    }
}

void display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << "   ";
    }
}

int main()
{
    cout << "\nORIGINAL ARRRAY\n";
    display();

    cout << "\nSORTING ARRAY\n";
    quick_sort(0, 9);
    display();

    return 0;
}