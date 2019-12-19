const int maxm = 1000000 + 100;
int num[maxm];
int Max,Min,sum;

struct tree{
     int left,right;
     int maxx,minn;
     int sum;
}t[maxm*3 + 100];

void push_up(int k){
    t[k].maxx =max( t[k<<1].maxx, t[k<<1|1].maxx);
    t[k].minn =min( t[k<<1].minn, t[k<<1|1].minn);
    t[k].sum =t[k<<1].sum+t[k<<1|1].sum;
}

void make(int l,int r,int k){
    if(l==r){
        t[k].left=t[k].right=l;
        t[k].maxx=t[k].minn=t[k].sum=num[l];
        return;
    }                       
    t[k].left=l;
    t[k].right=r;
    make(l,(l+r)>>1,k<<1);
    make(((l+r)>>1)+1,r,k<<1|1);
    push_up(k);
}

void Query(int l,int r,int k){
    if(l<=t[k].left&&r>=t[k].right){
        Max=max(Max,t[k].maxx);
        Min=min(Min,t[k].minn);
        sum+=t[k].sum;
        return;
    }
    if(l<=(t[k].left+t[k].right)>>1)
        Query(l,r,k<<1);
    if(r>(t[k].left+t[k].right)>>1)
        Query(l,r,k<<1|1);
}