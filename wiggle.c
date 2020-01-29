#include <stdlib.h>

#include <xdo.h>

int main() {
	const char *disp = getenv("DISPLAY");

	Display *dpy = XOpenDisplay(disp);
	if(!dpy)
		return 3;

	xdo_t *xdo = xdo_new_with_opened_display(dpy, disp, False);

	int dir = 1;

	while(1){
		xdo_move_mouse_relative(xdo, dir * 10, 0);
		XSync(xdo->xdpy, 0);

		dir = -dir;
		sleep(5);
	}

  xdo_free(xdo);
}
