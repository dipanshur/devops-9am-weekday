#include <stdio.h>

// function to calculate interest
float calculateInterest(float principal, float rate, int time) {
    return (principal * rate * time) / 100;
}

int main() {
     char ch;
    int numAccounts = 5;
    int accountNumbers[] = {1001, 1002, 1003, 1004, 1005};
    float accountBalances[] = {10000.0, 20000.0, 30000.0, 40000.0, 50000.0};
    float interestRates[] = {5.0, 6.0, 7.0, 8.0, 9.0};
    int choice;
    float amount;

    // display menu and get user choice
    do {
        printf("1. Check balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. display interest\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: // check balance
                            printf("Enter account number: ");
                            int accNum;
                            scanf("%d", &accNum);

                // search for account number in array
                            int i;
                            for (i = 0; i < numAccounts; i++) {
                                if (accountNumbers[i] == accNum) {
                                    printf("Balance: $%.2f\n", accountBalances[i]);
                                    break;
                                }
                            }
                            if (i == numAccounts) {
                                printf("Account not found\n");
                            }
                            break;

            case 2: // deposit
                printf("Enter account number: ");
                int accNum2;
                scanf("%d", &accNum2);
                printf("Enter amount: ");
                scanf("%f", &amount);

                // search for account number in array
                int j;
                for (j = 0; j < numAccounts; j++) {
                    if (accountNumbers[j] == accNum2) {
                        accountBalances[j] += amount;
                        printf("Deposit successful\n");
                        break;
                    }
                }
                if (j == numAccounts) {
                    printf("Account not found\n");
                }
                break;

            case 3: // withdraw
                printf("Enter account number: ");
                int accNum3;
                scanf("%d", &accNum3);
                printf("Enter amount: ");
                scanf("%f", &amount);

                // search for account number in array
                int k;
                for (k = 0; k < numAccounts; k++) {
                    if (accountNumbers[k] == accNum3) {
                        if (amount > accountBalances[k]) {
                            printf("Insufficient balance\n");
                            break;
                        }
                        accountBalances[k] -= amount;
                        printf("Withdrawal successful\n");
                        break;
                    }
                }
                if (k == numAccounts) {
                    printf("Account not found\n");
                }
                break;
                
            case 4:  printf("displaying interest \n");
                                  for (int l = 0; l < numAccounts; l++)
                                  {
                                float interest = calculateInterest(accountBalances[l], interestRates[l], 1);
                                printf("Account number: %d, Balance: $%.2f, Interest: $%.2f\n", accountNumbers[l], accountBalances[l],interest);
                            }
                            break;

            case 5: // exit
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\n");
        
        printf("do you want to continue y/n ");
        scanf( " %c", &ch);
        
    } while(ch=='y'|| ch=='Y');
        
    return 0;
}