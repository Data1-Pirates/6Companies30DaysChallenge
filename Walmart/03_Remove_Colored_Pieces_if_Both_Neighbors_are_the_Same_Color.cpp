#include <bits/stdc++.h>
using namespace std;

bool winnerOfGame(string colors)
{
    int a = 0, b = 0;
    int a1 = 0, b1 = 0;
    int n = colors.length();
    for (int i = 0; i < n; i++)
    {
        if (colors[i] == 'A')
        {
            b1 = 0, a1++;
            if (a1 > 2)
                a++;
        }
        if (colors[i] == 'B')
        {
            a1 = 0, b1++;
            if (b1 > 2)
                b++;
        }
    }
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string colors = "AAABABB";
    if (winnerOfGame(colors))
        cout << "Winner: Alice\n";
    else
        cout << "Winner: Bob\n";

    return 0;
}