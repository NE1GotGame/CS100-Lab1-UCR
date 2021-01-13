#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1,test_val));
}

//Test case 1
TEST(EchoTest, orderNumbers) {
	char* test_val[4]; 
	test_val[0] = "./c-echo";
	test_val[1] = "4";
	test_val[2] = "12";
	test_val[3] = "9";
	EXPECT_EQ("4 12 9", echo(4, test_val));
}

//Test case 2
TEST(EchoTest, BoomPowWow){
	char* test_val[3]; 
	test_val[0] = "./c-echo"; 
	test_val[1] = "boom"; 
	test_val[2] = "pow";
	test_val[3] = "wow";
	EXPECT_NE("boom pow wow", echo(4, test_val));
}

//Test case 3
TEST(EchoTest, SpecialChar){
        char* test_val[3];
        test_val[0] = "./c-echo";
        test_val[1] = "#%^";
        test_val[2] = "(!";
        EXPECT_NE("#%^ (!", echo(3, test_val));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
