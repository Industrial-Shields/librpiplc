.PHONY: debs clean_debian

debs:
	./dpkg-buildpackage-arch.sh arm64
	./dpkg-buildpackage-arch.sh armhf
	lintian ../*.deb
	mv ../*.deb ../DebRepo
	mv ../*.changes ../DebRepo
	mv ../*.buildinfo ../DebRepo

clean_debian:
	$(MAKE) -f debian/rules clean
	rm -rf obj-aarch64-linux-gnu obj-arm-linux-gnueabihf build
