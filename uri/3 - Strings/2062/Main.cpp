#include <cstdio>
#include <cstring>

int main()
{
    int n,tam,p=0;
    char s[21];
    scanf("%d",&n);
    
    while(n>0){
        n--; p++;
        if(p>1)
        printf(" ");

        scanf("%s",s);
        tam=strlen(s);
        if (tam==3) {
            if (s[0]=='O' && s[1]=='B')
                printf("OBI");
            else if (s[0]=='U' && s[1]=='R')
                printf("URI");
            else
                printf("%s",s);
        } else
        printf("%s",s);
    }
    printf("\n");
    return 0;
}