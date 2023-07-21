def merge_intervals(intervals):
    intervals.sort()  # Sort the intervals based on the start time

    merged_intervals = []

    for interval in intervals:
        start, end = interval[0], interval[1]

        # If the current interval is completely inside the last interval in 'merged_intervals', skip it
        if merged_intervals and end <= merged_intervals[-1][1]:
            continue

        # Merge overlapping intervals
        for j in range(len(merged_intervals) - 1, -1, -1):
            if merged_intervals[j][1] >= start:
                start = merged_intervals[j][0]
                end = max(end, merged_intervals[j][1])
            else:
                break

        # Add the merged interval (start, end) to 'merged_intervals'
        merged_intervals.append([start, end])

    return merged_intervals


def merge_intervals(intervals):
    intervals.sort()  # Sort the intervals based on the start time

    merged_intervals = []

    for interval in intervals:
        start, end = interval[0], interval[1]

        # If the current interval is completely inside the last interval in 'merged_intervals', skip it
        if merged_intervals and end <= merged_intervals[-1][1]:
            continue

        # Merge overlapping intervals
        for j in range(len(merged_intervals) - 1, -1, -1):
            if merged_intervals[j][1] >= start:
                start = merged_intervals[j][0]
                end = max(end, merged_intervals[j][1])
            else:
                break

        # Add the merged interval (start, end) to 'merged_intervals'
        merged_intervals.append([start, end])

    return merged_intervals


def print_intervals(intervals):
    for interval in intervals:
        print(f"[{interval[0]}, {interval[1]}]", end=" ")
    print()


if __name__ == "__main__":
    intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]

    print("Original Intervals:", end=" ")
    print_intervals(intervals)

    # Merge overlapping intervals and store the result in 'merged_intervals'
    merged_intervals = merge_intervals(intervals)

    print("Merged Intervals:", end=" ")
    print_intervals(merged_intervals)
