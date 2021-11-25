CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-ansi
CPPFLAGS := #-DDEBUG
LD := cc
LDFLAGS := -g
LIBS :=

PROG := list
OBJS := main.o list.o

${PROG}: ${OBJS}
	${LD} ${LDFLAGS} -o ${PROG} ${OBJS} ${LIBS}

clean:
	rm -f ${PROG} ${OBJS}

.PHONY: clean
