#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> counts;
        int current_run = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                current_run++;
            }
            else
            {
                counts.push_back(current_run);
                current_run = 1;
            }
        }
        counts.push_back(current_run);

        sort(counts.begin(), counts.end());
        int numBlocks = counts.size();

        vector<long long> prefSum(numBlocks + 1, 0);
        for (int i = 0; i < numBlocks; i++)
        {
            prefSum[i + 1] = prefSum[i] + counts[i];
        }

        long long reachableCount = 0;

        for (int elimIdx = 0; elimIdx < numBlocks; elimIdx++)
        {
            if (elimIdx > 0 && counts[elimIdx] == counts[elimIdx - 1])
            {
                continue;
            }
            long long nm = numBlocks - elimIdx;
            long long sumSurviving = prefSum[numBlocks] - prefSum[elimIdx];
            long long rem = k - sumSurviving;

            if (rem % nm == 0)
            {
                long long delta = rem / nm;
                long long max_M = counts[elimIdx] - 1;

                if (delta >= -max_M)
                {
                    reachableCount++;
                }
            }
        }
        cout << reachableCount << "\n";
    }
    return 0;
}