NAME = minitalk
SRCLIENT =   client.c minitalk_utils.c
OBJSCLIENT = $(SRCLIENT:.c=.o)
SRCSERVER = server.c minitalk_utils.c
OBJSERVER = $(SRCSERVER:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)
	
$(NAME): $(OBJSERVER) $(OBJSCLIENT)
	@gcc -o server $(SRCSERVER) $(CFLAGS)
	@gcc -o client $(SRCLIENT) $(CFLAGS) 
	
clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT)
	
fclean: clean
	rm -f server client
	
re: fclean all

.PHONY: all clean fclean re