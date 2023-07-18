def findDuplicate(arr):
    # Write your code here
    n = len(arr)
    for i in range(0, n):
        for j in range(i+1, n):
            if arr[i] == arr[j]:
                return arr[i]
    return -1
    pass


def findDuplicate(arr):
    # Write your code here
    n = len(arr)
    list1 = [0]*n
    for i in range(0, n):
        list1[arr[i]] += 1

    for i in range(0, n):
        if list1[i] > 1:
            return i
    return -1
    pass


def findDuplicate(arr):
    n = len(arr)
    ans = 0
    for i in range(0, n):
        ans = ans ^ arr[i]

    for i in range(0, n):
        ans = ans ^ i
    return ans
    pass


# Example test case
arr = [1, 2, 3, 4, 4]
result = findDuplicate(arr)
if result != -1:
    print(f"Duplicate number: {result}")
else:
    print("No duplicate found.")
