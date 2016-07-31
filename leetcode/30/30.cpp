class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty())
            return ans;
        int slen = s.length();
        int wlen = words[0].length();
        int n = words.size();
        if(words[0].empty())
        {
            for(int i = 0; i <= slen; i++)
                ans.push_back(i);
            return ans;
        }
        map<string,int> table,used;
        for(auto &word : words)
        {
            table[word]++;
            used[word] = 0;
            //printf("%s\n",word.c_str());
        }
        //printf("\n");
        for(int i = 0; i < wlen;i++)
        {
            int start = i;
            int end = i;
            string first;
            for(auto &u :used)
                    u.second = 0;
            while(start <= slen - n*wlen)
            {
                if(end == start + n*wlen)
                    ans.push_back(start);
                string now = s.substr(end, wlen);
                if(start == end)
                    first = now;
                end += wlen;
                first = s.substr(start,wlen);
                //printf("start %4d end %4d first  %s now  %s\n",start,end,first.c_str(),now.c_str());
                map<string,int>::iterator iter = table.find(now);
                if(iter == table.end())
                {
                    start = end;
                    for(auto &u :used)
                        u.second = 0;
                }
                else
                {
                    //printf("used %d table %d\n",used[now],table[now]);
                    if(used[now] == table[now])
                    {
                        while(start < slen - n*wlen && now != first)
                        {
                            start += wlen;
                            used[first]--;
                            first = s.substr(start,wlen);
                        }
                        start += wlen;
                    }
                    else
                    {
                        used[now]++;
                    }
                }
            }
        }
    }
};