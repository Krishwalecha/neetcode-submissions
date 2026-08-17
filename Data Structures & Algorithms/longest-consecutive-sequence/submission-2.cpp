class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int maxStreak = 0, streak = 1;

        sort(nums.begin(), nums.end());
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i] == nums[i - 1] + 1) streak++;
            else if(nums[i] == nums[i - 1]) continue;
            else {
                maxStreak = max(maxStreak, streak);
                streak = 1;
            }
        }

        return max(maxStreak, streak);
    }
};
