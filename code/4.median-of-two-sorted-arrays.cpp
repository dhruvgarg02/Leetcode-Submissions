class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        int t = n+m;
        vector<double> v;
        double med;
        
        for(int i =0;i<n;i++)
        {
            v.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++)
        {
            v.push_back(nums2[i]);
        }
        sort(v.begin(), v.end());
        if(t%2 != 0)
        {
            med = v[(t-1)/2];
        }
        if(t%2 == 0)
        {
            med = (v[(t-1)/2] + v[t/2])/2;
        }
        
        return med;
    }
};