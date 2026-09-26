class Solution {
    double MedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int low = 0;
        int m = nums1.size();
        int n = nums2.size();
        int high = m;
        int partition = (m + n + 1) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int al =(mid==0)?INT_MIN:nums1[mid-1];
            int ar =(mid==m)?INT_MAX:nums1[mid];
            int temp = partition - mid;
            int bl = (temp==0)?INT_MIN:nums2[temp-1];
            int br = (temp==n) ?INT_MAX:nums2[temp];
            if (max(al, bl) <= min(ar, br)) {
                if ((m + n) % 2 == 0) {
                    return (max(al, bl) + min(ar, br)) / 2.0;
                }
                return max(al, bl);
            } 
            else if (al>br) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return 0.0;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() <= nums2.size()) {
            return MedianSortedArrays(nums1, nums2);
        } else {
            return MedianSortedArrays(nums2, nums1);
        }
    }
};