// Copyright 2018 Kulikova Svetlana

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Test1, Addition) {
	// Arrange
	double re1 = 1.2;
	double im1 = 3.4;
	double re2 = 5.6;
	double im2 = 7.8;

	// Act
	ComplexNumber a(re1, im1);
	ComplexNumber b(re2, im2);
	ComplexNumber c = a + b;

	// Assert
	EXPECT_EQ(re1, a.getRe());
	EXPECT_EQ(im1, a.getIm());
	EXPECT_EQ(re2, b.getRe());
	EXPECT_EQ(im2, b.getIm());
	EXPECT_EQ(re1 + re2, c.getRe());
	EXPECT_EQ(im1 + im2, c.getIm());
}

TEST(Test2, Subtraction) {
	// Arrange
	double re1 = 1.2;
	double im1 = 3.4;
	double re2 = 5.6;
	double im2 = 7.8;

	// Act
	ComplexNumber a(re1, im1);
	ComplexNumber b(re2, im2);
	ComplexNumber c = a - b;

	// Assert
	EXPECT_EQ(re1, a.getRe());
	EXPECT_EQ(im1, a.getIm());
	EXPECT_EQ(re2, b.getRe());
	EXPECT_EQ(im2, b.getIm());
	EXPECT_EQ(re1 - re2, c.getRe());
	EXPECT_EQ(im1 - im2, c.getIm());
}

TEST(Test3, Multiplication) {
	// Arrange
	double re1 = 1.2;
	double im1 = 3.4;
	double re2 = 5.6;
	double im2 = 7.8;

	// Act
	ComplexNumber a(re1, im1);
	ComplexNumber b(re2, im2);
	ComplexNumber c = a * b;

	// Assert
	EXPECT_EQ(re1, a.getRe());
	EXPECT_EQ(im1, a.getIm());
	EXPECT_EQ(re2, b.getRe());
	EXPECT_EQ(im2, b.getIm());
	EXPECT_EQ(re1 * re2 - im1 * im2, c.getRe());
	EXPECT_EQ(re1 * im2 + re2 * im1, c.getIm());
}

TEST(Test4, Equality) {
	// Arrange
	double re = 1.2;
	double im = 3.4;

	// Act
	ComplexNumber a(re, im);
	ComplexNumber b(re, im);

	// Assert
	EXPECT_EQ(re, a.getRe());
	EXPECT_EQ(im, a.getIm());
	EXPECT_EQ(re, b.getRe());
	EXPECT_EQ(im, b.getIm());
	EXPECT_TRUE(a == b);
}

TEST(Test5, Division) {
	// Arrange
	double re1 = 1.2;
	double im1 = 3.4;
	double re2 = 5.6;
	double im2 = 7.8;
	double d = 1.0 / (re2 * re2 + im2 * im2);

	// Act
	ComplexNumber a(re1, im1);
	ComplexNumber b(re2, im2);
	ComplexNumber c = a / b;

	// Assert
	EXPECT_EQ(re1, a.getRe());
	EXPECT_EQ(im1, a.getIm());
	EXPECT_EQ(re2, b.getRe());
	EXPECT_EQ(im2, b.getIm());
	EXPECT_EQ((re1 * re2 - im1 * im2) * d, c.getRe());
	EXPECT_EQ((re1 * im2 + re2 * im1) * d, c.getIm());
}
