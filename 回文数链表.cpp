/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/


class PalindromeList {
public:
    //逆置函数，用来逆置链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    bool chkPalindrome(ListNode* A) {
        //去除特殊情况，个位数以及链表不存在
        if(A == NULL ||A->next == NULL)
            return true;
        //方法一：利用数组来求解，将所有链表中的数放到数组中，然后遍历
        int arr[900] = {0};
        
        //i值表示链表的长度，即链表的个数
        int i = 0;
        ListNode* cur = A;
        while(cur)
        {
            //遍历链表
            arr[i++] = cur->val;
            cur = cur->next;
            
        }
        
        //遍历数组，进行对比
        int left = 0;
        int right = i - 1;
        while(left < right)
        {
            //如果数组的两个数不一样，直接返回false
            if(arr[left++] != arr[right--])
                return false;
        }
        return true;
    
        
        
        //方法二：分三步走
                //一.遍历链表，找到中间的节点
                //二.将后slow链表进行翻转
                //三.cur1链表和cur2链表进行比较
        
        //一.遍历链表，找到中间的节点
        ListNode* fast = A;
        ListNode* slow = A;
        ListNode* preslow = NULL;
 
        //快慢指针来求出链表的中间值       
        while(fast && fast->next)
        {
            fast = fast->next->next;
            preslow = slow;
            slow = slow->next;
        }
        
        //将分开的两个链表第一个最后置为空
        preslow->next = NULL;
        
        //二.将后slow链表进行翻转，reverseList函数搞定
        ListNode* cur2 = reverseList(slow);
        ListNode* cur1 = A;
        
        //三.cur1链表和cur2链表进行比较
       while(cur1 && cur2)
       {
           if(cur1->val != cur2->val)
               return false;
           cur1 = cur1->next;
           cur2 = cur2->next;
       }
       return true;
    }
};
