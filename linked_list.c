#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node * next;  
} node_t;

node_t populate_linked_list ();
void print_list (node_t * head);
void push_tail (node_t * head, int value);
void push_head (node_t ** head, int value);
int pop_tail (node_t * head);
int pop_head (node_t ** head);
int pop_by_val(node_t ** head, int val);


node_t populate_linked_list () {
  printf("Populating link list\n");
  node_t * head;
  node_t * current_node = malloc(sizeof(node_t));
  
  int i = 1; 
  int limit = 10;
  
  while (i <= limit) {
  
    current_node->val = i;
    current_node->next = NULL;
    
    if(i == 1) {
      head = current_node;
    }
    
    if (i != limit) {
      current_node->next = malloc(sizeof(node_t));
      current_node       = current_node->next;
    }
    
    i++;
    
  }
  
  return *head;
}

void print_list (node_t * head) {
  node_t * current = head;
  
  printf("printing node value\n");
  while (current != NULL) {
    printf("%d\n", current->val);
    current = current->next;
  }
}

void push_tail (node_t * head, int val) {
  node_t * current = head;
  
  while (current->next != NULL) {
    current = current->next;
  }
  
  current->next = malloc(sizeof(node_t));
  current->next->val = val; 
  current->next->next  = NULL;
}

void push_head (node_t ** head, int val) {
  node_t * new_node = malloc(sizeof(node_t));
  
  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

int pop_tail (node_t * head) {  
  int retval = 0;  
  
  if (head->next == NULL) {
    retval = head->val;
    free(head);
    return retval;
  }
  
  node_t * current = head;
  
  while (current->next->next != NULL) {
    current = current->next;
  }
  
  retval = current->val;
  free(current->next);
  current->next = NULL;
  return retval;
}

int pop_head (node_t ** head) {
  int retval;  
  node_t * next_node = NULL;
  
  if (*head == NULL){
    return -1;
  }
  
  next_node = (*head)->next;
  retval = (*head)->val;  
  *head = next_node;
  
  return retval;
}

int pop_by_val (node_t ** head, int val) {
  node_t * current = *head;
  node_t * current_before = NULL;
  node_t * temp_node = NULL;
  
  int retval = -1;
  
  while (current->next != NULL) {
    if (current->val == val) {
      temp_node = current;
      break;
    }
    current_before = current;
    current = current->next;
  } 
  
  // if(current == NULL){
  //   return -1;
  // }  
  return val;
}

int main() {
  node_t head = populate_linked_list();
  print_list(&head);
  
  for ( int i = 11; i <= 20; i++) {
    push_tail (&head, i);
  }
  
  print_list(&head);  
  
  node_t * current_head = &head;
  
  
  for (int i = 21; i <= 30; i++) {
    push_head ((node_t **)&current_head, i);
  }
  print_list(current_head);
  
  for (int i = 1; i <= 10; i++) {
    printf("pop_tail with value: %d\n", pop_tail(current_head));
  } 
  
  print_list(current_head);
  
  for (int i = 0; i < 10; i++) {
    printf("pop_head with value %d\n", pop_head((node_t **)&current_head));
  }  
  
  print_list(current_head);
  
  for (int i = 1; i <= 5; i++) {
    printf("pop_by_val with value %d\n", pop_by_val((node_t **)&current_head), i);
  } 
  
  print_list(current_head);
  return 0;
}