#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how may cents the customer is owed
    int cents = get_cents();

    //Calculatye the number of quarters to give the costumer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate ther numbers of dimes to giver the costumers
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    //Calculate the numbers of nickels to give the customers
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    //Calculate the number of pennies to give the customes
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    //Sum coins
    int coins = quarters + dimes + nickels + pennies;

    //Print total number of coins to give the customer
    printf("%i\n", coins);
}
// Promt the user to input chand until non-neg value provided
int get_cents (void)
{
    int cents;
    //Prompt user to input chand until non-neg value provided
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
//Calc num of quarters for given amount in cents
return cents / 25;
}

int calculate_dimes(int cents)
{
    //Calculate number of dimes for given amount in cents
    return cents / 10;
}

int calculate_nickels(int cents)
{
    //Calculate num of nickels for given amount in cents
    return cents / 5;
}

int calculate_pennies(int cents)
{
    //Calc num of pennies for given amount in cents
    return cents / 1;
}