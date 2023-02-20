#include <stdlib.h>
#include "libft.h"
#include "env.h"

int		check_quotes(char *str);
char	*ignore_quotes(char *str);
char	*ignore_single_quotes(char *str);
int		prepare(char **str, t_env *env);
char	*prepare_dollar(char	*str, t_env *env);
int		contains_quotes(char **str);