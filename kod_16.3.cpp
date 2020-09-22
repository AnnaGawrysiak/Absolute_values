/*
P = 1, różnica = |3 − 10| = 7
P = 2, różnica = |4 − 9| = 5
P = 3, różnica = |6 − 7| = 1
P = 4, różnica = |10 − 3| = 7
*/

#include <iostream>

using namespace std;

int minimum_value(int arr[], int const dimension);

int main()
{
    int const size = 5;

    int arr[size] = {3, 1, 2, 4, 3};

    cout << "Minimum difference that can be obtained: " << minimum_value(arr, size) << endl;

    return 0;
}

int minimum_value(int arr[], int const dimension)
{
    int left_range[dimension-1];
    int right_subset[dimension-1];
    int absolute_values[dimension-1];

    int initial_part = 0;

    int sum = 0;

   for (int i = 0; i < (dimension); i++)
        {
            sum = sum + arr[i];
        }

        int second_part = sum;

    for (int i = 0; i < (dimension-1); i++)
    {
        initial_part = initial_part + arr[i];
        left_range[i] = initial_part;
        second_part = second_part - arr[i];
        right_subset[i] = second_part;
        absolute_values[i] = abs(right_subset[i] - left_range[i]);
    }

    int the_lowest_value = absolute_values[0];

    for (int l = 0; l < (dimension-2); l++)
    {
        if (absolute_values[l] > absolute_values[l+1])
            the_lowest_value = absolute_values[l+1];
    }

    return the_lowest_value;
}
