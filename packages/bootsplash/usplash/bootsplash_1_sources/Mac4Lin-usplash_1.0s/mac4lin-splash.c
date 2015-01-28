#include <usplash-theme.h>
#include <usplash_backend.h>

/**********************************************************************************
 Usplash theme to provide a similar look to an OS X machine booting.  Best used with
 GTK and Icon themes of similar nature to get the look of the real deal.

 Thanks to all theme authors; especially usplash authors with custom animation for
 providing source as an example.
 
 Graphics taken from the Mac4Lin project
 Visit them at http://sourceforge.net/projects/mac4lin
 
 NOTE:  I am not responsible if you fry your computer attempting to use this boot
        theme, use at your own risk.
 
 Changelog:
 -----------------------------------------------------------------------------------
 0.1 - initial coding
 1.0 - fixed glitch in animation of spinner
 1.1 - changed location on screen of spinner to match real deal and repositioned
       text area to top of screen to accomodate new spinner location.  Included
       GPL license information
 
 ===================================================================================
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ==================================================================================
 
**********************************************************************************/

extern struct usplash_pixmap pixmap_macx_1024_768;
extern struct usplash_pixmap pixmap_macx_1280_1024;
extern struct usplash_pixmap pixmap_macx_1280_800;
extern struct usplash_pixmap pixmap_macx_1440_900;

extern struct usplash_pixmap pixmap_macx_spinner;
extern struct usplash_font font_helvB10;

void t_init(struct usplash_theme* theme);
void t_clear_progressbar(struct usplash_theme* theme);
void t_draw_progressbar(struct usplash_theme* theme, int percentage);
void t_animate_step(struct usplash_theme* theme, int pulsating);
void spinner(struct usplash_theme* theme);

struct usplash_theme usplash_theme;
struct usplash_theme usplash_theme_1280_1024;
struct usplash_theme usplash_theme_1280_800;
struct usplash_theme usplash_theme_1440_900;

static int spinner_x, spinner_y, spinner_part_width, spinner_height;
static int current_count = 0;
static int current_step = 0;
static int spinner_num_steps = 12;

// spinner_speed can be between 1 and 25
// there are 12 images in the spinner, so a value of 2 will make
// it spin around approx. once per second
static int spinner_speed = 2;

/** ----------------------------------------------------------------------- **/

struct usplash_theme usplash_theme = {
	.version = THEME_VERSION,
	.next = &usplash_theme_1280_1024,
	.ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_macx_1024_768,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x01,
	.progressbar_background = 0x00,
	.progressbar_foreground = 0x1E,
	.text_background        = 0x01,
	.text_foreground        = 0x01,
	.text_success           = 0x23,
	.text_failure           = 0x24,

	/* Text box position and size in pixels */
	.text_x      			= 300,
	.text_y      			= 650,
	.text_width  			= 680,
	.text_height 			= 300,

	/* Text details */
	.line_height  			= 15,
	.line_length  			= 32,
	.status_width 			= 50,

