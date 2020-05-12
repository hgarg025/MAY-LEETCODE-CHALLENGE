class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2])
            return nums[nums.size()-1];
        int beg=0;
        int end=nums.size()-1;
        while(beg<=end)
        {
            int mid = (beg+end)/2;
            if(mid%2==0)
            {
            if(nums[mid]==nums[mid-1])
                end=mid;
            else if(nums[mid]==nums[mid+1])
                beg=mid;
            else
                return nums[mid];
            }
            else
            {
                if(nums[mid]!=nums[mid-1])
                end=mid;
            else if(nums[mid]!=nums[mid+1])
                beg=mid;
            else
                return nums[mid];
            }
        }
        return 0;
    }
};
