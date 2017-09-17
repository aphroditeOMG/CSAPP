/** return if x <= y */
int float_lw(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy , sx,and sy */
    return  (sx > sy) || (sx == 1 && ux >= uy) || (sy == 0 && ux <= uy);
}