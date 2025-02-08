// 2349. Design a Number Container System
// Solved
// Medium
// Topics
// Companies
// Hint
// Design a number container system that can do the following:

// Insert or Replace a number at the given index in the system.
// Return the smallest index for the given number in the system.
// Implement the NumberContainers class:

// NumberContainers() Initializes the number container system.
// void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
// int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
 

// Example 1:

// Input
// ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
// [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
// Output
// [null, -1, null, null, null, null, 1, null, 2]

// Explanation
// NumberContainers nc = new NumberContainers();
// nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
// nc.change(2, 10); // Your container at index 2 will be filled with number 10.
// nc.change(1, 10); // Your container at index 1 will be filled with number 10.
// nc.change(3, 10); // Your container at index 3 will be filled with number 10.
// nc.change(5, 10); // Your container at index 5 will be filled with number 10.
// nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
// nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
// nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
 

// Constraints:

// 1 <= index, number <= 109
// At most 105 calls will be made in total to change and find.

#include <unordered_map>
#include <queue>
using namespace std;

class NumberContainers
{
public:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> res;
    unordered_map<int, int> index_val;

    void change(int index, int number)
    {
        if (index_val.count(index))
        {
            int prevNum = index_val[index];
            if (prevNum == number)
                return;
            res[prevNum].push(INT_MAX); // Lazy deletion
        }
        res[number].push(index);
        index_val[index] = number;
    }

    int find(int number)
    {
        while (!res[number].empty() && index_val[res[number].top()] != number)
        {
            res[number].pop();
        }
        return res[number].empty() ? -1 : res[number].top();
    }
};

/*
This code implements a number container system with two main operations:

1. Data structures used:
   - res: Maps numbers to min-heaps of indices where that number appears
   - index_val: Maps indices to their current values

2. change(index, number) function:
   - If index already has a value:
     * Marks old value for lazy deletion using INT_MAX
     * Updates if new number is different
   - Adds new index to number's priority queue
   - Updates index-to-value mapping

3. find(number) function:
   - Uses lazy deletion to remove invalid indices
   - Returns smallest valid index for the number
   - Returns -1 if number not found

The system efficiently handles updates and queries using priority queues
for maintaining sorted indices and hash maps for O(1) lookups.
*/