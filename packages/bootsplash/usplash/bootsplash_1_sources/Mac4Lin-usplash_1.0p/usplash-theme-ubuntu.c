/* Ubuntu Ultimate Usplash Maker
 *
# Copyright (c) 2007  Ubuntusoftware Team <http://ubuntusoftware.info>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <usplash-theme.h>
/* Needed for the custom drawing functions */
#include <usplash_backend.h>
extern struct usplash_pixmap pixmap_usplash_640_400, pixmap_usplash_640_480;
extern struct usplash_pixmap pixmap_usplash_800_600, pixmap_usplash_1024_768, pixmap_usplash_1280_1024;
extern struct usplash_pixmap pixmap_throbber_back_640_400;
extern struct usplash_pixmap pixmap_throbber_back_640_480;
extern struct usplash_pixmap pixmap_throbber_back_800_600;
extern struct usplash_pixmap pixmap_throbber_back_1024_768;
extern struct usplash_pixmap pixmap_throbber_back_1280_1024;
extern struct usplash_pixmap pixmap_throbber_fore_640_400;
extern struct usplash_pixmap pixmap_throbber_fore_640_480;
extern struct usplash_pixmap pixmap_throbber_fore_800_600;
extern struct usplash_pixmap pixmap_throbber_fore_1024_768;
extern struct usplash_pixmap pixmap_throbber_fore_1280_1024;
extern struct usplash_font font_helvB10;

void t_init(struct usplash_theme* theme);
void t_clear_progressbar_640_400(struct usplash_theme* theme);
void t_clear_progressbar_640_480(struct usplash_theme* theme);
void t_clear_progressbar_800_600(struct usplash_theme* theme);
void t_clear_progressbar_1024_768(struct usplash_theme* theme);
void t_clear_progressbar_1280_1024(struct usplash_theme* theme);
void t_draw_progressbar_640_400(struct usplash_theme* theme, int percentage);
void t_draw_progressbar_640_480(struct usplash_theme* theme, int percentage);
void t_draw_progressbar_800_600(struct usplash_theme* theme, int percentage);
void t_draw_progressbar_1024_768(struct usplash_theme* theme, int percentage);
void t_draw_progressbar_1280_1024(struct usplash_theme* theme, int percentage);
void t_animate_step_640_400(struct usplash_theme* theme, int pulsating);
void t_animate_step_640_480(struct usplash_theme* theme, int pulsating);
void t_animate_step_800_600(struct usplash_theme* theme, int pulsating);
void t_animate_step_1024_768(struct usplash_theme* theme, int pulsating);
void t_animate_step_1280_1024(struct usplash_theme* theme, int pulsating);


struct usplash_theme usplash_theme_640_480;
struct usplash_theme usplash_theme_800_600;
struct usplash_theme usplash_theme_1024_768;
struct usplash_theme usplash_theme_1280_1024;

struct usplash_theme usplash_theme = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_640_480,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_usplash_640_400,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x0,
  	.progressbar_background = 0x7,
  	.progressbar_foreground = 0x156,
	.text_background        = 0x15,
	.text_foreground        = 0x31,
	.text_success           = 0x171,
	.text_failure           = 0x156,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 212, /* 640/2-216/2 */
  	.progressbar_y      = 321,
  	.progressbar_width  = 216,
  	.progressbar_height = 8,

	/* Text box position and size in pixels */
  	.text_x      = 120,
  	.text_y      = 307,
  	.text_width  = 360,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_640_400,
    .draw_progressbar = t_draw_progressbar_640_400,
    .animate_step = t_animate_step_640_400,
};

struct usplash_theme usplash_theme_640_480 = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_800_600,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_usplash_640_480,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x0,
  	.progressbar_background = 0x7,
  	.progressbar_foreground = 0x156,
	.text_background        = 0x15,
	.text_foreground        = 0x31,
	.text_success           = 0x171,
	.text_failure           = 0x156,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 212, /* 640/2-216/2 */
  	.progressbar_y      = 291,
  	.progressbar_width  = 216,
  	.progressbar_height = 8,

	/* Text box position and size in pixels */
  	.text_x      = 160,
  	.text_y      = 312,
  	.text_width  = 320,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_640_480,
    .draw_progressbar = t_draw_progressbar_640_480,
    .animate_step = t_animate_step_640_480,
};

struct usplash_theme usplash_theme_800_600 = {
	.version = THEME_VERSION, /* ALWAYS set this to THEME_VERSION, 
                                 it's a compatibility check */
    .next = &usplash_theme_1024_768,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_usplash_800_600,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x0,
  	.progressbar_background = 0x7,
  	.progressbar_foreground = 0x156,
	.text_background        = 0x15,
	.text_foreground        = 0x31,
	.text_success           = 0x171,
	.text_failure           = 0x156,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 292, /* 800/2-216/2 */
  	.progressbar_y      = 370,
  	.progressbar_width  = 216,
  	.progressbar_height = 8,