	/* Functions */
	.init = t_init,
	.clear_progressbar = t_clear_progressbar,
	.draw_progressbar = t_draw_progressbar,
	.animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1280_1024 = {
	.version = THEME_VERSION,
	.next = &usplash_theme_1280_800,
	.ratio = USPLASH_4_3,

	/* Background and font */
	.pixmap = &pixmap_macx_1280_1024,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x01,
	.progressbar_background = 0x00,
	.progressbar_foreground = 0x1E,
	.text_background        = 0x01,
	.text_foreground        = 0x01,
	.text_success           = 0x23,
	.text_failure           = 0x24,

	/* Text box position and size in pixels */
	.text_x      			= 300,
	.text_y      			= 650,
	.text_width  			= 680,
	.text_height 			= 300,

	/* Text details */
	.line_height  			= 15,
	.line_length  			= 32,
	.status_width 			= 50,

	/* Functions */
	.init = t_init,
	.clear_progressbar = t_clear_progressbar,
	.draw_progressbar = t_draw_progressbar,
	.animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1280_800 = {
	.version = THEME_VERSION,
	.next = &usplash_theme_1440_900,
	.ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_macx_1280_800,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x01,
	.progressbar_background = 0x00,
	.progressbar_foreground = 0x1E,
	.text_background        = 0x01,
	.text_foreground        = 0x01,
	.text_success           = 0x23,
	.text_failure           = 0x24,

	/* Text box position and size in pixels */
	.text_x      			= 300,
	.text_y      			= 650,
	.text_width  			= 680,
	.text_height 			= 300,

	/* Text details */
	.line_height  			= 15,
	.line_length  			= 32,
	.status_width 			= 50,

	/* Functions */
	.init = t_init,
	.clear_progressbar = t_clear_progressbar,
	.draw_progressbar = t_draw_progressbar,
	.animate_step = t_animate_step,
};

struct usplash_theme usplash_theme_1440_900 = {
	.version = THEME_VERSION,
	.next = NULL,
	.ratio = USPLASH_16_9,

	/* Background and font */
	.pixmap = &pixmap_macx_1440_900,
	.font   = &font_helvB10,

	/* Palette indexes */
	.background             = 0x01,
	.progressbar_background = 0x00,
	.progressbar_foreground = 0x1E,
	.text_background        = 0x01,
	.text_foreground        = 0x01,
	.text_success           = 0x23,
	.text_failure           = 0x24,

	/* Text box position and size in pixels */
	.text_x      			= 300,
	.text_y      			= 650,
	.text_width  			= 680,
	.text_height 			= 300,

	/* Text details */
	.line_height  			= 15,
	.line_length  			= 32,
	.status_width 			= 50,

	/* Functions */
	.init = t_init,
	.clear_progressbar = t_clear_progressbar,
	.draw_progressbar = t_draw_progressbar,
	.animate_step = t_animate_step,
};

/** ---------------------------------------------------------- **/

/* init usplash */
void t_init(struct usplash_theme *theme) {
	// determine spinner position and dimensions
	spinner_height = pixmap_macx_spinner.height;
	spinner_part_width = pixmap_macx_spinner.width / spinner_num_steps;
	spinner_x = (theme->pixmap->width / 2) - (spinner_part_width / 2);
	spinner_y = (theme->pixmap->height / 2) + ((theme->pixmap->height / 2) / 2) - (pixmap_macx_spinner.height / 2);
	
	// set text box dimensions and size
	theme->text_width = 600;
	theme->text_x = (theme->pixmap->width / 2) - (theme->text_width / 2);
	theme->text_y = 50;
	theme->text_height = 250;
	
	// set theme color indexes
	theme->background             = 0;
	theme->progressbar_background = 0;
	theme->progressbar_foreground = 30;
	theme->text_background        = 0;
	theme->text_foreground        = 1;
	theme->text_success           = 35;
	theme->text_failure           = 36;
}

/******
 * Animation callback - called 25 times per second by Usplash 
 * 
 * Param:	struct usplash_theme* theme	- theme being used 
 * 			int pulsating - boolean int
 */
void t_animate_step(struct usplash_theme* theme, int pulsating) {
	current_count = current_count + 1;
	
	// increase test int for slower spinning
	if(current_count == spinner_speed) {
		spinner(theme);
		current_count = 0;	
	}
}

/********
 * Animate the spinner
 *  helper function to aid in animation of spinner
 */
void spinner(struct usplash_theme* theme) {
	current_step = current_step + 1;
	
	int x0 = (spinner_part_width * current_step) - spinner_part_width;
	int y0 = 0;
	
	// if current step > number of images in the spinner, then reset to beginning (at end or circular spinner)
	if(current_step >= spinner_num_steps) {
		current_step = 0;
	}
	
	// call usplash_put_part for the small or large spinner image
	usplash_put_part(spinner_x, spinner_y, spinner_part_width, spinner_height, &pixmap_macx_spinner, x0, y0);
}

/** not used for now **/
void t_clear_progressbar(struct usplash_theme *theme) { }
void t_draw_progressbar(struct usplash_theme *theme, int percentage) { }
