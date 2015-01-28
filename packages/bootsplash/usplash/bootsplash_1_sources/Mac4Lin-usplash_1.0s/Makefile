CC=gcc
CFLAGS=-g -Wall -fPIC
LDFLAGS=
INCLUDES=
COMPILE = $(CC) $(INCLUDES) $(CFLAGS)
LINK = $(CC) $(CFLAGS) $(LDFLAGS)

macx-splash.so: macx_1024_768.png.c.o macx_1280_1024.png.c.o macx_1280_800.png.c.o macx_1440_900.png.c.o macx_spinner.png.c.o macx-splash.c.o helvB10.bdf.c.o
	$(COMPILE) -shared -o $@ $^

%.c.o: %.c
	$(COMPILE) -o $@ -c $<

%.png.c: %.png
	pngtousplash $< > $@

%.bdf.c: %.bdf
	bdftousplash $< > $@

clean:
	rm -f *.png.c *.bdf.c *.c.o *.so

install:
	cp macx-splash.so /usr/lib/usplash
	rm /etc/alternatives/usplash-artwork.so
	ln -s /usr/lib/usplash/macx-splash.so /etc/alternatives/usplash-artwork.so
	dpkg-reconfigure usplash
test:
	usplash -c
