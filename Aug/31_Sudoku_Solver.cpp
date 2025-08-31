// 37. Sudoku Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

class Solution
{
    unsigned Row[9] = {0};
    unsigned Col[9] = {0};
    unsigned Block[9] = {0};
    vector<pair<char, char>> uncertain;

public:
    void print(vector<vector<char>> &board)
    {
        for (vector<char> &row : board)
        {
            for (char &c : row)
                cout << c;
            cout << endl;
        }
        cout << "===========\n";
    }
    void set3Cond(int i, int j, int x)
    {
        const int x2 = 1 << x;
        Row[i] |= x2;
        Col[j] |= x2;
        const int bidx = (i / 3) * 3 + j / 3;
        Block[bidx] |= x2;
    }

    void setup(vector<vector<char>> &board)
    {
        uncertain.reserve(81);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c == '.')
                {
                    uncertain.emplace_back(i, j);
                }
                else
                {
                    set3Cond(i, j, c - '1');
                }
            }
        }
    }

    bool solve(vector<vector<char>> &board, int idx)
    {
        if (idx == uncertain.size())
            return 1;
        auto [i, j] = uncertain[idx];
        const int bidx = (i / 3) * 3 + j / 3;
        unsigned notMask = ~(Row[i] | Col[j] | Block[bidx]) & 0b111111111;
        unsigned Bit = 0;
        for (; notMask; notMask ^= Bit)
        {
            Bit = bit_floor(notMask);
            const int x = countr_zero(Bit);

            board[i][j] = '1' + x;
            Row[i] |= Bit;
            Col[j] |= Bit;
            Block[bidx] |= Bit;
            if (solve(board, idx + 1))
                return 1;
            Row[i] ^= Bit;
            Col[j] ^= Bit;
            Block[bidx] ^= Bit; // backtracking
            board[i][j] = '.';
        }
        return 0;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        //    print(board);
        setup(board);
        solve(board, 0);
        //    print(board);
    }
};