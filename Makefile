.PHONY: debs clean_debian

debs:
	dpkg-buildpackage -us -uc -j$$(nproc) -b
	lintian ../*.deb
	mv ../{*.deb,*.changes,*.buildinfo} ../DebRepo

clean_debian:
	rm -rf DEBIAN .debhelper build obj-arm-linux-gnueabihf debian/librpiplc/ debian/librpiplc-dev/ debian/librpiplc-tests-*/ debian/tmp/ debian/*debhelper* debian/*substvars* debian/files
