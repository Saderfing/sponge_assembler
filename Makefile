# Directories
SRCDIR   = src
INCDIR   = $(wildcard $(SRCDIR)/*/)
PARDIR   = $(SRCDIR)/parser
OBJDIR   = obj
BINDIR   = bin

# Build modes

ifdef BUILD
CFLAGS   +=-O2
else
CPPFLAGS +=-g
CFLAGS   +=-O0
endif

ifdef TEST
PRG      = $(SRCDIR)/test.c
else
PRG      = $(SRCDIR)/micropiler.c
endif

# Files

LEXFILE  = $(wildcard $(PARDIR)/*.l)
PARFILE  = $(wildcard $(PARDIR)/*.y)

LEXBUILD = $(LEXFILE:%.l=%.c)
PARBUILD = $(PARFILE:%.y=%.c)

SRC      = $(LEXBUILD) $(PARBUILD) $(wildcard $(SRCDIR)/*/*.c) $(PRG)
INC      = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*/*.h)
OBJ      = $(SRC:%.c=%.o) 
EXEC     = $(BINDIR)/$(notdir $(PRG:%.c=%))


# Compile

CC       = gcc
CPPFLAGS = $(INCDIR:%=-I%)
CFLAGS   = -Wall
LDFLAGS  = -ll -lm  # (libs includes always at the end)

LEX      = lex
LFLAGS   = -Cf

YACC     = bison
YFLAGS   = -t --header=$(PARFILE:%.y=%.h) -Wall



.PHONY: all main test clean

all: $(EXEC)


%.c:%.l
	$(LEX) $(LFLAGS) -o $@ $<

%.c:%.y
	$(YACC) $(YFLAGS) -o $@ $<


$(EXEC):$(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo \* Main program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

clean:
	-rm $(BINDIR)/* $(SRCDIR)/*/*.o $(SRCDIR)/*.o $(LEXBUILD) $(PARBUILD)