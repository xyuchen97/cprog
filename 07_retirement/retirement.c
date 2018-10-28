#include <stdlib.h>
#include <stdio.h>
struct struct_retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
  typedef struct struct_retire_info retire_info;
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
