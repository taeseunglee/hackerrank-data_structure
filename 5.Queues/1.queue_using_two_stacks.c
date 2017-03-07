#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct queue {
    struct queue_node *head;
    struct queue_node *tail;
};

struct queue_node {
    int item;
    struct queue_node *next;
};

void queue_push(struct queue *, int);
int queue_pop(struct queue *);
int queue_front(struct queue);

int main() {
    int q;
    scanf("%d", &q);
    
    struct queue my_queue;
    for (int q_i = 0; q_i < q; ++q_i) {
        int type, x;
        scanf("%d", &type);
        
        switch (type) {
            case 1:
            {
                scanf("%d", &x);
                queue_push(&my_queue, x);
            } break;
            
            case 2:
            {
                queue_pop(&my_queue);
            } break;
            
            case 3:
            {
                printf("%d\n", queue_front(my_queue));
            } break;
        }
        
    }
    
    return 0;
}

void queue_push(struct queue *self, int item)
{
    struct queue_node   *new_node = calloc(1, sizeof(struct queue_node)),
                        *traverse = self->head;
    new_node->item = item;
    
    if (self->tail) {
        new_node->next = self->tail;
        self->tail = new_node;
    }
    else {
        self->head = new_node;
        self->tail = new_node;
    }
}
    
int queue_pop(struct queue *self)
{
    if (self->head) {
        struct queue_node   *traverse = self->tail,
                            *delete_node = self->head;
        int ret = 0;
        
        if (traverse->next) {
            while (traverse->next->next)
                traverse = traverse->next;
            // traverse->next <=> head
            delete_node = traverse->next;
            self->head = traverse;
            self->head->next = NULL;
        }
        else { // head == tail
            self->head = NULL;
            self->tail = NULL;
        }
        ret = delete_node->item;
        free(delete_node);
        return ret;
    }
    else {
        printf("Error : there is no node\n");
        return -1;
    }
}
    
int queue_front(struct queue self)
{
    if (self.head) return self.head->item;
    else {
        printf("Error : there is no node\n");
        return -1;
    }
}