DESTDIR=
BINDIR=$(DESTDIR)/bin

all:
	echo "Nothing to be done for all"

install:
	install -d $(DESTDIR)/etc
	install -m 644 src/etc/password_tool.conf $(DESTDIR)/etc/password_tool.conf
	install -d $(BINDIR)
	install -m 755 src/bin/password_tool $(BINDIR)/password_tool

uninstall:
	rm $(DESTDIR)/etc/password_tool.conf
	rm $(BINDIR)/etc/password_tool
