#include <stdio.h>
#include <stdlib.h>

#define M  12

void read(int request[]) {
    int temp, i = 0;
    for (i = 0; i < M; i++) {
        scanf("%d", &request[i]);
    }
}

/*给数组赋值*/
void setarray(int arr[], int num, int val) {
    int i;
    for (i = 0; i < num; ++i) {
        arr[i] = val;
    }
}

/*查找内存 mem 中是否存在页面 page*/
int findexist(int mem[], int mnum, int page) {
    int i;
    for (i = 0; i < mnum; i++) {
        if (mem[i] == page) {
            return i;
        }
    }
    return -1;
}

/*查找内存 mem 中是否存空的位置*/ 
int findempty(int mem[], int mnum) {
    int i;
    for (i = 0; i < mnum; i++) {
        if (mem[i] == -1) {
            return i;
        }
    }
    return -1;
}

/*先进先出页面置换算法*/ 
int fifo(int req[], int rnum, int mnum) {
    int count;
    int i, j;
    int pos;
    int max; /*分配内存空间*/
    int *mem = (int *)malloc(sizeof(int) * mnum);
    int val[mnum][rnum];
    for (i = 0; i < mnum; i++) {
        for (j = 0; j < rnum; j++) {
            val[i][j] = -1;
        }
    }
    setarray(mem, mnum, -1);

    /*time 记录内存中每个页面进入的时间*/ 
    int *time = (int *)malloc(sizeof(int) * mnum);
    setarray(time, mnum, M); 
    /*缺页率初始时为 0*/
    count = 0;

    for (i = 0; i < rnum; ++i) { 
        /*发现页面请求是否存在内存中*/
        pos = findexist(mem, mnum, req[i]);

        /*如果内存中存在页面请求*/ 
        if (pos != -1) {
            int k = 0;
            for (k = 0; k < mnum; k++) {
                val[k][i] = val[k][i-1];
            }
            continue; /*如果内存中不存在缺页次数加一*/
        }
        count++;

        /*内存中是否存在空位置可以存放新页面*/ 
        pos = findempty(mem, mnum);

        /*存在空位置，直接存入新页面，不做置换*/ 
        if (pos != -1) {
            mem[pos] = req[i];
            time[pos] = i;
            int k = 0;
            for (k = 0; k < mnum; k++) {
                val[k][i] = val[k][i-1];
            }
            val[pos][i] = req[i];
            continue;
        }
        /*不存在空位置，寻找要置换的页面，fifo*/

        pos = 0;
        for (j = 1; j < mnum; ++j) {
            if (time[j] < time[pos]) {
                pos = j;
            }
        }
        int k = 0;
        for (k = 0; k < mnum; k++) {
            val[k][i] = val[k][i-1];
        }
        val[pos][i] = req[i];
        mem[pos] = req[i];
        time[pos] = i;
    }
    
    for (i = 0; i < mnum; i++) {
        for (j = 0; j < rnum; j++) {
            printf("%3d ", val[i][j]);
        }
        printf("\n");
    }
    free(time);
    free(mem);
    return count;
}

