#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int count_chars_in_string(char*, char*);
bool is_letter(int);

int main(int argc, char **argv) {
    int count = count_chars_in_string(argv[1],argv[2]);
    if (count==-1) {
        puts("only letters can be checked!");
    } else {
        printf("The given letters occur %d times in the supplied string.\n", count);
    }
    return 0;
}

int count_chars_in_string(char* letters_to_check, char* string_to_check) {

    unsigned long long int mask = 0;
    short int count = 0;

    // set bits for letters to check
    for(int i = 0; i < strlen(letters_to_check); i++) {
        int letter = letters_to_check[i]-'A';
        if(!is_letter(letter)) {
            return (-1);
        }
        mask |= 1ULL << letter;
    }

    // count letters in string
    for(int i = 0; i < strlen(string_to_check); i++) {
        int letter = string_to_check[i]-'A';
        if(is_letter(letter)) {
            if(mask & (1ULL << letter)) {
                count++;
            }
        }
    }
    return count;
}

bool is_letter(int letter) {
    return !(letter < 0 || (letter > 25 && letter < 32) || letter > 57);
}
