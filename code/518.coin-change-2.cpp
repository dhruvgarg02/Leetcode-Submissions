class Solution {
public:
    int change(int n, vector<int>& S) {
        int m = S.size();
        int table[n+1];

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));


    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    for(int i = 0; i < n+1; i++)
    {
        cout<<table[i]<<" ";
    }
    cout<<"\n";
    return table[n];
    }
};