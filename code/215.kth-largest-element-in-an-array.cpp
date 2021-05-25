class Solution {
public:
    int partition(vector<int> &v, int l, int r){
    int pivot = v[r];
    int i = l-1;
    for(int j = l; j < r; j++){
        if(pivot > v[j]){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[r]);
    return i+1;
}
    int kthSmallest(vector<int> &v, int l, int r, int k){
    int dis = partition(v, l, r);
    if(dis < k)
        return kthSmallest(v, dis+1, r, k);
    else if(dis > k)
        return kthSmallest(v, l, dis-1, k);
    else
        return v[dis];
}
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        return kthSmallest(nums, l, r, n-k);
    }
};