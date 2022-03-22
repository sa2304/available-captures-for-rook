#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRookCaptures(vector<vector<char>> &board) {
    // FIXME
    return 0;
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
