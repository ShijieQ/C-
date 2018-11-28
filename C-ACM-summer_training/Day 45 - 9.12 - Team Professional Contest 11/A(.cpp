#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

char Map[55][55];
int seat[55];
int d[55];
int r,n;
int row;
int lef;
int righ;

void getrow(){
   if(seat[2]&&seat[r/2+3]){
     if(seat[2]==seat[r/2+3]||seat[2]>seat[r/2+3]) row=2;
     else row=r/2+3;
   }
   else if(seat[2]) row=2;
   else if(seat[r/2+3]) row=r/2+3;
   else{
      int maxseat=0;
      for(int i=1;i<=r+3;i++) maxseat=max(maxseat,seat[i]);
      int mind=100;
      for(int i=1;i<=r+3;i++) if(seat[i]==maxseat) mind=min(mind,d[i]);
      for(int i=1;i<=r+3;i++) if(seat[i]==maxseat&&d[i]==mind) {row=i; break;}
   }
}

void getseat(char c){
   seat[row]--;
   if(Map[row][5]=='-'&&Map[row][7]=='-'){
      if(lef>righ) {Map[row][7]=c; righ++; return;}
      else {Map[row][5]=c; lef++; return;}
   }
   else if(Map[row][5]=='-') {Map[row][5]=c; lef++; return;}
   else if(Map[row][7]=='-') {Map[row][7]=c; righ++; return;}
   if(Map[row][3]=='-'&&Map[row][9]=='-'){
      if(lef>righ) {Map[row][9]=c; righ++; return;}
      else {Map[row][3]=c; lef++; return;}
   }
   else if(Map[row][3]=='-') {Map[row][3]=c; lef++; return;}
   else if(Map[row][9]=='-') {Map[row][9]=c; righ++; return;}
   if(Map[row][1]=='-'&&Map[row][11]=='-'){
      if(lef>righ) {Map[row][11]=c; righ++; return;}
      else {Map[row][1]=c; lef++; return;}
   }
   else if(Map[row][1]=='-') {Map[row][1]=c; lef++; return;}
   else if(Map[row][11]=='-') {Map[row][11]=c; righ++; return;}
   if(Map[row][6]=='-') {Map[row][6]=c; return;}
   if(Map[row][2]=='-'&&Map[row][10]=='-'){
      if(lef>righ) {Map[row][10]=c; righ++; return;}
      else {Map[row][2]=c; lef++; return;}
   }
   else if(Map[row][2]=='-') {Map[row][2]=c; lef++; return;}
   else if(Map[row][10]=='-') {Map[row][10]=c; righ++; return;}
}

int main()
{
    scanf("%d%d",&r,&n);
    for(int i=1;i<=r+3;i++){
        for(int j=1;j<=11;j++){
            scanf(" %c",&Map[i][j]);
            if(Map[i][j]=='-') seat[i]++;
            if(Map[i][j]=='#'){
                if(j<6) lef++;
                if(j>6) righ++;
            }
        }
        d[i]=min(abs(i-1),min(abs(i-r/2-2),abs(i-r-3)));
    }
    for(int i=0;i<n;i++){
        char c='a'+i;
        getrow();
        getseat(c);

    }
    for(int i=1;i<=r+3;i++){
        for(int j=1;j<=11;j++){
            cout<<Map[i][j];
        }
        printf("\n");
    }
    return 0;
}