#include <stdio.h>  
#include <string.h>  
#define N 24 * 60  
char flag[N + 1];  
int main(void)  
{  
    int n, sh, sm, eh, em, i;  
    while(scanf("%d", &n) != EOF) {  
        memset(flag, 1, sizeof(flag));  
        while(n--) {  
            scanf("%d:%d%d:%d", &sh, &sm, &eh, &em);  
            int start = sh * 60 + sm;  
            int end = eh * 60 + em;  
            memset(flag + start, 0, end - start);  
        }  
        int ans = 0;  
        for(i=0; i<N; i++)  
            if(flag[i])  
                ans++;  
        printf("%d\n", ans);  
    }  
  
    return 0;  
}

