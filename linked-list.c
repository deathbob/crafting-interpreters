#include <stdio.h>
#include <string.h>

typedef struct Node{
  char * name;
  struct Node* prev;
  struct Node* next;
} Node;

void p2n(char *str, Node * n){
  printf("%s", str);
  char addr_str[32];
  sprintf(addr_str, "%p", n);
  puts(addr_str);
}

void p2p(char *str, char* str2){
  printf("%s", str);
  printf("%s \n", str2);  
}

void pnode(Node * n){
  if(n == NULL){
    puts("node is null, returning");
    return;
  }
  char addr_str[32];
  sprintf(addr_str, "%p", n);
//  if(n->name == NULL){
//    printf("node has no name :(  Address is %s", addr_str);
//  }else{
//    //    puts("node does have name! Let's see what it is");        
//    printf("addr of %s : %s", n->name, addr_str);
//  }

  printf("node addr  = %s \n", addr_str);
  p2p("node->name = ", n->name);
  p2n("node->prev = ", n->prev);
  p2n("node->next = ", n->next);
  puts("");  
}


typedef struct LinkedList{
  Node * head;
  int size;
} LinkedList;

int insert(LinkedList* list, Node* toInsert, int idx){
  // inserts toInsert into head @ idx

  puts("Inserting ");
  pnode(toInsert);
  
  int i = 0;
  Node* curr = list->head;

  if(curr == NULL){
    puts("   adding to empty list");
    list->head = toInsert;
    list->size = 1;
    return 0;
  }
  while(i < idx){
    i++;
    curr = curr->next;
    if(curr == NULL){
      break;
    }
  }
  if(curr != NULL){
//    puts("curr2");
//    pnode(curr);
//    puts("toInsert");
//    pnode(toInsert);
    if(idx == 0){
      list->head = toInsert;
    }
    toInsert->next = curr;
    toInsert->prev = curr->prev;
    curr->prev = toInsert;
    list->size = list->size + 1;
  }

  return 0;
};

int delete(LinkedList * list, int idx){
  
  int i = 0;
  Node* curr = list->head;
  if(curr == NULL){
    puts("List is empty, nothing to delete");
    return 0;
  }
  if(list->size < idx){
    printf("attempting to delete element %d when size is %d, impossible", idx, list->size);
  }
  while(i < idx){
    i++;
    curr = curr->next;
    if(curr == NULL){
      break;
    }
  }
  if(curr != NULL){
    Node * prev;
    prev = curr->prev;
    prev->next = curr->next;
    list->size = list->size - 1;
  }
  return 0;
  
}

void p2s(char *str, int num){
  printf("%s", str);
  char addr_str[32];
  sprintf(addr_str, "%i", num);
  puts(addr_str);
}




void walk(LinkedList * l){
  if(l == NULL){
    puts("Null Linked List");
    return;
  }
  
  Node * head = l->head;
  puts(" \n Walking ");
  if(head == NULL){
    puts("empty list");
    return;
  }else{
    puts("go some kind of list, let's see more");
    printf("allegedly %d elements", l->size);
  }
  
  char addr_str[32];
  sprintf(addr_str, "%p", head);
  printf("addr of head %s", addr_str);
  puts("");
  
  int i = 0;
  Node* curr;
  curr = head;

  do {
    p2s("i = ", i);
    pnode(curr); // blowing up here
    curr = curr->next;
    i++;
  }while(curr != NULL);
  
}



int main() {
  puts("First i create a node ");    
  Node *n1Ptr;
  Node n1;
  n1Ptr = &n1;
  n1Ptr->name = "asdf";
  n1Ptr->prev = NULL;
  n1Ptr->next = NULL;
  pnode(n1Ptr);

  puts("Then i create an empty list");
  LinkedList *listPtr, list;
  listPtr = &list;
  listPtr->head = NULL;
  listPtr->size = 0;
  walk(listPtr);



  

  insert(listPtr, n1Ptr, 0);

  Node *n2Ptr, n2;
  n2Ptr = &n2;
  n2Ptr->prev = NULL;
  n2Ptr->next = NULL;
  puts(" then i insert a node at the beginning of the list \n");
  insert(listPtr, n2Ptr, 0);
  walk(listPtr);


  puts("Create and insert another node at the beginning of the list");
  Node *n3Ptr, n3;
  n3Ptr = &n3;
  n3Ptr->prev = NULL;
  n3Ptr->next = NULL;
  insert(listPtr, n3Ptr, 0);
  walk(listPtr);


  puts(" then i delete something \n");
  delete(listPtr, 1);
  walk(listPtr);


  puts("let's try deleting something that doesn't exist");
  delete(listPtr, 100);
  walk(listPtr);
  puts("need to practice inserting at beginning and end \n");
  puts("need to practice deleting beginning and end too \n");
  return 0;
}





