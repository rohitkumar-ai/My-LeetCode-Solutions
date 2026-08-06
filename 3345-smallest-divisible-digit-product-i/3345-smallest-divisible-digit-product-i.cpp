class Solution {
public:
    int smallestNumber(int n, int t) {

        // Check numbers starting from n.
        for (int num = n; num < n + 10; ++num) {

            // If the product of digits is divisible by t.
            if (getDigitProd(num) % t == 0)

                // Return the first valid number.
                return num;
        }

        // This line is never expected to execute because
        // the problem guarantees that an answer exists.
        throw;
    }

private:

    // Function to calculate the product of all digits of a number.
    int getDigitProd(int num) {

        // Initially, product is 1 because it is the multiplicative identity.
        int digitProd = 1;

        // Continue until all digits are processed.
        while (num > 0) {

            // Take the last digit and multiply it with the current product.
            digitProd *= num % 10;

            // Remove the last digit from the number.
            num /= 10;
        }

        // Return the final product of all digits.
        return digitProd;
    }
};