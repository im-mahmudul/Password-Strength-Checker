#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(char password[]) {
    int length = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;


    if (length < 8) 
    return 0;

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) 
        hasLower = 1;
        else if (isupper(password[i])) 
        hasUpper = 1;
        else if (isdigit(password[i])) 
        hasDigit = 1;
        else hasSpecial = 1;
    }

    if (hasLower && hasUpper && hasDigit && hasSpecial) 
    return 3; 
    if ((hasLower + hasUpper + hasDigit + hasSpecial) >= 3) 
    return 2; 
    return 1; 
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);


    if (strength == 0)
        printf("Password is too short. Use at least 8 characters.\n");
    else if (strength == 1)
        printf("Password is weak. Try adding uppercase, lowercase, numbers, and symbols.\n");
    else if (strength == 2)
        printf("Password is moderate. Adding more character variety can help.\n");
    else
        printf("Password is strong. Great job!\n");

    return 0;
}
