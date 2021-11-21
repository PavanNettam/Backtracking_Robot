#define MAXI 100
typedef struct node{
    int data;
    int x;
    int y;
    struct node* right;
    struct node* down;
}Node;
typedef struct list{
    Node* head;
    int sx,sy,dx,dy;
}List;
typedef struct stack{
    Node* arr[MAXI];
    int top;
}Stack;
void init(List* l);
void readMap(List* l);
void initS(Stack* s);
void push(Stack* s,Node* ele);
Node* pop(Stack* s);
Node* peep(Stack* s);
int findPath(Stack* s,List* l);
void storePath(Stack* s,List* l);