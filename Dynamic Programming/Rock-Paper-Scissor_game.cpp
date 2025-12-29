#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Standard RPS rules
bool beats(char a, char b)
{
    if (a == 'P' && b == 'R')
        return true;
    if (a == 'S' && b == 'P')
        return true;
    if (a == 'R' && b == 'S')
        return true;
    return false;
}

char getWinningHand(char a, char b)
{
    if (a == 'X')
        return b; // If one side is empty, other advances
    if (b == 'X')
        return a;
    if (a == b)
        return 'X'; // Tie means both out
    return beats(a, b) ? a : b;
}

// Global/Member variables for the simulation
string formations;
int poi_idx;
const int INF = 1e9;

// Memoization table: memo[round][hand_type]
// hands: 0=R, 1=P, 2=S
int memo[32][3];
char hand_chars[] = {'R', 'P', 'S'};

// Pre-calculate who wins any sub-bracket not containing the POI
char getBracketWinner(int L, int R)
{
    if (L == R)
        return formations[L];

    int mid = L + (R - L) / 2;
    char left = getBracketWinner(L, mid);
    char right = getBracketWinner(mid + 1, R);

    return getWinningHand(left, right);
}

int dp(int L, int R, int hand_idx)
{
    // Base Case: POI is at the leaf node
    if (L == R)
        return 0;

    // Check memo
    int round = 0;
    int temp_len = R - L + 1;
    while (temp_len >>= 1)
        round++;
    if (memo[round][hand_idx] != -1)
        return memo[round][hand_idx];

    int mid = L + (R - L) / 2;
    char my_hand = hand_chars[hand_idx];
    char opponent;

    // Determine if POI is in the left or right sub-bracket
    int prev_L, prev_R;
    if (poi_idx <= mid)
    {
        opponent = (mid + 1 <= R) ? getBracketWinner(mid + 1, R) : 'X';
        prev_L = L;
        prev_R = mid;
    }
    else
    {
        opponent = getBracketWinner(L, mid);
        prev_L = mid + 1;
        prev_R = R;
    }

    // To advance, POI must beat opponent or opponent must be 'X' (Bye)
    if (opponent != 'X' && !beats(my_hand, opponent))
    {
        return memo[round][hand_idx] = INF;
    }

    // Try all possible hands the POI could have used in the PREVIOUS round
    int min_changes = INF;
    for (int prev_hand_idx = 0; prev_hand_idx < 3; prev_hand_idx++)
    {
        int cost = dp(prev_L, prev_R, prev_hand_idx);
        if (cost != INF)
        {
            // If current hand is different from previous hand, add 1
            int change = (hand_idx == prev_hand_idx) ? 0 : 1;
            min_changes = min(min_changes, cost + change);
        }
    }

    return memo[round][hand_idx] = min_changes;
}

int main()
{
    int n = 4;
    poi_idx = 1;
    string input_formations = "PRS"; // Indices 0, 2, 3

    // Reconstruct full player list (POI is a hole in the input string)
    formations = "";
    int input_ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == poi_idx)
            formations += '?';
        else
            formations += input_formations[input_ptr++];
    }

    // Initialize memo
    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 3; j++)
            memo[i][j] = -1;

    int res = INF;
    for (int h = 0; h < 3; h++)
    {
        res = min(res, dp(0, n - 1, h));
    }

    cout << "Minimum changes: " << res << endl;

    return 0;
}

/*
To help you practice or share this problem with others, here is a formalized problem statement written in a standard "Competitive Programming" style (like LeetCode or Codeforces).

---

## Problem: The Persistent Strategist

### Description

In a single-elimination Rock-Paper-Scissors tournament,  players stand in a line. The tournament progresses in rounds. In each round:

1. Consecutive pairs of players compete (Player 0 vs Player 1, Player 2 vs Player 3, etc.).
2. If the number of players in a round is **odd**, the last player in line automatically advances to the next round (a "bye").
3. The outcome of a match follows standard rules:
* **Paper beats Rock**
* **Scissors beat Paper**
* **Rock beats Scissors**


4. If a match results in a **tie** (both players choose the same formation), **both players are eliminated** and no one advances from that match.
5. Winners move to the next round, maintaining their relative order.

Every player except for one—the **Person of Interest (POI)**—is stubborn and will use the same hand formation (Rock, Paper, or Scissors) for every match they play in the tournament.

The **POI** is flexible. They can choose any hand formation for their first match and can change it between rounds. However, the POI wants to win the entire tournament while **changing their hand formation as few times as possible.**

**Your Task:** Determine the minimum number of changes the POI must make to be the sole winner of the tournament.

---

### Input Format

* `n`: An integer representing the total number of players (including the POI).
* `poi`: An integer representing the 0-indexed initial position of the POI in the line.
* `formations`: A string of length  representing the fixed choices of all other players in their original order.

### Output Format

* Return an integer representing the minimum number of hand changes required. If it is impossible for the POI to win, return `-1`.

---

### Constraints

*
*
* `formations[i]` is one of `'R'`, `'P'`, or `'S'`.

---

### Examples

**Example 1**

* **Input:** `n = 3`, `poi = 2`, `formations = "PS"`
* **Output:** `0`
* **Explanation:** * Round 1: Player 0 (P) vs Player 1 (S). Player 1 wins. POI (at index 2) has a bye and advances.
* Round 2: Player 1 (S) vs POI. POI chooses Rock (R).
* POI wins the tournament. No changes were made to the POI's hand during the tournament.



**Example 2**

* **Input:** `n = 4`, `poi = 1`, `formations = "PRS"`
* **Output:** `1`
* **Explanation:**
* Players are: [0:P, 1:POI, 2:R, 3:S]
* Round 1: Match 1: Player 0(P) vs POI. POI chooses Scissors(S) to win. Match 2: Player 2(R) vs Player 3(S). Rock(R) wins.
* Round 2: POI(S) vs Player 2(R). POI must change to Paper(P) to win.
* Total changes: 1 (from S to P).



---

### Logical Tip for Updating

If you want to make this problem **harder**, you could add:

* **Cost Weights:** Changing to a specific hand (e.g., Rock to Scissors) costs more than others.
* **Multiple POIs:** What if two players can change their hands and want to cooperate?

**Would you like me to generate a set of "Hidden Test Cases" (Input and Expected Output) so you can verify if your code works correctly?**
*/