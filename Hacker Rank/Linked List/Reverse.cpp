struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    
    ListNode* pre = nullptr;
    ListNode* cur = head;
    
    while (cur!=nullptr) {
        
        ListNode* nextT = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextT;
        
    }
    return pre;
}