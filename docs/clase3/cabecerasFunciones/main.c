#include <stdio.h>
#include <math.h>
#include "cmplx.h"

int main() {
    struct cmplx num1 = {3,4};
    struct cmplx *pnum1 = &num1;

    struct cmplx num2 = {1,2};
    struct cmplx *pnum2 = &num2;

    struct cmplx result;
    struct cmplx *presult = &result;

    double abs;
    int norm;

    result = cmplx_sum(pnum1,pnum2);
    cmplx_print(presult);

    result = cmplx_sub(pnum1,pnum2);
    cmplx_print(presult);

    abs = cmplx_abs(pnum1);
    printf("Abs = %f\n", abs);

    norm = cmplx_norm(pnum1);
    printf("Norm = %d\n", norm);

    return 0;
}
