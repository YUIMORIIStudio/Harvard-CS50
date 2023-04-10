#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Declare that each of the three variables stores the text entered by the user
int num_letters(string text);
int num_words(string text);
int num_sentences(string text);


//count the number of letter in the text
int num_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        //Include case of letters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}
//count the number of word in the text
int num_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

//count the number of sentence in the text
int num_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

int main(void)
{
    //prompt text insert by users
    string text = get_string("please insert your text: ");
    int letters = num_letters(text);
    int words = num_words(text);
    int sentences = num_sentences(text);
    //Coleman-Liau formula
    // L is the average number of letters per 100 words in the text
    // float L = (float)letters / words * 100;
    // S is the average number of sentences per 100 words in the text
    // float S = (float)sentences / words * 100;
    int index = round(0.0588 * ((float)letters / words * 100) - 0.296 * ((float)sentences / words * 100) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}