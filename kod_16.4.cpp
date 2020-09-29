/*
P = 1, różnica = |3 − 10| = 7
P = 2, różnica = |4 − 9| = 5
P = 3, różnica = |6 − 7| = 1
P = 4, różnica = |10 − 3| = 7
*/

#include <iostream>
#include <algorithm>    // std::min_element, std::max_element

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
    int left_range = 0;
    int right_subset = 0;
    int absolute_values[dimension-1];

    int initial_part = 0;

    int second_part = 0;

   for (int i = 0; i < (dimension); i++)
        {
             second_part =  second_part + arr[i];
        }

    for (int i = 0; i < (dimension-1); i++)
    {
        initial_part = initial_part + arr[i];
        left_range = initial_part;
        second_part = second_part - arr[i];
        right_subset = second_part;
        absolute_values[i] = abs(right_subset - left_range);
    }

    int the_lowest_value = absolute_values[0];

    the_lowest_value = * min_element( absolute_values, absolute_values + dimension );

    return the_lowest_value;
}

