// 1353. Maximum Number of Events That Can Be Attended

// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

// Return the maximum number of events you can attend.

 

// Example 1:


// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.
// Example 2:

// Input: events= [[1,2],[2,3],[3,4],[1,2]]
// Output: 4
 

// Constraints:

// 1 <= events.length <= 105
// events[i].length == 2
// 1 <= startDayi <= endDayi <= 105

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        // Sort events based on start day
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 0, index = 0, n = events.size(), result = 0;

        while (!minHeap.empty() || index < n)
        {
            if (minHeap.empty())
            {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day)
            {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            result++;
            day++;

            while (!minHeap.empty() && minHeap.top() < day)
            {
                minHeap.pop();
            }
        }
        return result;
    }
};

/*
Explanation:
This solution uses a min heap to efficiently track and attend events. Here's how it works:

1. First, sort all events by their start time to process them in chronological order.
2. Use a min heap to store end times of events that have started but haven't been attended yet.
3. For each day:
   - Add all events that start on or before current day to the min heap
   - Attend the event that ends earliest (top of min heap)
   - Remove events that have already ended (end time < current day)
4. Continue this process until all events are processed

Time Complexity: O(NlogN)
- Sorting events takes O(NlogN)
- Each event is pushed and popped from heap once, each operation taking O(logN)
- Total operations: O(NlogN)

Space Complexity: O(N)
- Priority queue can store at most N events
*/