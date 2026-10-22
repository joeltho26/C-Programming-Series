#include <stdio.h>
#include <string.h>

int main() {
    int count = 10;
    const char *hash_str = "###################";
    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char fname[15] = ""; 
    char lname[15] = "";
    char fullname[50] = "";
    printf("Enter firstname:");
    scanf("%s", &fname); // strings with spaces not allowed i.e. first and last name

    printf("Enter lastname:");
    scanf("%s", &lname);

    /*
    getchar() => used to print and fetch the input in a separate line, 
    needed when we use fgets to obtain user input values after a scanf statement
    */
    getchar(); 
    printf("Enter fullname:");
    fgets(fullname, sizeof(fullname), stdin); // allows strings with spaces
    /*
    make the last character null instead of \n which is the default behaviour
    when we use fgets method otherwise, when we print there will be additional 
    empty line i.e. \n. note: do not remove \n from the printf statement instead 
    use the below line of code
    */
    fullname[strlen(fullname) - 1] = '\0'; 

    printf("Enter age:");
    scanf("%d", &age);

    printf("Enter gpa:");
    scanf("%f", &gpa);

    /*
    The infamous '\n' glitch only happens if you try to read a character (%c) 
    or a scanset (%[^\n]) immediately after reading a number

    SCENARIO: 
    • When you type a float (like 3.14) and hit Enter, scanf("%f") consumes 
    3.14 but leaves the \n sitting in the input buffer.
    • If your next command is another scanf("%f") or scanf("%d"), it doesn't matter.
    The next function will happily skip right past that leftover \n to find the next number.
    • If your next command is scanf("%c"), the %c specifier does not skip whitespace. It will immediately consume that leftover \n as the character, skipping your intended user prompt entirely
    */
    printf("Enter grade:");
    scanf(" %c", &grade);
    // .* to limit how many characters get printed
    printf("%.*s\n", count, hash_str);
    printf("First name: %s\n", fname);
    printf("Last name: %s\n", lname);
    printf("Full name: %s\n", fullname);
    printf("Age: %d\n", age);
    printf("Grade: %c\n", grade);
    printf("GPA: %.2f\n", gpa);
    printf("%.*s\n", count, hash_str);
    return 0;
}
