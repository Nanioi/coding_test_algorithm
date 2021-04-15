#include <stdio.h>

int main() {
    int i,j,k,n,m,x[100][100],c=1,cnt=0;

    scanf("%d %d", &n, &m);

    for (k = 0;k < n + m - 1;k++) {
        j = k;
        for (i = 0;i <= k;i++) {
            if ((i + j == k)&& i < n && j < m) {
                x[i][j] = c;
                c++;
            }
            j--;
        }
    }

    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++)
            printf(" %d", x[i][j]);
        printf("\n");
    }
}