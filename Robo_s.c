#include<stdio.h>
#include<stdlib.h>
#define MAXI 100
#include "PES1UG20CS573_H.h"
void init(List* l){
    l->head = NULL;
}
void readMap(List* l){
    init(l);
    FILE* rf = fopen("input.txt","r");
    fscanf(rf,"%d", &l->sx);
    fscanf(rf,"%d", &l->sy);
    fscanf(rf,"%d", &l->dx);
    fscanf(rf,"%d", &l->dy);
    
    //creating 0 0 node
    Node* temp = (Node*)malloc(sizeof(Node));
    fscanf(rf,"%d", &temp->data);
    temp->x = 0;
    temp->y = 0;
    temp->right = NULL;
    temp->down = NULL;
    l->head = temp;

    //creating 0 y row of nodes
    Node* p = l->head;
    for(int j=l->sy+1;j<=l->dy;j++){
        Node* temp = (Node*)malloc(sizeof(Node));
        fscanf(rf,"%d", &temp->data);
        temp->x = 0;
        temp->y = j;
        temp->right = NULL;
        temp->down = NULL;
        p->right = temp;
        p = temp;
    }
    Node* q = l->head;

    //creating remaining rows and columns
    for(int i=l->sx+1;i<=l->dx;i++){
        //creating x 0 column of nodes
        Node* temp = (Node*)malloc(sizeof(Node));
        fscanf(rf,"%d", &temp->data);
        temp->x = i;
        temp->y = 0;
        temp->right = NULL;
        temp->down = NULL;
        q->down = temp;
        q = q->down;
        p = q;

        for(int j=l->sy+1;j<=l->dy;j++){
            Node* temp = (Node*)malloc(sizeof(Node));
            fscanf(rf,"%d", &temp->data);
            temp->x = i;
            temp->y = j;
            temp->right = NULL;
            temp->down = NULL;
            p->right = temp;
            p = temp;
        }
    }

    Node* r = l->head;
    while(r->down != NULL){
        p = r->right;
        q = r->down->right;
        while(p != NULL){
            p->down = q;
            p = p->right;
            q = q->right;
        }
        r = r->down;
    }
    
    //Display
    printf("File read contains:\n");
    printf("%d %d \n%d %d",l->sx,l->sy,l->dx,l->dy);
    printf("\n");
    p = l->head;
    q = p;
    while(q!=NULL){
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->right;
        }
        printf("\n");
        q = q->down;
        p = q;
    }
    printf("And is stored in the multilist as:\n");
    printf("\n");
    p = l->head;
    q = p;
    while(q!=NULL){
        while(p!=NULL){
            printf("%d (%d,%d) ",p->data,p->x,p->y);
            p = p->right;
        }
        printf("\n");
        q = q->down;
        p = q;
    }
    fclose(rf);
}
void initS(Stack* s){
    s->top = -1;
}
void push(Stack* s,Node* ele){
    if(s->top == MAXI-1){
        return;
    }else{
        s->top++;
        s->arr[s->top] = ele;
    }
}
Node* pop(Stack* s){
    if(s->top == -1){
        return NULL;
    }else{
        Node* ele = s->arr[s->top];
        s->top--;
        return ele;
    }
}
Node* peep(Stack* s){
    if(s->top == -1){
        return NULL;
    }else{
        return s->arr[s->top];
    }
}
int findPath(Stack* s,List* l){
    Node* p;
    Node* q;
    p = l->head;
    int found = 0;
    while(1){
        if(p->right != NULL && p->right->data == 0){
            push(s,p);
            p = p->right;
        }else if(p->down != NULL && p->down->data == 0){
            push(s,p);
            p = p->down;
        }else{
            q = p;
            p = pop(s);
            while(1){
                if(p->down != NULL && p->down->data == 0 && p->down != q){
                    push(s,p);
                    p = p->down;
                    break;
                }
                q = p;
                p = pop(s);
                if((p->x == l->sx && p->y == l->sy) || s->top == -1){
                    return found;
                }
            }
        }
        if(p->x == l->dx && p->y == l->dy){
            found = 1;
            break;
        }
    }
    return found;
}
void storePath(Stack* s,List* l){
    FILE* wf = fopen("output.txt","w");
    for(int i=0;i<=s->top;i++){
        fprintf(wf,"%d %d\n",s->arr[i]->x,s->arr[i]->y);
    }
    fprintf(wf,"%d %d\n",l->dx,l->dy);
    fclose(wf);
}