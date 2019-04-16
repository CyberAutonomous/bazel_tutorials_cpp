cc_library(
	name = "calLib",
	srcs = ["libs/libCal.so"],
	hdrs = ["libs/calc.h"],
	)

cc_test(
	name = "gg_test_ex1",
	srcs = ["gg_test_ex1.cc"],
	copts = [
		"-Iexternal/google_test/googletest/include",
		"-Iexternal/google_test/googletest",
		"-Ilibs"
		],
	deps = [
		"@google_test//:google_test_lib",
		"calLib"]
	)