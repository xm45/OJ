class Solution {
	double findkth(vector<int>::iterator a,int m, vector<int>::iterator b, int n, int k)
	{
		if(m > n)
			return findkth(b,n,a,m,k);
		if(m == 0)
			return b[k-1];
		if(k == 1)
			return min(*a,*b);

		int ptra = min(k/2,m);
		int ptrb = k - ptra;
		if(*(a + ptra - 1) < *(b + ptrb -1))
			return findkth(a+ptra,m-ptra,b,n,k-ptra);
		else if(*(a + ptra -1) > *(b + ptrb -1))
			return findkth(a,m,b+ptrb,n-ptrb,k-ptrb);
		else
			return *(a+ptra-1);
	}
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>::iterator a = nums1.begin();
		vector<int>::iterator b = nums2.begin();
		int m = nums1.size(), n = nums2.size();
		int sum = m + n;

		if(sum%2)
			return findkth(a, m, b, n, sum/2 + 1);
		else
			return (findkth(a, m, b, n, sum/2) +
					findkth(a, m, b, n, sum/2 + 1))/2;
	}
};