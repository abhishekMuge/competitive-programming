#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        // 1. Sort meeting by start time
        sort(meetings.begin(), meetings.end());
        // Count of meetings per room
        vector<long long> booking_count(n, 0);

        // Min-heap for free rooms (stores room index)
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for (int i = 0; i < n; i++)
        {
            free_rooms.push(i);
        }
        // Min-heap for busy rooms: stores {finish_time, room_index}
        // Using long long for time to avoid overflow
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy_rooms;

        for (auto &meeting : meetings)
        {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = (end - start);
            // 2. Release rooms that have finished before the current meeting starts
            while (!busy_rooms.empty() && busy_rooms.top().first <= start)
            {
                free_rooms.push(busy_rooms.top().second);
                busy_rooms.pop();
            }

            int room;
            // 3. Case A: A room is available immediately
            if (!free_rooms.empty())
            {
                room = free_rooms.top();
                free_rooms.pop();
                busy_rooms.push({end, room});
            }
            // 4. Case B: All rooms are busy, must wait for the earliest one to finish
            else
            {
                auto [earliest_finish, earliest_room] = busy_rooms.top();
                busy_rooms.pop();
                room = earliest_room;
                busy_rooms.push({earliest_finish + duration, earliest_room});
            }
            booking_count[room]++;
        }
        int result_room = 0;
        for (int i = 1; i < n; i++)
        {
            if (booking_count[i] > booking_count[result_room])
            {
                result_room = i;
            }
        }

        return result_room;
    }
};