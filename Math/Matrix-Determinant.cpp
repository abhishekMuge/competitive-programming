#include <vector>
using namespace std;

class Matrix
{
public:
    static long long determinant(vector<vector<long long>> m)
    {
        int n = m.size();

        // Base case 1x1
        if (n == 1)
            return m[0][0];

        // Base case 2x2
        if (n == 2)
            return m[0][0] * m[1][1]
                 - m[0][1] * m[1][0];

        long long det = 0;

        for (int col = 0; col < n; col++)
        {
            vector<vector<long long>> minor;

            // Build minor matrix
            for (int i = 1; i < n; i++)
            {
                vector<long long> row;

                for (int j = 0; j < n; j++)
                {
                    if (j != col)
                        row.push_back(m[i][j]);
                }

                minor.push_back(row);
            }

            long long sign = (col % 2 == 0) ? 1 : -1;

            det += sign * m[0][col]
                         * determinant(minor);
        }

        return det;
    }
};