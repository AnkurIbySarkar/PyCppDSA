#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the largest element in an array using max_element function
int findLargestElement(int arr[], int n)
{
    int *ans = max_element(arr, arr + n);
    return *ans;
}

// Function to find the largest element in an array using sorting
int findLargestElementSorting(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[n - 1];
}

// Function to find the largest element in an array using linear comparison
int findLargestElementLinear(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

// Function to find the smallest element in an array using min_element function
int findSmallestElement(int arr[], int n)
{
    int *ans = min_element(arr, arr + n);
    return *ans;
}

// Function to find the smallest element in an array using sorting
int findSmallestElementSorting(int arr[], int n)
{
    sort(arr, arr + n);
    return arr[0];
}

// Function to find the smallest element in an array using linear comparison
int findSmallestElementLinear(int arr[], int n)
{
    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }
    return mini;
}

int main()
{
    int arr1[] = {2, 5, 1, 3, 0};
    int n = 5;
    int max = findLargestElement(arr1, n);
    int min = findSmallestElement(arr1, n);
    cout << "The largest element in the array is: " << max << endl;
    cout << "The smallest element in the array is: " << min << endl;

    int arr2[] = {8, 10, 5, 7, 9};
    n = 5;
    max = findLargestElement(arr2, n);
    min = findSmallestElement(arr2, n);
    cout << "The largest element in the array is: " << max << endl;
    cout << "The smallest element in the array is: " << min << endl;

    return 0;
}