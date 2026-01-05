#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int totalSum = 0;

        for (int x : nums)
        {
            int count = 0;
            int sum = 0;

            for (int i = 1; i * i <= x; ++i)
            {
                if (x % i == 0)
                {
                    int d1 = i;
                    int d2 = x / i;
                    // below case is used for handling perfect sq., eg
                    //  n = 36
                    //  i = 6 == 36 / 6 = 6 - which produce an same number, which can leads to count twice.
                    if (d1 == d2)
                    {
                        count += 1;
                        sum += d1;
                    }
                    else
                    {
                        count += 2;
                        sum += d1 + d2;
                    }

                    // Early termination
                    if (count > 4)
                    {
                        break;
                    }
                }
            }

            if (count == 4)
            {
                totalSum += sum;
            }
        }

        return totalSum;
    }
};
