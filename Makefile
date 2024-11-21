SRC_DIR  = src
OBJ_DIR  = src
BIN_DIR  = bin

MAIN_PRG = $(SRC_DIR)/micropiler.c
TEST_PRG = $(SRC_DIR)/test.c

PRG      = $(BIN_DIR)/micropiler
TST      = $(BIN_DIR)/test
SRC      = $(wildcard $(SRC_DIR)/*/*.c)
INC      = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/*/*.h)
OBJ      = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC       = gcc
CFLAGS   = -Wall -g -O0
CPPFLAGS =

YFLAGS   = -d

.PHONY: all test clean

all: $(PRG) $(TST)

main: $(PRG)

test: $(TST)

$(OBJ_DIR)/%.c: $(SRC_DIR)/%.y
	bison $(YFLAGS) -o $@ $<

$(OBJ_DIR)/%.c: $(SRC_DIR)/%.l
	lex -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TST): $(OBJ) $(TEST_PRG)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_PRG) -o $@ -lm -ll
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo  \* Test program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

$(PRG): $(OBJ) $(MAIN_PRG)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_PRG) -o $@ -lm -ll
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo \* Main program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

clean:
	$(RM) -rv $(BIN_DIR)/* $(OBJ_DIR)/*/*.o

-include $(OBJ:.o=.d)