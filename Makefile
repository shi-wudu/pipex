NAME			=	pipex

SRCS			=	pipex.c utils.c errors.c

LIBFT_PATH		=	./Libft
LIBFT			=	$(LIBFT_PATH)/libft.a

PRINTF_PATH		=	./ft_printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

OBJS			=	$(SRCS:.c=.o)

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g -I. -I$(LIBFT_PATH) -I$(PRINTF_PATH)

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) --silent

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH) --silent

$(NAME): 	$(LIBFT) $(PRINTF) $(OBJS)
					@$(CC) $(CFLAGS) $(OBJS) -L$(PRINTF_PATH) -lftprintf -L$(LIBFT_PATH) -lft -o $(NAME)
					@echo -e "✓ pipex compiled successfully! \n"
					@echo -e "                                              █████████████\n \
                                         ███████ ████      ██████                                    \n \
                                    ██████████████  █████████   ████    ███ █████                    \n \
                                  ██████████████████████████████ ██████████ ███████                  \n \
                              ███████████ ███████████████████████████ ███████████████                \n \
                             ████████████████████████████████████████   ██████████████               \n \
                            ████████████████████████████████████████ █   █████████████               \n \
                           ████████████████████████████████████████ ██  ██████████████               \n \
                          ███████████████████████████████████████████████████████████                \n \
                          ██████████ ██ ██ █████████████████████████████████████████                 \n \
                         ████████              ██  ███  ██████████████████████████                   \n \
                         █████                           █████████████████████████                   \n \
                         ████                            ██████  ██████████████████				     \n \
                         ███                             ██████   █████████████████                  \n \
                         ███                             ██████   ███████████████████                \n \
                         █████     ██████          ████████████   ███████████ ███████                \n \
                          ██                             ██████   ███████████  ███████               \n \
                          ██                             █████    ██████████     ██████              \n \
                          ████████████████        ████████████    ███████ ██      ██████             \n \
                          ██        █                 ██ █████    ███ ███ ██        █  ██            \n \
                          ██  █████████            ███████████    ██ █ █████                         \n \
                          ██                             ████       █ █  ██                          \n \
                           █                             ████       ███  ██                          \n \
                           █              █              ████       █ █ ██                           \n \
                           █                            ████        ██ ██                            \n \
                           █                            ███        ██  ██                            \n \
                           ██                           ██             ██                            \n \
                           ██                           █              █                             \n \
                           ███         ████████        ██      ██  ██ ██                             \n \
                            ███       ██      ██       █        █ █████                              \n \
                             ███        █    ██                 ██ ███                               \n \
                              ███        ██ █                   █████                                \n \
                                ██                             ███                                   \n \
                                ███                      ███  ███                                    \n \
                                 ████                █████    ███                                    \n \
                                 ██ ██          ████████     ████                                    \n \
                             ██████ ███████████████ ██       ██████                                  \n \
                          ███████████████████ ██████     ██████████                                  \n \
                          ███████████████ █████████████████████████                                  \n \
                          ███████████████ ████████████████████████                                   \n \
                          ██████████ █████████████████████████████                                   \n \
                          ████████████████████████████████████████                                   \n \
                          ███████████  ███████████████████████████                                   \n \
                          ███████████  ███████████████████████████                                   \n \
                         █████████████████████████████████████████                                   \n \
                     █████████████████████████████████████████████████                               \n \
                 ████████████████████████████████████████████████████████                            \n \
              █████████████████████████████████████████████████████████████                          \n \
          ████████████████████████████████████████████████████████████████████                       "



clean:
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@$(MAKE) -C $(LIBFT_PATH) clean --silent
					@$(MAKE) -C $(PRINTF_PATH) clean --silent
					@echo "✓ All files cleaned"

fclean: 	clean
					@$(MAKE) -C $(LIBFT_PATH) fclean --silent
					@$(MAKE) -C $(PRINTF_PATH) fclean --silent
					@echo "✓ All files deep cleaned"

re:			fclean all

.PHONY: all clean fclean re