#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
char Separator[2],Operator[26],Brackets[8];
char* keyword[32];
char* Functions[32];
char* Integer[1000];
char* RealNumber[1000];
char* ValidIdentifier[1000];

// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}'||ch == '%' || ch == '+=' || ch == '-='
            || ch == '*=' || ch == '/=' || ch == '%=' || ch == '=='
            || ch == '!=' || ch == '>=' || ch == '<=' || ch == '&&' || ch == '||' || ch == '!'
            || ch == '&'|| ch == '|'|| ch == '^'|| ch == '~'|| ch == '<<'|| ch == '>>'|| ch == '"')
        return (true);
    return (false);
}
bool isBrackets(char ch)
{
    if (ch == '(' || ch == ')' || ch == '{' ||
            ch == '}' || ch == '[' ||
            ch == ']'|| ch == '<' || ch == '>')
        return (true);
    return (false);
}

// Operator source https://www.programiz.com/c-programming/c-operators || Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' ||
            ch == '='|| ch == '+=' || ch == '-=' || ch == '*=' || ch == '/=' || ch == '%=' || ch == '==' || ch == '>'
            || ch == '<' || ch == '!=' || ch == '>=' || ch == '<=' || ch == '&&' || ch == '||' || ch == '!'
            || ch == '&'|| ch == '|'|| ch == '^'|| ch == '~'|| ch == '<<'|| ch == '>>' )
        return (true);
    return (false);
}

// Returns 'true' if the string is a Separator.
bool isSeparator(char ch)
{
    if (ch==','||ch==';')
        return(true);
    return(false);
}
// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
    int len = strlen(str),tLen=0,flag=0;
    while(tLen<len)
    {
        if (isDelimiter(str[tLen]) == true||str[tLen] == '^'||str[tLen] == '%'||str[tLen] == '#'||str[tLen] == '@'||
                str[tLen] == '!'||str[tLen] == '?')
            return(false);
        tLen++;
    }

    if (str[0] >= 'A' && str[0] <= 'Z' || str[0] == '$' ||
            str[0] == '_' || str[0] >= 'a' && str[0] <= 'z' )
    {
        if(str[len-1] >= 'A' && str[len-1] <= 'Z' || str[len-1] == '$' ||
                str[len-1] == '_' || str[len-1] >= 'a' && str[len-1] <= 'z')
        {
            while(len!=1)
            {

                if(str[len-2] >= '0' && str[len-2] <= '9')
                {

                    return(false);
                }
                len--;
            }
        }
        else if(str[len-1] >= '0' && str[len-1] <= '9' ||str[len-1] == '$' ||
                str[len-1] == '_')
        {

            while(len!=1)
            {

                if(str[len-2] >= '0' && str[len-2] <= '9')
                {
                    len--;
                    flag=1;
                }
                else
                {
                    flag=0;
                    break;
                }

            }
            if (flag==0)
            {
                tLen=len-3;
                while(tLen!=1)
                {

                    if  (str[tLen] >= 'A' && str[tLen] <= 'Z' || str[tLen] == '$' ||
                            str[tLen] == '_' || str[tLen] >= 'a' && str[tLen] <= 'z')
                    {
                        tLen--;

                    }
                    else
                    {
                        return(false);
                    }

                }
                return (true);
            }

        }
        return (true);
    }
    return (false);
}

