class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next;
        int hlen = haystack.length();
        int nlen = needle.length();
        next.push_back(0);
        int eq = 0;
        for(int i = 1; i < nlen; i++)
        {
            int last = eq;
            //printf("i %d last %d %c %c %d\n",i,last,needle[i-1],needle[last],next[last]);
            while(last != 0)
            {
                if(needle[i-1] == needle[last-1])
                {
                    eq++;
                    if(needle[i] == needle[last])
                        next.push_back(next[last]);
                    else
                        next.push_back(last);
                    break;
                }
                else
                    last = next[last];
            }
            if(last != 0)
                continue;
            if(needle[i-1] == needle[0])
            {
                eq++;
                if(needle[i] != needle[1])
                    next.push_back(1);
                else
                    next.push_back(0);
            }
            else
            {
                eq = 0;
                next.push_back(0);
            }
        }
        //for(int i = 0; i < nlen; i++)
        //    printf("%c %d\n",needle[i],next[i]);
        int i = 0, j = 0;
        while(i < hlen)
        {
            //printf("%d %c %d %c\n",i,haystack[i],j,needle[j]);
            if(j == nlen)
                return i - nlen;
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j == 0)
                    i++;
                j = next[j];
            }
        }
        if(j == nlen)
            return i - nlen;
        return -1;
    }
};