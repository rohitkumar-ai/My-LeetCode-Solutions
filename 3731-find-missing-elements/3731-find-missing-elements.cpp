class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        // We need to know the smallest number in the array.
        // Assume the minimum is very large initially (100).
        // During traversal, it will become the actual minimum value.
        int mn = 100,

        // We also need the largest number in the array.
        // Assume the maximum is very small initially (0).
        // During traversal, it will become the actual maximum value.
        mx = 0;

        // We need fast lookup to check whether a number exists.
        // unordered_set provides average O(1) search time.
        unordered_set<int> s;

        // Traverse every element in the input array.
        for (int x : nums) {

            // Compare current element with current minimum.
            // If current element is smaller, update mn.
            mn = min(mn, x);

            // Compare current element with current maximum.
            // If current element is larger, update mx.
            mx = max(mx, x);

            // Store the current element inside the set.
            // Duplicate values are automatically ignored.
            s.insert(x);
        }

        // This vector will store all missing numbers.
        vector<int> ans;

        // Start checking from one number after the minimum.
        // No need to check mn because it already exists.
        // Stop before mx because it also already exists.
        for (int x = mn + 1; x < mx; ++x) {

            // Check whether the current number is NOT present.
            if (!s.count(x)) {

                // If the number is missing,
                // store it in the answer vector.
                ans.push_back(x);
            }
        }

        // Return all missing numbers between
        // the minimum and maximum values.
        return ans;
    }
};