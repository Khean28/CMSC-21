#include <stdio.h>
#include <ctype.h> /* toupper, isalpha */
#include <stdbool.h>

//declare required functions
void scan_word(int *occurrences);
bool is_anagram(const int *occurrences1, const int *occurrences2);

int main(void) {
    /*
    int i,
        same = 1,
        letters[26] = {0};
    char c;
    */
    // no need to use above code (or the same = 1) since is_anagram function will just compare each element of the two arrays (occurrences1[i] != occurrences2[i])
    int occurrences1[26] = {0};
    int occurrences2[26] = {0};

    printf("Enter the first word: ");
    scan_word(occurrences1);

    printf("Enter the second word: ");
    scan_word(occurrences2);

    if (is_anagram(occurrences1, occurrences2)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

    return 0;
}

void scan_word(int *occurrences) {
    char c;
    //same code from 12-16, no need to make a code for the second word (line 18-22) since both words will be scanned using this function and their occurrences will be stored separately in occurrences1 and occurrences2 for comparisons
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            occurrences[toupper(c) - 'A']++;
        }
    }
}

bool is_anagram(const int *occurrences1, const int *occurrences2) {
    //modified code from 24-29
    for (int i = 0; i < 26; i++) {
        // if the number of each letter is not 0, then the words are not anagrams
        if (occurrences1[i] != occurrences2[i]) { 
            return false;  // Not an anagram
        }
    }
    //else, if the number of each letter in both occurrences1 and occurrences2 are the same, then the words are anagrams
    return true;
}
