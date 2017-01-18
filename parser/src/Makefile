##########################################
#
# Makefile
#
# @Author: @Ing. Diego Cordoba - @d1cor - www.juncotic.com
# @Date: 28 Dec 2016
#
##########################################

BIN := parser
OBJDIR := ../obj
SRCDIR := .
LIBDIR := ../lib


CFLAGS := -g -Wall $(CFLAGS) $(DEFINE) -I../lib/iniparser/src/
LDFLAGS := $(LDFLAGS) -L../lib/iniparser/ -liniparser


OBJECTS :=  $(addprefix $(OBJDIR)/, \
						parser.o \
						$(BIN).o)

TARGET := ../bin/$(BIN)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "compiling libiniparser"
	@make libiniparser
	@echo "Generating binary ...."
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $< -c -o $@

$(OBJDIR)/iniparser.o: $(LIBDIR)/iniparser/iniparser.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $< -c -o $@

libiniparser:
	@echo "Compiling iniparser"
	@$(MAKE) --no-print-directory -C ../lib/iniparser/

clean:
	@rm -f $(TARGET) $(OBJECTS)
	@cd ../lib/iniparser/ && make clean