	/* Text box position and size in pixels */
  	.text_x      = 225,
  	.text_y      = 407,
  	.text_width  = 360,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_800_600,
    .draw_progressbar = t_draw_progressbar_800_600,
    .animate_step = t_animate_step_800_600,
};

struct usplash_theme usplash_theme_1024_768 = {
	.version = THEME_VERSION,
    .next = &usplash_theme_1280_1024,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_usplash_1024_768,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x0,
  	.progressbar_background = 0x7,
  	.progressbar_foreground = 0x156,
	.text_background        = 0x15,
	.text_foreground        = 0x31,
	.text_success           = 0x171,
	.text_failure           = 0x156,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 404, /* 1024/2 - 216/2 */
  	.progressbar_y      = 475,
  	.progressbar_width  = 216,
  	.progressbar_height = 8,

	/* Text box position and size in pixels */
  	.text_x      = 322,
  	.text_y      = 525,
  	.text_width  = 380,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_1024_768,
    .draw_progressbar = t_draw_progressbar_1024_768,
    .animate_step = t_animate_step_1024_768,
};

/* Added 1280 X 1024 support*/

struct usplash_theme usplash_theme_1280_1024 = {
	.version = THEME_VERSION,
    .next = NULL,
    .ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_usplash_1280_1024,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x0,
  	.progressbar_background = 0x7,
  	.progressbar_foreground = 0x156,
	.text_background        = 0x15,
	.text_foreground        = 0x252, /*was 31*/
	.text_success           = 0x171,
	.text_failure           = 0x156,

	/* Progress bar position and size in pixels */
  	.progressbar_x      = 532, /* 1280/2 - 512/2 */
  	.progressbar_y      = 595,
  	.progressbar_width  = 525,
  	.progressbar_height = 8,

	/* Text box position and size in pixels */
  	.text_x      = 377,
  	.text_y      = 640,
  	.text_width  = 525,
  	.text_height = 100,

	/* Text details */
  	.line_height  = 15,
  	.line_length  = 32,
  	.status_width = 35,

    /* Functions */
    .init = t_init,
    .clear_progressbar = t_clear_progressbar_1280_1024,
    .draw_progressbar = t_draw_progressbar_1280_1024,
    .animate_step = t_animate_step_1280_1024,
};

void t_init(struct usplash_theme *theme) {
    int x, y;
    usplash_getdimensions(&x, &y);
    theme->progressbar_x = (x - theme->pixmap->width)/2 + theme->progressbar_x;
    theme->progressbar_y = (y - theme->pixmap->height)/2 + theme->progressbar_y;
}

void t_clear_progressbar_640_400(struct usplash_theme *theme) {
    t_draw_progressbar_640_400(theme, 0);
}

void t_clear_progressbar_640_480(struct usplash_theme *theme) {
    t_draw_progressbar_640_480(theme, 0);
}

void t_clear_progressbar_800_600(struct usplash_theme *theme) {
    t_draw_progressbar_800_600(theme, 0);
}

void t_clear_progressbar_1024_768(struct usplash_theme *theme) {
    t_draw_progressbar_1024_768(theme, 0);
}

void t_clear_progressbar_1280_1024(struct usplash_theme *theme) {
    t_draw_progressbar_1280_1024(theme, 0);
}

void t_draw_progressbar_640_400(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_640_400.width * percentage / 100);
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_640_400);
    if(percentage == 0)
        return;
    if(percentage < 0)
        usplash_put_part(theme->progressbar_x - w, theme->progressbar_y, pixmap_throbber_back_640_400.width + w,
                         pixmap_throbber_back_640_400.height, &pixmap_throbber_fore_640_400, -w, 0);
    else
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_640_400.height, 
                         &pixmap_throbber_fore_640_400, 0, 0);
}

void t_draw_progressbar_640_480(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_640_480.width * percentage / 100);
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_640_480);
    if(percentage == 0)
        return;
    if(percentage < 0)
        usplash_put_part(theme->progressbar_x - w, theme->progressbar_y, pixmap_throbber_back_640_480.width + w,
                         pixmap_throbber_back_640_480.height, &pixmap_throbber_fore_640_480, -w, 0);
    else
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_640_480.height, 
                         &pixmap_throbber_fore_640_480, 0, 0);
}

