class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < numbers.size(); i++) {
            int needed = target - numbers[i];
            if (hash.count(needed)) return {hash[needed] + 1, i + 1};

            hash[numbers[i]] = i;
        }

        return {-1, -1};
    }
};
