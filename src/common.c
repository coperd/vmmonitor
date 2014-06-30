#include <stdlib.h>
#include <errno.h>

/* 
 * Like strtol, but produce an "int" result, and check more carefully.
 * Return 0 upon success;  return -1 to indicate failure.
 * When END_PTR is NULL, the byte after the final valid digit must be NUL.
 * Otherwise, it's like strtol and lets the caller check any suffix for
 * validity.  This function is careful to return -1 when the string S
 * represents a number that is not representable as an "int". 
 */
int strtol_i(char const *s, char **end_ptr, int base, int *result)
{
    long int val;
    char *p;
    int err;

    errno = 0;
    val = strtol(s, &p, base); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s || (int) val != val);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}

/* 
 * Just like strtol_i, above, but produce an "unsigned int" value.  
 */
int strtol_ui(char const *s, char **end_ptr, int base, unsigned int *result)
{
    unsigned long int val;
    char *p;
    int err;

    errno = 0;
    val = strtoul(s, &p, base); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s || (unsigned int) val != val);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}

/* 
 * Just like strtol_i, above, but produce a "long" value.  
 */
int strtol_l(char const *s, char **end_ptr, int base, long *result)
{
    long int val;
    char *p;
    int err;

    errno = 0;
    val = strtol(s, &p, base); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}

/* 
 * Just like strtol_i, above, but produce an "unsigned long" value.  
 */
int strtol_ul(char const *s, char **end_ptr, int base, unsigned long *result)
{
    unsigned long int val;
    char *p;
    int err;

    errno = 0;
    val = strtoul(s, &p, base); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}

/* 
 * Just like strtol_i, above, but produce a "long long" value.  
 */
int strtol_ll(char const *s, char **end_ptr, int base, long long *result)
{
    long long val;
    char *p;
    int err;

    errno = 0;
    val = strtoll(s, &p, base); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}

/* 
 * Just like strtol_i, above, but produce an "unsigned long long" value.  
 */
int strtol_ull(char const *s, char **end_ptr, int base, unsigned long long *result)
{
    unsigned long long val;
    char *p;
    int err;

    errno = 0;
    val = strtoull(s, &p, base); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}

int strtod_d(char const *s, char **end_ptr, double *result)
{
    double val;
    char *p;
    int err;

    errno = 0;
    val = strtod(s, &p); /* exempt from syntax-check */
    err = (errno || (!end_ptr && *p) || p == s);
    if (end_ptr)
        *end_ptr = p;
    if (err)
        return -1;
    *result = val;
    return 0;
}
