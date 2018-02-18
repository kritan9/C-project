#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Factors.h"
#include "properfraction.h"
#include "det.h"
#include "swap.h"
#include "LinearEquation.h"
#include "regression.h"


int main(){
    int x=0;
X:
    printf("\nSelect an Option\n");
    scanf(" %d",&x);
   if(x==1) Linear();
    if(x==2) regression();
    goto X;
    return 0;
}



