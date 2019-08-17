/* Problem No. 2 (Add two Numbers)
Difficulty: Medium
Problem Statement: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
link: https://leetcode.com/problems/add-two-numbers/
*/

#include<bits/stdc++.h>
using nameapsce std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans=NULL;
        ListNode* temp=NULL;
        while(l1!=NULL && l2!=NULL){
        int sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            if(ans==NULL){
                ans=node;
                temp=ans;
            }else{
                ans->next=node;
                ans=ans->next;
            }
            
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1!=NULL ){
        int sum=l1->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            if(ans==NULL){
                ans=node;
            }else{
                ans->next=node;
                ans=ans->next;
            }
            l1=l1->next;
        }
        
        while( l2!=NULL){
        int sum=l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            if(ans==NULL){
                ans=node;
            }else{
                ans->next=node;
                ans=ans->next;
            }
            l2=l2->next;
        }
        
        if(carry!=0){
            ListNode* node=new ListNode(carry);
            ans->next=node;
        }
        
        return temp;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}