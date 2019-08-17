/* Problem 7: Reverse Interger,
easy,
Problem statement: Given a 32-bit signed integer, reverse digits of an integer.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {     // required function signature
public:
    int reverse(int x) {
        long long int ans=0;
        bool flag=true;
        if(x==-2147483648){
            return 0;
        }
        if(x<0){
            flag=false;
            x=-x;
        }
        while(x!=0){
            int d=x%10;
            x=x/10;
            ans=ans*10+d;
        }
        
        if(!flag){
            ans=-ans;
        }
        
        if(ans<=-2147483648 || ans>=2147483647){
            return 0;
        }
        
        int small=ans;
        return small;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}