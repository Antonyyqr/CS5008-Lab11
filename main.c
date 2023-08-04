#include <stdio.h>
#include <stdlib.h>

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    // Initialize the dp array with a large value
    for (int i = 1; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // Build up the dp array
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = (dp[i - coins[j]] + 1 < dp[i]) ? dp[i - coins[j]] + 1 : dp[i];
            }
        }
    }

    // If the amount can't be made with the given coins
    if (dp[amount] == amount + 1) {
        return -1;
    }

    return dp[amount];
}

int main() {
    int n, amount;

    printf("Number of values of coins:\n");
    scanf("%d", &n);

    int *coins = (int *)malloc(n * sizeof(int));

    printf("Coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Amount:\n");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if (result == -1) {
        printf("It is not possible to make the amount with the given coins.\n");
    } else {
        printf("Answer: %d\n", result);
    }

    free(coins);
    return 0;
}
