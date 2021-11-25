/*
  *@author Vinícius Prata Klôh
*/

#ifndef COLORS_H
#define COLORS_H 1

        /* Define functions */
#define set_background(color) BACKGROUND_##color
#define set_foreground(color) FOREGROUND_##color

        /* Define background colors */
#define BACKGROUND_DEFAULT printf("\033[0;0m")
#define BACKGROUND_BLUE printf("\033[44m")
#define BACKGROUND_GREEN printf("\033[42m")
#define BACKGROUND_ORANGE printf("\033[43m")
#define BACKGROUND_RED printf("\033[41m")
#define BACKGROUND_MAGENTA printf("\033[45m")

        /* Define foreground colors */
#define FOREGROUND_DEFAULT printf("\033[0;0m")
#define FOREGROUND_BLUE printf("\033[34m")
#define FOREGROUND_GREEN printf("\033[32m")
#define FOREGROUND_ORANGE printf("\033[33m")
#define FOREGROUND_RED printf("\033[31m")
#define FOREGROUND_MAGENTA printf("\033[35m")

#endif /* COLORS_H */
