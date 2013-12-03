#include "tools.h"

char	*my_stradd(char *str1, char *str2)
{
  char	*ret;
  int	i;
  int	j;

  if (!(ret = my_malloc(my_strlen(str1) + my_strlen(str2) + 1)))
    return (ret);
  i = 0;
  while (str1[i] != '\0')
    {
      ret[i] = str1[i];
      i++;
    }
  j = 0;
  while (str2[j] != '\0')
    {
      ret[i + j] = str2[j];
      j++;
    }
  return (ret);
}
