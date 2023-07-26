class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 4 cases:
        // all +ve -> just perform max product subarray
        // even -ve -> same just perform max product and -ve will be cancelled
        // odd -ve -> we need prefix and suffix as we need to exclude one -ve each time, due to this our array turns into 2 halves, so we run from front and then from end and keep finding the max product
        // 0 -> now prefix and suffix will fail if we encounter 0 thus we need to ignore 0s by dividing the the whole array into parts and ignoring 0s thus when 0 comes we start from scratch i.e., 1

        int prefix = 1, sufix = 1;
        int ans = INT_MIN;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(prefix == 0) prefix = 1;
            if(sufix == 0) sufix = 1;

            prefix = prefix * nums[i];
            sufix = sufix * nums[n-i-1];

            ans = max(ans, max(prefix, sufix));
        }

        return ans;
    }
};