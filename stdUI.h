// Command Code
#define FORMAT 1 
#define PUSH 2
#define SHOW_ALL_ELEMENTS 3
#define SHOW_ALL_ELEMENTS_REVERSE 4
#define POP 5
#define TOP 6
#define EMPTY 7
#define INPUT_ERROR 1000

void showClientUI(){
  printf("=====================================\n");
  printf("1. Format stack\n");
  printf("2. Push stack\n");
  printf("3. Show all elements\n");
  printf("4. Show all elements reverse\n");
  printf("5. Pop\n");
  printf("6. Top\n");
  printf("7. Empty\n");
  printf("=====================================\n");
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
    case SHOW_ALL_ELEMENTS_REVERSE :
      showAllElementsReverse();
      break;
    case POP :
      pop();
      break;
    case TOP :
      top();
      break;
    case EMPTY :
      empty();
      break;
    default :
      return INPUT_ERROR;
  }

  return command;
}
