
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
		"//libs:calLib"
		]
	)

cc_test(
	name = "gg_test_protobuf_ex1",
	srcs = ["gg_test_buffer.cc"],
	copts = [
		"-Iexternal/google_test/googletest/include",
		"-Iexternal/google_test/googletest",
		"-Iexternal/com_google_protobuf/src"
	],
	deps = [
		"@google_test//:google_test_lib",
		"//proto/modules/v2x:v2x_proto"
	]
	)