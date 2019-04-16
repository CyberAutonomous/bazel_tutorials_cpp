cc_library(
	name = "google_test_lib",
	srcs = glob(["googletest/src/*.cc"],
		exclude = ["googletest/src/gtest-all.cc"]),
	hdrs = glob([
		"googletest/src/*.h",
		"googletest/include/**/*.h"
		]),
	copts = [
		"-Iexternal/google_test/googletest/include",
		"-Iexternal/google_test/googletest"
		],
	linkopts = ["-pthread"],
	visibility = ["//visibility:public"]
	)