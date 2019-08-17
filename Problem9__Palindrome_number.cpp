/* Problem No. 9 (Palindrome Number)
Difficulty: Easy
Problem Statement:Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
link:https://leetcode.com/problems/palindrome-number/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int temp=x;
        long long int ans=0;
        while(temp!=0){
            int d=temp%10;
            temp=temp/10;
            ans=ans*10+d;
        }
        
        int m=ans;
        if(x==m){
            return true;
        }else{
            return false;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}