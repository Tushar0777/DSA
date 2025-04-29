#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, k;
    vector<vector<int>> memo;

    int dfs(int city, int week, vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (week == k) return 0;
        if (memo[city][week] != -1) return memo[city][week];

        int maxVacation = 0;

        for (int dest = 0; dest < n; ++dest) {
            // can stay or fly
            if (city == dest || flights[city][dest] == 1) {
                int vac = days[dest][week] + dfs(dest, week + 1, flights, days);
                maxVacation = max(maxVacation, vac);
            }
        }

        return memo[city][week] = maxVacation;
    }

    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        n = flights.size();
        k = days[0].size();
        memo = vector<vector<int>>(n, vector<int>(k, -1));

        return dfs(0, 0, flights, days);
    }
};

// this is topdown+memo 





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, k;
    vector<vector<int>> memo;

    int dfs(int city, int week, vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (week == k) return 0;
        if (memo[city][week] != -1) return memo[city][week];

        int maxVacation = 0;

        for (int dest = 0; dest < n; ++dest) {
            // can stay or fly
            if (city == dest || flights[city][dest] == 1) {
                int vac = days[dest][week] + dfs(dest, week + 1, flights, days);
                maxVacation = max(maxVacation, vac);
            }
        }

        return memo[city][week] = maxVacation;
    }

    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        n = flights.size();
        k = days[0].size();
        memo = vector<vector<int>>(n, vector<int>(k, -1));

        return dfs(0, 0, flights, days);
    }
};



//now bottom up is below 


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

