class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n,si; n = asteroids.size();
        vector<int> ans; stack<int> s;
        for (int i = 0 ; i < n ; i++) {
            while (!s.empty() && asteroids[i] < 0 && (-1)* asteroids[i] > asteroids[s.top()]) {
                s.pop();
            }
            if (!s.empty() && asteroids[i] < 0 && (-1)* asteroids[i] == asteroids[s.top()]) {
                s.pop(); continue;
            }
            if (s.empty() && asteroids[i] < 0) ans.push_back(asteroids[i]);
            if (asteroids[i] > 0) s.push(i);
        }
        si = ans.size();
        while(!s.empty()) {ans.insert(ans.begin()+si,asteroids[s.top()]); s.pop();}
        return ans;
    }
};