struct trieNode{
    int countP = 0 ; 
     trieNode* children[26];
};


class Solution {
public:

trieNode* getNode(){
    //new node bnane ka funstion hai 
    trieNode* newNode = new trieNode();
    
    for(int i = 0 ; i< 26 ; i++){
        newNode->children[i] = nullptr;

    }
    newNode->countP= 0;
    return newNode;
    
}

void insert( string &word,trieNode* root){
    trieNode* crawl = root ; 
    for(char &ch : word){
        int idx = ch-'a';
    

    if(!crawl->children[idx]){
        //nhi exist kar raha to new bnado
crawl->children[idx]= getNode();
    }
    //If the child at this index does  exist then us pointer ke children ka count badha do and crawl ko aaddge badha do 
    crawl->children[idx]->countP +=1;
    //crawl ko aage badhado
    crawl = crawl->children[idx];
    }
}

int getScore(string word,trieNode* root){
    //root bnao 
    trieNode* crawl =root;
    int score = 0 ; 
    for(auto& ch : word){
        int idx = ch-'a';
        //index nikal lo 
        score += crawl ->children[idx]->countP;
        //jo countP ki value milti ja rahi score mai dak di and cr\wal ko aage badha do 
        crawl = crawl ->children[idx];
       
    }
     return score;
}
    vector<int> sumPrefixScores(vector<string>& words) {
        //root node bnao 
        //trieNode* root = getNode();//fir se empty trie bna dega 
        //so start fro the existing trie 

           // Step 1: create root
    trieNode* root = getNode();
        //ab trie bnao by inserting element 
        for(auto& word : words){
            insert(word, root);
        }
 // Step 3: calculate scores
    int n = words.size();
        vector<int>result(n);
        for(int i = 0 ; i< n ; i++){
            result[i]= getScore(words[i],root);
        }
        return result;
    }
};

//tc = total N word hai har word ke sare character par iterate(L) mna rahe ho 
// t.c = O(N*L) = s.c