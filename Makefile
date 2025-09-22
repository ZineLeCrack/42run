NAME = 42run

CC = c++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++11 -Iincludes
GLFLAGS = -lGL -lGLU -lglut -lSOIL

SRCDIR = srcs
OBJDIR = objs

SRCS = Game.cpp Map.cpp rooms.cpp utils.cpp main.cpp
SRCS := $(addprefix $(SRCDIR)/, $(SRCS))

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(GLFLAGS)
	@echo "\033[32m✔ Compilation completed\033[0m"

clean:
	$(RM) -r $(OBJDIR)
	@echo "\033[33m✔ $(OBJDIR) suppressed\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[31m✔ $(NAME) suppressed\033[0m"

re: fclean all
