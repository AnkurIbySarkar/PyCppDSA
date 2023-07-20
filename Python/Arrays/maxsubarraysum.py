# Approach 1 - Brute Force
# This function finds the maximum subarray sum using a brute force approach.
# It considers all possible subarrays and computes their sum to find the maximum.
def max_subarray1(nums):
    max_sum = float('-inf')
    subarray = []
    for i in range(len(nums)):
        for j in range(i, len(nums)):
            curr_sum = 0
            for k in range(i, j):
                curr_sum += nums[k]
                if curr_sum > max_sum:
                    # Update the max_sum and store the start and end indices of the subarray
                    subarray = [i, j-1]
                    max_sum = curr_sum
    return max_sum

# Approach 2 - Optimized Brute Force
# This function finds the maximum subarray sum using an optimized brute force approach.
# It optimizes the inner loop by directly calculating the sum of subarrays.


def max_subarray2(nums):
    max_sum = float('-inf')
    subarray = []
    for i in range(len(nums)):
        curr_sum = 0
        for j in range(i, len(nums)):
            # Compute the sum of the subarray using the previously calculated sum and the new element nums[j]
            curr_sum += nums[j]
            if curr_sum > max_sum:
                # Update the max_sum and store the start and end indices of the subarray
                subarray = [i, j]
                max_sum = curr_sum
    return max_sum

# Approach 3 - Kadane's Algorithm
# This function finds the maximum subarray sum using Kadane's Algorithm.
# It efficiently calculates the maximum sum subarray in a single pass through the array.


def max_subarray3(nums):
    max_sum = float('-inf')
    curr_sum = 0
    for num in nums:
        curr_sum += num
        # Keep track of the maximum sum encountered so far
        max_sum = max(curr_sum, max_sum)

        # If the current sum is negative, reset it to 0 as we don't want to include negative sums in the subarray
        if curr_sum < 0:
            curr_sum = 0

    # Handle the case when all elements in the array are negative
    if max_sum < 0:
        max_sum = 0

    return max_sum


def main():
    arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

    # Using Approach 1 - Brute Force
    ans1 = max_subarray1(arr)
    print("Max Subarray Sum (Brute Force):", ans1)

    # Using Approach 2 - Optimized Brute Force
    ans2 = max_subarray2(arr)
    print("Max Subarray Sum (Optimized Brute Force):", ans2)

    # Using Approach 3 - Kadane's Algorithm
    ans3 = max_subarray3(arr)
    print("Max Subarray Sum (Kadane's Algorithm):", ans3)
