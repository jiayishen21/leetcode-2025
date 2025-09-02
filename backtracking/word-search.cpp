#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (backtrack(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>> &board, string &word, int index, int i, int j)
    {
        if (index >= word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
        {
            return false;
        }

        // Note that '#' != word[index]
        if (board[i][j] != word[index])
        {
            return false;
        }

        // Mark as visited
        board[i][j] = '#';

        if (backtrack(board, word, index + 1, i + 1, j) ||
            backtrack(board, word, index + 1, i - 1, j) ||
            backtrack(board, word, index + 1, i, j + 1) ||
            backtrack(board, word, index + 1, i, j - 1))
        {
            board[i][j] = word[index];
            return true;
        }
        else
        {
            board[i][j] = word[index];
            return false;
        }
    }
};
