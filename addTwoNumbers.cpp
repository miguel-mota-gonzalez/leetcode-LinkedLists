/*
Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> q1;
        queue<int> q2;
        
        ListNode *tmp = l1;        
        while(tmp!=nullptr){
            q1.push(tmp->val);        
            tmp = tmp->next;           
        }
        
        tmp = l2;
        while(tmp!=nullptr){
            q2.push(tmp->val);
            tmp = tmp->next;           
        }
        
        queue<int> qSum;
        int targetLen = q1.size() > q2.size() ? q1.size() : q2.size();
        
       int acum = 0;
        for(int i = 0; i < targetLen; i++){
            int num1 = !q1.empty() ? q1.front() : 0;
            int num2 = !q2.empty() ? q2.front() : 0;    

            if(!q1.empty())
                q1.pop();
            
            if(!q2.empty())
                q2.pop();
            
            int sum = num1 + num2 + acum;

            if(sum > 9){
                acum = 1;
                sum -= 10;
                qSum.push(sum);
            }
            else{
                qSum.push(sum);
                acum = 0;
            }
        }
        
        if(acum>0)
            qSum.push(1);
        
        ListNode *ret = new ListNode();
        tmp = ret;
        while(!qSum.empty()){
            tmp->val = qSum.front();
            qSum.pop();
            if(!qSum.empty())
                tmp->next = new ListNode();        
            tmp=tmp->next;
        }

        return ret;
    }
};