/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:49:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/28 16:15:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

//keycodes HK_***
//events and event masks
# ifdef LINUX
#  include <X11/X.h>
#  define HK_Z              0//define value
#  define HK_ESC            65307
#  define HK_PLUS           61
#  define HK_MINUS          45
#  define HK_UP             65362
#  define HK_DOWN           65364
#  define HK_LEFT           65361
#  define HK_RIGHT          65363

#  define KEY_PRESS         KeyPress
#  define KEY_RELEASE       KeyRelease
// #  define MOUSE_MOVE_UP     MouseMove //?what number on linux
// #  define MOUSE_MOVE_DOWN   MouseMove //? what number on linux
#  define DESTROY_NOTIFY        DestroyNotify

#  define KEY_PRESS_MASK	KeyPressMask
#  define KEY_RELEASE_MASK	KeyReleaseMask
#  define NOEVENT_MASK      NoEventMask
// #  define MOUSE_WHEEL_MASK  Button3MotionMask
// #  define MOUSE_MOVE_MASK   MouseMoveMask
# else
#  define HK_Z              6
#  define HK_X              7
#  define HK_Y              16
#  define HK_R              15
#  define HK_ARROW_L        43
#  define HK_ARROW_R        47
#  define HK_CTRL_L         256
#  define HK_CTRL_R         264
#  define HK_ESC            53
#  define HK_PLUS           24
#  define HK_MINUS          27
#  define HK_UP             126
#  define HK_DOWN           125
#  define HK_LEFT           123
#  define HK_RIGHT          124
#  define DESTROY_NOTIFY    17

#  define KEY_PRESS         2
#  define KEY_RELEASE       3
#  define HK_MOUSE_L        1
// #  define MOUSE_MOVE_UP     5
// #  define MOUSE_MOVE_DOWN   4
// #  define BTN_PRESS         4

#  define KEY_PRESS_MASK	1
#  define KEY_RELEASE_MASK	2
#  define NOEVENT_MASK      0
// #  define MOUSE_WHEEL_MASK  10
// #  define MOUSE_MOVE_MASK   3
# endif

#endif

//MASK just specify the type of event to track, and others to not pay attention
//EVENT - tells the event type to React for exactly
//key HOOK - is the specifier of the exact button/key of mouse/keybr event