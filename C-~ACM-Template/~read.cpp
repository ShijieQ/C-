inline long long read(){
    long long int x = 0, t = 1, c;
    while(!isdigit(c = getchar())){ 
        if(c=='-'){ 
            t = -1;
        }
    }
    while(isdigit(c)){ 
        x = x*10 + c - '0';
        c = getchar();
    }
    return x*t;
}