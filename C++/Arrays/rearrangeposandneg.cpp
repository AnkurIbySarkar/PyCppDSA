#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    // Sort the vector in ascending order
    sort(nums.begin(), nums.end());

    // Return the sorted vector
    return nums;
}
vector<int> separateNegativeAndPositive(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;

    // Use two pointers to separate negative and positive integers
    while (i < j)
    {
        if (nums[i] >= 0 && nums[j] < 0)
        {
            // Swap the elements if i-th element is positive and j-th element is negative
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        // Increment i if the i-th element is already negative
        if (nums[i] < 0)
        {
            i++;
        }

        // Decrement j if the j-th element is already positive
        if (nums[j] >= 0)
        {
            j--;
        }
    }

    // Return the updated vector with negative and positive integers separated
    return nums;
}
int main()
{
    vector<int> nums = {1, -4, -2, 5, 3};
    vector<int> ans = separateNegativeAndPositive(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}