class Solution {
public:
    int normalBinarySearch(vector<int>& nums,int target,int lo,int hi){
        int mid = (lo+hi)/2;
        if(lo > hi)
            return -1;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target){
            return normalBinarySearch(nums,target,mid+1,hi);
          
        }
        else{
            return normalBinarySearch(nums,target,lo,mid-1);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        
        while(lo < hi) {
            int mid = (lo+hi)/2;
            if (nums[mid] > nums[hi]) lo = mid+1;
            else hi = mid;
        }
        cout<<lo;
        int rotate = lo;
        if (nums[rotate] <= target and nums[n-1] >= target) return normalBinarySearch(nums,target,rotate,n-1);
        else return normalBinarySearch(nums,target,0,rotate -1);
    }
};