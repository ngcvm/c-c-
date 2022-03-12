#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    int count;
    Node *head;
} LinkedList;

LinkedList* init_linked_list();
void destroy_linked_list(LinkedList*);
void print_linked_list(LinkedList*);
void print_node(Node*);
void insert_node(LinkedList*, int);
void remove_node(LinkedList*, Node*);

int main(int argc, char* argv[]) {
    LinkedList *my_list = init_linked_list();
    if (!my_list) {
        return 1;
    }

    insert_node(my_list, 1);
    print_linked_list(my_list);

    insert_node(my_list, 2);
    print_linked_list(my_list);

    insert_node(my_list, 3);
    print_linked_list(my_list);

    remove_node(my_list, my_list->head->next);
    print_linked_list(my_list);

    destroy_linked_list(my_list);
    return 0;
}

LinkedList *init_linked_list() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->count = 0;
        list->head = NULL;
    }
    return list;
}

void destroy_linked_list(LinkedList *linked_list) {
    if (linked_list == NULL)
        return;

    Node *current = linked_list->head;
    while (current != NULL) {
        Node *next = current->next;
        remove_node(linked_list, current);
        current = next;
    }

    free(linked_list);
    printf("List destroyed!!!\n");
}

void print_linked_list(LinkedList *linked_list) {
    if (linked_list == NULL)
        return;

    Node *current = linked_list->head;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

void print_node(Node *node) {
    if (node == NULL)
        return;

    printf("Node data at %p is: %d\n", node, node->data);
}

void insert_node(LinkedList *linked_list, int data) {
    if (linked_list == NULL) {
        return;
    }

    // Initialize new node 
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node *tail = NULL,
        *current = linked_list->head;

    while (current) {
        tail = current;
        current = current->next;
    }

    if (tail == NULL) {
        linked_list->head = new_node;
    } else {
        tail->next = new_node;
    }
    linked_list->count++;
}

void remove_node(LinkedList *linked_list, Node *node_to_remove) {
    if (linked_list == NULL || node_to_remove == NULL) 
        return;

    if (linked_list->head == node_to_remove) {
        Node *current_node = linked_list->head;
        linked_list->head = linked_list->head->next;
        linked_list->count--;
        free(current_node);
    } else {
        Node *previous_node = NULL,
            *current = linked_list->head;

        while (current) {
            if (current == node_to_remove) {
                previous_node->next = current->next;
                linked_list->count--;
                free(current);
                break;
            }
            previous_node = current;
            current = current->next;
        }
    }
}

