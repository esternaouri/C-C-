#include <stdio.h>
#include <string.h>

 

int main()
{

FILE *income_sheet;

FILE *balance_sheet;

balance_sheet=fopen("balance.txt","r");

read_blance_word(balance_sheet);

    return 0;

}

void read_blance_word(FILE *f){

    char assets[6]="assets";

    char current[7]="current";

    char total[5]="total";

    char liabilities[11]="liabilities";

    char equity[11]="equity";

    int _equity,total_liabilities , currents_liabilities , total_assets, currents_assets;

    char words[1024];

    while (fscanf(f," %1023s",words)==1){

        puts(words);

        int i;

        for (i=0; i<sizeof(words); i++){

            if ((strcmp (words[i],total)==0)&&(strcmp (words[i+1],current)==0)&&(strcmp (words[i+2],assets)==0)){

              currents_assets=atoi(words[i+3]);

            }

            else if ((strcmp (words[i],total)==0)&&(strcmp (words[i+1],assets)==0)){

              total_assets=atoi(words[i+2]);

            }

            else if ((strcmp (words[i],total)==0)&&(strcmp (words[i+1],current)==0)&&(strcmp (words[i+2],liabilities)==0)){

              currents_liabilities=atoi(words[i+3]);

            }

            else if ((strcmp (words[i],total)==0)&&(strcmp (words[i+1],liabilities)==0)){

              total_assets=atoi(words[i+2]);

            }

            else if (strcmp (words[i],equity)==0){

              _equity=atoi(words[i+1]);

               

            }

        }

    }

    int c_rate,e_rate;

    c_rate=current_ratio (currents_assets,currents_liabilities);

    e_rate=equity_ratio (currents_assets,_equity);

    if(e_rate<0.5){

        printf("your buisness is going to die - liquidity issue (unless you are in your 2 first years) ");

    }

     if(e_rate<0.5){

        printf("your equity is less than it must be.");

    }

 

}


int current_ratio (int c_assets,int c_liabilities){

     double rate=c_assets/c_liabilities;

     return rate;

}

int equity_ratio (int c_assets,int t_equity){

     double rate=c_assets/t_equity;

     return rate;

}
