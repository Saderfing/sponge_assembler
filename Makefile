# Directories
SRCDIR   = src
INCDIR   = $(wildcard $(SRCDIR)/*/)
PARDIR   = $(SRCDIR)/parser
OBJDIR   = obj
BINDIR   = bin

# Build modes
CC       = gcc
CPPFLAGS = $(INCDIR:%=-I%)
CFLAGS   = -Wall -Wextra
LDFLAGS  = -ll -lm  # (libs includes always at the end)

LEX      = flex
LFLAGS   = -Cf

YACC     = bison
YFLAGS   = -t --header=$(PARFILE:%.y=%.h) -Wall

ifdef BUILD
CFLAGS   += -O2
else
CPPFLAGS += -g
CFLAGS   += -O0
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

SRC      = $(wildcard $(SRCDIR)/*/*.c) $(PRG)
INC      = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*/*.h)
OBJ      = $(SRC:%.c=%.o) $(PARFILE:%.y=%.o) $(LEXFILE:%.l=%.o)
EXEC     = $(BINDIR)/$(notdir $(PRG:%.c=%))

# Compile
.PHONY: all clean

all: $(EXEC)

%.c:%.l
	$(LEX) $(LFLAGS) -o $@ $<

%.c:%.y
	$(YACC) $(YFLAGS) --defines=$(patsubst %.c,%.h,$@) -o $@ $<

analyzer:
	@echo "#include \"parser.h\"" > $(PARDIR)/analyzer.h
	@echo "#include \"lexer.h\"" >> $(PARDIR)/analyzer.h

parser:$(LEXBUILD) $(PARBUILD)

$(EXEC):parser $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
	@echo \* Main program compiled successfully ! \*
	@echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"

clean:
	-rm $(BINDIR)/* $(SRCDIR)/*/*.o $(SRCDIR)/*.o $(PARBUILD) $(PARFILE:%.y=.h) $(LEXBUILD)