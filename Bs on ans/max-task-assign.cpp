class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end()); // strongest k workers
        
        for (int i = k - 1; i >= 0; --i) { // from hardest to easiest task
            int task = tasks[i];
            auto it = available.lower_bound(task); // find worker without pill
            if (it != available.end()) {
                available.erase(it);
            } else {
                if (pills == 0) return false;

                auto pillIt = available.lower_bound(task - strength); // with pill
                if (pillIt == available.end()) return false;

                available.erase(pillIt);
                pills--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size()), answer = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};
