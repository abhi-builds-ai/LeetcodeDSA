
class Solution {
public:
    int rows, cols;
    int emptycells;
    int ans = 0;

    vector<vector<int>> directions{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void solve(vector<vector<int>>& grid, int i, int j, int count) {

        // Out of bounds or obstacle/visited
        if (i < 0 || i >= rows || j < 0 || j >= cols ||
            grid[i][j] == -1)
            return;

        // Reached ending cell
        if (grid[i][j] == 2) {
            if (count == emptycells)
                ans++;

            return;
        }

        // Mark current cell as visited
        int temp = grid[i][j];
        grid[i][j] = -1;

        // Try all 4 directions
        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            solve(grid, new_i, new_j, count + 1);
        }

        // Backtrack
        grid[i][j] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        emptycells = 0;
        ans = 0;

        int startRow = 0;
        int startCol = 0;

        // Count non-obstacle cells and find start
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] != -1)
                    emptycells++;

                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        solve(grid, startRow, startCol, 1);

        return ans;
    }
};

//sc:O(E)  the max path can contain all E non-obstacle cells
//tc:O(4^E)