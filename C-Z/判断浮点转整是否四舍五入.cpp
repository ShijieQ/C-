#include<stdio.h>
int main ()
{
  int a,b,c,d;
  scanf("%d",&a);
  b = a / 100;
  if(a < 0)
    a = -a;
  c = a / 10 % 10;
  d = a % 10;
  printf("%d",b + c + d);
  return 0;
}
  #include<stdio.h>
int main ()
{
  char a;
  a = getchar ();
  printf("The ASCII of '%c' is %d.",a,a);
  return 0;
}  
#include<stdio.h>
int main ()
{
  int a,b,c,d;
  scanf("%d",&a);
  if(a < 0)
    a = -a;
  b = a / 100;
  c = a / 10 % 10;
  d = a % 10;
  printf("%d",b + c + d);
  return 0;
}
#include<stdio.h>
int main()
{
  float f;
  scanf("%f",&f);
  printf("%.2f",(f-32)/1.8);
  return 0;
}


