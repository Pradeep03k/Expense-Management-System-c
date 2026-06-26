#include <stdio.h>
#include <string.h>

// Structure declaration
struct Expense
{
    int id;
    char category[50];
    char description[100];
    float amount;
};

struct Expense expenses[100];

int count = 0;
float income = 0;


// Add Expense
void addExpenses()
{
    int howmuch;

    printf("Enter how many entries you want to add: ");
    scanf("%d", &howmuch);


    for(int i = 0; i < howmuch; i++)
    {

        if(count >= 100)
        {
            printf("Expense storage is full!\n");
            return;
        }


        printf("\nExpense %d\n", i + 1);


        printf("Enter Expense ID: ");
        scanf("%d", &expenses[count].id);


        printf("Enter Category: ");
        scanf(" %[^\n]", expenses[count].category);


        printf("Enter Description: ");
        scanf(" %[^\n]", expenses[count].description);


        printf("Enter Amount: ");
        scanf("%f", &expenses[count].amount);



        count++;

        printf("Expense added successfully!\n");

    }
}



// View Expense
void viewExpenses()
{

    if(count == 0)
    {
        printf("No record found\n");
        return;
    }


    printf("\nID\tCATEGORY\tDESCRIPTION\tAMOUNT\n");


    for(int i = 0; i < count; i++)
    {

        printf("%d\t%s\t\t%s\t\t%.2f\n",
        expenses[i].id,
        expenses[i].category,
        expenses[i].description,
        expenses[i].amount);

    }

}



// Update Expense
void updateExpenses()
{

    int id;
    int found = 0;


    printf("Enter Expense ID: ");
    scanf("%d",&id);



    for(int i = 0; i < count; i++)
    {

        if(id == expenses[i].id)
        {

            found = 1;


            printf("Enter New Category: ");
            scanf(" %[^\n]", expenses[i].category);



            printf("Enter New Description: ");
            scanf(" %[^\n]", expenses[i].description);



            printf("Enter New Amount: ");
            scanf("%f",&expenses[i].amount);



            printf("Expense Updated Successfully!\n");

            break;

        }

    }



    if(found == 0)
    {
        printf("Expense ID not found!\n");
    }

}




// Calculate Total Expenses

float calculateTotalExpenses()
{

    float total = 0;


    for(int i = 0; i < count; i++)
    {

        total += expenses[i].amount;

    }


    return total;

}



// Remaining Amount

void showRemainingAmount()
{

    float total = calculateTotalExpenses();


    printf("\nMonthly Income: %.2f",income);


    printf("\nTotal Expenses: %.2f",total);



    float remaining = income - total;


    printf("\nRemaining Budget: %.2f\n",remaining);



    if(total > income)
    {

        printf("Budget overloaded\n");

    }

}




// Search Expense

void searchExpense()
{

    int id;
    int found = 0;


    printf("Enter Expense ID: ");
    scanf("%d",&id);



    for(int i = 0; i < count; i++)
    {

        if(id == expenses[i].id)
        {

            found = 1;


            printf("\nID\tCATEGORY\tDESCRIPTION\tAMOUNT\n");


            printf("%d\t%s\t\t%s\t\t%.2f\n",
            expenses[i].id,
            expenses[i].category,
            expenses[i].description,
            expenses[i].amount);



            break;

        }

    }



    if(found == 0)
    {

        printf("Expense ID not found!\n");

    }

}





// Delete Expense

void deleteExpense()
{

    int id;
    int found = 0;



    printf("Enter Expense ID to delete: ");
    scanf("%d",&id);



    for(int i = 0; i < count; i++)
    {

        if(expenses[i].id == id)
        {

            found = 1;



            for(int j = i; j < count-1; j++)
            {

                expenses[j] = expenses[j+1];

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





int main()
{

    int choice;

    char name[50];
    char jobname[50];



    printf("\n------------ Welcome To Expense Management System ------------\n");



    printf("Enter Your Name: ");
    scanf(" %[^\n]",name);



    printf("Enter Your Job Name: ");
    scanf(" %[^\n]",jobname);



    printf("Enter Monthly Income: ");
    scanf("%f",&income);




    while(1)
    {


        printf("\n------------- Daily Expenses -------------\n");


        printf("1. Add Expense\n");
        printf("2. View Expense\n");
        printf("3. Update Expense\n");
        printf("4. Total Expense\n");
        printf("5. Remaining Amount\n");
        printf("6. Search Expense\n");
        printf("7. Delete Expense\n");
        printf("8. Exit\n");



        printf("Enter choice: ");
        scanf("%d",&choice);



        switch(choice)
        {

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
            {
                float total = calculateTotalExpenses();

                printf("Total Expenses: %.2f\n",total);

                break;
            }


            case 5:
                showRemainingAmount();
                break;



            case 6:
                searchExpense();
                break;



            case 7:
                deleteExpense();
                break;



            case 8:
                printf("Thank you for using Expense Management System\n");
                return 0;



            default:
                printf("Invalid choice!\n");

        }


    }


    return 0;

}