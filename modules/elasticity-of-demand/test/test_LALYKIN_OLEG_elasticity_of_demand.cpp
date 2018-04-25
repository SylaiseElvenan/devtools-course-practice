// Copyright 2018 Lalykin Oleg

#include <gtest/gtest.h>

#include "include/elasticity-of-demand.h"

//TEST(Lalykin_Oleg_Elasticity_Of_Demand, constructor) 
//{
//   // Arrange
//   double Q1 = 4000.0;
//   double  Q2 = 2000.0;
//   double P1 = 4.0;
//   double  P2 = 5.0;
//   
//   // Act
//   Elasticity E;
//   
//   // Assert
//   EXPECT_EQ(E.GetQ1(), Q1);
//}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, get_coeff_method) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 2000.0;
    double P1 = 4.0;
    double  P2 = 5.0;

    // Act
    Elasticity E;
    E.PriceElasticity(Q1, Q2, P1, P2);
    // Assert
    EXPECT_EQ(E.GetCoeff(), 3);
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, calculate_coeff) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 2000.0;
    double P1 = 4.0;
    double  P2 = 5.0;

    // Act
    Elasticity E;
    
    // Assert
    EXPECT_EQ(3, E.PriceElasticity(Q1, Q2, P1, P2));
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, price_answer_is_elastic) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 2000.0;
    double P1 = 4.0;
    double  P2 = 5.0;

    // Act
    Elasticity E;
    E.PriceElasticity(Q1, Q2, P1, P2);
    E.PriceAnswer();
    // Assert
    EXPECT_EQ("demand is elastic", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, price_answer_is_inelastic) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 4000.0;
    double P1 = 6.0;
    double  P2 = 5.0;

    // Act
    Elasticity E;
    E.PriceElasticity(Q1, Q2, P1, P2);
    E.PriceAnswer();
    // Assert
    EXPECT_EQ("demand is inelastic", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, price_answer_is_unit) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 2000.0;
    double P1 = 4.0;
    double  P2 = 2.0;

    // Act
    Elasticity E;
    E.PriceElasticity(Q1, Q2, P1, P2);
    E.PriceAnswer();
    // Assert
    EXPECT_EQ("unit elasticity", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, income_answer_normal_goods) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 2000.0;
    double P1 = 4.0;
    double  P2 = 2.0;

    // Act
    Elasticity E;
    E.IncomeElasticity(Q1, Q2, P1, P2);
    E.IncomeAnswer();
    // Assert
    EXPECT_EQ("normal goods", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, income_answer_inferior_goods) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 2000.0;
    double P1 = 2.0;
    double  P2 = 4.0;

    // Act
    Elasticity E;
    E.IncomeElasticity(Q1, Q2, P1, P2);
    E.IncomeAnswer();
    // Assert
    EXPECT_EQ("inferior goods", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, Cross_answer_interchangeable_goods) {
    // Arrange
    double Q1 = 4000.0;
    double  Q2 = 6000.0;
    double P1 = 2.0;
    double  P2 = 4.0;

    // Act
    Elasticity E;
    E.CrossElasticity(Q1, Q2, P1, P2);
    E.CrossAnswer();
    // Assert
    EXPECT_EQ("goods are interchangeable", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, Cross_answer_mutually_complementary_goods) {
    // Arrange
    double Q1 = 1000.0;
    double  Q2 = 4000.0;
    double P1 = 2.0;
    double  P2 = 1.0;

    // Act
    Elasticity E;
    E.CrossElasticity(Q1, Q2, P1, P2);
    E.CrossAnswer();
    // Assert
    EXPECT_EQ("mutually complementary goods", E.GetAns());
}

TEST(Lalykin_Oleg_Elasticity_Of_Demand, Cross_answer_independent_of_each_other_goods) {
    // Arrange
    double Q1 = 2.0;
    double  Q2 = 2.0;
    double P1 = 2.0;
    double  P2 = 4.0;

    // Act
    Elasticity E;
    E.CrossElasticity(Q1, Q2, P1, P2);
    E.CrossAnswer();
    // Assert
    EXPECT_EQ("goods independent of each other", E.GetAns());
}
