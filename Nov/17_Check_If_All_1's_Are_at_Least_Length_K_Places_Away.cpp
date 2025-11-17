// 1437. Check If All 1's Are at Least Length K Places Away

class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int zeros = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (zeros < k)
                    return false;
                zeros = 0;
            }
            else
            {
                zeros++;
            }
        }
        return true;
    }
};