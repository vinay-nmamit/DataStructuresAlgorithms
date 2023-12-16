#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringconcat(const char *str1, const char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result = (char *)malloc(len1 + len2 + 1);  //+1 for null termination
    if(result == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result,str1);
    strcat(result,str2);
    return result;
}  

int main(){
    const char *str1 = "HEllo ";
    const char *str2 = "world!!!!";
    char *stringconcatenate = stringconcat(str1,str2);
    printf("concatenated string: %s\n",stringconcatenate);
    free(stringconcatenate);
    return 0;
}