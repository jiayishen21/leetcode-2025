#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

bool findWord(vector<vector<char>> &board, string target, vector<vector<bool>> &visited, int sIndex, int i, int j)
{
    if (sIndex >= target.size())
    {
        return true;
    }
    if (i < 0 || j < 0)
    {
        return false;
    }
    if (i >= board.size() || j >= board[i].size())
    {
        return false;
    }
    if (visited[i][j])
    {
        return false;
    }
    if (board[i][j] != target[sIndex])
    {
        return false;
    }

    visited[i][j] = true;
    if (findWord(board, target, visited, sIndex + 1, i + 1, j) ||
        findWord(board, target, visited, sIndex + 1, i - 1, j) ||
        findWord(board, target, visited, sIndex + 1, i, j + 1) ||
        findWord(board, target, visited, sIndex + 1, i, j - 1))
    {
        visited[i][j] = false;
        return true;
    }
    visited[i][j] = false;
    return false;
}

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        unordered_map<char, vector<pair<int, int>>> starts;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                starts[board[i][j]].push_back(pair{i, j});
            }
        }

        vector<string> res;
        vector<vector<bool>> visited{board.size(), vector<bool>(board[0].size(), false)};
        for (const auto &word : words)
        {
            char initialC = word[0];
            if (starts.find(initialC) == starts.end())
            {
                continue;
            }
            for (const auto &start : starts[initialC])
            {
                if (findWord(board, word, visited, 0, start.first, start.second))
                {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};
