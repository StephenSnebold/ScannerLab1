#include "scanner.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 32

//
// clean up the referenced token (if it isn't NULL).
//
void freeToken(TOKEN **token)
{

    free(*token);
    /*
     * TODO
     * free the referenced TOKEN*, and any data in
     * the referenced TOKEN which requires freeing
     * (not in that order).
     *
     * Then, set the referenced TOKEN* to NULL.
     */


    *token = NULL;
}

void printToken (TOKEN **token)
{
    switch ((*token)->type)
    {
        case INVALID_TOKEN:
            printf("\n<INVALID>");
            break;

        case EOF_TOKEN:
            printf("\n<EOF>");
            break;

        case INT_TOKEN:
            printf("\n<INT>, %ld", (*token)->val.integer);
            break;

        case FLOAT_TOKEN:
            printf("\n<FLOAT>, %f,", (*token)->val.floating_point);
            break;

        case ADDOP_TOKEN:
            printf("\n<ADDOP>, %c", (*token)->val.op);
            break;

        case MULTOP_TOKEN:
            printf("\n<MULTOP>, %c", (*token)->val.op);
            break;

        case IDENT_TOKEN:
            printf("\n<IDENT>, %s", (*token)->val.string);
            break;

        case REPEAT_TOKEN:
            printf("\n<REPEAT>");
            break;

        case PRINT_TOKEN:
            printf("\n<PRINT>");
            break;

        case SIMICOLON_TOKEN:
            printf("\n<SIMICOLON>");
            break;

        case LPAREN_TOKEN:
            printf("\n<LPAREN>");
            break;

        case RPAREN_TOKEN:
            printf("\n<RPAREN>");
            break;

        case ASSIGN_TOKEN:
            printf("\n<ASSIGN>");
            break;

    }
    /*
     * TODO
     * Print the referenced token in a readable format.
     * Displayed information should include the token's type,
     * and also the token's value if applicable.
     *
     * Check the sample runs for an example format.
     */
}

void checkKeywordOrID(TOKEN *token, char *str)
{
    if(strcmp(str, "print\x10") == 0)
    {
        token->type = PRINT_TOKEN;
    }
    else if (strcmp(str, "repeat\x10") == 0)
    {
        token->type = REPEAT_TOKEN;
    }
    else
    {
        token->type = IDENT_TOKEN;
        token->val.string = strdup(str);
    }
    /*
     * TODO
     * For use in the scanner function, to differentiate between keywords
     * and identifiers (which are treated identically by the state machine).
     *
     * Check if the collected token is a keyword by comparing the string
     * value arg to the string values of the keywords (print and repeat).
     * If the string value denotes is a print or repeat token, change its
     * type to the corresponding TOKEN_TYPE.
     *
     * If the token is not a keyword, then it is an identifier. Change its
     * type accordingly, and store its string value. Note that the str
     * argument is the scanner's buffer, so it should not be assigned
     * directly, but copied; the buffer will be freed before the token
     * is returned (see the bottom of the scanner function).
     *
     * Recall, to copy a string:
     * 1. Allocate enough space to store the string (including the null terminator).
     * 2. Copy the characters into this new space from the original.
     */
}

TOKEN *scanner()
{
    /*
        stringValue is a buffer to store a token's contained characters
        while it is being lexed. You should add characters to it like an
        array, and be sure to keep the stringValueIndex up to date so you
        know where the next character should go.

        Dont forget to terminate string values when they're complete!
    */
    size_t bufferSize = BUFFER_SIZE;
    char *stringValue = calloc(sizeof(char), bufferSize);
    int stringValueIndex = 0;

    // allocate space for the new token
    TOKEN *token = (TOKEN *) malloc(sizeof(TOKEN));

    // initialize the token type to denote that the token is in progress
    token->type = NO_TOKEN_TYPE;

    // set state machine to starting state
    FSM_STATE state = START_STATE;

    char currentChar = '\0';

    while (currentChar != EOF && token->type == NO_TOKEN_TYPE)
    {
        currentChar = (char) getchar();
        switch (state)
        {
            case START_STATE:
            //TODO
                switch (currentChar)
                {
                    case ';':
                        token->type = SIMICOLON_TOKEN;
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        stringValue[stringValueIndex++] = currentChar;
                        state = INT_STATE;
                        break;

                    case'(':
                        token->type = LPAREN_TOKEN;
                        break;

                    case')':
                        token->type = RPAREN_TOKEN;
                        break;

                    case'=':
                        token->type = ASSIGN_TOKEN;
                        break;

                    case '+':
                    case '-':
                        token->type = ADDOP_TOKEN;
                        break;

                    case '*':
                    case '/':
                    case '%':
                        token->type = MULTOP_TOKEN;
                        break;

                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                    case '_':
                    case '$':
                        stringValue[stringValueIndex++] = currentChar;
                        state = IDENT_OR_KEYWORD_STATE;

                        break;
                    case ' ':
                    case '\n':
                    case '\t':
                    case '\r':
                        break;

                    case EOF:
                        token->type = EOF_TOKEN;
                        break;

                    default:
                        token->type = INVALID_TOKEN;
                        token->val.op = currentChar;
                        break;
                }
            break;

            case INT_STATE:
                switch (currentChar)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        stringValue[stringValueIndex++] = currentChar;
                        break;
                    case '.':
                        stringValue[stringValueIndex++] = currentChar;
                        state = FLOAT_STATE;

                    break;
                    default:
                        ungetc(currentChar, stdin);
                        token->type = INT_TOKEN;
                        stringValue[stringValueIndex++] = '\0';
                        token->val.integer = strtol(stringValue, NULL, 10);

                        break;
                }
                break;


            case FLOAT_STATE:
                switch (currentChar)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        stringValue[stringValueIndex++] = currentChar;
                        break;
                    default:
                        ungetc(currentChar, stdin);
                        token->type = FLOAT_TOKEN;
                        stringValue[stringValueIndex++] = '\0';
                        token->val.floating_point = strtol(stringValue, NULL, 10);

                        break;

                }



                break;
            case IDENT_OR_KEYWORD_STATE:

                switch (currentChar)
                {


                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                    case '_':
                    case '$':
                        stringValue[stringValueIndex++] = currentChar;
                        break;

                    default:
                        ungetc(currentChar, stdin);
                        stringValue[stringValueIndex++] = "\0";
                        checkKeywordOrID(token,stringValue);
                        break;
                    
                }



                break;

        }
        /*
         * TODO
         * Given the current state of the state machine
         * and the next character, update the state machine
         * (and the string value of the token being built,
         * if applicable).
         *
         * DO NOT return anything here. The only return is the
         * one at the end of this function. Note that the while
         * loop stops iterating once token->type is updated, so
         * token->type should only be updated once the token is
         * ready to be returned.
         */

        // if the buffer is full, quadruple its size (do not edit)
        if (stringValueIndex >= bufferSize-1)
        {
            bufferSize *= 4;
            char *temp = calloc(sizeof(char), bufferSize);
            strcpy(temp, stringValue);
            free(stringValue);
            stringValue = temp;
        }
    }

    free(stringValue);
    return token;
}

