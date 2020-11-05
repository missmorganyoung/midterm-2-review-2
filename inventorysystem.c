#include <stdio.h>
#define FILE_NAME "parts.txt"

int getMenuChoice();
_Bool findPartNumber(FILE*, int, int*, double*);

int main(){

  FILE* filePtr;
  int userInput, partNumToFind, quantity;
  double price;
  do{userInput = getMenuChoice();
  switch(userInput){
  
      case 1:
      
        filePtr = fopen(FILE_NAME, "r");
        if(filePtr == NULL){

            printf("Can not open inventory file.\n");
          
      }
      
      else{
      
        printf("Please enter the part number you're looking for: ");
        scanf("%d", &partNumToFind);

        if(findPartNumber(filePtr, partNumToFind, &quantity, &price)){
            printf("Your part: \n");
            printf("%d, %d, %.2lf\n", partNumToFind, quantity, price);
      }
      
      else{
      
          printf("Sorry, couldn't find your part.\n");
          
      }
      
      fclose(filePtr);
      
      }
      
      break;
      
      case 0:
        break;
        
      default:
      
        printf("Please enter a valid option!\n");
    }} while (userInput != 0);
    
    return 0;
    
    }
    
    int getMenuChoice(){
    
        int menuChoice;
        printf("***INVENTORY SYSTEM***\n");
        printf("1. Find Part Number\n");
        printf("0. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        return menuChoice;
     }
    
    _Bool findPartNumber(FILE* partsFile, int partToFind, int* partQuantity, double* partPrice){
    
        int partNumber;
        
        while(fscanf(partsFile, "%d%d%lf", &partNumber, partQuantity, partPrice) == 3){
            if(partToFind == partNumber){
                return 1;
             }
        }
        
        return 0;
        
}
