// 3169. Count Days Without Meetings

// You are given an integer days, representing the total number of days in a period, and a list of meetings, where each meetings[i] = [start, end] represents a meeting spanning from day start to day end (both inclusive).
// Your task is to determine the number of days that are not covered by any meeting.

// Constraints & Conditions:
// Meetings are given as an array of intervals [start, end], where:
// 1 ≤ start ≤ end ≤ days
// The total number of days is given as days, where:
// 1 ≤ days ≤ 10^9
// The list of meetings may have overlapping intervals.
// You need to count only the days that do not fall within any meeting interval.

// Input:
// days: An integer representing the total number of days.
// meetings: A list of integer pairs [start, end], representing meetings scheduled over specific days.

// Output:
// Return an integer representing the number of free days (days not covered by any meeting).

// Example:
// Input:
// int days = 10;
// vector<vector<int>> meetings = {{1, 3}, {5, 6}, {2, 8}};

// Processing:
// Meetings cover days 1 to 3, 2 to 8, and 5 to 6.
// The occupied days (merged) are: {1, 2, 3, 4, 5, 6, 7, 8}.
// The free days are: {9, 10}.

// Output:
// 2

class Solution {
    #define pii pair<int, int>

public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pii> time;

        for (auto& meeting : meetings) {
            time.push_back(make_pair(meeting[0], 1));
            time.push_back(make_pair(meeting[1] + 1, 0));
        }

        sort(time.begin(), time.end());

        int overlap = 0;
        int count = time[0].first - 1;

        for (int i = 0; i < time.size() - 1; ++i) {
            if (time[i].second == 0) {
                overlap--;
            } else {
                overlap++;
            }

            if (overlap == 0) {
                count += time[i + 1].first - time[i].first;
            }
        }

        count += days - time.back().first + 1;
        return count;
    }
};
