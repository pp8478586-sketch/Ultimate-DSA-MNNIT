class Solution {
public:
    bool sorted(vector<int>arr) {
        
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
               return false; 
                
            }
            
                 }
    return true;
    }
    // bool checksort(vector<int>&arr){
    //     if(sorted(arr)){
    //         return true;
    //     }
    //     else{
    //     vector<int>v=arr;
        
    //     for(int j=0;j<arr.size();j++){
    //         int temp=arr[j];
    //         int n=arr.size();
    //         for(int i=0;i<arr.size();i++){
    //             arr[i]=arr[i+1];
    //             arr[n-1] =temp;
    //             }
    //         if(sorted(arr)){
    //             return true;
    //         }

            
    //     }
    //     }
    //     return false;
    
        
    // }
    void rotate(vector<int>&nums){
            int temp=nums[0];
            int n=nums.size();
            for(int i=0;i<nums.size()-1;i++){
                nums[i]=nums[i+1];
                
                }
                nums[n-1] =temp;

    }
    

    bool check(vector<int>& nums) {

        
     if(sorted(nums)){
            return true;
        }
        else{
        vector<int>temp=nums;
        
        
        for(int j=0;j<nums.size();j++){
            rotate(temp);
            
            if(sorted(temp)){
                return true;
            }

            
        }
        }
        return false;
    
        
        
    } 
};