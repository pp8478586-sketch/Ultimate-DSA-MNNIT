class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={-1,-1,-1};
        int total=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                arr[0]=i;
            }
            if(s[i]=='b'){
                arr[1]=i;
            }
            if(s[i]=='c'){
                arr[2]=i;
            }
            int minIndex=*min_element(arr,arr+3);
            if(minIndex>=0){
                total=total+minIndex+1;
            }

        }
        return total;
    }
};