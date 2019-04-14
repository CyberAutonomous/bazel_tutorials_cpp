cc_library(
	name = "calLib",
	srcs = ["libs/libCal.so"],
	hdrs = ["libs/calc.h"],
	)

cc_binary(
	name = "test_main",
	srcs = ["main.c"],
	copts = ["-Itest_l1/include",
			"-Ilibs"],
	deps = ["//test_l1:test1",
			"calLib"],
	)