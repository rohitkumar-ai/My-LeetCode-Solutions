class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        // Total number of stones in the array.
        int n = stoneValue.size();

        // dp[i] = Maximum score difference (Current Player - Opponent)
        // that can be achieved starting from index i.
        vector<int> dp(n + 1, INT_MIN / 2);

        // Base Case:
        // If no stones are left, both players score 0.
        dp[n] = 0;

        // Start from the last index because
        // dp[i] depends on dp[i+1], dp[i+2], and dp[i+3].
        for (int i = n - 1; i >= 0; i--) {

            // Stores the sum of stones taken in the current move.
            int sum = 0;

            // Try taking 1, 2, or 3 stones.
            for (int j = i; j < i + 3 && j < n; j++) {

                // Add the current stone to the running sum.
                sum += stoneValue[j];

                // Current player's advantage =
                // Stones collected now
                // -
                // Opponent's best possible advantage from the next position.
                //
                // Why subtract?
                // Because dp[j+1] already represents the maximum score
                // difference the opponent can achieve after our move.
                //
                // Formula:
                // Current Advantage = Current Sum - Opponent Advantage
                dp[i] = max(dp[i], sum - dp[j + 1]);
            }
        }

        // Final score difference after both players play optimally.
        int score = dp[0];

        // Positive score means Alice gets more points.
        if (score > 0)
            return "Alice";

        // Negative score means Bob gets more points.
        if (score < 0)
            return "Bob";

        // Zero score means both players get equal points.
        return "Tie";
    }
};