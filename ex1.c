#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char text[], char where[], char what[])
{
    int textLen = strlen(text);
    int whereLen = strlen(where);
    int whatLen = strlen(what);

    for (int i = 0; i <= textLen - whereLen;) 
    {
        if (strncmp(&text[i], where, whereLen) == 0) 
        {
            if (whereLen != whatLen) 
            {
                if (whatLen > whereLen) 
                {
                    memmove(&text[i + whatLen], &text[i + whereLen], textLen - i - whereLen + 1);
                }
                else 
                {
                    // Shift left to remove extra space
                    memmove(&text[i + whatLen], &text[i + whereLen], textLen - i - whereLen + 1);
                }
                textLen += (whatLen - whereLen);
            }
            // Copy replacement
            memcpy(&text[i], what, whatLen);
            i += whatLen;
        }
        else {
            i++;
        }
    }
}

int main()
{
   char text[256] = "hello world, world!";
   change(text, "world", "earth");
   printf("%s\n", text); // Output: hello earth, earth!
   return 0;
}

