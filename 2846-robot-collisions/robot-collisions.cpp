class Solution {
public:

    struct Robot {
        int pos;
        int health;
        char dir;
        int idx;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {

        int n = positions.size();

        vector<Robot> robots;

        for (int i = 0; i < n; i++) {
            robots.push_back(
                {positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end(),
             [](Robot &a, Robot &b) {
                 return a.pos < b.pos;
             });

        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (robots[i].dir == 'R') {
                st.push(i);
            }
            else {

                while (!st.empty() &&
                       robots[i].health > 0) {

                    int j = st.top();

                    if (robots[j].health < robots[i].health) {

                        robots[i].health--;

                        robots[j].health = 0;

                        st.pop();
                    }

                    else if (robots[j].health > robots[i].health) {

                        robots[j].health--;

                        robots[i].health = 0;
                    }

                    else {

                        robots[j].health = 0;
                        robots[i].health = 0;

                        st.pop();
                    }
                }
            }
        }

        vector<pair<int,int>> ans;

        for (auto &r : robots) {
            if (r.health > 0)
                ans.push_back({r.idx, r.health});
        }

        sort(ans.begin(), ans.end());

        vector<int> res;

        for (auto &x : ans)
            res.push_back(x.second);

        return res;
    }
};