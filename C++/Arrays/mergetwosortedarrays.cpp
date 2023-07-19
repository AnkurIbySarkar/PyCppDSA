#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to merge two sorted arrays nums1 and nums2 into nums1
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums3; // Temporary vector to store the merged result

    int left = 0, right = 0, index = 0; // Pointers for iterating through nums1, nums2, and nums3

    // Compare elements from nums1 and nums2, and store the smaller element in nums3
    while (left < n && right < m)
    {
        if (nums1[left] <= nums2[right])
        {
            nums3[index] = nums1[left];
            left++, index++;
        }
        else
        {
            nums3[index++] = nums2[right++];
            right++, index++;
        }
    }

    // Copy any remaining elements from nums1 or nums2 to nums3
    while (left < n)
    {
        nums3[index++] = nums1[left++];
    }
    while (right < m)
    {
        nums3[index++] = nums2[right++];
    }

    // Copy elements from nums3 back to nums1 and nums2
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            nums1[i] = nums3[i];
        else
            nums2[i - n] = nums3[i];
    }
}

// Alternative implementation of merge function
void merge(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int left = n - 1, right = 0;

    // Compare elements from arr1 and arr2, and swap if necessary to maintain sorted order
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    // Sort the modified arr1 and arr2
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

// Helper function to swap elements if the first element is greater than the second
void swapIfGreater(vector<int> &ar1, vector<int> &ar2, int ind1, int ind2)
{
    if (ar1[ind1] > ar2[ind2])
    {
        swap(ar1[ind1], ar2[ind2]);
    }
}

// Improved merge function using the gap method for merging two sorted arrays
void merge(vector<int> &ar1, vector<int> &ar2)
{
    int n = ar1.size();
    int m = ar2.size();
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        // Compare elements based on the gap and swap if necessary
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapIfGreater(ar1, ar2, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swapIfGreater(ar2, ar2, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(ar1, ar1, left, right);
            }
            left++, right++;
        }

        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    vector<int> v1{1, 2, 3};
    int m = 3;
    vector<int> v2{2, 5, 6};
    int n = 3;

    merge(v1, m, v2, n);

    // Print the elements of v1 and v2 after merging
    for (auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : v2)
    {
        cout << i << " ";
    }

    return 0;
}