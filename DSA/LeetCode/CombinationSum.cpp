#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findNumbers(vector<int>& ar, int sum, vector<vector<int> >& res, vector<int>& r, int i)
{
    if (sum == 0) {
        res.push_back(r);
        return;
    }

    while (i < ar.size() && sum - ar[i] >= 0) {

        r.push_back(ar[i]); // add them to list

        findNumbers(ar, sum - ar[i], res, r, i);
        i++;

        r.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& ar, int sum)
{
    // sort input array
    sort(ar.begin(), ar.end());

    // remove duplicates
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    vector<int> r;
    vector<vector<int> > res;
    findNumbers(ar, sum, res, r, 0);

    return res;
}

int main()
{
    

    return 0;
}