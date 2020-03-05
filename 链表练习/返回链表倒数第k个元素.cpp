//结构体链表

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //参数检测，看pListHead和k是否不合法
        if(NULL == pListHead || 0 == k)
            return NULL;
        
        //定义快慢指针
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;
        
        //fast先走k步
        /*
        while(k--)
        {
            //防止k大于链表的长度
            if(NULL == fast)
                return NULL;
            fast = fast->next;
        }
        
        //fast 和 slow同时走，最后返回slow
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        */
        
        
        //fast先走了k-1步
        while(--k)
        {
            if(NULL == fast)
                return NULL;
            fast = fast->next;
        }
        
        //防止fast走完之后，fast为NULL
        if(fast == NULL)
            return NULL;      
        
        //fast和slow同时走
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        //返回slow
        return slow;
    }
};
