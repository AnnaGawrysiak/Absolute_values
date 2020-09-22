#include <iostream>
#include <cmath>

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

    int initial_part = 0;
    int second_part = 0;

    for (int i = 0; i < (dimension-1); i++)
    {
        initial_part = initial_part + arr[i];
        left_range[i] = initial_part;
    }


    for (int j = 1; j < dimension; j++)
       {

           for (int k = j; k < dimension; k++)
           {
                second_part = second_part + arr[k];
           }

         right_subset[j-1] = second_part;
         second_part = 0;
       }

    int absolute_values[dimension-1];


    for (int p = 0; p < (dimension-1); p++)
    {
            absolute_values[p] = abs(right_subset[p] - left_range[p]);
    }


    for (int i = 0; i < (dimension-1); i++)
    {
       cout << "Absolute values: " << absolute_values[i] << endl;
    }

    int the_lowest_value = absolute_values[0];

    for (int l = 0; l < (dimension-2); l++)
    {
        if (absolute_values[l] > absolute_values[l+1])
            the_lowest_value = absolute_values[l+1];
    }

    return the_lowest_value;
}
