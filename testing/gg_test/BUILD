
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
		"//libs:calLib"]
	)