// Keyword source https://www.programiz.com/c-programming/list-all-keywords-c-language || Returns 'true' if the character is a Keyword.
bool isKeyword(char* str)
{
    if (!strcmp(str, "auto") || !strcmp(str, "const") ||
            !strcmp(str, "double") || !strcmp(str, "float") ||
            !strcmp(str, "int") ||
            !strcmp(str, "short") || !strcmp(str, "struct")
            || !strcmp(str, "unsigned") || !strcmp(str, "break")
            || !strcmp(str, "continue") || !strcmp(str, "else")
            || !strcmp(str, "for") || !strcmp(str, "long")
            || !strcmp(str, "signed") || !strcmp(str, "switch")
            || !strcmp(str, "void") || !strcmp(str, "case")
            || !strcmp(str, "default") || !strcmp(str, "enum")
            || !strcmp(str, "goto") || !strcmp(str, "register")
            || !strcmp(str, "sizeof") || !strcmp(str, "typedef"))
        return (true);
    return (false);
}
// Library Functions source https://fresh2refresh.com/c-programming/c-function/c-library-functions/ || Returns 'true' if the character is a Library Functions.
bool isLibraryFunctions(char* str)
{
    if (!strcmp(str, "gets") || !strcmp(str, "malloc") ||
            !strcmp(str, "printf") || !strcmp(str, "pow") ||
            !strcmp(str, "puts") ||
            !strcmp(str, "scanf") || !strcmp(str, "sin")
            || !strcmp(str, "sqrt") || !strcmp(str, "strcmp")
            || !strcmp(str, "strcpy") || !strcmp(str, "tan")
            || !strcmp(str, "ceil") || !strcmp(str, "cos")
            || !strcmp(str, "getchar") || !strcmp(str, "strlen")
            || !strcmp(str, "floor") || !strcmp(str, "round")
            || !strcmp(str, "log") || !strcmp(str, "strchr")
            || !strcmp(str, "strdup") || !strcmp(str, "strlwr")
            || !strcmp(str, "strrev") || !strcmp(str, "main"))
        return (true);
    return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
    int i, len = strlen(str);

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;

    if (len == 0)
        return (false);
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' && str[i] != '.' ||
                (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

// Extracts the SUBSTRING.
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));

    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

