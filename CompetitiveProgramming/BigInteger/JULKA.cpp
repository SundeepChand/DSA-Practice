#include <bits/stdc++.h>
using namespace std;

char digitToChar(int x)
{
    return x + '0';
}

int charToDigit(char c)
{
    return c - '0';
}

string add(string n, string k)
{
    reverse(n.begin(), n.end());
    reverse(k.begin(), k.end());

    int a = n.size(), b = k.size();
    if (a < b)
    {
        swap(n, k);
        swap(a, b);
    }

    string res = "";
    int carry = 0;
    for (int i = 0; i < b; i++)
    {
        int d1 = charToDigit(n[i]), d2 = charToDigit(k[i]);
        int sum = d1 + d2 + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    for (int i = b; i < a; i++)
    {
        int d1 = charToDigit(n[i]);
        int sum = d1 + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
    }
    while (carry > 0)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

string half(string x)
{
    reverse(x.begin(), x.end());
    // TODO
}

string subtract(string x, string y)
{
    // TODO
}

int main()
{
    string n, k;
    cin >> n >> k;

    string x2 = add(n, k);
    string x = half(x2);
    string klaudia = x;
    string natalie = subtract(x, k);
    cout << klaudia << endl;
    cout << natalie << endl;
    return 0;
}