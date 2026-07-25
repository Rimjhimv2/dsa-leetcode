class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
int n = board.size();
        vector<set<char>>row(9);
        vector<set<char>>col(9);
        vector<set<char>>boxes(9);

        for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j<n; j++){
                if(board[i][j]=='.'){
                    continue;
                }



                char num = board[i][j];

                //num = '5';

                int box = (i/3)*3 + (j/3);

                 if(row[i].count(num) || col[j].count(num) || boxes[box].count(num)){


                    return false;
                 }
                 row[i].insert(num);
                 col[j].insert(num);
                 boxes[box].insert(num);

            }
        }

return true;
    }
};