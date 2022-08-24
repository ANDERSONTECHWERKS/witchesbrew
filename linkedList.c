#include <stdio.h>
#include <stddef.h>
struct linkedList
{
    struct Node *head;
    int numberOfNodes;
};

struct Node
{
    char *data;
    void *next;
};

struct linkedList *createLinkedList()
{
    struct linkedList *new_list = calloc(1,sizeof(struct linkedList));
    new_list->head = NULL;
    new_list->numberOfNodes = 0;
    return new_list;
}

void destroyLinkedList(struct linkedList* list){

    while (list->numberOfNodes != 0){
        pop_node_stack(list);
    }

    free(list);

}


void push_node_via_tail(struct linkedList *list, struct Node *new_node)
{

    if (list->head == NULL)
    {
        list->head = new_node;
        list->numberOfNodes = 1;
    }
    else
    {
        struct Node *curr = list->head;

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = new_node;
        list->numberOfNodes = list->numberOfNodes + 1;
    }
}


void pop_node_queue(struct linkedList *list)
{
    struct Node *curr = list->head;
    struct Node *prev = NULL;

    // Check if the list is empty before popping


    // Iterate to the 'top' of the stack
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    printf("%s",curr->data);

    // If we are not currently looking at the head of the list, remove the reference to the current node from the previous node.
    if(prev != NULL){
        prev->next = NULL;
    }

    // Free the memory of the current node.
    free(curr);

    // Subtract 1 from number of nodes
    list->numberOfNodes = list->numberOfNodes - 1;


}

void pop_node_stack(struct linkedList *list)
{
   // First - take the data we need. Do something with it.
   printf(list->head->data);

   // Next - pop the head off and reassign new head.
   struct Node *curr = list->head;

   //  
   list->head = curr->next;

   // Free the newly-orphaned node
   free(curr);

    // Subtract 1 from number of nodes
    list->numberOfNodes = list->numberOfNodes - 1;
}


void push_node_via_head(struct linkedList *list, struct Node *new_node){

    if (list->head == NULL)
    {
        list->head = new_node;
        list->numberOfNodes = 1;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
        list->numberOfNodes = list->numberOfNodes + 1;
    }    
}


void push_node(struct linkedList *list, struct Node *new_node){

    if (list->head == NULL)
    {
        list->head = new_node;
        list->numberOfNodes = 1;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
        list->numberOfNodes = list->numberOfNodes + 1;
    }    
}

void *createNode(char *inp_data)
{
    struct Node *new_node = calloc(1,sizeof(struct Node));

    new_node->data = inp_data;
    new_node->next = NULL;
    return new_node;
}

void main()
{
    // Basic data instantiation
    char *firstData = "Test1";
    char *secondData = "Test2";
    char *thirdData = "Test3";

    // Test node creation functions
    struct Node *head = createNode(firstData);
    struct Node *node1 = createNode(secondData);
    struct Node *node2 = createNode(thirdData);

    // Test linkedList stack behavior
    struct linkedList *new_list = createLinkedList();
    push_node(new_list,head);
    push_node(new_list,node1);
    push_node(new_list,node2);
    pop_node_stack(new_list);
    pop_node_stack(new_list);
    pop_node_stack(new_list);
    destroyLinkedList(new_list);

    // Test node creation functions
    struct Node *head2 = createNode(firstData);
    struct Node *node3 = createNode(secondData);
    struct Node *node4 = createNode(thirdData);

    //Test linkedList queue behavior
    struct linkedList *new_list2 = createLinkedList();
    push_node(new_list2,head2);
    push_node(new_list2,node3);
    push_node(new_list2,node4);
    pop_node_queue(new_list2);
    pop_node_queue(new_list2);
    pop_node_queue(new_list2);
    destroyLinkedList(new_list2);
}
