// 3531. Count Covered Buildings

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {

        unordered_map<int, vector<int>> rowMap;
        unordered_map<int, vector<int>> colMap;

        // Build maps
        for (auto &b : buildings)
        {
            rowMap[b[0]].push_back(b[1]);
            colMap[b[1]].push_back(b[0]);
        }

        int result = 0;

        for (auto &b : buildings)
        {
            int x = b[0], y = b[1];

            bool left = false, right = false;
            bool up = false, down = false;

            // Check row for left/right
            for (int col : rowMap[x])
            {
                if (col < y)
                    left = true;
                if (col > y)
                    right = true;
            }

            // Check column for up/down
            for (int row : colMap[y])
            {
                if (row < x)
                    up = true;
                if (row > x)
                    down = true;
            }

            if (left && right && up && down)
                result++;
        }

        return result;
    }
};