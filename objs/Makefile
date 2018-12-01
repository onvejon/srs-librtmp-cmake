GCC = gcc
CXX = g++
AR = ar
LINK = g++
CXXFLAGS =  -ansi -Wall -g -O0 -fPIC

.PHONY: default srs srs_ingest_hls librtmp

default:

#####################################################################################
# the CORE module.
#####################################################################################

# INCS for CORE, headers of module and its depends to compile
CORE_MODULE_INCS = -Isrc/core 
CORE_INCS = -Isrc/core -Iobjs 

# DEPS for CORE, the depends of make schema
CORE_DEPS =  src/core/srs_core.hpp src/core/srs_core_autofree.hpp src/core/srs_core_performance.hpp src/core/srs_core_mem_watch.hpp

# OBJ for CORE, each object file
objs/src/core/srs_core.o: $(CORE_DEPS) src/core/srs_core.cpp 
	$(CXX) -c $(CXXFLAGS)  $(CORE_INCS)\
          -o objs/src/core/srs_core.o src/core/srs_core.cpp
objs/src/core/srs_core_autofree.o: $(CORE_DEPS) src/core/srs_core_autofree.cpp 
	$(CXX) -c $(CXXFLAGS)  $(CORE_INCS)\
          -o objs/src/core/srs_core_autofree.o src/core/srs_core_autofree.cpp
objs/src/core/srs_core_performance.o: $(CORE_DEPS) src/core/srs_core_performance.cpp 
	$(CXX) -c $(CXXFLAGS)  $(CORE_INCS)\
          -o objs/src/core/srs_core_performance.o src/core/srs_core_performance.cpp
objs/src/core/srs_core_mem_watch.o: $(CORE_DEPS) src/core/srs_core_mem_watch.cpp 
	$(CXX) -c $(CXXFLAGS)  $(CORE_INCS)\
          -o objs/src/core/srs_core_mem_watch.o src/core/srs_core_mem_watch.cpp

#####################################################################################
# the KERNEL module.
#####################################################################################

# INCS for KERNEL, headers of module and its depends to compile
KERNEL_MODULE_INCS = -Isrc/kernel 
KERNEL_INCS = -Isrc/kernel $(CORE_MODULE_INCS) -Iobjs 

# DEPS for KERNEL, the depends of make schema
KERNEL_DEPS =  src/kernel/srs_kernel_error.hpp src/kernel/srs_kernel_log.hpp src/kernel/srs_kernel_stream.hpp src/kernel/srs_kernel_utility.hpp src/kernel/srs_kernel_flv.hpp src/kernel/srs_kernel_codec.hpp src/kernel/srs_kernel_file.hpp src/kernel/srs_kernel_consts.hpp src/kernel/srs_kernel_aac.hpp src/kernel/srs_kernel_mp3.hpp src/kernel/srs_kernel_ts.hpp src/kernel/srs_kernel_buffer.hpp $(CORE_DEPS) 

# OBJ for KERNEL, each object file
objs/src/kernel/srs_kernel_error.o: $(KERNEL_DEPS) src/kernel/srs_kernel_error.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_error.o src/kernel/srs_kernel_error.cpp
objs/src/kernel/srs_kernel_log.o: $(KERNEL_DEPS) src/kernel/srs_kernel_log.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_log.o src/kernel/srs_kernel_log.cpp
objs/src/kernel/srs_kernel_stream.o: $(KERNEL_DEPS) src/kernel/srs_kernel_stream.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_stream.o src/kernel/srs_kernel_stream.cpp
objs/src/kernel/srs_kernel_utility.o: $(KERNEL_DEPS) src/kernel/srs_kernel_utility.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_utility.o src/kernel/srs_kernel_utility.cpp
objs/src/kernel/srs_kernel_flv.o: $(KERNEL_DEPS) src/kernel/srs_kernel_flv.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_flv.o src/kernel/srs_kernel_flv.cpp
objs/src/kernel/srs_kernel_codec.o: $(KERNEL_DEPS) src/kernel/srs_kernel_codec.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_codec.o src/kernel/srs_kernel_codec.cpp
objs/src/kernel/srs_kernel_file.o: $(KERNEL_DEPS) src/kernel/srs_kernel_file.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_file.o src/kernel/srs_kernel_file.cpp
objs/src/kernel/srs_kernel_consts.o: $(KERNEL_DEPS) src/kernel/srs_kernel_consts.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_consts.o src/kernel/srs_kernel_consts.cpp
objs/src/kernel/srs_kernel_aac.o: $(KERNEL_DEPS) src/kernel/srs_kernel_aac.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_aac.o src/kernel/srs_kernel_aac.cpp
objs/src/kernel/srs_kernel_mp3.o: $(KERNEL_DEPS) src/kernel/srs_kernel_mp3.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_mp3.o src/kernel/srs_kernel_mp3.cpp
objs/src/kernel/srs_kernel_ts.o: $(KERNEL_DEPS) src/kernel/srs_kernel_ts.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_ts.o src/kernel/srs_kernel_ts.cpp
objs/src/kernel/srs_kernel_buffer.o: $(KERNEL_DEPS) src/kernel/srs_kernel_buffer.cpp 
	$(CXX) -c $(CXXFLAGS)  $(KERNEL_INCS)\
          -o objs/src/kernel/srs_kernel_buffer.o src/kernel/srs_kernel_buffer.cpp

