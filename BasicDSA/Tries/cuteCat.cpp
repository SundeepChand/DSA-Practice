#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
        unordered_map<char, TrieNode*> children;
        bool isLeaf;
        TrieNode()
        {
            isLeaf = false;
        }
};

class Trie
{
    TrieNode* root;

    public:
        Trie()
        {
            root = new TrieNode();
        }
        void insert(string word)
        {
            TrieNode* cur = root;
            for (auto x: word)
            {
                if (cur->children.find(x) == cur->children.end())
                    cur->children[x] = new TrieNode();
                cur = cur->children[x];
            }
            cur->isLeaf = true;
        }
        void exists(const string &s, int i, unordered_set<string> &u)
        {
            int n = s.length();
            TrieNode* cur = root;

            string word = "";
            char c = s[i];
            while (cur->children.find(c) != cur->children.end() && i < n)
            {
                word += c;
                cur = cur->children[c];
                if (cur->isLeaf)
                {
                    u.insert(word);
                }
                i++;
                c = s[i];
            }
        }
};

vector<bool> solve(string document, vector<string> words)
{
    Trie t;
    for (auto x: words)
    {
        t.insert(x);
    }

    // Find all the substrings that appear in the document
    int n = document.size();
    unordered_set<string> u;
    for (int i = 0; i < n; i++)
    {
        t.exists(document, i, u);
    }

    // Create the ans vector from the map
    vector<bool> ans(words.size());
    for (int i = 0; i < words.size(); i++)
    {
        if (u.find(words[i]) != u.end())
            ans[i] = true;
        else
            ans[i] = false;
    }
    return ans;
}

int main()
{
    string document = "little cute cat loves to code in c++, java & python.";
    vector<string> words = {"cute cat", "ttle", "cutest", "cat", "quick", "big", "python"};

    vector<bool> ans = solve(document, words);
    for (int i = 0; i < words.size(); i++)
    {
        cout<<words[i]<<": "<<ans[i]<<endl;
    }

    // Trie t;
    // for (auto x: words)
    //     t.insert(x);
    return 0;
}