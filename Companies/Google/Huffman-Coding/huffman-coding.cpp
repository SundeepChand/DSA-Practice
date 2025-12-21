// https://leetcode.com/discuss/post/416316/google-onsite-software-engineer-huffman-f1zfq/
#include <bits/stdc++.h>
using namespace std;

const char INTERNAL_NODE_MARKER = '$';

class Node
{
public:
    char c;
    int freq;
    Node *left, *right;
    // Keep track of the characters in the sub-tree for the desired solution.
    vector<char> subChars;

    Node(char c, int freq)
    {
        this->c = c;
        this->freq = freq;
        left = right = NULL;
        subChars.push_back(c);
    }
};

class NodeComparator
{
public:
    bool operator()(Node *a, Node *b)
    {
        if (a->freq == b->freq)
        {
            return a->c > b->c;
        }
        return a->freq > b->freq;
    }
};

class HuffmanEncoder
{
public:
    virtual unordered_map<char, vector<bool>> getEncodings() = 0;
    virtual vector<bool> encode(string) = 0;
    virtual string decode(vector<bool>) = 0;
    virtual double getCompressionRatio(string) = 0;
};

// ------- Naive Huffman Coding ---------
class HuffmanEncoderNaive : public HuffmanEncoder
{
public:
    unordered_map<char, vector<bool>> mp;
    Node *root;

    HuffmanEncoderNaive(string str)
    {
        // Build the encoder tree based on input
        priority_queue<Node *, vector<Node *>, NodeComparator> pq;

        unordered_map<char, int> freq;
        for (char c : str)
        {
            freq[c]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            pq.push(new Node(it->first, it->second));
        }

        // Edge case, when there is only 1 character
        if (pq.size() == 1)
        {
            Node *internal = new Node('$', pq.top()->freq);
            internal->left = pq.top();
            pq.pop();
            pq.push(internal);
        }

        while (pq.size() > 1)
        {
            auto left = pq.top();
            pq.pop();

            auto right = pq.top();
            pq.pop();

            Node *internal = new Node(INTERNAL_NODE_MARKER, left->freq + right->freq);
            internal->left = left;
            internal->right = right;
            pq.push(internal);
        }

        root = pq.top();
        pq.pop();

        // Generate the code mappings
        vector<bool> cur;
        generateCode(root, cur);
    }

    // private
    void generateCode(Node *cur, vector<bool> &curCode)
    {
        if (cur->c != INTERNAL_NODE_MARKER)
        {
            mp[cur->c] = curCode;
            return;
        }
        if (cur->left != NULL)
        {
            curCode.push_back(0);
            generateCode(cur->left, curCode);
            curCode.pop_back();
        }
        if (cur->right != NULL)
        {
            curCode.push_back(1);
            generateCode(cur->right, curCode);
            curCode.pop_back();
        }
    }

    unordered_map<char, vector<bool>> getEncodings() override
    {
        return mp;
    }

    vector<bool> encode(string input) override
    {
        // Encode the input string using the tree
        vector<bool> res;

        for (char c : input)
        {
            vector<bool> enc = mp[c];
            res.insert(res.end(), enc.begin(), enc.end());
        }
        return res;
    }

    double getCompressionRatio(string input) override
    {
        // Return the compression ratio
        vector<bool> encoded = encode(input);
        return (8 * input.size() * 100) / double(encoded.size());
    }

    string decode(vector<bool> encoded) override
    {
        // Return the decoded string
        Node *cur = root;

        string res = "";

        traverse(encoded, 0, root, res);
        return res;
    }

    // private method
    void traverse(const vector<bool> &encoded, int i, Node *cur, string &res)
    {
        if (cur->c != INTERNAL_NODE_MARKER)
        {
            res.push_back(cur->c);
            traverse(encoded, i, root, res);
            return;
        }
        if (i >= encoded.size())
        {
            return;
        }
        if (encoded[i] == 0)
        {
            traverse(encoded, i + 1, cur->left, res);
        }
        else
        {
            traverse(encoded, i + 1, cur->right, res);
        }
    }
};

// ------- Huffman Coding Solution ---------
class HuffmanEncoderSolution : public HuffmanEncoder
{
public:
    unordered_map<char, vector<bool>> mp;
    Node *root;

    HuffmanEncoderSolution(string str)
    {
        // Build the encoder
        unordered_map<char, int> freq;

        for (char c : str)
        {
            freq[c]++;
        }

        priority_queue<Node *, vector<Node *>, NodeComparator> pq;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            pq.push(new Node(it->first, it->second));
        }

        if (pq.size() == 1)
        {
            auto internal = new Node('$', pq.top()->freq);
            internal->left = pq.top();

            mp[pq.top()->c] = {0};

            pq.pop();
            pq.push(internal);
        }
        while (pq.size() > 1)
        {
            auto left = pq.top();
            pq.pop();

            auto right = pq.top();
            pq.pop();

            // Update the encodings for sub-characters in left & right
            for (char c : left->subChars)
            {
                if (mp.find(c) == mp.end())
                {
                    mp[c] = vector<bool>();
                }
                mp[c].push_back(0);
            }

            for (char c : right->subChars)
            {
                if (mp.find(c) == mp.end())
                {
                    mp[c] = vector<bool>();
                }
                mp[c].push_back(1);
            }

            Node *internal = new Node('$', left->freq + right->freq);
            internal->subChars.insert(internal->subChars.end(), left->subChars.begin(), left->subChars.end());
            internal->subChars.insert(internal->subChars.end(), right->subChars.begin(), right->subChars.end());

            internal->left = left;
            internal->right = right;

            pq.push(internal);
        }

        root = pq.top();
        pq.pop();

        // Reverse the encodings
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            reverse(it->second.begin(), it->second.end());
        }
    }

    unordered_map<char, vector<bool>> getEncodings() override
    {
        return mp;
    }

    vector<bool> encode(string input) override
    {
        // Encode the input string using the tree
        vector<bool> res;

        for (char c : input)
        {
            vector<bool> enc = mp[c];
            res.insert(res.end(), enc.begin(), enc.end());
        }
        return res;
    }

    double getCompressionRatio(string input) override
    {
        // Return the compression ratio
        vector<bool> encoded = encode(input);
        return (8 * input.size() * 100) / double(encoded.size());
    }

    string decode(vector<bool> encoded) override
    {
        // Return the decoded string
        Node *cur = root;

        string res = "";

        traverse(encoded, 0, root, res);
        return res;
    }

    // private method
    void traverse(const vector<bool> &encoded, int i, Node *cur, string &res)
    {
        if (cur->c != INTERNAL_NODE_MARKER)
        {
            res.push_back(cur->c);
            traverse(encoded, i, root, res);
            return;
        }
        if (i >= encoded.size())
        {
            return;
        }
        if (encoded[i] == 0)
        {
            traverse(encoded, i + 1, cur->left, res);
        }
        else
        {
            traverse(encoded, i + 1, cur->right, res);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (n--)
    {
        string input;
        getline(cin, input);

        HuffmanEncoder *enc = new HuffmanEncoderSolution(input);
        cout << enc->getCompressionRatio(input) << ": " << enc->decode(enc->encode(input)) << ": ";
        for (auto x : enc->encode(input))
        {
            cout << x;
        }
        cout << endl;
    }

    return 0;
}