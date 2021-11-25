CC := cc
CFLAGS := -g -Wall -Wextra -Werror #-ansi
CPPFLAGS := #-DDEBUG
LD := cc
LDFLAGS := -g
LIBS :=

PROG := pollutant_propagation
OBJS := main.o pp_utils.o io.o

${PROG}: ${OBJS}
	${LD} ${LDFLAGS} -o ${PROG} ${OBJS} ${LIBS}

clean:
	rm -f ${PROG} ${OBJS}

.PHONY: clean
