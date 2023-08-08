#include<stdio.h>
long int power(int a,int b,int mod)
 {
  long long int t;
  if(b==1)
  return a;
  t=power(a,b/2,mod);
  if(b%2==0)
   return (t*t)%mod;
  else
   return (((t*t)%mod)*a)%mod;
 }
 long long int calculateKey(int a,int x,int n)
 {
  return power(a,x,n);
 }
 int main()
 {
  int n,q,x,a,y,b;  
  printf("enter the value of q and n : "); 
  scanf("%d%d",&n,&q);     
  printf("enter the value of x1  ");
  scanf("%d",&x);  a=power(q,x,n);    
  printf("enter the value of x2  ");
  scanf("%d",&y);  b=power(q,y,n);
  printf("key for the first person is : %lld\n",power(b,x,n));
  printf("key for the second person is : %lld\n",power(a,y,n));
  return 0;
 }
