// 717. 1-bit and 2-bit Characters

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;
        int n = bits.size();
        while (i < n - 1)
        {
            if (bits[i] == 0)
            {
                i = i + 1;
            }
            else
            {
                i = i + 2;
            }
        }

        return i == n - 1;
    }
};