class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        // Optimal Approach
        unordered_set<int> hash;
        for (int num : nums) {
            // Check if the element already exists in the hash set
            if (hash.count(num)) {
                return true;
            }

            // Insert the element if it is not already present
            hash.insert(num);
        }

        return false;
    }
};