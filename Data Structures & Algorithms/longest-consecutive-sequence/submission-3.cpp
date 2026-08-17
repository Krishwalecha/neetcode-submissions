class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(), nums.end());

        int maxStreak = 0;

        for(const int& num : store) {
            int curr = num, streak = 0;
            if(!(store.count(curr - 1))) {
                while(store.count(curr)) {
                    streak++, curr++;
                }
            }

            maxStreak = max(maxStreak, streak);
        }

        return maxStreak;
    }
};
