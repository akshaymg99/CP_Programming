// Shortest distance to target color

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        using vec3 = array<int, 3>;
        constexpr vec3 invalid = {INT_MAX, INT_MAX, INT_MAX};
        vector<vec3> dist(n, invalid);

        for(auto [first, last, step] : {tuple(0, n, 1), tuple(n-1, -1, -1)} ){
            vec3 prev = invalid;
            for(int i=first; i!=last; i+=step){
                for(int c=0; c<3; ++c)
                    if(colors[i] == c+1)
                        dist[i][c] = 0;
                    else
                        dist[i][c] = min(dist[i][c], prev[c]==INT_MAX ? INT_MAX : prev[c]+1);
                prev = dist[i];
            }
        }

        vector<int> ans;
        for(auto& q : queries){
            int d = dist[q[0]][q[1]-1];
            if(d == INT_MAX) d = -1;
            ans.push_back(d);
        }
        return ans;
        }
};