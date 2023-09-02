#include <iostream>
#include <iomanip>
void checkBalance(double balance);
double withdrawMoney(double balance);
double deposit();
int main()
{
   int choice = 0;
   double balance = 0;
   std::cout << "**********Bank Management System**********" << '\n';
   do
   {

      std::cout << "******************************************" << '\n';
      std::cout << "1. Check Balance" << '\n';
      std::cout << "2. Withdraw Money" << '\n';
      std::cout << "3. Deposit Money" << '\n';
      std::cout << "4. Exit" << '\n';
      std::cout << "******************************************" << '\n';

      std::cout << "Enter your choice: ";
      std::cin >> choice;

      std::cin.clear();
      fflush(stdin);

      switch (choice)
      {
      case 1:
         checkBalance(balance);
         break;

      case 2:
         balance -= withdrawMoney(balance);
         checkBalance(balance);
         break;

      case 3:
         balance += deposit();
         checkBalance(balance);
         break;

      case 4:
         std::cout << "Thanks for visiting!" << '\n';
         break;
      default:
         std::cout << "**INVALID CHOICE**" << '\n'<< '\n';
         break;
      }

   } while (choice != 4);

   std::cout << "******************************************" << '\n';

   return 0;
}

void checkBalance(double balance)
{

   std::cout << "Your Balance is : $" << std::setprecision(2) << std::fixed << balance << '\n'
             << '\n';
}

double withdrawMoney(double balance)
{
   double withdrawAmount = 0;

   std::cout << "Enter the amount to be withdrawn: ";
   std::cin >> withdrawAmount;

   if (withdrawAmount > balance)
   {
      std::cout << "**Insufficient amount in the account**" << '\n';
      return 0;
   }
   else if (withdrawAmount < 0)
   {
      std::cout << "**Enter a valid amount**" << '\n';
      return 0;
   }
   else
   {
      std::cout << "You have successfully withdrawn your money!" << '\n';
      return withdrawAmount;
   }
}

double deposit()
{
   double depositAmount = 0;
   std::cout << "Enter the amount to be deposited: ";
   std::cin >> depositAmount;

   if (depositAmount < 0 || depositAmount == ' ')
   {
      std::cout << "\n**Invalid Amount**\n";
      return 0;
   }
   else
   {
      std::cout << "Amount deposited sucessfully!" << '\n';
      return depositAmount;
   }
}