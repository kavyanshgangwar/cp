#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;
    deque<char> ans;
    if (abs(p3 - p4) > 1)
    {
 
        cout << -1 << "\n";
        return 0;
    }
    if (p3 == p4)
    {
        for (int i = 1; i < p3; i++)
        {
            ans.push_back('4');
            ans.push_back('7');
            p1--;
            p2--;
        }
        if (p1 < 1 or p2 < 1)
        {
            cout << "-1\n";
            return 0;
        }
        if (p1 >= 2)
        {
            ans.push_back('4');
            p1--;
            if (p1 < 1 or p2 < 1)
            {
                cout << "-1\n";
                return 0;
            }
            while (p2 > 0)
            {
                ans.push_back('7');
                p2--;
            }
            ans.push_back('4');
            p1--;
            while (p1 > 0)
            {
                ans.push_front('4');
                p1--;
            }
        }
        else
        {
 
            p2--;
            if (p1 < 1 or p2 < 1)
            {
                cout << "-1\n";
                return 0;
            }
            ans.push_back('4');
            p1--;
            while (p2 > 0)
            {
                ans.push_back('7');
                p2--;
            }
            while (p1 > 0)
            {
                ans.push_front('4');
                p1--;
            }
 
            ans.push_front('7');
        }
        for (auto x : ans)
            cout << x;
        cout << endl;
        return 0;
    }
    else
    {
        if (p3 > p4)
        {
            for (int i = 0; i < p3 - 1; i++)
            {
                ans.push_back('4');
                ans.push_back('7');
                p1--;
                p2--;
            }
            if (p1 < 1 or p2 < 1)
            {
                cout << "-1\n";
                return 0;
            }
 
            ans.push_front('7');
            p2--;
            while (p1 > 0)
            {
                ans.push_front('4');
                p1--;
            }
            while (p2 > 0)
            {
                ans.push_back('7');
                p2--;
            }
        }
        else
        {
            for (int i = 0; i < p4 - 1; i++)
            {
                if (i == 0)
                {
                    ans.push_back('4');
                    p1--;
                    p2--;
                    continue;
                }
                ans.push_back('7');
                ans.push_back('4');
                p1--;
                p2--;
            }
            if (p1 < 1 or p2 < 1)
            {
                cout << "-1\n";
                return 0;
            }
            while (p2 > 0)
            {
                ans.push_back('7');
                p2--;
            }
            ans.push_back('4');
            p1--;
            while (p1 > 0)
            {
                ans.push_front('4');
                p1--;
            }
            ans.push_front('7');
        }
        for (auto x : ans)
            cout << x;
        cout << endl;
    }
}