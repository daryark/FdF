#ifndef KEYCODE_H
# define KEYCODE_H

//keycodes HK_***
//events and event masks
# ifdef LINUX
# include <X11/X.h>
#  define HK_ESC            65307
#  define HK_PLUS           61
#  define HK_MINUS          45
#  define HK_UP             65362
#  define HK_DOWN           65364
#  define HK_LEFT           65361
#  define HK_RIGHT          65363

#  define KEY_PRESS        KeyPress
#  define CLOSE_BTN         DestroyNotify

#  define KEY_PRESS_MASK	KeyPressMask
# else
#  define HK_ESC            53
#  define HK_PLUS           24
#  define HK_MINUS          27
#  define HK_UP             126
#  define HK_DOWN           125
#  define HK_LEFT           123
#  define HK_RIGHT          124

#  define KEY_PRESS        2
#  define CLOSE_BTN         17

#  define KEY_PRESS_MASK	1
# endif



#endif