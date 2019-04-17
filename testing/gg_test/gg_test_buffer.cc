#include "gtest/gtest.h"
#include "proto/modules/v2x/v2x.pb.h"

TEST(TEST_V2X_GGPROTOBUF, EXAMPLE1) {
	int v2x_status = 1;
	V2xStatus v2xObj;
	//set v2x status
	v2xObj.set_stt((::status)v2x_status);
	//get v2x status after updating
	int return_stt = v2xObj.stt();
	EXPECT_EQ(v2x_status, return_stt);
}
