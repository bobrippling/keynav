#include <stdlib.h>
#include <time.h>

#include <xdo.h>

static void move(xdo_t *xdo, int x, int y) {
		xdo_move_mouse_relative(xdo, x, y);
		XSync(xdo->xdpy, 0);
}

int main() {
	const char *disp = getenv("DISPLAY");

	Display *dpy = XOpenDisplay(disp);
	if(!dpy)
		return 3;

	xdo_t *xdo = xdo_new_with_opened_display(dpy, disp, False);
	const struct timespec delay = {
		.tv_nsec = 1000000 * 50, // 50ms
	};

	while(1){
		move(xdo, 10, 0);

		struct timespec delay2 = delay;
		nanosleep(&delay2, NULL);

		move(xdo, -10, 0);

		sleep(5);
	}

	xdo_free(xdo);
}
