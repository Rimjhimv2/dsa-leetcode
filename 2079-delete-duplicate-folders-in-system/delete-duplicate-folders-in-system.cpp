class Solution {
public:

    struct Node{
        string val;
        string subFolder;
        unordered_map<string,Node*> children;

        Node(string v){
            val = v;
            subFolder = "";
        }
    };

    // 🔹 create node
    Node* getNode(string val){
        return new Node(val);
    }

    // 🔹 insert path into trie
    void insert(Node* root, vector<string>& path){
        for(auto &folder : path){
            if(!root->children.count(folder)){
                root->children[folder] = getNode(folder);
            }
            root = root->children[folder];
        }
    }

    // 🔹 build subtree string + count
    string populateNodes(Node* root, unordered_map<string,int>& subFolderMap){

        vector<pair<string,string>> subFolderPaths;

        for(auto &[childName, child] : root->children){
            string sub = populateNodes(child, subFolderMap);
            subFolderPaths.push_back({childName, sub});
        }

        sort(subFolderPaths.begin(), subFolderPaths.end());

        string completePath = "";

        for(auto &[childName, childPath] : subFolderPaths){
            completePath += "(" + childName + childPath + ")";
        }

        root->subFolder = completePath;

        if(!completePath.empty()){
            subFolderMap[completePath]++;
        }

        return completePath;
    }

    // 🔹 remove duplicate subtrees
    void removeDuplicates(Node* root, unordered_map<string,int>& subFolderMap){
        for(auto it = root->children.begin(); it != root->children.end(); ){

            Node* child = it->second;

            if(child->subFolder != "" && subFolderMap[child->subFolder] > 1){
                it = root->children.erase(it);
            }
            else{
                removeDuplicates(child, subFolderMap);
                ++it;
            }
        }
    }

    // 🔹 build result
    void constructResult(Node* root, vector<string>& path, vector<vector<string>>& result){

        for(auto &[name, child] : root->children){
            path.push_back(name);
            result.push_back(path);

            constructResult(child, path, result);

            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {

        Node* root = getNode("/");

        // build trie
        for(auto &path : paths){
            insert(root, path);
        }

        unordered_map<string,int> subFolderMap;

        // step 1: build subtree strings
        populateNodes(root, subFolderMap);

        // step 2: remove duplicates
        removeDuplicates(root, subFolderMap);

        vector<vector<string>> result;
        vector<string> path;

        constructResult(root, path, result);

        return result;
    }
};
//koi bhi 2 folder ko identical kab bolte ho jab unke subfolders mai identical set ke ho 
//root->children['a']=newNode;

// es line ka matlab ye hai ki root ek folder manlo and childern uska subfolder to root se  a folder nahi tha toh humne naaaya node bnaliya 


///hame traversal karna or uske subfolders ko store karna hai 

//jo bhi subfolder milega usko sort jarur karna 
//sirf sorting se kaam nhi chalega unke subfolders ka structure bhi same hona chaiye 
//  👉 Iska structure:

// a ke 2 children → c, d
// d ke niche → e

//es structure ka subfolder = (c)(d(e))
// a
// ├── c
// └── d
//      └── e
// // 👉 Iska structure:

// b ke 2 children → e, c
// c ke niche → d

//es structure ka subfolder = (c(d))(e)

// b
// ├── e
// └── c
//      └── d  
// yaha en dono ka structure hi alag hohgya...sorting karne se fas ja rahe hai 

///1step= create trie
//2nd step = populate node values
// usme sort kero
// then use brackets

//map use kro 
//agar dublicate value mili to remove bhi karna hoga 

