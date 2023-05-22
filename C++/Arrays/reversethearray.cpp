#include <iostream>
#include <algorithm>

using namespace std;

// Function to reverse the array in-place
void reverseArray(int arr[], int size)
{
    int start = 0, end = size - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++, end--;
    }
}

int main()
{
    // Array initialization
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Output the original array
    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reverse the array using std::reverse function
    reverse(arr, arr + size);

    reverseArray(arr, size);
    // Output the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}