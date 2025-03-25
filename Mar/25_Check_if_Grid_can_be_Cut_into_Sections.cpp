// 3394. Check if Grid can be Cut into Sections

// You are given an integer days, representing the total number of days in a given period, and a list of meetings, where each meetings[i] = [start, end] denotes a meeting spanning from day start to day end (both inclusive). Your task is to determine how many days are not covered by any meeting.

// Constraints & Conditions:
// Each meeting is represented as an interval [start, end], where:
// 1≤start≤end≤days

// The total number of days is given as days, where:
// 1≤days≤10^9
 
// The list of meetings may contain overlapping intervals.
// You need to count only the days that are not covered by any meeting interval.

// Input:
// days: An integer representing the total number of days.
// meetings: A list of integer pairs [start, end], representing scheduled meetings.

// Output:
// Return an integer representing the number of free days (days not covered by any meeting).

// Example:
// Input:
// int days = 10;
// vector<vector<int>> meetings = {{1, 3}, {5, 6}, {2, 8}};

// Processing:
// Meetings cover the following days:

// {1, 2, 3} from [1, 3]

// {5, 6} from [5, 6]

// {2, 3, 4, 5, 6, 7, 8} from [2, 8]

// Merging these intervals, the occupied days are {1, 2, 3, 4, 5, 6, 7, 8}.

// The free days are {9, 10}.

// Output:
// 2

class Solution {
    #define pii pair<int, int>

    bool countLineIntersections(vector<pii>& coordinates) {
        int lines = 0;
        int overlap = 0;
        
        for (int i = 0; i < coordinates.size(); ++i) {
            if (coordinates[i].second == 0) {
                overlap--;
            } else {
                overlap++;
            }
            
            if (overlap == 0) {
                lines++;
            }
        }
        
        return lines >= 3;
    }

 public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pii> y_cordinates, x_cordinates;
        
        for (auto& rectangle : rectangles) {
            y_cordinates.push_back(make_pair(rectangle[1], 1));
            y_cordinates.push_back(make_pair(rectangle[3], 0));
            x_cordinates.push_back(make_pair(rectangle[0], 1));
            x_cordinates.push_back(make_pair(rectangle[2], 0));
        }
        
        sort(y_cordinates.begin(), y_cordinates.end());
        sort(x_cordinates.begin(), x_cordinates.end());
        
        return (countLineIntersections(y_cordinates) || countLineIntersections(x_cordinates));
    }
};