#####################################################################################
# the PROTOCOL module.
#####################################################################################

# INCS for PROTOCOL, headers of module and its depends to compile
PROTOCOL_MODULE_INCS = -Isrc/protocol 
PROTOCOL_INCS = -Isrc/protocol $(CORE_MODULE_INCS) $(KERNEL_MODULE_INCS) -Iobjs 

# DEPS for PROTOCOL, the depends of make schema
PROTOCOL_DEPS =  src/protocol/srs_rtmp_amf0.hpp src/protocol/srs_rtmp_io.hpp src/protocol/srs_rtmp_stack.hpp src/protocol/srs_rtmp_handshake.hpp src/protocol/srs_rtmp_utility.hpp src/protocol/srs_rtmp_msg_array.hpp src/protocol/srs_protocol_buffer.hpp src/protocol/srs_raw_avc.hpp src/protocol/srs_rtsp_stack.hpp src/protocol/srs_http_stack.hpp src/protocol/srs_protocol_kbps.hpp src/protocol/srs_protocol_json.hpp $(CORE_DEPS)  $(KERNEL_DEPS) 

# OBJ for PROTOCOL, each object file
objs/src/protocol/srs_rtmp_amf0.o: $(PROTOCOL_DEPS) src/protocol/srs_rtmp_amf0.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtmp_amf0.o src/protocol/srs_rtmp_amf0.cpp
objs/src/protocol/srs_rtmp_io.o: $(PROTOCOL_DEPS) src/protocol/srs_rtmp_io.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtmp_io.o src/protocol/srs_rtmp_io.cpp
objs/src/protocol/srs_rtmp_stack.o: $(PROTOCOL_DEPS) src/protocol/srs_rtmp_stack.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtmp_stack.o src/protocol/srs_rtmp_stack.cpp
objs/src/protocol/srs_rtmp_handshake.o: $(PROTOCOL_DEPS) src/protocol/srs_rtmp_handshake.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtmp_handshake.o src/protocol/srs_rtmp_handshake.cpp
objs/src/protocol/srs_rtmp_utility.o: $(PROTOCOL_DEPS) src/protocol/srs_rtmp_utility.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtmp_utility.o src/protocol/srs_rtmp_utility.cpp
objs/src/protocol/srs_rtmp_msg_array.o: $(PROTOCOL_DEPS) src/protocol/srs_rtmp_msg_array.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtmp_msg_array.o src/protocol/srs_rtmp_msg_array.cpp
objs/src/protocol/srs_protocol_buffer.o: $(PROTOCOL_DEPS) src/protocol/srs_protocol_buffer.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_protocol_buffer.o src/protocol/srs_protocol_buffer.cpp
objs/src/protocol/srs_raw_avc.o: $(PROTOCOL_DEPS) src/protocol/srs_raw_avc.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_raw_avc.o src/protocol/srs_raw_avc.cpp
objs/src/protocol/srs_rtsp_stack.o: $(PROTOCOL_DEPS) src/protocol/srs_rtsp_stack.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_rtsp_stack.o src/protocol/srs_rtsp_stack.cpp
objs/src/protocol/srs_http_stack.o: $(PROTOCOL_DEPS) src/protocol/srs_http_stack.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_http_stack.o src/protocol/srs_http_stack.cpp
objs/src/protocol/srs_protocol_kbps.o: $(PROTOCOL_DEPS) src/protocol/srs_protocol_kbps.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_protocol_kbps.o src/protocol/srs_protocol_kbps.cpp
objs/src/protocol/srs_protocol_json.o: $(PROTOCOL_DEPS) src/protocol/srs_protocol_json.cpp 
	$(CXX) -c $(CXXFLAGS)  $(PROTOCOL_INCS)\
          -o objs/src/protocol/srs_protocol_json.o src/protocol/srs_protocol_json.cpp

#####################################################################################
# the LIBS module.
#####################################################################################

# INCS for LIBS, headers of module and its depends to compile
LIBS_MODULE_INCS = -Isrc/libs 
LIBS_INCS = -Isrc/libs $(CORE_MODULE_INCS) $(KERNEL_MODULE_INCS) $(PROTOCOL_MODULE_INCS) -Iobjs 

