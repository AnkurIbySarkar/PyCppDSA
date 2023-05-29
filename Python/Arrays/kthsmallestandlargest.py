import heapq


def kth_smallest_largest(nums, k):
    # Sort the list in ascending order
    sorted_nums = sorted(nums)

    # Return the kth smallest and largest elements
    return sorted_nums[k-1], sorted_nums[-k]


def kth_smallest_largest(arr, k):
    # Create a min heap of the first k elements
    min_heap = arr[:k]
    heapq.heapify(min_heap)

    # Find the kth largest element
    for num in arr[k:]:
        if num > min_heap[0]:
            heapq.heappop(min_heap)
            heapq.heappush(min_heap, num)
    kth_largest = min_heap[0]

    # Create a max heap of the first k elements (negated)
    max_heap = [-num for num in arr[:k]]
    heapq.heapify(max_heap)

    # Find the kth smallest element
    for num in arr[k:]:
        if num < -max_heap[0]:
            heapq.heappop(max_heap)
            heapq.heappush(max_heap, -num)
    kth_smallest = -max_heap[0]

    return kth_smallest, kth_largest


# Partition the array around a pivot element
def partition(arr, low, high):
    pivot = arr[low]
    i = low
    j = high
    while i < j:
        while arr[i] <= pivot and i <= high - 1:
            i += 1
        while arr[j] > pivot and j >= low + 1:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[j] = arr[j], arr[low]
    return j

# Perform quickselect algorithm to find the kth smallest or kth largest element


def quickselect(arr, low, high, k):
    if low <= high:
        pivotIndex = partition(arr, low, high)
        if pivotIndex == k:
            return arr[pivotIndex]
        elif pivotIndex < k:
            return quickselect(arr, pivotIndex + 1, high, k)
        else:
            return quickselect(arr, low, pivotIndex - 1, k)
    return -1

# Find the kth smallest and kth largest elements in the array


def kth_smallest_largest(arr, k):
    n = len(arr)
    smallest = quickselect(arr, 0, n - 1, k - 1)
    largest = quickselect(arr, 0, n - 1, n - k)
    return smallest, largest


# Test the function
arr = [4, 2, 9, 1, 7]
k = 2
kth_smallest, kth_largest = kth_smallest_largest(arr, k)
print(f"The {k}th smallest element is: {kth_smallest}")
print(f"The {k}th largest element is: {kth_largest}")

arr = [4, 2, 9, 1, 7]
k = 2
kth_smallest, kth_largest = kth_smallest_largest(arr, k)
print(f"The {k}th smallest element is: {kth_smallest}")
print(f"The {k}th largest element is: {kth_largest}")
