class Solution {
public:

    // This function checks whether Alice can collect more stones than Bob.
    bool stoneGame(vector<int>& piles) {

        // Store the total number of piles because we need it many times.
        int n = piles.size();

        // Create a DP table where dp[i][j] stores the maximum stone difference from pile i to pile j.
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Visit every pile to initialize the base case.
        for (int i = 0; i < n; i++) {

            // If only one pile is available, the current player takes all stones from that pile.
            dp[i][i] = piles[i];
        }

        // Increase the subarray length from 2 piles to n piles.
        for (int d = 1; d < n; d++) {

            // Move the starting index for every possible subarray.
            for (int i = 0; i + d < n; i++) {

                // Calculate the ending index of the current subarray.
                int j = i + d;

                // Calculate the score difference if the current player picks the left pile.
                int takeLeft = piles[i] - dp[i + 1][j];

                // Calculate the score difference if the current player picks the right pile.
                int takeRight = piles[j] - dp[i][j - 1];

                // Store the better choice that gives the maximum stone difference.
                dp[i][j] = max(takeLeft, takeRight);
            }
        }

        // Return true if Alice gets more stones than Bob.
        return dp[0][n - 1] > 0;
    }
};