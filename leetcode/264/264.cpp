class Solution {
public:
    int nthUglyNumber(int n) {
          priority_queue<long long,vector<long long>,greater<long long>> q;
          set<long long> hash;
          q.push(1);
          hash.insert(1);
          long long last = 0;
          long long add = 0;
          while(n--)
          {
              last = q.top();
              q.pop();
              add = last*2;
              if(hash.find(add)==hash.end())
              {
                q.push(add);
                hash.insert(add);
              }
              add = last*3;
              if(hash.find(add)==hash.end())
              {
                q.push(add);
                hash.insert(add);
              }
              add = last*5;
              if(hash.find(add)==hash.end())
              {
                q.push(add);
                hash.insert(add);
              }
              //printf("%d\n",last);
          }
          return last;
    }
};