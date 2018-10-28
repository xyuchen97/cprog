#include <stdlib.h>
#include <stdio.h>
struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
  typedef struct _retire_info retire_info;
void retirement(int startAge, 	double initial,   retire_info working, 	retire_info retired) 
{
  double balance=initial;
  for(int i = 0; i < working.months; i++ ){
    int cur_month = startAge + i;
    int month = cur_month%12;
    int age = (cur_month - month)/12;
    printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
    balance = balance + balance*working.rate_of_return/12+working.contribution;
  }
  for(int i = 0; i < retired.months; i++ ){
    int cur_month = startAge + working.months + i;
    int month = cur_month%12;
    int age = (cur_month - month)/12;
    printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
    balance = balance + balance*retired.rate_of_return/12+retired.contribution;
  }
}
int main(void){
  retire_info working, retired;
  working.contribution = 1000;
  working.months = 489;
  working.rate_of_return = 0.045;
  retired.contribution = -4000;
  retired.months = 384;
  retired.rate_of_return = 0.01;
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
