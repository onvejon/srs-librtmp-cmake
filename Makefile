.PHONY: default _default install install-api help clean server srs_ingest_hls librtmp utest _prepare_dir 

# install prefix.
SRS_PREFIX=/usr/local/srs
__REAL_INSTALL=$(DESTDIR)$(SRS_PREFIX)

default:
	$(MAKE) _default

_default: server srs_ingest_hls librtmp utest 
	@bash objs/_srs_build_summary.sh

help:
	@echo "Usage: make <help>|<clean>|<server>|<srs_ingest_hls>|<librtmp>|<utest>|<install>|<install-api>|<uninstall>"
	@echo "     help               display this help menu"
	@echo "     clean              cleanup project"
	@echo "     server             build the srs(simple rtmp server) over st(state-threads)"
	@echo "     srs_ingest_hls     build the hls ingest tool of srs."
	@echo "     librtmp            build the client publish/play library, and samples"
	@echo "     utest              build the utest for srs"
	@echo "     install            install srs to the prefix path"
	@echo "     install-api        install srs and api-server to the prefix path"
	@echo "     uninstall          uninstall srs from prefix path"
	@echo "@remark all modules will auto genearted and build"
	@echo "For example:"
	@echo "     make"
	@echo "     make help"

clean: 
	(cd objs && rm -rf srs srs_utest )
	(cd objs && rm -rf src include lib)
	(cd objs/utest && rm -rf *.o *.a)
	(cd research/librtmp && make clean)
	(cd research/api-server/static-dir && rm -rf crossdomain.xml forward live players)

server: _prepare_dir
	@echo "donot build the srs(simple rtmp server) for srs-librtmp"
srs_ingest_hls: _prepare_dir
	@echo "donot build the srs_ingest_hls for srs-librtmp"

uninstall: 
	@echo "disable uninstall for srs-librtmp"

install-api: 
	@echo "disable install-api for srs-librtmp"

install: 
	@echo "disable install for srs-librtmp"

librtmp: server
	@echo "build the client publish/play library."
	$(MAKE) -f objs/Makefile librtmp
	@echo "build the srs-librtmp sample"
	(cd research/librtmp; $(MAKE) nossl)

utest: server
	@echo "utest is disabled, ignore"

# the ./configure will generate it.
_prepare_dir:
	@mkdir -p objs
	@mkdir -p objs/src/core
	@mkdir -p objs/src/kernel
	@mkdir -p objs/src/protocol
	@mkdir -p objs/src/libs
	@mkdir -p objs/include
	@mkdir -p objs/lib
