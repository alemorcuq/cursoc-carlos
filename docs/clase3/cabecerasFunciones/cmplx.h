#ifndef _PERSON_H_
#define _PERSON_H_

#define MAX_NAME 256

struct cmplx {
    double real;
    double img;
};

struct cmplx cmplx_sum(const struct cmplx *a, const struct cmplx *b);
struct cmplx cmplx_sub(const struct cmplx *a, const struct cmplx *b);
double cmplx_abs(const struct cmplx *c);
int cmplx_norm(struct cmplx *c);
void cmplx_print(const struct cmplx *c);

#endif
