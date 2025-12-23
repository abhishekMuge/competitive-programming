class Solution
{
public:
    int numberOfWays(string corridor)
    {
        const int MOD = 1e9 + 7;

        long long ways = 1;
        int seatCount = 0;
        int plantBetween = 0;

        for (char ch : corridor)
        {
            if (ch == 'S')
            {
                seatCount++;

                // Every time we complete a pair AFTER the first pair,
                // we multiply the choices formed by plants in between
                if (seatCount > 2 && seatCount % 2 == 1)
                {
                    ways = (ways * (plantBetween + 1)) % MOD;
                    plantBetween = 0;
                }
            }
            else if (seatCount >= 2 && seatCount % 2 == 0)
            {
                // Count plants only between completed seat-pairs
                plantBetween++;
            }
        }

        // Total seats must be even and at least one section must exist
        if (seatCount == 0 || seatCount % 2 != 0)
        {
            return 0;
        }

        return ways;
    }
};
