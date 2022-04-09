SHELL = /bin/sh

INSTALL_DIR = ~/.config
NAME = xshbar

help:
	@echo "make install          Install xshbar."
	@echo "make uninstall        Remove xshbar."

install:
	mkdir -pv ${INSTALL_DIR}/xshbar
	mkdir -pv ${INSTALL_DIR}/xshbar/plugins.use
	cp -r * ${INSTALL_DIR}/xshbar
	chmod +x ${INSTALL_DIR}/xshbar/${NAME}
	chmod +x ${INSTALL_DIR}/xshbar/prn
	chmod +x ${INSTALL_DIR}/xshbar/config
	chmod +x ${INSTALL_DIR}/xshbar/plugins/*

uninstall:
	rm -r ${INSTALL_DIR}/${NAME}
