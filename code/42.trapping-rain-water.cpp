class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
                int l = 0, r = n-1, maxl = 0, maxr = 0, water = 0;
        while(l!=r){
            if(arr[l] <= arr[r]){
                maxl = max(maxl, arr[l]);
                water += maxl - arr[l];
                l++;
            }
            else{
                maxr = max(maxr, arr[r]);
                water += maxr - arr[r];
                r--;
            }
        }
        return water;
    }
};