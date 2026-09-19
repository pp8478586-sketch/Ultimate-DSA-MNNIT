class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1)return nums;
        vector<int>ans;
        int cad1=nums[0];
        int cad2=nums[1];
        int count1=0;
        int count2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==cad1){
                count1++;
            }
            else if(nums[i]==cad2){
                count2++;
            }
            else if(count1==0){
                cad1=nums[i];
                count1=1;
            }
            else if(count2==0){
                cad2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }

        }
        int freq1=0;
        int freq2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cad1){
                freq1++;
            }
            else if(nums[i]==cad2){
                freq2++;
            }
        }
        if(freq1>n/3)ans.push_back(cad1);
        if(freq2>n/3)ans.push_back(cad2);
        return ans;
    }
};