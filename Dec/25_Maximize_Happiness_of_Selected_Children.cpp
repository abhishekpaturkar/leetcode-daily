// 3075. Maximize Happiness of Selected Children

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int currSelected = happiness[i] - i;
            if (currSelected <= 0)
            {
                break;
            }
            ans += currSelected;
        }
        return ans;
    }
};