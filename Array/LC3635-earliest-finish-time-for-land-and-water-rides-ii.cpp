#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long minLandFinish = LLONG_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(
                minLandFinish,
                (long long)landStartTime[i] + landDuration[i]
            );
        }

        long long landToWater = LLONG_MAX;

        for (int j = 0; j < waterStartTime.size(); j++) {
            landToWater = min(
                landToWater,
                max(minLandFinish,
                    (long long)waterStartTime[j]) +
                waterDuration[j]
            );
        }

        long long minWaterFinish = LLONG_MAX;

        for (int j = 0; j < waterStartTime.size(); j++) {
            minWaterFinish = min(
                minWaterFinish,
                (long long)waterStartTime[j] + waterDuration[j]
            );
        }

        long long waterToLand = LLONG_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            waterToLand = min(
                waterToLand,
                max(minWaterFinish,
                    (long long)landStartTime[i]) +
                landDuration[i]
            );
        }

        return (int)min(landToWater, waterToLand);
    }
};