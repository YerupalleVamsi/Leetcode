/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node * helper(Node* curr){
        Node *temp=curr;
        Node *last=curr;
        while(temp!=NULL){
            Node * next_node=temp->next;
            if(temp->child!=NULL){
                Node * child_node= temp->child;
                child_node->prev=temp;
                Node *nxt = helper(child_node);
                temp->next=child_node;
                if(next_node!=NULL){
                    nxt->next=next_node;
                    next_node->prev=nxt;}
                temp->child=NULL;
                last=nxt;
            }
            else{
                last=temp;
            }
            temp=next_node;
        }
        return last;
    }
    Node* flatten(Node* head) {
         if (head == NULL) return NULL;
        helper(head);
        return head;
    }
};