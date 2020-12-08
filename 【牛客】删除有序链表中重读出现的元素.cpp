/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode newnode(0);
        newnode.next = head;
        ListNode* pnode = &newnode;
        while(pnode->next)
        {
            ListNode* ptemp = pnode->next;
            bool flag = false;
            while(ptemp && ptemp->next && ptemp->val == ptemp->next->val)
            {
                ptemp = ptemp->next;
                flag = true;
            }
            if(flag)
            {
                pnode->next = ptemp->next;
            }
            else
            {
                pnode = pnode->next;
            }
        }
        return newnode.next;
    }
};
