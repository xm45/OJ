class Solution {
public:
    struct T
    {
        int v;
        int l;
        int r;
        int h;
        T(int v_, int l_, int r_, int h_)
            :v(v_),l(l_),r(r_),h(h_) {};
        bool operator <(const T &a) const  {  return v < a.v; }
        bool operator >(const T &a) const  {  return v > a.v; }
    };
    int get(priority_queue<T, vector<T>, less<T>> &height,int l)
    {
        //printf("get %d\n",l);
        while(height.size() && height.top().r <= l)
        {
            T now = height.top();
            //printf("get %d %d %d \n",now.l,now.r,now.h);
            height.pop();
        }
        if(height.size())
            return height.top().h;
        else
            return 0;
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<T, vector<T>, less<T>> height;
        priority_queue<T, vector<T>, greater<T>> rheap;
        vector<pair<int, int>> ans;
        for(vector<vector<int>>::iterator iter = buildings.begin(); iter != buildings.end(); iter++)
        {
            int l = (*iter)[0];
            int r = (*iter)[1];
            int h = (*iter)[2];
            //printf("%d %d %d\n",l,r,h);
            while(rheap.size() > 0 && rheap.top().r<=l)
            {
                T now = rheap.top();
                rheap.pop();
                //printf("pop now(%d %d %d)\n",now.l,now.r,now.h);
                int h = get(height,now.r);
                ans.push_back(pair<int,int>(now.r,h));
                //printf("%d %d r\n",r,h);
            }
            //printf("after r\n");
            height.push(T(h,l,r,h));
            rheap.push(T(r,l,r,h));
            ans.push_back(pair<int,int>(l,get(height,l)));
            //printf("%d %d l\n",l,h);
            //printf("after now\n");
        }
        while(rheap.size() > 0)
        {
            T now = rheap.top();
            rheap.pop();
            //printf("pop now(%d %d %d)\n",now.l,now.r,now.h);
            int h = get(height,now.r);
            ans.push_back(pair<int,int>(now.r,h));
            //printf("%d %d r\n",now.r,h);
        }
        vector<pair<int, int>> rans;
        int np = -1, nh = -1;
        //printf("real ans\n");
        for(vector<pair<int, int>>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            //printf("%d %d\n",(*iter).first,(*iter).second);
            if(np == (*iter).first)
                nh = max(nh,(*iter).second);
            else
            if(nh == (*iter).second)
                continue;
            else
            {
                if(np != -1)
                {
                    if(rans.size() && np == rans[rans.size()-1].first)
                        rans[rans.size()-1] = pair<int,int>(rans[rans.size()-1].first, max(rans[rans.size()-1].second, nh));
                    else
                    if(rans.size() && nh == rans[rans.size()-1].second)
                        nh = nh;//rans[rans.size()-1] = pair<int,int>(max(rans[rans.size()-1].first,np), rans[rans.size()-1].second);
                    else
                        rans.push_back(pair<int,int>(np,nh));
                }
                np = (*iter).first;
                nh = (*iter).second;
            }
        }
        if(np != -1)
            rans.push_back(pair<int,int>(np,nh));
        return rans;
    }
};