void t_draw_progressbar_800_600(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_800_600.width * percentage / 100);
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_800_600);
    if(percentage == 0)
        return;
    if(percentage < 0)
        usplash_put_part(theme->progressbar_x - w, theme->progressbar_y, pixmap_throbber_back_800_600.width + w,
                         pixmap_throbber_back_800_600.height, &pixmap_throbber_fore_800_600, -w, 0);
    else
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_800_600.height, 
                         &pixmap_throbber_fore_800_600, 0, 0);
}

void t_draw_progressbar_1024_768(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_1024_768.width * percentage / 100);
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_1024_768);
    if(percentage == 0)
        return;
    if(percentage < 0)
        usplash_put_part(theme->progressbar_x - w, theme->progressbar_y, pixmap_throbber_back_1024_768.width + w,
                         pixmap_throbber_back_1024_768.height, &pixmap_throbber_fore_1024_768, -w, 0);
    else
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_1024_768.height, 
                         &pixmap_throbber_fore_1024_768, 0, 0);
}

void t_draw_progressbar_1280_1024(struct usplash_theme *theme, int percentage) {
    int w = (pixmap_throbber_back_1280_1024.width * percentage / 100);
    usplash_put(theme->progressbar_x, theme->progressbar_y, &pixmap_throbber_back_1280_1024);
    if(percentage == 0)
        return;
    if(percentage < 0)
        usplash_put_part(theme->progressbar_x - w, theme->progressbar_y, pixmap_throbber_back_1280_1024.width + w,
                         pixmap_throbber_back_1280_1024.height, &pixmap_throbber_fore_1280_1024, -w, 0);
    else
        usplash_put_part(theme->progressbar_x, theme->progressbar_y, w, pixmap_throbber_back_1280_1024.height, 
                         &pixmap_throbber_fore_1024_768, 0, 0);
}

void t_animate_step_640_400(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 56;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    num_steps = (pixmap_throbber_fore_640_400.width - pulse_width)/2;

    if (pulsating) {
        t_draw_progressbar_640_400(theme, 0);
    
        if(pulsate_step < num_steps/2+1)
	        x1 = 2 * step_width * pulsate_step;
        else
	        x1 = pixmap_throbber_fore_640_400.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);

        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_fore_640_400.height, &pixmap_throbber_fore_640_400, x1, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

void t_animate_step_640_480(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 56;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    num_steps = (pixmap_throbber_fore_640_480.width - pulse_width)/2;

    if (pulsating) {
        t_draw_progressbar_640_480(theme, 0);
    
        if(pulsate_step < num_steps/2+1)
	        x1 = 2 * step_width * pulsate_step;
        else
	        x1 = pixmap_throbber_fore_640_480.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);

        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_fore_640_480.height, &pixmap_throbber_fore_640_480, x1, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

void t_animate_step_800_600(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 56;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    num_steps = (pixmap_throbber_fore_800_600.width - pulse_width)/2;

    if (pulsating) {
        t_draw_progressbar_800_600(theme, 0);
    
        if(pulsate_step < num_steps/2+1)
	        x1 = 2 * step_width * pulsate_step;
        else
	        x1 = pixmap_throbber_fore_800_600.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);

        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_fore_800_600.height, &pixmap_throbber_fore_800_600, x1, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

void t_animate_step_1024_768(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 56;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    num_steps = (pixmap_throbber_fore_1024_768.width - pulse_width)/2;

    if (pulsating) {
        t_draw_progressbar_1024_768(theme, 0);
    
        if(pulsate_step < num_steps/2+1)
	        x1 = 2 * step_width * pulsate_step;
        else
	        x1 = pixmap_throbber_fore_1024_768.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);

        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_fore_1024_768.height, &pixmap_throbber_fore_1024_768, x1, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}

void t_animate_step_1280_1024(struct usplash_theme* theme, int pulsating) {

    static int pulsate_step = 0;
    static int pulse_width = 56;
    static int step_width = 2;
    static int num_steps = 0;
    int x1;
    num_steps = (pixmap_throbber_fore_1280_1024.width - pulse_width)/2;

    if (pulsating) {
        t_draw_progressbar_1280_1024(theme, 0);
    
        if(pulsate_step < num_steps/2+1)
	        x1 = 2 * step_width * pulsate_step;
        else
	        x1 = pixmap_throbber_fore_1280_1024.width - pulse_width - 2 * step_width * (pulsate_step - num_steps/2+1);

        usplash_put_part(theme->progressbar_x + x1, theme->progressbar_y, pulse_width,
                         pixmap_throbber_fore_1280_1024.height, &pixmap_throbber_fore_1280_1024, x1, 0);

        pulsate_step = (pulsate_step + 1) % num_steps;
    }
}
