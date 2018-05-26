// Copyright 2018 Kulikova Svetlana

#include "include/numerical_integration.h"
#include "include/numerical-integration-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

IntegralApp::IntegralApp() : message_("") {}

void IntegralApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a numerical integration application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <low> <up> <N> <Method>\n\n" +

          "Where <low> and <up> arguments are double-precision numbers, " +
          "and <N> should be in non-negative integer numbers, " +
          "and <Methods> is one of 'RiemannSumLeft', 'TrapezoidalRule', 'SimpsonRule', " +
          "'Simpson3_8Rule', 'BooleRule', 'NewtonCotes5', 'GaussianQuadrature'.\n";
}

bool IntegralApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 5) {
        Help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseInt(const char* arg) {
    char* end;
    int value = (int)strtol(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char* parseMethod(const char* arg) {
    if (strcmp(arg, "RiemannSumLeft") == 0) {
        return "RiemannSumLeft";
    } else if (strcmp(arg, "TrapezoidalRule") == 0) {
        return "TrapezoidalRule";
    } else if (strcmp(arg, "SimpsonRule") == 0) {
        return "SimpsonRule";
    } else if (strcmp(arg, "Simpson3_8Rule") == 0) {
        return "Simpson3_8Rule";
    } else if (strcmp(arg, "BooleRule") == 0) {
        return "BooleRule";
    } else if (strcmp(arg, "NewtonCotes5") == 0) {
        return "NewtonCotes5";
    } else if (strcmp(arg, "GaussianQuadrature") == 0) {
        return "GaussianQuadrature";
    } else {
        throw std::string("Wrong operation format!");
    }
}

std::string IntegralApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv))
        return message_;

    try {
        args.low    = parseDouble(argv[1]);
        args.up     = parseDouble(argv[2]);
        args.N      = parseInt(argv[3]);
        args.Method = parseMethod(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }
    
    Integral I;
    
    I.setLower(args.low);
    I.setUpper(args.up);
    I.setDevisions(args.N);
    
    double result;
    std::ostringstream stream;
    switch (args.Method) {
     case "RiemannSumLeft":
        result = I.RiemannSumLeft();
        stream << "result = " << result;
        break;
     case "TrapezoidalRule":
        result = I.TrapezoidalRule();
        stream << "result = " << result;
        break;
     case "SimpsonRule":
        result = I.SimpsonRule();
        stream << "result = " << result;
        break;
     case "Simpson3_8Rule":
        result = I.Simpson3_8Rule();
        stream << "result = " << result;
        break;
     case "BooleRule":
        result = I.BooleRule();
        stream << "result = " << result;
        break;
     case "NewtonCotes5":
        result = I.NewtonCotes5();
        stream << "result = " << result;
        break;
     case "GaussianQuadrature":
        result = I.GaussianQuadrature();
        stream << "result = " << result;
        break;
    }

    message_ = stream.str();

    return message_;
}
