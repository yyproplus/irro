#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char* stringtohex(char *dest,const char *src)
{
    char *str=(char *)malloc(100);
    printf("src length=%d\n",strlen(src));
    for(int i=0;i<strlen(src);i++)
    {
        char temp[3]={0};
        sprintf(temp,"%02x",src[i]);
        strncat(str,temp,2);
        printf("%s\n",str);
    }
    strcpy(dest,str);
    free(str);
    str=NULL;
    printf("dest=%s\n",dest);
    return dest;
}
int main() {
    char hex_str[] = {0x64, 0x73, 0x68, 0x6a, 0x6b, 0x61, 0x73};
    char *p = (char *)malloc(100);
    p[0] = '\0';  // 初始化 p 为空字符串
    printf("str length = %d\n", strlen(hex_str));
    for (int i = 0; i < strlen(hex_str); i++) {
        char hex[3] = {0};  // 需要 3 个字符来存储每个十六进制数（包括结尾的空字符）
        hex_str[i] = toupper(hex_str[i]);
        printf("%x",hex_str[i]);
        /* sprintf(hex, "%02X", hex_str[i]);
        strcat(p, hex);
        printf("p = %s\n", p); */
    }
    printf("p length = %d\n", strlen(p));
    printf("Hex string in uppercase: %s\n", p);
    free(p);
    p = NULL;
    return 0;
}

