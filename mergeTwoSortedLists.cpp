/*
Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {    
        if(l1 == nullptr)
            return l2;
        
        if(l2 == nullptr)
            return l1;
     
        bool isl1 = true;
        ListNode* newList = nullptr;
        ListNode* al1 = l1;
        ListNode* al2 = l2;
        
        if(al1->val <= al2->val){
            isl1 = true;
            newList = al1;
        }
        else{
            isl1 = false;
            newList = al2;
        }
        
        ListNode* processing = newList;
        
        while(true){                        
            if( processing->next != nullptr && processing->next->val >= (isl1 ? al2->val : al1->val) ){                   
                if(isl1){
                    isl1 = false;
                    al1 = processing->next;
                    processing->next = al2;
                    processing = al2;
                }
                else{
                    isl1 = true;
                    al2 = processing->next;
                    processing->next = al1;
                    processing = al1;
                }
            }
            else if(processing->next != nullptr){
                if(isl1)                
                    al1 = processing->next;                                    
                else                
                    al2 = processing->next;                

                processing = processing->next;
            }
            
            
            if(processing->next == nullptr){                
                if(isl1)                                
                    processing->next = al2;                
                else                
                    processing->next = al1;                                      
                
                break;
            }            
        }
        
        return newList;
    }
};