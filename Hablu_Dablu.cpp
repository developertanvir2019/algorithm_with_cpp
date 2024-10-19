#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, H;
    cin >> n >> H;

    vector<int> v;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        maxVal = max(maxVal, x);
    }

    bool hablu = true;
    bool dablu = false;
    while (H > 0 && maxVal > 0)
    {
        if (hablu)
        {
            maxVal--;
        }
        else
        {
            H -= maxVal;
        }
        swap(hablu, dablu);
    }


    if (H > maxVal)
    {
        cout << "Hablu";
    }
    else
    {
        cout << "Dablu";
    }

    return 0;
}