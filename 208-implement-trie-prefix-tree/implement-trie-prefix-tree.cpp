 class Trie {
public:

    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    // Node create karne ka function
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }

    // 🔹 INSERT FUNCTION
    void insert(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];

            // index nikaalo (a=0, b=1 ...)
            int index = ch - 'a';

            // agar node exist nahi karta
            if (crawler->children[index] == NULL) {
                crawler->children[index] = getNode();
            }

            // move to next node
            crawler = crawler->children[index];
        }

        // last node pe mark karo
        crawler->isEndOfWord = true;
    }

    // 🔹 SEARCH FUNCTION
    bool search(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (crawler->children[index] == NULL) {
                return false;
            }

            crawler = crawler->children[index];
        }

        return crawler->isEndOfWord;
    }

    // 🔹 PREFIX CHECK
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';

            if (crawler->children[index] == NULL) {
                return false;
            }

            crawler = crawler->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */