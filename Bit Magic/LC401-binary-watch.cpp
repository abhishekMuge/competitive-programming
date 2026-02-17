#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<string> result;

    void backtrack(int turnedOn,
                   int index,
                   int count,
                   int hour,
                   int minute)
    {
        // Pruning
        if (hour >= 12 || minute >= 60)
            return;

        // Found valid combination
        if (count == turnedOn)
        {
            string time = to_string(hour) + ":";

            if (minute < 10)
                time += "0";

            time += to_string(minute);

            result.push_back(time);
            return;
        }

        // No more LEDs to choose
        if (index == 10)
            return;

        for (int i = index; i < 10; i++)
        {

            if (i < 4)
            {
                // Hour bit
                backtrack(turnedOn,
                          i + 1,
                          count + 1,
                          hour + (1 << i),
                          minute);
            }
            else
            {
                // Minute bit
                backtrack(turnedOn,
                          i + 1,
                          count + 1,
                          hour,
                          minute + (1 << (i - 4)));
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        result.clear();
        backtrack(turnedOn, 0, 0, 0, 0);
        return result;
    }
};