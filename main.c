#include <stdio.h>
#include <stdlib.h>

// Command Code
#define FORMAT 1 
#define PUSH 2
#define SHOW_ALL_ELEMENTS 3
#define INPUT_ERROR 1000

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
  Element *nextElement;
}Element;

// Typedef stack data structure
typedef struct Stack{
  // topElem(Top-Element in Stack), bottomElem(Bottom-Element in Stack)
  Element *topElem, *bottomElem;
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

void showClientUI(){
  printf("=====================================\n");
  printf("1. Format stack\n");
  printf("2. Push stack\n");
  printf("3. Show all elements\n");
  printf("=====================================\n");
}

short addElementInStack(int data){
  if(stack->size >= ELEMENTS_LIMIT) return PUSH_FAIL_BY_SIZE;

  Element *newElem = (Element *)malloc(sizeof(Element));
  newElem->data = data;
  newElem->nextElement = NULL;

  if(stack->size == 0){
    stack->topElem = newElem;
    stack->bottomElem = newElem;
  }else{
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

short getCommandFromStdIn(){
  showClientUI();
  short command;
  scanf("%hd",&command);

  switch(command){
    case FORMAT :
      format(VISIBLE);
      break;
    case PUSH :
      push();
      break;
    case SHOW_ALL_ELEMENTS :
      showAllElements();
      break;
    default :
      return INPUT_ERROR;
  }

  return command;
}

int main(void){
  format(INVISIBLE);
  while(getCommandFromStdIn() != INPUT_ERROR);
}
