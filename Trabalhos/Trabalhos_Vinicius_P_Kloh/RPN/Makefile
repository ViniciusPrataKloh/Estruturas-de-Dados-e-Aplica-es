CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-ansi
CPPFLAGS := #-DDEBUG
LD := cc
LDFLAGS := -g
LIBS := -lm

PROG := rpn_calc
OBJS := main.o stack.o calc.o

${PROG}: ${OBJS}
	${LD} ${LDFLAGS} -o ${PROG} ${OBJS} ${LIBS}

clean:
	rm -f ${PROG} ${OBJS}

.PHONY: clean
