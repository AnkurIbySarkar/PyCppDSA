#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = INT_MIN; // Variable to store the maximum subarray sum encountered so far
    for (int i = 0; i < n; i++)
    {
        long long sum = 0; // Variable to keep track of the current sum of subarray elements
        for (int j = i; j < n; j++)
        {
            sum += arr[j];         // Add the current element to the sum
            maxi = max(maxi, sum); // Update the maximum subarray sum if necessary
        }
        maxi = max(maxi, 0LL); // Consider the sum of an empty subarray as 0 and update the maximum sum
    }

    return maxi; // Return the maximum subarray sum
}
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;        // Variable to keep track of the current sum of subarray elements
    long long maxi = INT_MIN; // Variable to store the maximum subarray sum encountered so far

    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // Add the current element to the sum

        maxi = max(sum, maxi); // Update the maximum subarray sum if necessary

        if (sum < 0)
            sum = 0; // If the sum becomes negative, reset it to 0
        if (maxi < 0)
        {
            maxi = 0; // If the maximum sum becomes negative, reset it to 0
        }
    }

    return maxi; // Return the maximum subarray sum
}

int main()
{
    int arr[] = {-2, 3, -1, 5, 4, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long maxSum = maxSubarraySum(arr, n);
    cout << "Maximum subarray sum: " << maxSum << endl;

    return 0;
}