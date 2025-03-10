/*
** mlx_int_param_event.c for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Wed Oct  6 13:14:52 2004 Olivier Crouzet
*/

#include    "mlx_int.h"

int mlx_int_param_undef(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	return 0;
}

int mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(KeySym, void *) = (void *)win->hooks[KeyPress].hook;
	hook(XkbKeycodeToKeysym(xvar->display, ev->xkey.keycode, 0, 0),
		 win->hooks[KeyPress].param);
	return 0;
}

int mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(KeySym, void *) = (void *)win->hooks[KeyRelease].hook;
	hook(XkbKeycodeToKeysym(xvar->display, ev->xkey.keycode, 0, 0),
		 win->hooks[KeyRelease].param);
	return 0;
}

int mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(unsigned int, int, int, void *) = (void *)win->hooks[ButtonPress].hook;
	hook(ev->xbutton.button, ev->xbutton.x, ev->xbutton.y,
		win->hooks[ButtonPress].param);
	return 0;
}

int mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(unsigned int, int, int, void *) = (void *)win->hooks[ButtonRelease].hook;
	hook(ev->xbutton.button, ev->xbutton.x, ev->xbutton.y,
		win->hooks[ButtonRelease].param);
	return 0;
}

int mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(int, int, void *) = (void *)win->hooks[MotionNotify].hook;
	hook(ev->xbutton.x, ev->xbutton.y, win->hooks[MotionNotify].param);
	return 0;
}

int mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(void *) = (void *)win->hooks[Expose].hook;

	if (!ev->xexpose.count)
		hook(win->hooks[Expose].param);
	return 0;
}

int mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win)
{
	int (*hook)(void *) = (void *)win->hooks[ev->type].hook;
	hook(win->hooks[ev->type].param);
	return 0;
}

int (*(mlx_int_param_event[]))(t_xvar *xvar, XEvent *ev, t_win_list *win) = {
	mlx_int_param_undef,   /* 0 */
	mlx_int_param_undef,
	mlx_int_param_KeyPress,
	mlx_int_param_KeyRelease,  /* 3 */
	mlx_int_param_ButtonPress,
	mlx_int_param_ButtonRelease,
	mlx_int_param_MotionNotify,  /* 6 */
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_Expose,   /* 12 */
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic,
	mlx_int_param_generic
};
