class Solution {
    long long sumOfn(long long  n){
        return (n*(n+1))/2;
}
public:
    int candy(vector<int>& ratings) {
        int count=0;
        long long ans=ratings.size();
        int temp=0;
        int i=0;
        while(i<ratings.size()-1){
            int difference =ratings[i+1]-ratings[i];
            if(difference>0){
                
                while(i<ratings.size()-1&&ratings[i+1]-ratings[i]>0){
                    count++;
                    i++;
                }
                ans+=sumOfn(count);
                temp=count;
                count=0;

            }
            else if(difference<0){
                while(i<ratings.size()-1&&ratings[i+1]-ratings[i]<0){
                    count++;
                    i++;
                }
                ans+=sumOfn(count)-min(count,temp);
                
                temp=0;
                count=0;
            }
            else{
                i++;
                count=0;
                temp=0;
            }
           
        }
        return ans;
    }
};