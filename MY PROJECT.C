#include <stdio.h>
#include<string.h>
// here i declare structure
struct Expense{
    int id;
    char category[50];
    char description[100];
    float amount;
};
struct Expense expenses[100];
int count=0;
float income=0;

// add function
void addExpenses()
{
    int howmuch;

    printf("Enter how many entries u want to add: ");
    scanf("%d", &howmuch);

    for(int i = 0; i < howmuch; i++)
    {
        printf("\nExpense %d\n", i + 1);

        printf("Enter Expense ID: ");
        scanf("%d", &expenses[count].id);

        printf("Enter Category: ");
        scanf("%s", expenses[count].category);

        printf("Enter Description: ");
        scanf("%s", expenses[count].description);

        printf("Enter Amount: ");
        scanf("%f", &expenses[count].amount);

        count++;

        printf("Expense added successfully!\n");
    }
}

// view function()
void viewExpenses(){
    
    if(count==0){
        printf("No record found\n");
        return;
    }
    
printf("\nID\tCATEGORY\tDESCRIPTION\tAMOUNT\n");
    for(int i=0; i<count; i++){
        printf("%d\t%s\t\t%s\t\t%.2f\n",expenses[i].id,expenses[i].category,expenses[i].description,expenses[i].amount);
    }
    
}
// update expenses
void updateExpenses()
{
    int id;
    int found = 0;

    printf("Enter Expense ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(id == expenses[i].id)
        {
            found = 1;

            printf("Enter New Category: ");
            scanf("%s", expenses[i].category);

            printf("Enter New Description: ");
            scanf("%s", expenses[i].description);

            printf("Enter New Amount: ");
            scanf("%f", &expenses[i].amount);

            printf("Expense Updated Successfully!\n");
            break;
        }

    }

    if(found == 0)
    {
        printf("Expense ID not found!\n");
    }
}

//calculate total expenses 
float calculateTotalExpenses()
{
    float total=0;
    
    for(int i=0; i<count; i++){
        total=total+expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
    
    return total;
}

// remaining ammount
void showRemainingAmount(){
    float total= calculateTotalExpenses();
    printf("\nMonthly Income: %.2f",income);
    printf("\nTotal Expenses: %.2f",total);
    float Remaining=income-total;
    printf("\nReamaining Budget: %.2f\n",Remaining);
    
    if(total>income){
        printf("budet overload\n");
    }
}

// searh 
void searchof(){
    int id;
    int found=0;
    printf("Enter the id:");
    scanf("%d",&id);
    
    for(int i=0; i<count; i++){
        if(id==expenses[i].id)
        {
            found=1;
            printf("%d\t%s\t%s\t%.2f\t\n",expenses[i].id,expenses[i].category,expenses[i].description,expenses[i].amount);
            break;
        }
    }
    if(found==0){
        printf("The Id is not existed plz enter valid id----\n");
    }
}
// delete record 
void deleteExpense()
{
    int id;
    int found = 0;

    printf("Enter Expense ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(expenses[i].id == id)
        {
            found = 1;

            // Shift all records one position left
            for(int j = i; j < count - 1; j++)
            {
                expenses[j] = expenses[j + 1];
            }

            count--;

            printf("Expense Deleted Successfully!\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("Expense ID not found!\n");
    }
}
int main() {
    // option to give user by the s/w
    int choice=1;
    char name[50];
    char jobname[50];
    printf("\n\t\t-----------------Welcome To Expenses Management System-----------------\t\t\n");
    printf("Enter Your Name: ");
    scanf("%s",name);
    printf("Enter your Job Name: ");
    scanf("%s",jobname);
    printf("Enter the Monthly Income: ");
    scanf("%f",&income);
    
    while(1){
        printf("\t\t\t-----------------Daily Expenses-----------------\t\t\t\n");
        printf("1.Add Expense\n2.View Expense\n3.Update Expenses\n4.Total Expenses\n5.Remaining Ammount\n6.Search Expenses\n7.Delete Expenses\n8.Exit\n");
        
        printf("enter the choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                addExpenses();
                break;
                
            case 2:
                viewExpenses();
                break;
            
            case 3:
                updateExpenses();
                break;
            
            case 4:
                calculateTotalExpenses();
                break;
            
            case 5:
                showRemainingAmount();
                break;
            case 6:
                searchof();
                break;
            case 7:
                deleteExpense();
                break;
            case 8:
                printf("Exit");
                break;
            default:
                printf("invalid conditons ! plz choose right option---");
                break;
        }
    }
  return 0;  
}
