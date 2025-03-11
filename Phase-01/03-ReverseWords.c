#include <stdio.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 40

/**
 * my_strcpy - My custom strcpy function.
 * @dest: destination where we'll put our copy.
 * @src: source that we want to copy from.
 */
void my_strcpy(char *dest, const char *src){
    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // add the null terminator at the end of dest.
}

/**
 * split_words - split a phrase into words.
 * @phrase: input source phrase.
 * @words: the destination where we'll put our words.
 * @words_count: the number of words we have in the phrase.
 */
void split_words(const char phrase[MAX_WORDS], char words[MAX_WORDS][MAX_WORD_LEN], int *words_count){
    int i = 0, j = 0, k = 0;
    while (phrase[i] != '\0'){
        if (phrase[i] != ' '){
            words[j][k++] = phrase[i]; // update the value of words[j][k] then increment k.
        } else if (k > 0){ // end of word
            words[j][k] = '\0';
            j++;
            k = 0;
        }
        i++;
    }
    if (k > 0) {
        words[j][k] = '\0';
        j++;
    }
    *words_count = j;
}

/**
 * words_to_phrase - convert back words into one phrase
 * @Source: input source words.
 * @DesStr: the destination where we'll write our phrase.
 * @words_count: the number of words we have.
 * @delim: the delimiter of between the words
 */
void words_to_phrase(char words[MAX_WORDS][MAX_WORD_LEN], char dest[], int words_count, char delim) {
    int pos = 0;
    for (int i = 0; i < words_count; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            dest[pos++] = words[i][j];
        }
        if (i != words_count - 1) {
            dest[pos++] = delim;
        }
    }
    dest[pos] = '\0';
}

void swap_words(char *first_word, char *second_word){
    char temp[MAX_WORD_LEN];
    my_strcpy(temp, first_word);
    my_strcpy(first_word, second_word);
    my_strcpy(second_word, temp);
}

/**
 * reverse_words - A function that reverser the order of words.
 * @str: Input string.
 */
void reverse_words ( char str[])
{
    int words_count = 0;
    char words[MAX_WORDS][MAX_WORD_LEN];

    split_words(str, words, &words_count);
    // reverse_string(str);

    for (int i = 0; i < words_count/2; i++){
        swap_words(words[i], words[words_count - i - 1]);
    }
    words_to_phrase(words, str, words_count, ' ');
}

int main ( void )
{
    char test1 [] = "The dragons are coming";
    char test2 [] = "code love I";
    char test3 [] = "G";
    printf (" Before : %s\n" , test1 );
    reverse_words ( test1 );
    printf (" After : %s\n\n" , test1 );
    printf (" Before : %s\n" , test2 );
    reverse_words ( test2 );
    printf (" After : %s\n\n" , test2 );
    printf (" Before : %s\n" , test3 );
    reverse_words ( test3 );
    printf (" After : %s\n\n" , test3 );
    return 0;
}