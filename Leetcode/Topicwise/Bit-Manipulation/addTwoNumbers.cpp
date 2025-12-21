class Solution
{
public:
    int getSum(int a, int b)
    {
        int s = 0, c = 0, temp = 1;
        while (a > 0 and b > 0)
        {
            int l = a & 1, m = b & 1;
            s = l ^ m ^ c;
            c = (l & m) | (l & c) | (m & c);
            temp = temp << 1;
            temp = temp | s;
            a >>= 1, b >>= 1;
        }
        while (a > 0)
        {
            int l = a & 1;
            s = l ^ c;
            c = l & c;
            temp <<= 1;
            temp = temp | s;
            a >>= 1;
        }
        while (b > 0)
        {
            int m = b & 1;
            s = m ^ c;
            c = m & c;
            temp <<= 1;
            temp = temp | s;
            b >>= 1;
        }
        if (c)
        {
            temp = temp << 1;
            temp = temp | c;
        }
        int ans = 0;
        while (temp)
        {
            ans = ans << 1;
            ans = ans | (temp & 1);
            temp = temp >> 1;
        }
        ans >>= 1;
        return ans;
    }
};