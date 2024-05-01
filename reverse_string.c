#include<stdio.h>
#include<string.h>
#define BUFFER_SIZE 1024

int main() {
    char buf[BUFFER_SIZE];
    printf("%s","Enter the string to reverse: ");
    
    if(fgets(buf, BUFFER_SIZE, stdin) == NULL) {
        puts("Failed to read input.");
        return 0;
    }
    
    buf[strcspn(buf, "\n")] = 0; // remove the newline at the end of the input
    int len = strlen(buf);
    char temp;
    
    for(int i = 0; i < len/2; i++) {
        temp = buf[len-(i+1)];
        buf[len-(i+1)] = buf[i];
        buf[i] = temp;
    }
        
    printf("Reversed string: %s\n", buf);
    return 0;
}
