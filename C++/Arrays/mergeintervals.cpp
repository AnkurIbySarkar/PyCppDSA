#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to merge overlapping intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Sort the intervals based on the start time
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If the current interval is completely inside the last interval in 'ans', skip it
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // Merge overlapping intervals
        for (int j = i + 1; j < n; j++)
        {
            // If the start time of the next interval is less than or equal to the current end time,
            // there is an overlap, so extend the current interval's end time to cover the overlapping intervals.
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                // If there is no overlap, break out of the loop to process the next non-overlapping interval.
                break;
            }
        }
        // Add the merged interval (start, end) to the 'ans' vector.
        ans.push_back({start, end});
    }
    return ans;
}

// Function to print intervals
void printIntervals(const vector<vector<int>> &intervals)
{
    for (const auto &interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    cout << "Original Intervals: ";
    printIntervals(intervals);

    // Merge overlapping intervals and store the result in 'mergedIntervals'
    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);

    cout << "Merged Intervals: ";
    printIntervals(mergedIntervals);

    return 0;
}