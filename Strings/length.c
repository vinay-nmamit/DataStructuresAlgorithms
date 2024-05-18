#include <stdio.h>

int stringLength(const char *str){
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

int main(){
    const char *str = "Good morning students";
    int length = stringLength(str);
    printf("length of the string: %d\n", length);
    return 0;

}
    
