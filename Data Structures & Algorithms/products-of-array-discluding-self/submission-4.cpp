class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), left = 1, right = 1;

        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> res(n);

        for(int i = 0 ; i < n ; i++) {
            prefix[i] = left;
            left *= nums[i];
        }

        for(int i = n - 1 ; i >= 0 ; i--) {
            suffix[i] = right;
            right *= nums[i];
        }

        for(int i = 0 ; i < n ; i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
