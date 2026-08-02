#include "eskdron.h"

/**
 * @brief This function delete every occurence of the char c
 * in the source (char *src).
 */
char *trim(char *src, char c, int *trimed_len)
{
    int j;
    char *res;
    int c_occur;
    size_t src_len;

    j = 0;
    res = NULL;
    c_occur = 0;
    src_len = ft_strlen(src);
    if (src_len == 0)
        return (res);
    for (size_t i = 0; i < src_len; i++)
    {
        if (src[i] == c)
            c_occur++;
    }
    res = malloc((src_len - c_occur + 1) * sizeof(char));
    if (!res)
        return (res);
    for (size_t i = 0; i < src_len; i++)
    {
        if (src[i] != c)
        {
            res[j] = src[i];
            j++;
        }
    }
    if (j == 0)
    {
        free(res);
        return (NULL);
    }
    res[j] = '\0';
    *trimed_len = src_len - c_occur;
    return (res);
}