// Parsing the input STRING.
void headFunction(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
    int literal=-1, tLiteral=-1, notOperator=-1, comment=-1;
    while (right <= len && left <= right)
    {

        if (isDelimiter(str[right]) == false)
            right++;

        if (isDelimiter(str[right]) == true && left == right)
        {
            if (isOperator(str[right]) == true)
            {
                int i=0,flag=0;
                if(notOperator==0)
                    printf("%c ",str[right]);
                else
                {
                    while(Operator[i]!='\0')
                    {
                        if(Operator[i]==str[right])
                        {
                            flag=1;
                            i++;
                            break;
                        }

                        else
                        {
                            flag=0;
                            i++;
                        }
                    }
                    if(flag==1)
                        printf("---------------------------Operator\n");
                    else
                    {
                        Operator[i]=str[right];
                        printf("'%c' is a Operator\n", str[right]);
                    }
                }


            }

            else if(isSeparator(str[right])==true)
            {
                int i=0,flag=0;
                if(notOperator==0)
                    printf("%c ",str[right]);
                else
                {
                    while(Separator[i]!='\0')
                    {
                        if(Separator[i]==str[right])
                        {
                            flag=1;
                            i++;
                            break;
                        }

                        else
                        {
                            flag=0;
                            i++;
                        }
                    }
                    if(flag==1)
                        printf("---------------------------Separator\n");
                    else
                    {
                        Separator[i]=str[right];
                        printf("'%c' is a Separator\n", str[right]);
                    }
                }

            }

            else if(isBrackets(str[right])==true)
            {
                int i=0,flag=0;
                if(notOperator==0)
                    printf("%c ",str[right]);
                else
                {
                    while(Brackets[i]!='\0')
                    {
                        if(Brackets[i]==str[right])
                        {
                            flag=1;
                            i++;
                            break;
                        }

                        else
                        {
                            flag=0;
                            i++;
                        }
                    }
                    if(flag==1)
                    {
                        printf("---------------------------Bracket\n");
                    }
                    else
                    {
                        Brackets[i]=str[right];
                        printf("'%c' is a Brackets\n", str[right]);
                    }//int();int();

                }

            }
            else if(str[right]=='"'&&tLiteral==-1)
            {
                literal=1;
                notOperator=0;
                printf("Literal= %c ",str[right]);
            }
            else if(str[right]=='"'&&literal==1)
            {
                printf("%c \n",str[right]);
                literal=-1;
                tLiteral=-1;
                notOperator=-1;
            }

            right++;
            left = right;
        }
        else if (isDelimiter(str[right]) == true && left != right
                 || (right == len && left != right))
        {
            char* subStr = subString(str, left, right - 1);
            if(literal==1)
            {
                tLiteral=0;
                printf("%s ", subStr);
            }
            else if (isKeyword(subStr) == true)
            {
                int i=0,flag=0;
                while(keyword[i]!='\0')
                {
                    if(strcmp(keyword[i], subStr)==0)
                    {

                        flag=1;
                        i++;
                        break;
                    }

                    else
                    {
                        flag=0;
                        i++;
                    }


                }
                if(flag==1)
                    printf("---------------------------Keyword\n");
                else
                {
                    keyword[i]=subStr;
                    printf("'%s' IS A Keyword\n", subStr);//unsigned,short,break,float
                }

            }
            else if (isLibraryFunctions(subStr) == true)
            {
                int i=0,flag=0;
                while(Functions[i]!='\0')
                {
                    if(strcmp(Functions[i], subStr)==0)
                    {

                        flag=1;
                        i++;
                        break;
                    }

                    else
                    {
                        flag=0;
                        i++;
                    }


                }
                if(flag==1)
                    printf("---------------------------Functions\n");
                else
                {
                    Functions[i]=subStr;
                    printf("'%s()' IS A Library Function\n", subStr);//unsigned,short,break,float
                }
            }

            else if (isInteger(subStr) == true)
            {
                int i=0,flag=0;
                while(Integer[i]!='\0')
                {
                    if(strcmp(Integer[i], subStr)==0)
                    {

                        flag=1;
                        i++;
                        break;
                    }

                    else
                    {
                        flag=0;
                        i++;
                    }


                }
                if(flag==1)
                    printf("---------------------------Integer\n");
                else
                {
                    Integer[i]=subStr;
                    printf("'%s' is an Integer\n", subStr);//unsigned,short,break,float
                }
            }

            else if (isRealNumber(subStr) == true)
            {
                int i=0,flag=0;
                while(RealNumber[i]!='\0')
                {
                    if(strcmp(RealNumber[i], subStr)==0)
                    {

                        flag=1;
                        i++;
                        break;
                    }

                    else
                    {
                        flag=0;
                        i++;
                    }


                }
                if(flag==1)
                    printf("---------------------------RealNumber\n");
                else
                {
                    RealNumber[i]=subStr;
                    printf("'%s' IS A REAL NUMBER\n", subStr);//unsigned,short,break,float
                }
            }


            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
            {
                int i=0,flag=0;
                while(ValidIdentifier[i]!='\0')
                {
                    if(strcmp(ValidIdentifier[i], subStr)==0)
                    {

                        flag=1;
                        i++;
                        break;
                    }

                    else
                    {
                        flag=0;
                        i++;
                    }


                }
                if(flag==1)
                    printf("---------------------------ValidIdentifier\n");
                else
                {
                    ValidIdentifier[i]=subStr;
                    printf("'%s' IS A VALID IDENTIFIER\n", subStr);//unsigned,short,break,float
                }
            }


            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}


int main()
{
    char str[100] ;
    while(true)
    {
        printf("Enter your line of code\n");
        gets(str);
        if(strlen(str)==0)
            break;
        else
            headFunction(str); // calling the headFunction function
    }
    int coun;
    coun= strlen(Separator);
    printf("\nTotal Separator= %d", coun);

    coun=strlen(keyword);
    printf("\nTotal keyword= %d", coun);

    coun=strlen(Functions);
    printf("\nTotal Functions= %d", coun);

    coun=strlen(Brackets);
    printf("\nTotal Brackets= %d", coun);

    coun=strlen(Operator);
    printf("\nTotal Operator= %d", coun);

    coun=strlen(Integer);
    printf("\nTotal Integer= %d", coun);

    coun=strlen(RealNumber);
    printf("\nTotal Real Number= %d", coun);

    coun=strlen(ValidIdentifier);
    printf("\nTotal Valid Identifier= %d", coun);

    return 0;
}
