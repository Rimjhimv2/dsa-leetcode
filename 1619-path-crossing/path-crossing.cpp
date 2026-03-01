class Solution {
public:
    bool isPathCrossing(string path) {
        

// set bnaya jo unique 2 value lega 
        set<pair<int,int>> visited;

int x = 0, y = 0;
//add kra a
visited.insert({0, 0});

for(int i = 0; i<path.length() ; i++){
    int ch = path[i];
    if(ch == 'E') x++;
    else if(ch =='W') x--;
    else if(ch == 'S') y--;
    else y++;

    if(visited.count({x,y})){
        return true;
    }
    visited.insert({x,y});


}
return false;
    }
};