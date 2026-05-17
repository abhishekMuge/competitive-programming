#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
Given two different positions on a chess board, find the least number of moves it would take a knight to get from one to the other. The positions will be passed as two arguments in algebraic notation. For example, knight("a3", "b5") should return 1.

The knight is not allowed to move off the board. The board is 8x8.

Logic:
1. Convert source/destination to coordinates

2. Push source into queue

3. Mark source visited

4. While queue not empty:
      pop front

      if destination reached:
            return moves

      try all 8 knight moves

      if valid and not visited:
            push into queue
            mark visited

Knight Movements from (x,y)
(x+2, y+1)
(x+2, y-1)

(x-2, y+1)
(x-2, y-1)

(x+1, y+2)
(x+1, y-2)

(x-1, y+2)
(x-1, y-2)
*/


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int knight(string start, string target)
{
    int sx = start[0] - 'a';
    int sy = start[1] - '1';

    int tx = target[0] - 'a';
    int ty = target[1] - '1';

    // If already same position
    if (sx == tx && sy == ty)
        return 0;

    vector<pair<int,int>> directions =
    {
        {2,1}, {2,-1},
        {-2,1}, {-2,-1},
        {1,2}, {1,-2},
        {-1,2}, {-1,-2}
    };

    bool visited[8][8] = {false};

    queue<tuple<int,int,int>> q;

    q.push({sx, sy, 0});

    visited[sx][sy] = true;

    while (!q.empty())
    {
        auto [x, y, moves] = q.front();
        q.pop();

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            // boundary check
            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8)
                continue;

            // already visited
            if (visited[nx][ny])
                continue;

            // destination found
            if (nx == tx && ny == ty)
                return moves + 1;

            visited[nx][ny] = true;

            q.push({nx, ny, moves + 1});
        }
    }

    return -1;
}