class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> jlb;
        vector<int> rd;
        vector<int> ls;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            jlb.push_back(vector<int>());
            rd.push_back(0);
        }
        for(int i = 0; i < prerequisites.size(); i++){
            jlb[prerequisites[i].second].push_back(prerequisites[i].first);
            rd[prerequisites[i].first]++;
        }
        for(int i = 0; i < numCourses; i++)
            if(rd[i] == 0)
                ls.push_back(i);
        int ptr = 0;
        while(ptr<ls.size()){
            int k = ls[ptr];
            ans.push_back(k);
            for(int i = 0; i < jlb[k].size(); i++)
            {
                rd[jlb[k][i]]--;
                if(rd[jlb[k][i]] == 0)
                    ls.push_back(jlb[k][i]);
            }
            ptr++;
        }
        if(ans.size() == numCourses)
            return ans;
        else
            return vector<int>();
    }
};