class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1000000007, l = 0, r = nums.size() - 1;
        vector<int> pre = {1};
        for (auto i = 1; i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);   
                
        sort(begin(nums), end(nums));
        
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pre[r - l++]) % mod;
            }
        }

        return res;
    }
};