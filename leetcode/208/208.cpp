class TrieNode {
public:
    char val;
    int end;
    TrieNode *next[26];
    // Initialize your data structure here.
    TrieNode(){
        val = ' ';
        end = 0;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    TrieNode(char v, int isEnd = 0) {
        val = v;
        end = isEnd;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
   }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* now = root;
        int len = word.length();
        for(int i = 0; i < len; i++)
        {
            int c = word[i] - 'a';
            if(now->next[c] == NULL)
            {
                now->next[c] = new TrieNode(word[i],0);
            }
            now = now->next[c];
        }
        now->end++;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* now = root;
        int len = word.length();
        for(int i = 0; i < len; i++)
        {
            int c = word[i] - 'a';
            if(now->next[c] == NULL)
                return false;
            now = now->next[c];
        }
        return now->end != 0;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* now = root;
        int len = prefix.length();
        for(int i = 0; i < len; i++)
        {
            int c = prefix[i] - 'a';
            if(now->next[c] == NULL)
                return false;
            now = now->next[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");