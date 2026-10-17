class Solution {
    void helper(int index, string &num ,int &target ,long long  value, long long prev,vector<string>&ans,string a,int n){
        if(index==n){
            if(value==target){
                ans.push_back(a);
            }
        }
        long long curr=0;
        for(int i=index;i<n;i++){
            if(i>index&&num[index]=='0'){
                break;
            }
            string part=num.substr(index,i-index+1);
            curr=curr*10+(num[i]-'0');
            if(index==0){
                helper(i+1,num,target,value+curr,curr,ans,part,n);
            }
            else{
                helper(i+1,num,target,value+curr,curr,ans,a+'+'+part,n);
                helper(i+1,num,target,value-curr,-curr,ans,a+'-'+part,n);
                helper(i+1,num,target,value-prev+prev*curr,prev*curr,ans,a+'*'+part,n);
            }


        }
        
        
    }
public:
    vector<string> addOperators(string num, int target) {
        int n=num.size();
        vector<string>ans;
        string a;
        helper(0,num,target,0,0,ans,a,n);
        return ans;

        
    }
};