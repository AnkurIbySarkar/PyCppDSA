#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimizeIt(vector<int> arr, int K)
{
    // Get the size of the input array
    int n = arr.size();

    // Sort the array in ascending order
    sort(arr.begin(), arr.end());

    // Initialize variables to track maximum, minimum, and minimum difference
    int maxi = arr[n - 1];
    int mini = arr[0];
    int ans = arr[n - 1] - arr[0];

    // Iterate over the array
    for (int i = 1; i < n; i++)
    {
        // Skip elements if the difference with K is negative
        if (arr[i] - K < 0)
            continue;

        // Update maximum and minimum values within the range
        maxi = max(arr[i - 1] + K, arr[n - 1] - K);
        mini = min(arr[0] + K, arr[i] - K);

        // Update the minimum difference
        ans = min(ans, maxi - mini);
    }

    // Return the minimum difference
    return ans;
}
int main()
{
    std::vector<int> arr = {10, 7, 3, 6, 4, 8, 1};
    int K = 2;

    int result = minimizeIt(arr, K);

    cout << "Minimum Difference: " << result << endl;

    return 0;
}