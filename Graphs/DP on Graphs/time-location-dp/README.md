# Maximum Vacation Days (LeetCode 568)

### Problem Description:
You are given a **flights matrix** and a **days matrix** representing different cities, the flights available between them, and the number of vacation days available for each city at each week. The goal is to plan your vacation so that you maximize the total vacation days within `k` weeks while adhering to the constraints.

### Problem Constraints:
- You start in city 0.
- You can only fly on Monday mornings (no flights on other days).
- Traveling from city `A` to city `B` uses up one vacation day for city `B`.
- You can only spend vacation days in a city during the `k` weeks.

### Problem Link:
[LeetCode 568: Maximum Vacation Days](https://leetcode.com/problems/maximum-vacation-days/)

---

## 💡 Approach:

This problem can be solved using **Dynamic Programming (DP)** with a time-location state representation. The problem requires calculating the maximum vacation days you can gather by choosing cities optimally over a span of `k` weeks.

### DP State Design:
- Let `dp[week][city]` represent the maximum vacation days you can get if you are in city `city` at the end of week `week`.
- **Transition**:
  - For each city you could have traveled from in the previous week (either stayed or flew), update the vacation days.
  
---

## 🔄 Bottom-Up (Tabulation) Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size();
        vector<vector<int>> dp(k, vector<int>(n, -1));

        // Initialize for week 0
        dp[0][0] = days[0][0];
        for (int city = 1; city < n; ++city) {
            if (flights[0][city] == 1) {
                dp[0][city] = days[city][0];
            }
        }

        for (int week = 1; week < k; ++week) {
            for (int curr = 0; curr < n; ++curr) {
                for (int prev = 0; prev < n; ++prev) {
                    if (dp[week - 1][prev] == -1) continue;
                    if (flights[prev][curr] == 1 || prev == curr) {
                        dp[week][curr] = max(dp[week][curr], dp[week - 1][prev] + days[curr][week]);
                    }
                }
            }
        }

        return *max_element(dp[k - 1].begin(), dp[k - 1].end());
    }
};
