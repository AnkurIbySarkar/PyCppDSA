#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Approach 1 - Brute Force
// This function finds the maximum subarray sum using a brute force approach.
// It considers all possible subarrays and computes their sum to find the maximum.
int maxSubarray1(vector<int> &nums)
{
    vector<int> subarray;
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int curr_sum = 0;
            for (int k = i; k < j; k++)
            {
                curr_sum += nums[k];
                if (curr_sum > max_sum)
                {
                    // Update the max_sum and store the start and end indices of the subarray
                    subarray.clear();
                    max_sum = curr_sum;
                    subarray.push_back(i);
                    subarray.push_back(j);
                }
            }
        }
    }
    return max_sum;
}

// Approach 2 - Optimized Brute Force
// This function finds the maximum subarray sum using an optimized brute force approach.
// It optimizes the inner loop by directly calculating the sum of subarrays.
int maxSubarray2(vector<int> &nums)
{
    vector<int> subarray;
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr_sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            // Compute the sum of the subarray using the previously calculated sum and the new element nums[j]
            curr_sum += nums[j];
            if (curr_sum > max_sum)
            {
                // Update the max_sum and store the start and end indices of the subarray
                subarray.clear();
                max_sum = curr_sum;
                subarray.push_back(i);
                subarray.push_back(j);
            }
        }
    }
    return max_sum;
}

// Approach 3 - Kadane's Algorithm
// This function finds the maximum subarray sum using Kadane's Algorithm.
// It efficiently calculates the maximum sum subarray in a single pass through the array.
int maxSubarray3(vector<int> &nums)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (auto i : nums)
    {
        sum += i;
        // Keep track of the maximum sum encountered so far
        maxi = max(sum, maxi);

        // If the current sum is negative, reset it to 0 as we don't want to include negative sums in the subarray
        if (sum < 0)
            sum = 0;
    }
    // Handle the case when all elements in the array are negative
    if (maxi < 0)
    {
        maxi = 0;
    }
    return maxi;
}

int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Using Approach 1 - Brute Force
    int ans1 = maxSubarray1(arr);
    cout << "Max Subarray Sum (Brute Force): " << ans1 << endl;

    // Using Approach 2 - Optimized Brute Force
    int ans2 = maxSubarray2(arr);
    cout << "Max Subarray Sum (Optimized Brute Force): " << ans2 << endl;

    // Using Approach 3 - Kadane's Algorithm
    int ans3 = maxSubarray3(arr);
    cout << "Max Subarray Sum (Kadane's Algorithm): " << ans3 << endl;
}