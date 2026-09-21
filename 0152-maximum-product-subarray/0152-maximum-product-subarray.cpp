class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long product=1;
        long long maxProduct=INT_MIN;
        int negatives=0;
        int firstNegative=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                if(firstNegative==-1){
                    firstNegative=i;
                }
                negatives++;
            }
            if(nums[i]==0){
                if(negatives%2==1){
                    product=1;
                    for(int j=firstNegative+1;j<i;j++){
                        product=product*nums[j];
                        maxProduct=max(product,maxProduct);
                    }
                    
                }
                negatives=0;
                product=1;
                firstNegative=-1;
                if(maxProduct<0){
                    maxProduct=0;
                }
            }
            else{
                product=product*nums[i];
                maxProduct=max(product,maxProduct);
            }
        }
        product=1;
        if(negatives%2==1){
            for(int i=firstNegative+1;i<n;i++){
                product=product*nums[i];
                maxProduct=max(maxProduct,product);
            }

        }
        return maxProduct;

    }
};