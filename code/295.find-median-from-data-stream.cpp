class MedianFinder {
    vector<int> v;

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        v.resize(v.size() + 1);
        int i;
        for (i = v.size()-2; i >= 0; i--) {
            v[i+1] = v[i];
            if (num >= v[i]) break;
        }
        v[i+1] = num;
    }

    // Returns the median of current data stream
    double findMedian()
    {
        // sort(store.begin(), store.end());

        int n = v.size();
        return (n & 1 ? v[n / 2] : ((double) v[n / 2 - 1] + v[n / 2]) * 0.5);
    }
};