CC=gcc
CFLAGS=-g -Wall -fPIC
LDFLAGS=
INCLUDES=

COMPILE = $(CC) $(INCLUDES) $(CFLAGS)
LINK = $(CC) $(CFLAGS) $(LDFLAGS)

INSTALL = /usr/bin/install -c
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_PROGRAM = $(INSTALL) -m 755

usplash-theme-ubuntu.so: throbber_back_640_400.png.c.o throbber_back_640_480.png.c.o throbber_back_800_600.png.c.o  \
                         throbber_back_1024_768.png.c.o throbber_back_1280_1024.png.c.o \
			 throbber_fore_640_400.png.c.o throbber_fore_640_480.png.c.o throbber_fore_800_600.png.c.o  \
                         throbber_fore_1024_768.png.c.o throbber_fore_1280_1024.png.c.o \
                         usplash_640_400.png.c.o usplash_640_480.png.c.o usplash_800_600.png.c.o \
		         usplash_1024_768.png.c.o usplash_1280_1024.png.c.o \
			 usplash-theme-ubuntu.c.o

	$(COMPILE) -shared -o $@ $^

%.png.c: %.png
	pngtousplash $< > $@

%.bdf.c: %.bdf
	bdftousplash $< > $@

%.c.o: %.c
	$(COMPILE) -o $@ -c $<

install:
	$(INSTALL) -d $(DESTDIR)/usr/lib/usplash
	$(INSTALL_PROGRAM) usplash-theme-ubuntu.so $(DESTDIR)/usr/lib/usplash/usplash-theme-ubuntu.so
clean:
	rm -f *.png.c *.bdf.c *.c.o
