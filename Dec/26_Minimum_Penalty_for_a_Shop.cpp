// 2483. Minimum Penalty for a Shop

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int totalCustomers = 0;
        for (char c : customers)
        {
            if (c == 'Y')
                totalCustomers++;
        }

        int n = customers.size();
        int min = INT_MAX;
        int prefixSumCustomer = 0;
        int time = n;

        for (int i = 0; i <= n; i++)
        {
            int remainingCustomers = totalCustomers - prefixSumCustomer;
            int penalty = i - prefixSumCustomer;
            penalty += remainingCustomers;

            if (min > penalty)
            {
                min = penalty;
                time = i;
            }

            if (i != n && customers[i] == 'Y')
            {
                prefixSumCustomer++;
            }
        }
        return time;
    }
};