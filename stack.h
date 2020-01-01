#include <stdlib.h>
// Stack property
#define ELEMENTS_LIMIT 1000
#define PUSH_SUCCESS 100
#define PUSH_FAIL 200
#define PUSH_FAIL_BY_SIZE 201

// Program property
#define VISIBLE 1
#define INVISIBLE 0

// Typedef stack element
typedef struct Element{
  int data;
  struct Element *prevElement, *nextElement;
}Element;

// Typedef stack data structure
typedef struct Stack{
  // topElem(Top-Element in Stack), bottomElem(Bottom-Element in Stack)
  struct Element *topElem, *bottomElem;
  // size(In stack size)
  int size;
}Stack;
Stack *stack;

void format(int visibleMode){
  if(visibleMode == VISIBLE){
    printf("[Trace] Format stared!\n");
  }
  if(stack != NULL){ free(stack); }
  stack = (Stack *)malloc(sizeof(Stack));
  stack->topElem = NULL;
  stack->bottomElem = NULL;
  stack->size = 0;
  if(visibleMode == VISIBLE){
    printf("[Trace] Format finished!\n");
  }
}

short addElementInStack(int data){
  if(stack->size >= ELEMENTS_LIMIT) return PUSH_FAIL_BY_SIZE;

  Element *newElem = (Element *)malloc(sizeof(Element));
  newElem->data = data;
  newElem->nextElement = NULL;

  if(stack->size == 0){
    stack->topElem = newElem;
    stack->bottomElem = newElem;
    newElem->prevElement = NULL;
  }else{
    newElem->prevElement = stack->topElem;
    stack->topElem->nextElement = newElem;
    stack->topElem = newElem;
  }

  stack->size++;

  return PUSH_SUCCESS;
}

void push(){
  printf("Please input data : ");
  int data;
  scanf("%d", &data);

  switch(addElementInStack(data)){
    case PUSH_SUCCESS :
      printf("[Trace] data %d push successed!\n", data);
      break;
    case PUSH_FAIL_BY_SIZE :
      printf("[Trace] data %d push failed by overflow! (Size Limit : %d)\n", data, ELEMENTS_LIMIT);
      break;
  }
}

void showAllElements(){
  Element *temp = stack->bottomElem;
  int count = 1;
  printf("[Show all elements]\n");
  while(temp){
    printf("(%d element) : %d\n", count++, temp->data);
    temp = temp->nextElement;
  }

  if(count == 1){
    printf("[Trace] Stack empty!\n");
  }
}

void showAllElementsReverse(){
  Element *temp = stack->topElem;
  int count = 1;
  printf("[Show all elements reverse]\n");
  while(temp){
    printf("(%d element) : %d\n", count++, temp->data);
    temp = temp->prevElement;
  }

  if(count == 1){
    printf("[Trace] Stack empty!\n");
  }
}
void pop(){
  int popData = 0;
  if(stack->size == 0){
    printf("[Trace] Stack empty!\n");
    return;
  }else if(stack->size == 1){
    popData = stack->topElem->data;
    free(stack->topElem);
    stack->topElem = NULL; stack->bottomElem = NULL;
  }else{
    popData = stack->topElem->data;
    Element *temp = stack->topElem;
    stack->topElem = temp->prevElement;
    stack->topElem->nextElement = NULL;
    free(temp);
  }
  stack->size--;
  printf("[Trace] Delete success (Pop data : %d)!\n", popData);
  return;
}

void empty(){
  if(stack->size == 0){
    printf("[Trace] Stack empty!\n");
  }else {
    printf("[Trace] Stack not empty!\n");
  }
  return;
}

void top(){
  if(stack->size == 0){
    printf("[Trace] Stack empty!\n");
  }else{
    printf("[Trace] Top data : %d\n", stack->topElem->data);
  }
  return;
}