/*最近最久未使用页面置换算法*/ 
int lru(int req[], int rnum, int mnum) {
    int count;
    int i, j;
    int pos;
    int max; /*分配内存空间*/
    int *mem = (int *)malloc(sizeof(int) * mnum);
    int val[mnum][rnum];
    for (i = 0; i < mnum; i++) {
        for (j = 0; j < rnum; j++) {
            val[i][j] = -1;
        }
    }
    setarray(mem, mnum, -1);

    /*time 记录内存中每个页面最后访问的时间*/ 
    int *time = (int *)malloc(sizeof(int) * mnum);
    setarray(time, mnum, M); /*缺页率初始时为 0*/
    count = 0;

    for (i = 0; i < rnum; ++i) { /*发现页面请求是否存在内存中*/
        pos = findexist(mem, mnum, req[i]);

        /*如果内存中存在页面请求，此处与 fifo 有些许区别*/
        if (pos != -1) {
            time[pos] = i;
            int k = 0;
            for (k = 0; k < mnum; k++) {
                val[k][i] = val[k][i-1];
            }
            /*此处 lru 记录的是最后一次的访问时间，而 fifo 中记录的是最先进入的时间*/
            continue;
        } /*如果内存中不存在缺页次数加一*/
        count++;

        /*内存中是否存在空位置可以存放新页面*/ 
        pos = findempty(mem, mnum);
        /*存在空位置，直接存入新页面，不做置换*/ 
        if (pos != -1) {
            mem[pos] = req[i];
            time[pos] = i;
            int k = 0;
            for (k = 0; k < mnum; k++) {
                val[k][i] = val[k][i-1];
            }
            val[pos][i] = req[i];
            continue;
        } 
        /*不存在空位置，寻找要置换的页面，lru*/
        pos = 0;
        for (j = 1; j < mnum; ++j) {
            if (time[j] < time[pos]) {
                pos = j;
            }
        }
        int k = 0;
        for (k = 0; k < mnum; k++) {
            val[k][i] = val[k][i-1];
        }
        val[pos][i] = req[i];
        mem[pos] = req[i];
        time[pos] = i;
    }

    for (i = 0; i < mnum; i++) {
        for (j = 0; j < rnum; j++) {
            printf("%3d ", val[i][j]);
        }
        printf("\n");
    }
    free(time);
    free(mem);
    return count;
}

/*最佳页面置换算法*/ 
int opt(int req[], int rnum, int mnum) {
    int count;
    int i, j;

    int pos;
    int max; /*分配内存空间*/
    int *mem = (int *)malloc(sizeof(int) * mnum);
    int val[mnum][rnum];
    for (i = 0; i < mnum; i++) {
        for (j = 0; j < rnum; j++) {
            val[i][j] = -1;
        }
    }
    setarray(mem, mnum, -1);

    /*time 记录内存中每个页面将来要访问的时间*/ 
    int *time = (int *)malloc(sizeof(int) * mnum); /*缺页率初始时为 0*/
    count = 0;

    for (i = 0; i < rnum; ++i) { 
        /*发现页面请求是否存在内存中*/
        pos = findexist(mem, mnum, req[i]);

        /*如果内存中存在页面请求，此处与 fifo 相同*/ 
        if (pos != -1) {
            int k = 0;
            for (k = 0; k < mnum; k++) {
                val[k][i] = val[k][i-1];
            }
            continue;
        }
        /*如果内存中不存在缺页次数加一*/ 
        count++;

        /*内存中是否存在空位置可以存放新页面*/ 
        pos = findempty(mem, mnum);

        /*存在空位置，直接存入新页面，不做置换*/ 
        if (pos != -1) {
            mem[pos] = req[i];
            int k = 0;
            for (k = 0; k < mnum; k++) {
                val[k][i] = val[k][i-1];
            }
            val[pos][i] = req[i];
            continue;
        }

        /*不存在空位置，寻找要置换的页面，opt*/ 
        setarray(time, mnum, M);

        int k;
        /*查找内存中每个页面在将来出现的最近时间*/

        for (j = 0; j < mnum; ++j) {
            for (k = i + 1; k < rnum; k++) {
                if (mem[j] == req[k]) {
                    time[j] = k;
                    break;
                }
            }
        }

        pos = 0;
        for (j = 1; j < mnum; ++j) {
            /*此处与 fifo 和 lru 有区别*/
            if (time[j] > time[pos]) {
                pos = j;
            }
        }
        int l = 0;
        for (l = 0; l < mnum; l++) {
            val[l][i] = val[l][i-1];
        }
        val[pos][i] = req[i];
        mem[pos] = req[i];
    }
    for (i = 0; i < mnum; i++) {
        for (j = 0; j < rnum; j++) {
            printf("%3d ", val[i][j]);
        }
        printf("\n");
    }
    free(time);
    free(mem);
    return count;
}

int main() {
    freopen("data.in", "r", stdin);
    int request[M];
    read(request);
    // for (int i = 0; i < M; i++) {
    //     printf("%d ", request[i]);
    // }
    // int request[M] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};

    int count;
    int n = 3;

    count = fifo(request, M, n);
    printf("fifo: %d \n", count);
    count = lru(request, M, n);
    printf("lru: %d \n", count);

    count = opt(request, M, n);
    printf("opt: %d \n", count);

    return 0;
}