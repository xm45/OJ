class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> a;
    priority_queue<int, vector<int>, greater<int>> b;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(b.size() == 0 || num<b.top())
            a.push(num);
        else
            b.push(num);
        if(a.size() > b.size() + 1){
            int at = a.top();
            a.pop();
            b.push(at);
        }
        if(b.size()  > a.size()){
            int bt = b.top();
            b.pop();
            a.push(bt);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
         if(a.size() == b.size())
            return (a.top()+b.top())/2.00;
        else
            return a.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();