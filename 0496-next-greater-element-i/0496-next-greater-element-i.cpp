class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int element=nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==element){
                    int k=j;
                    while(k<nums2.size()-1&&nums2[k]<=element){
                        k++;
                    }
                    if(nums2[k]>element){
                        ans.push_back(nums2[k]);
                    }
                    else{
                        ans.push_back(-1);
                    }
                  

                }
            }
        }
        return ans;        
    }
};