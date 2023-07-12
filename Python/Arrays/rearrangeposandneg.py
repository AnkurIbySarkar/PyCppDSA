from os import *
from sys import *
from collections import *
from math import *


def separateNegativeAndPositive(nums):
    nums.sort()  # Sort the numbers in ascending order
    return nums  # Return the sorted list
    pass


def separateNegativeAndPositive(nums):
    i = 0  # Pointer for the beginning of the list
    j = len(nums) - 1  # Pointer for the end of the list

    while i < j:  # Continue until the pointers meet or cross each other
        if nums[i] >= 0 and nums[j] < 0:
            # If the number at position i is positive and the number at position j is negative,
            # swap their positions to move negative numbers to the left and positive numbers to the right
            nums[i], nums[j] = nums[j], nums[i]
            i += 1  # Move the left pointer one step forward
            j -= 1  # Move the right pointer one step backward

        if nums[i] < 0:
            i += 1  # If the number at position i is already negative, move the left pointer one step forward

        if nums[j] >= 0:
            j -= 1  # If the number at position j is already positive, move the right pointer one step backward

    return nums  # Return the modified list


nums = [1, -4, -2, 5, 3]
ans = separateNegativeAndPositive(nums)
print(ans)
