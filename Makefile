.PHONY: make_debs clean_debian

make_debs:
	dpkg-buildpackage -us -uc -j$$(nproc) -b && lintian ../*.deb

clean_debian:
	rm -rf DEBIAN .debhelper build obj-arm-linux-gnueabihf debian/librpiplc/ debian/librpiplc-dev/ debian/librpiplc-tests-*/ debian/tmp/ debian/*debhelper* debian/*substvars* debian/files
