#include <stdlib.h>
#include <stdio.h>

struct ListNode{
        int val;
        struct ListNode *next;
};

struct ListNode* initLink(struct ListNode *head, int len){
        int i;
        if (len<1) return NULL;
        struct ListNode *pt = head;
        head->val=0;
        head->next=NULL;
        for(i=0; i<len; i++){
                pt = pt->next =(struct ListNode *)malloc(sizeof(struct ListNode));
                pt->val=0;
                pt->next=NULL;
        }
        return head;
}

int destroyLink(struct ListNode *head) {
        if (head == NULL) { return -1; }
        int i = 0;
        struct ListNode *p=head->next;
        struct ListNode *q=p;
        while (p) {
                q = p->next;
                free(p);
                p = q;
        }
        return 0;
}
        

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

        int gw=0, sw=0;
        struct ListNode head = { .next=NULL }, *curr=&head;
        while ((l1 != NULL) || (l2 != NULL) || sw) {
                int v1,v2=0;
                if (l1) {
                        v1 = l1->val;
                        l1 = l1->next;
                }
                
                if (l2) {
                        v2 = l2->val;
                        l2 = l2->next;
                }
        
                gw = v1 + v2 + sw;
                sw = gw > 9;
                curr = curr->next=(struct ListNode*)malloc(sizeof(struct ListNode));
                curr->val=gw % 10;
                curr->next = NULL;

        }
        return head.next;
}

int main(int argc, char** argv){
        struct ListNode *xHead, *yHead;
        struct ListNode x;
        struct ListNode y;

        int iVal;
        int lenx, i, leny;
        
        lenx = 3;
        leny = 3;
        xHead = &x;
        yHead = &y;
        xHead = initLink(xHead, lenx);
        yHead = initLink(yHead, leny);

        printf("\nInput for x:\n");
        struct ListNode *p=xHead;
        for(i=0; i<lenx; i++){
                scanf("%d", &iVal);
                //printf("%d\t", iVal);
                p->val = iVal;
                p=p->next;
        }
        
        printf ("\nInput for y:\n");
        
        p = yHead;
        for(i=0; i<leny; i++){
                scanf("%d", &iVal);
                //printf("%d\t", iVal);
                p->val = iVal;
                p=p->next;
        }

        printf("xHead link:\n");
        p = xHead;
        for(i=0; i<lenx; i++){
                printf("%d\t", p->val);
                p=p->next;
        }
        printf("yHead link:\n");
        p = yHead;
        for(i=0; i<leny; i++){
                printf("%d\t", p->val);
                p=p->next;
        }

        printf("\nresult: \n");
        struct ListNode *resLink = addTwoNumbers(xHead, yHead);
        struct ListNode *tmp = resLink;
        while (tmp){
                printf("%d",tmp->val);
                tmp=tmp->next;
        }
        printf("\n");
        destroyLink(xHead);
        destroyLink(yHead);
        destroyLink(resLink);
        return 0;
}
