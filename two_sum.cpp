#include<bits/stdc++.h>
using namespace std;

/* problem no.1 , Easy , Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {   // required function signature
        vector<int>x;         
        for(int i=0;i<nums.size();i++){
            int k=target-nums[i];
            for(int j=0;j<nums.size();j++){
                if(j==i){
                    continue;
                }
                
                if(k==nums[j]){
                    x.push_back(j);
                    break;
                }
            }
            
            if(x.size()!=0){
                x.push_back(i);
                int i=x[0];
                x[0]=x[1];
                x[1]=i;
                
                break;
            }
        }
        
        return x;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}