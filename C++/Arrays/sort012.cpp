#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sorting - O(nlogn)
void sortArray(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end()); // Sort the array using the built-in sort function
}

// Counting - O(2n)
void sortArray(vector<int> &arr, int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++) // Fill the array with 0s, followed by 1s, and then 2s
        arr[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1;
    for (int i = cnt0 + cnt1; i < cnt0 + cnt1 + cnt2; i++)
        arr[i] = 2;
}

// Dutch flag algorithm - O(n)
void sortArray(vector<int> &arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0) // If the current element is 0, swap it with the element at the 'low' index
        {
            swap(arr[low], arr[mid]);
            low++, mid++;
        }
        else if (arr[mid] == 1) // If the current element is 1, move to the next element
        {
            mid++;
        }
        else // If the current element is 2, swap it with the element at the 'high' index
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
