class Solution {
public:
    bool checkValidString(string s) {
        int minBalance=0;
        int maxBalance=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='('){
                minBalance+=1;
                maxBalance+=1;
            }
            else if(s[i]==')'){
                minBalance-=1;
                maxBalance-=1;
            }
            else{
                minBalance-=1;
                maxBalance+=1;
            }
            if(minBalance<0){
                minBalance=0;
            }
            if(maxBalance<0){
                return false;
            }
        }
        if(minBalance==0){
            return true;
        }
        return false;
    }
};