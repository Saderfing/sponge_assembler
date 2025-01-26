SRC_DIR  = src
PAR_DIR  = $(SRC_DIR)/parser
OBJ_DIR  = src
BIN_DIR  = bin

MAIN_PRG = $(SRC_DIR)/micropiler.c
TEST_PRG = $(SRC_DIR)/test.c
PRG      = $(BIN_DIR)/micropiler
TST      = $(BIN_DIR)/test

LEX      = $(wildcard $(PAR_DIR)/*.l)
PAR      = $(wildcard $(PAR_DIR)/*.y)
SRC      = $(wildcard $(SRC_DIR)/*/*.c) $(patsubst $(PAR_DIR)/%.l, $(PAR_DIR)/%.o, $(LEX)) $(patsubst $(PAR_DIR)/%.y, $(PAR_DIR)/%.o, $(PAR))
INC      = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/*/*.h) $(patsubst $(PAR_DIR)/%.y, $(PAR_DIR)/%.h, $(PAR))
OBJ      = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CC       = gcc
CFLAGS   = -Wall -g -O0
CPPFLAGS =

LFLAGS   = -Cf
YFLAGS   = -dtv -Wcounterexamples -Wconflicts-sr -Wconflicts-rr


.PHONY: all test clean make_parser

all: $(PRG) $(TST)

main: $(PRG)

test: $(TST)

%.c:%.l
	lex $(LFLAGS) -o $@ $<

%.c:%.y
	bison $(YFLAGS) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(TST): $(PAR) $(LEX) $(OBJ) $(TEST_PRG)
	$(CC) $(CFLAGS) $(OBJ) $(TEST_PRG) -o $@ -lm -ll
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo  \* Test program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

$(PRG): $(PAR) $(LEX) $(OBJ) $(MAIN_PRG)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN_PRG) -o $@ -lm -ll
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo \* Main program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

clean:
	$(RM) -rv $(BIN_DIR)/* $(OBJ_DIR)/*/*.o

-include $(OBJ:.o=.d)