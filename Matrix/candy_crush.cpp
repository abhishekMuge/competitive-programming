class Solution
{
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {

        int rows = board.size();
        int cols = board[0].size();

        // This loop continues until the board becomes stable
        while (true)
        {

            // Flag to check if any candy was crushed in this iteration
            bool crushed = false;

            /* ============================================================
               STEP 1: FIND ALL HORIZONTAL CRUSHES
               ============================================================ */
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c + 2 < cols; c++)
                {

                    int val = abs(board[r][c]);

                    // Skip empty cells
                    if (val == 0)
                        continue;

                    // Check if 3 consecutive candies are the same
                    if (abs(board[r][c + 1]) == val &&
                        abs(board[r][c + 2]) == val)
                    {

                        // Mark all consecutive same candies as crushable
                        int k = c;
                        while (k < cols && abs(board[r][k]) == val)
                        {
                            board[r][k] = -val; // mark as negative
                            k++;
                        }

                        crushed = true;
                    }
                }
            }

            /* ============================================================
               STEP 2: FIND ALL VERTICAL CRUSHES
               ============================================================ */
            for (int c = 0; c < cols; c++)
            {
                for (int r = 0; r + 2 < rows; r++)
                {

                    int val = abs(board[r][c]);

                    // Skip empty cells
                    if (val == 0)
                        continue;

                    // Check if 3 consecutive candies are the same
                    if (abs(board[r + 1][c]) == val &&
                        abs(board[r + 2][c]) == val)
                    {

                        // Mark all consecutive same candies as crushable
                        int k = r;
                        while (k < rows && abs(board[k][c]) == val)
                        {
                            board[k][c] = -val; // mark as negative
                            k++;
                        }

                        crushed = true;
                    }
                }
            }

            /* ============================================================
               IF NOTHING WAS CRUSHED, BOARD IS STABLE
               ============================================================ */
            if (!crushed)
                break;

            /* ============================================================
               STEP 3: CRUSH THE MARKED CANDIES
               ============================================================ */
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    if (board[r][c] < 0)
                    {
                        board[r][c] = 0; // remove candy
                    }
                }
            }

            /* ============================================================
               STEP 4: APPLY GRAVITY COLUMN BY COLUMN
               ============================================================ */
            for (int c = 0; c < cols; c++)
            {

                int writeRow = rows - 1;

                // Move non-zero candies downward
                for (int r = rows - 1; r >= 0; r--)
                {
                    if (board[r][c] > 0)
                    {
                        board[writeRow][c] = board[r][c];
                        writeRow--;
                    }
                }

                // Fill remaining upper cells with 0
                while (writeRow >= 0)
                {
                    board[writeRow][c] = 0;
                    writeRow--;
                }
            }
        }

        return board;
    }
};
