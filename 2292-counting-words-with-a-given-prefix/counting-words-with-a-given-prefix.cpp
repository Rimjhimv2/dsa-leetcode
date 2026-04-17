struct trieNode{
    trieNode* children[26];
    bool isEndOfNode;
    int count;
};
///ab tum new node bnao  
trieNode* getNode(){
    trieNode* newNode = new trieNode();
    newNode->isEndOfNode = false;
    newNode->count = 0 ; 
    for(int i = 0 ; i< 26 ; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie{
    public:
    trieNode*root;
    Trie(){
        root = getNode();
        //ye constuctor ek naya node bnati hai or usko root mai store kar deti hai 
    }

    void insert(string word){

        trieNode* pcrawl = root;
        for(char &ch: word){
            //word ke har character par loop chalega 
            //ab tum character ko  index m convert kro 
            int idx = ch - 'a';

if(pcrawl->children[idx] == NULL){
    pcrawl->children[idx] = getNode();
}
//ab pointer ko next char  mai move krdo
pcrawl= pcrawl->children[idx];
pcrawl->count++;
        }
        pcrawl->isEndOfNode = true;
    }
///“kitne words given prefix pref se start hote hain”

    int searchPrefixCount(string pref){
        trieNode*pcrawl = root;
        //ham trie ke starting node se start karte hai 
       
        for(char & ch : pref){
             int idx = ch - 'a';
            if(pcrawl->children[idx] == NULL){
                return 0 ; 
            }
            pcrawl = pcrawl->children[idx];
        }
        return pcrawl->count;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie; 
        //ek empty trie ban gya 
        //yeh range based loop hai 
        //yaha word mai ek ek aayega like phle cat, car,dog ese aayega 

        //words = ["cat", "car", "dog"]
        //words = ["cat", "car", "dog"]
        for(string &word : words) {
        trie.insert(word);
    }

    return trie.searchPrefixCount(pref);
    }
};