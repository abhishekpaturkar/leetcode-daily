// 1523. Count Odd Numbers in an Interval Range

class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + (high & 1) - low + (low & 1)) >> 1;
    }
};