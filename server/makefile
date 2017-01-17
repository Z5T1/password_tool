DESTDIR=
BINDIR=$(DESTDIR)/bin

all:
	cd src/password_generator; make

install:
	install -d $(BINDIR)
	install -m 755 src/password_generator/password_generator $(BINDIR)/password_generator

uninstall:
	rm $(BINDIR)/password_generator
