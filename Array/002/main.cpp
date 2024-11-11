class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> combine(m + n, 0);
        
        int i = 0, j = 0, k = 0;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                combine[k++] = nums1[i++];
            } else {
                combine[k++] = nums2[j++];
            }
        }
        
        while (i < m) {
            combine[k++] = nums1[i++];
        }
        while (j < n) {
            combine[k++] = nums2[j++];
        }

        int total = m + n;
        if (total % 2 == 1) {
            return combine[total / 2];
        } else {
            return (combine[total / 2 - 1] + combine[total / 2]) / 2.0;
        }
    }
};