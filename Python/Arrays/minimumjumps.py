# Recursive solution
def minimum_jumps_recursive(arr, pos):
    n = len(arr)
    # Base case: If the current position is the last index, no jumps are needed
    if pos == n - 1:
        return 0

    # If the current position is unreachable, return -1
    if arr[pos] == 0:
        return -1

    min_jumps = float('inf')

    # Recursively try all possible jumps from the current position
    for i in range(1, arr[pos] + 1):
        if pos + i < n:
            jumps = minimum_jumps_recursive(arr, pos + i)
            if jumps != -1:
                min_jumps = min(min_jumps, jumps + 1)

    return -1 if min_jumps == float('inf') else min_jumps


# Memoization solution
def minimum_jumps_memoization(arr):
    n = len(arr)
    # Create a DP table to store intermediate results
    dp = [-1] * n

    def helper(pos):
        nonlocal dp
        # Base case: If the current position is the last index, no jumps are needed
        if pos == n - 1:
            return 0

        # If the current position is unreachable, return -1
        if arr[pos] == 0:
            return -1

        # If the result for the current position is already calculated, return it
        if dp[pos] != -1:
            return dp[pos]

        min_jumps = float('inf')

        # Recursively try all possible jumps from the current position
        for i in range(1, arr[pos] + 1):
            if pos + i < n:
                jumps = helper(pos + i)
                if jumps != -1:
                    min_jumps = min(min_jumps, jumps + 1)

        # Store the calculated result in the DP table for future use
        dp[pos] = -1 if min_jumps == float('inf') else min_jumps
        return dp[pos]

    # Call the helper function with the initial position 0
    return helper(0)


# Tabulation solution
def minimum_jumps_tabulation(arr):
    n = len(arr)
    # Create a DP table to store the minimum jumps required to reach each index
    dp = [float('inf')] * n

    # Initialize the base case: no jumps are needed to reach the first index
    dp[0] = 0

    # Traverse through each index starting from the second index
    for i in range(1, n):
        # Check all possible previous indices that can jump to the current index
        for j in range(i):
            # If the previous index is reachable and its minimum jumps value is valid
            if j + arr[j] >= i and dp[j] != float('inf'):
                # Update the minimum jumps required to reach the current index
                dp[i] = min(dp[i], dp[j] + 1)

    # Return -1 if the last index is unreachable, else return the minimum jumps required to reach it
    return -1 if dp[n - 1] == float('inf') else dp[n - 1]


# Space-optimized Tabulation solution
def minimum_jumps_space_optimized(arr):
    n = len(arr)
    if n <= 1:
        return 0

    max_reach = arr[0]  # Maximum reachable index from the current position
    steps = arr[0]  # Steps remaining at the current position
    jumps = 1  # Minimum jumps required

    for i in range(1, n):
        if steps == 0:
            return -1  # Return -1 if the current position is unreachable

        if i == n - 1:
            return jumps  # Return the minimum jumps required

        max_reach = max(max_reach, i + arr[i])
        steps -= 1

        if steps == 0:
            jumps += 1

            if i >= max_reach:
                return -1  # Return -1 if the current position is unreachable

            steps = max_reach - i

    return -1


# Test case
arr = [0, 1, 2, 3, 4]
result_recursive = minimum_jumps_recursive(arr, 0)
result_memoization = minimum_jumps_memoization(arr)
result_tabulation = minimum_jumps_tabulation(arr)
result_space_optimized = minimum_jumps_space_optimized(arr)

print("Recursive: ", result_recursive)  # Output: -1
print("Memoization: ", result_memoization)  # Output: -1
print("Tabulation: ", result_tabulation)  # Output: -1
print("Space-optimized: ", result_space_optimized)  # Output: -1
