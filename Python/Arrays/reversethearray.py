arr = [1, 2, 3, 4, 5]
# Reverse the array using slice notation
reversed_arr = arr[::-1]

# Output the original array
print("Original array:", arr)

# Output the reversed array
print("Reversed array:", reversed_arr)


arr = [1, 2, 3, 4, 5]
arr.reverse()

print("Reversed array:", arr)

def reverse_array(arr):
    # Calculate the size of the array
    size = len(arr)
    
    # Iterate over the array elements up to the midpoint
    for i in range(size // 2):
        # Swap elements at symmetric positions
        arr[i], arr[size - 1 - i] = arr[size - 1 - i], arr[i]

arr = [1, 2, 3, 4, 5]
reversed_arr = reverse_array(arr)
print("Reversed array:", reversed_arr)