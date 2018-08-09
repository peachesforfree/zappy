CLIENT = client
CFLAGS += -Wall -Werror -Wextra
INCLUDES = -I./inc
CC = gcc

################################################################################
# Source directories identifiers                                               #
################################################################################

SRCDIR = src/
SRCDIR_CLN = client/
SRCDIR_UTIL = util/


OBJSRC = $(patsubst %, %.o, $(addprefix $(addprefix $(SRCDIR), $(SRCDIR_CLN)), $(SRC_CLN)))
OBJSRC += $(patsubst %, %.o, $(addprefix $(addprefix $(SRCDIR), $(SRCDIR_UTIL)), $(SRC_UTIL)))

################################################################################
# SOURCE FILES                                                                 #
################################################################################

SRC_CLN = server

SRC_UTIL = read_flags

################################################################################
# SOURCE FILES                                                                 #
################################################################################

all: $(CLIENT)

$(SRV): $(OBJSRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJSRC) -o $(CLIENT) 

%.o: %.c
	@ echo "$(YELLOW)Compiling $<...$(RES)"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJSRC)
	
fclean: clean
	rm -f $(CLIENT)
	
re: fclean all
	