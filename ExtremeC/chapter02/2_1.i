# 1 "2_1.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 410 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "2_1.c" 2
# 1 "./2_1.h" 1



typedef enum {
    NONE,
    NORMAL,
    SQUARED
} average_type_t;


double avg(int*, int, average_type_t);
# 2 "2_1.c" 2

double avg(int* array, int length, average_type_t type) {
    if (length <= 0 || type == NONE) {
        return 0;
    }
    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        if (type == NORMAL) {
            sum += array[i];
        } else if (type == SQUARED) {
            sum += array[i] * array[i];
        }
    }
    return sum / length;
}
