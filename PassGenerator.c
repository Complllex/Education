#include <stdio.h>
#include <stdlib.h>

int main(){
    int count;
    int chech = 0;
    int letter;
    char* alphabet[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S","T", "U", "V", "W", "X", "Y", "Z","a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s","t", "u", "v", "w", "x", "y", "z","0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "'", "`", "\"", "!", "?", ".", ",", ":", ";", "$", "%", "@", "~", "#", "(", ")", "<", ">", "{", "}", "[", "]", "_", "*", "-", "+", "^", "=", "/", "|", "\\"};
    printf("Password generator v1 by Complllex\n");
    printf("How many letters should your password contain?\n");
    scanf("%d", &count);
    if(count >= 50){
    count = 50;
    }
    printf("Your password: ");
    while (chech++ != count)
    {
       letter = rand()%93;
       printf("%s", alphabet[letter]);
    }
    printf("\n");
    return 0;
}