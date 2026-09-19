class Solution {
   
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first=m-1;
        int end=n+m-1;
        int second=n-1;
        while(first>=0&&second>=0){
            if(nums1[first]>=nums2[second]){
                nums1[end]=nums1[first];
                nums1[first]=0;
                first--;
                end--;
            }
            else{
                nums1[end]=nums2[second];
                second--;
                end--;
            }
        }
        while(second>=0){
            nums1[end]=nums2[second];
            end--;
            second--;
        }
        

    }
};