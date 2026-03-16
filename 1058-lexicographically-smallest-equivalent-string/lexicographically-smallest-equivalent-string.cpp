class Solution {
public:
    
    char DFSFindMinChar(unordered_map<char, vector<char>>& adj, char ch, vector<int>& visited) {

        visited[ch-'a']= true;
        char minStr= ch;
        // ab ch ka neighbour dekho adj list ki help se
        for(int i =0; i<adj[ch].size();i++){
            int neigh= adj[ch][i];
            if(!visited[neigh-'a']){
                char curr = DFSFindMinChar(adj, neigh, visited);
                minStr= min(minStr,curr);
            }
            }
            return minStr;
        }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int m = s1.size();
        int n = baseStr.size();
unordered_map <char, vector<char>>adj;
        for(int i =0; i<m ;i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        string result;
        for(int i=0;i<n;i++){
            char ch = baseStr[i];
vector<int>visited(26,0);
            char minStr = DFSFindMinChar(adj,ch,visited);
            result.push_back(minStr);      }
        return result;
        
    }
};