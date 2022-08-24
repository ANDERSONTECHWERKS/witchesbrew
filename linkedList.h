struct linkedList *createLinkedList();
void destroyLinkedList(struct linkedList* list);
void push_node_via_tail(struct linkedList *list, struct Node *new_node);
void push_node_via_head(struct linkedList *list, struct Node *new_node);
void pop_node_queue(struct linkedList *list);
void pop_node_stack(struct linkedList *list);
void push_node(struct linkedList *list, struct Node *new_node);
void *createNode(char *inp_data);
