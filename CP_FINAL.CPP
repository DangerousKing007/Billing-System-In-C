#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int oldbill;
// Function to add an item to the bill
void addItem(FILE *billFile) {
    char itemName[50];
    float itemPrice;

    printf("Enter item name: ");
    scanf("%s", itemName);

    printf("Enter item price: ");
    scanf("%f", &itemPrice);

    // Append item details to the bill file
    fprintf(billFile, "%s %.2f\n", itemName, itemPrice);

    printf("Item added to the bill.\n");
}

// Function to print the current bill
void printBill(FILE *billFile) {
    fseek(billFile,oldbill,SEEK_SET);
    printf("\nCurrent Bill:\n");
    printf("--------------\n");

    char itemName[50];
    float itemPrice, total = 0;
    printf(" - - -Anime Supermarket- - - \n");
    // Read and print each item in the bill
while (fscanf(billFile, "%s %f", itemName, &itemPrice) != EOF) {
  printf("%s %.2f\n", itemName, itemPrice);
  total += itemPrice;
    }

    printf("--------------\n");
    printf("Total: %.2f\n", total);
}

// Function to calculate and print total sales
void printTotalSales(FILE *billFile) {
    fseek(billFile,0,SEEK_SET); // Move file cursor to the beginning

    float totalSales=0;
    float itemprice=0;
    char itemname[50];
    printf(" - - -Anime Supermarket- - - \n");
    // Read and sum up all item prices in the bill
    while (fscanf(billFile, "%s %f",itemname, &itemprice) != EOF) {
  printf("%s %.2f\n", itemname, itemprice);
  totalSales += itemprice;
    }
    printf("Total Sales: %.2f\n", totalSales);
}

int main() {
    FILE *billFile;
    billFile = fopen("bill.txt", "a+"); // Open file in append and read mode

    if (billFile == NULL) {
  printf("Error opening file.\n");
  return 1;
    }

    int choice;
    fseek(billFile,0,SEEK_END);
    oldbill=ftell(billFile);
    do {
  printf("\n1. Add Item\n2. Print Current Bill\n3. Print Total Sales\n4. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
      case 1:
    addItem(billFile);
    break;
      case 2:
    printBill(billFile);
    break;
      case 3:
    printTotalSales(billFile);
    break;
      case 4:
    printf("Exiting program.\n");
    break;
      default:
    printf("Invalid choice. Please try again.\n");
  }
    } while (choice != 4);

    fclose(billFile);

    return 0;
}