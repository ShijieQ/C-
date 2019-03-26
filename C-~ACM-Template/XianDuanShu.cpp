const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const int MAX = 5e4+10;
const int maxn = 2e5+100;
int A[maxn];

struct node{
    int left;
    int right;
    int max;
    int sum;
    int min;
}Tree[maxn<<2];

void maintain(int root){
    int LC = root<<1; 
    int RC = (root<<1)+1;
    Tree[root].sum = Tree[LC].sum + Tree[RC].sum;   
    Tree[root].max = max(Tree[LC].max,Tree[RC].max);  
    Tree[root].min = min(Tree[LC].min,Tree[RC].min);  
}

void Build(int root,int start,int end){
    Tree[root].left = start;   
    Tree[root].right = end;
    if(start == end){
        Tree[root].sum = A[start];
        Tree[root].max = A[start];
        Tree[root].min = A[start];
        return;
    }
    int mid = (start + end)>>1;   
    Build(root<<1,start,mid);   
    Build((root<<1)+1,mid+1,end);  
    maintain(root);
}


void update(int root,int pos,int value){
    if(Tree[root].left == Tree[root].right && Tree[root].left == pos){
        Tree[root].sum += value;
        Tree[root].max = value;
        Tree[root].min = value;
        return;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1; 
    if(pos <= mid)   
        update(root<<1,pos,value);
    else
        update((root<<1)+1,pos,value);
    maintain(root);   
}


int Query(int root,int start,int end){
    if(start == Tree[root].left && Tree[root].right == end){
        return Tree[root].sum;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1;
    int ret = 0;
    if(end <= mid)
        ret += Query(root<<1,start,end);
    else if(start >= mid+1)
        ret += Query((root<<1)+1,start,end);
    else
    {
        ret += Query(root<<1,start,mid);
        ret += Query((root<<1)+1,mid+1,end);
    }
    return ret;
}


int RminQ(int root,int start,int end){
    if(start == Tree[root].left && Tree[root].right == end){
        return Tree[root].min;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1;
    int ret = INF;
    if(end <= mid)
        ret = min(ret,RminQ(root<<1,start,end));
    else if(start >= mid+1)
        ret = min(ret,RminQ((root<<1)+1,start,end));
    else{
        int a = RminQ(root<<1,start,mid);
        int b = RminQ((root<<1)+1,mid+1,end);
        ret = min(a,b);
    }
    return ret;
}


int RmaxQ(int root,int start,int end){
    if(start == Tree[root].left && Tree[root].right == end)
    {
        return Tree[root].max;
    }
    int mid = (Tree[root].left + Tree[root].right)>>1;
    int ret = -INF;
    if(end <= mid)
        ret = max(ret,RmaxQ(root<<1,start,end));
    else if(start >= mid+1)
        ret = max(ret,RmaxQ((root<<1)+1,start,end));
    else
    {
        int a = RmaxQ(root<<1,start,mid);
        int b = RmaxQ((root<<1)+1,mid+1,end);
        ret = max(a,b);
    }
    return ret;
}