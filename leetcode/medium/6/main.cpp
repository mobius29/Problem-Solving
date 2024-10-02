#include <vector>

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || s.length() <= numRows)
      return s;

    vector<vector<char>> zigzag(numRows, vector<char>());
    for (int i = 0; i < s.length(); ++i) {
      int col = i / (numRows - 1);
      int row = i % (numRows - 1);

      if (col % 2 == 0) {
        zigzag[row].push_back(s[i]);
      } else {
        zigzag[numRows - row - 1].push_back(s[i]);
      }
    }

    string answer;
    for (int i = 0; i < numRows; ++i) {
      for (int j = 0; j < zigzag[i].size(); ++j) {
        answer.push_back(zigzag[i][j]);
      }
    }

    return answer;
  }
};
