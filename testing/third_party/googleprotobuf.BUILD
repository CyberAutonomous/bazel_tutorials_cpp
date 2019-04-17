cc_library(
	name = "proto_lib",
	srcs = glob(["src/**/*.cc"]),
	hdrs = glob(["src/**/*.h"]),
	copts = ["-Iexternal/com_google_protobuf/protobuf-cpp-3.7.1/src"],
	visibility = ["//visibility:public"]
	)

cc_binary(
	name = "protoc",
	srcs = glob(["src/google/protobuf/compiler/main.cc"]),
	copts = ["-Iexternal/com_google_protobuf/protobuf-cpp-3.7.1/src"],
	deps = ["proto_lib"],
	visibility = ["//visibility:public"]
	)