#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  struct Pos {
    int row;
    int column;
  };

 public:
  int numRookCaptures(vector<vector<char>> &board) {
    Pos rook{-1, -1};
    const int rowCount = board.size();
    const int columnCount = board.front().size();
    bool found = false;
    for (int r = 0; r < rowCount && !found; ++r) {
      for (int c = 0; c < columnCount && !found; ++c) {
        if ('R' == board[r][c]) {
          rook = {r, c};
          found = true;
        }
      }
    }

    int count = 0;
    for (int c = rook.column - 1; 0 <= c; --c) {
      char f = board[rook.row][c];
      if ('p' == f) {
        ++count;
        break;
      } else if ('B' == f) {
        break;
      }
    }

    for (int c = rook.column + 1; c < columnCount; ++c) {
      char f = board[rook.row][c];
      if ('p' == f) {
        ++count;
        break;
      } else if ('B' == f) {
        break;
      }
    }

    for (int r = rook.row - 1; 0 <= r; --r) {
      char f = board[r][rook.column];
      if ('p' == f) {
        ++count;
        break;
      } else if ('B' == f) {
        break;
      }
    }

    for (int r = rook.row + 1; r < rowCount; ++r) {
      char f = board[r][rook.column];
      if ('p' == f) {
        ++count;
        break;
      } else if ('B' == f) {
        break;
      }
    }

    return count;
  }
};

void TestNumRookCaptures() {
  Solution s;
  {
    vector<vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', 'p', '.', '.', '.', '.'},
                               {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', 'p', '.', '.', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'}};
    assert(3 == s.numRookCaptures(board));
  }
  {
    vector<vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                               {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                               {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
                               {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                               {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'}};
    assert(0 == s.numRookCaptures(board));
  }
  {
    vector<vector<char>> board{{'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', 'p', '.', '.', '.', '.'},
                               {'.', '.', '.', 'p', '.', '.', '.', '.'},
                               {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', 'B', '.', '.', '.', '.'},
                               {'.', '.', '.', 'p', '.', '.', '.', '.'},
                               {'.', '.', '.', '.', '.', '.', '.', '.'}};
    assert(3 == s.numRookCaptures(board));
  }
}

int main() {
  TestNumRookCaptures();
  std::cout << "Ok!" << std::endl;
  return 0;
}
