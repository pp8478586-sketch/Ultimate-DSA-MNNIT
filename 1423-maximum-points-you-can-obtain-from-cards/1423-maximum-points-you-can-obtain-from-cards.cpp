class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int begin=k-1;
        int end=n-1;
        int sum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        maxSum=sum;
        while(begin>=0){
            int newSum=0;
            newSum=sum-cardPoints[begin]+cardPoints[end];
            sum=newSum;
            maxSum=max(maxSum,newSum);
            begin--;
            end--;
        }   
        return maxSum;
    }
};