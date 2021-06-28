#ifndef SIG_HANDLER_H
# define SIG_HANDLER_H

# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>

void sig_handler(int sig);
void set_term(void);

#endif
