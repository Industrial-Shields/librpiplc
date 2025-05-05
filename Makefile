.PHONY: debs clean_debian

debs:
	dpkg-buildpackage --sign-key=5AD8FD2E2EF303FD7FAD59938356C65F95C75269 -j$$(nproc) -b
	lintian ../*.deb
	mv ../*.deb ../DebRepo
	mv ../*.changes ../DebRepo
	mv ../*.buildinfo ../DebRepo

clean_debian:
	rm -rf DEBIAN .debhelper build obj-arm-linux-gnueabihf debian/librpiplc/ debian/librpiplc-dev/ debian/librpiplc-tests-*/ debian/tmp/ debian/*debhelper* debian/*substvars* debian/files
