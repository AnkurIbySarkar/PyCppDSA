#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Find the kth smallest and kth largest elements using sorting:nlogn
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> ans;
    sort(arr.begin(), arr.end()); // Sort the array in ascending order

    ans.push_back(arr[k - 1]); // Store the kth smallest element
    ans.push_back(arr[n - k]); // Store the kth largest element
    return ans;                // Return the results
}

// minHeap, MaxHeap n *logk
vector<int>
kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> ans;
    // Write your code here.

    if (k < 0 || k >= n)
    {
        return ans; // Return empty vector if k is invalid
    }

    // Create a min-heap to find the kth smallest element
    // Create a min-heap to find the kth smallest element
    priority_queue<int> min_pq;
    for (auto x : arr)
    {
        min_pq.push(x);
        if (min_pq.size() > k)
        {
            min_pq.pop();
        }
    }
    ans.push_back(min_pq.top());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x : arr)
    {
        pq.push(x);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    ans.push_back(pq.top());
    return ans;
}

// Quickselect :O(n)
// Code chunk 1: Partition the array around a pivot element
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        { // Move i until arr[i] > pivot or end of array
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        { // Move j until arr[j] <= pivot or start of array
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]); // Swap elements at i and j
        }
    }

    swap(arr[low], arr[j]); // Swap pivot element with jth element
    return j;               // Return the partition position
}

// Code chunk 2: Perform quickselect algorithm to find the kth smallest or kth largest element
int quickselect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high); // Find the pivot index

        if (pivotIndex == k)
        {
            return arr[pivotIndex]; // Return the pivot element if it is the kth element
        }
        else if (pivotIndex < k)
        {
            return quickselect(arr, pivotIndex + 1, high, k); // Recursively search in the right subarray
        }
        else
        {
            return quickselect(arr, low, pivotIndex - 1, k); // Recursively search in the left subarray
        }
    }

    return -1; // Return -1 if k is out of range
}

// Code chunk 3: Find the kth smallest and kth largest elements using quickselect
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> ans;
    int smallest = quickselect(arr, 0, n - 1, k - 1); // Find the kth smallest element
    int largest = quickselect(arr, 0, n - 1, n - k);  // Find the kth largest element
    ans.push_back(smallest);                          // Store the kth smallest element
    ans.push_back(largest);                           // Store the kth largest element
    return ans;                                       // Return the results
}

int main()
{
    // Example usage
    vector<int> arr = {4, 2, 9, 1, 7};
    int n = arr.size();
    int k = 2;

    vector<int> result = kthSmallLarge(arr, n, k);

    if (result.empty())
    {
        cout << "Invalid k value." << endl;
    }
    else
    {
        cout << "Kth smallest element: " << result[0] << endl;
        cout << "Kth largest element: " << result[1] << endl;
    }

    return 0;
}