# DEPS for LIBS, the depends of make schema
LIBS_DEPS =  src/libs/srs_librtmp.hpp src/libs/srs_lib_simple_socket.hpp src/libs/srs_lib_bandwidth.hpp $(CORE_DEPS)  $(KERNEL_DEPS)  $(PROTOCOL_DEPS) 

# OBJ for LIBS, each object file
objs/src/libs/srs_librtmp.o: $(LIBS_DEPS) src/libs/srs_librtmp.cpp 
	$(CXX) -c $(CXXFLAGS)  $(LIBS_INCS)\
          -o objs/src/libs/srs_librtmp.o src/libs/srs_librtmp.cpp
objs/src/libs/srs_lib_simple_socket.o: $(LIBS_DEPS) src/libs/srs_lib_simple_socket.cpp 
	$(CXX) -c $(CXXFLAGS)  $(LIBS_INCS)\
          -o objs/src/libs/srs_lib_simple_socket.o src/libs/srs_lib_simple_socket.cpp
objs/src/libs/srs_lib_bandwidth.o: $(LIBS_DEPS) src/libs/srs_lib_bandwidth.cpp 
	$(CXX) -c $(CXXFLAGS)  $(LIBS_INCS)\
          -o objs/src/libs/srs_lib_bandwidth.o src/libs/srs_lib_bandwidth.cpp


# archive library objs/lib/srs_librtmp.a
librtmp: objs/lib/srs_librtmp.a
objs/lib/srs_librtmp.a: objs/src/core/srs_core.o objs/src/core/srs_core_autofree.o objs/src/core/srs_core_performance.o objs/src/core/srs_core_mem_watch.o objs/src/kernel/srs_kernel_error.o objs/src/kernel/srs_kernel_log.o objs/src/kernel/srs_kernel_stream.o objs/src/kernel/srs_kernel_utility.o objs/src/kernel/srs_kernel_flv.o objs/src/kernel/srs_kernel_codec.o objs/src/kernel/srs_kernel_file.o objs/src/kernel/srs_kernel_consts.o objs/src/kernel/srs_kernel_aac.o objs/src/kernel/srs_kernel_mp3.o objs/src/kernel/srs_kernel_ts.o objs/src/kernel/srs_kernel_buffer.o objs/src/protocol/srs_rtmp_amf0.o objs/src/protocol/srs_rtmp_io.o objs/src/protocol/srs_rtmp_stack.o objs/src/protocol/srs_rtmp_handshake.o objs/src/protocol/srs_rtmp_utility.o objs/src/protocol/srs_rtmp_msg_array.o objs/src/protocol/srs_protocol_buffer.o objs/src/protocol/srs_raw_avc.o objs/src/protocol/srs_rtsp_stack.o objs/src/protocol/srs_http_stack.o objs/src/protocol/srs_protocol_kbps.o objs/src/protocol/srs_protocol_json.o objs/src/libs/srs_librtmp.o objs/src/libs/srs_lib_simple_socket.o objs/src/libs/srs_lib_bandwidth.o 
	@bash auto/generate_header.sh objs
	$(AR) -rs objs/lib/srs_librtmp.a objs/src/core/srs_core.o objs/src/core/srs_core_autofree.o objs/src/core/srs_core_performance.o objs/src/core/srs_core_mem_watch.o objs/src/kernel/srs_kernel_error.o objs/src/kernel/srs_kernel_log.o objs/src/kernel/srs_kernel_stream.o objs/src/kernel/srs_kernel_utility.o objs/src/kernel/srs_kernel_flv.o objs/src/kernel/srs_kernel_codec.o objs/src/kernel/srs_kernel_file.o objs/src/kernel/srs_kernel_consts.o objs/src/kernel/srs_kernel_aac.o objs/src/kernel/srs_kernel_mp3.o objs/src/kernel/srs_kernel_ts.o objs/src/kernel/srs_kernel_buffer.o objs/src/protocol/srs_rtmp_amf0.o objs/src/protocol/srs_rtmp_io.o objs/src/protocol/srs_rtmp_stack.o objs/src/protocol/srs_rtmp_handshake.o objs/src/protocol/srs_rtmp_utility.o objs/src/protocol/srs_rtmp_msg_array.o objs/src/protocol/srs_protocol_buffer.o objs/src/protocol/srs_raw_avc.o objs/src/protocol/srs_rtsp_stack.o objs/src/protocol/srs_http_stack.o objs/src/protocol/srs_protocol_kbps.o objs/src/protocol/srs_protocol_json.o objs/src/libs/srs_librtmp.o objs/src/libs/srs_lib_simple_socket.o objs/src/libs/srs_lib_bandwidth.o 
