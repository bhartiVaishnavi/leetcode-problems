class Solution {
public:
    int myAtoi(string s){
        int i = 0;
        int l = s.length();
        while(i < l && s[i] == ' '){
            i++;
        }
        int sign = 1;
        if(i < l && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
                
            }
            i++;
        }
        long long ans = 0;
        while(i < l && isdigit(s[i])){
            ans = ans * 10 + (s[i] - '0');
            i++;

            if(sign*ans > INT_MAX) return INT_MAX;
            if(sign * ans < INT_MIN) return INT_MIN;

        }
        return ans * sign;
    } 
    
};