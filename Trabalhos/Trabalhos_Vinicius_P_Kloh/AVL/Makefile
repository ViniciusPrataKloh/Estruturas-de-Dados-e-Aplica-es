CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-ansi
CPPFLAGS := #-DDEBUG
LD := cc
LDFLAGS := -g
LIBS :=

PROG := avl
OBJS := main.o avl.o

${PROG}: ${OBJS}
	${LD} ${LDFLAGS} -o ${PROG} ${OBJS} ${LIBS}

clean:
	rm -f ${PROG} ${OBJS}

.PHONY: clean
