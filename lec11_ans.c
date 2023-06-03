#include <stdio.h>
#include <ctype.h> /* toupper, isalpha */
#include <stdbool.h>

//declare required functions
void scan_word(int occurences[26]);
bool is_anagram(int occurences1[26], int occurences2[26]);

int main(void) {
    /*
    int i,
        same = 1,
        letters[26] = {0};
    char c;
    */
    //no need to use above code (or the same = 1) since is_anagram function will just compare each element of the two arrays (occurences1[i] != occurences2[i])
    int occurences1[26] = {0};
    int occurences2[26] = {0};

    printf("Enter the first word: ");
    scan_word(occurences1);

    printf("Enter the second word: ");
    scan_word(occurences2);

    if (is_anagram(occurences1, occurences2)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

void scan_word(int occurences[26]) {
    char c;
    //same code from 12-16, no need to make a code for the second word (line 18-22) since both words will be scanned using this function and their occurences will be stored separately in occurences1 and occurences2 for comparisons
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            occurences[toupper(c) - 'A']++;
        }
    }
}

bool is_anagram(int occurences1[26], int occurences2[26]) {
    //modified code from 24-29
    for (int i = 0; i < 26; i++) {
        // if the number of each letter is not 0, then the words are not anagrams
        if (occurences1[i] != occurences2[i]) { 
            return false;  // Not an anagram
        }
    }
    //else, if the number of each letter in both occurences1 and occurences2 are the same, then the words are anagrams
    return true; 
}
