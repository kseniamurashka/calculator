#include "test.h"
#include <iostream>

double eps = 1.0e-7;

TEST_F(BinOperators, Test1)
{
	Calculator calc(add_str);
	double res1 = 9.578;
    EXPECT_DOUBLE_EQ(res1, calc.count_expr());
}
TEST_F(BinOperators, Test2)
{
	Calculator calc(subtr_str);
	double res1 = 2.6544;
	EXPECT_DOUBLE_EQ(res1, calc.count_expr());
}
TEST_F(BinOperators, Test3)
{
	Calculator calc(multipl_str);
	double res1 = 29.67;
	EXPECT_DOUBLE_EQ(res1, calc.count_expr());
}
TEST_F(BinOperators, Test4)
{
	Calculator calc4 (div_str);
	double res1 = 78 / 745.8;
	EXPECT_DOUBLE_EQ(res1, calc4.count_expr());
}


TEST_F(TrigonomFunctions, sin) {
	Calculator calc(sin_str1);
	double res1 = sin(123);
	EXPECT_NEAR(res1, calc.count_expr(), eps);
}
TEST_F(TrigonomFunctions, cos) {
	Calculator calc(cos_str1);
	double res1 = cos(123);
	EXPECT_NEAR(res1, calc.count_expr(), eps);
}
TEST_F(TrigonomFunctions, tg) {
	Calculator calc(tg_str1);
	double res1 = sin(123) / cos(123);
	EXPECT_NEAR(res1, calc.count_expr(), eps);
}
TEST_F(TrigonomFunctions, ctg) {
	Calculator calc(ctg_str1);
	double res1 = cos(123) / sin(123);
	EXPECT_NEAR(res1, calc.count_expr(), eps);
}

TEST_F(TrigonomFunctions, asin) {
	Calculator calc1(asin_str1);
	double res1 = asin(0.123);
	EXPECT_NEAR(res1, calc1.count_expr(), eps);

	try {
		Calculator calc2(asin_str2);
		double exc = calc2.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for asin: not in [-1, 1]"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for asin: not in [-1, 1])";
    }
}
TEST_F(TrigonomFunctions, acos) {
	Calculator calc1(acos_str1);
	double res1 = acos(0.123);
	EXPECT_NEAR(res1, calc1.count_expr(), eps);

	try {
		Calculator calc2(acos_str2);
		double exc = calc2.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for acos: not in [-1, 1]"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for acos: not in [-1, 1])";
    }
}
TEST_F(TrigonomFunctions, atg) {
	Calculator calc(atg_str);
	double res1 = atan(123);
	EXPECT_NEAR(res1, calc.count_expr(), eps);
}
TEST_F(TrigonomFunctions, actg) {
	Calculator calc(actg_str);
	double res1 =  M_PI/2 - atan(123);
	EXPECT_NEAR(res1, calc.count_expr(), eps);
}

TEST_F(LogFunctions, lnn) {
	Calculator calc1(lnn_str1);
	double res1 = log(123);
	EXPECT_NEAR(res1, calc1.count_expr(), eps);

	try {
		Calculator calc2(lnn_str2);
		double exc = calc2.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for lnn: less or equal 0"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for lnn: less or equal 0)";
    }
}
TEST_F(LogFunctions, log2n) {
	Calculator calc1(log2n_str1);
	double res1 = log2(123);
	EXPECT_NEAR(res1, calc1.count_expr(), eps);

	try {
		Calculator calc2(log2n_str2);
		double exc = calc2.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for log2n: less or equal 0"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for log2n: less or equal 0)";
    }
}
TEST_F(LogFunctions, lgn) {
	Calculator calc1(lgn_str1);
	double res1 = log10(123);
	EXPECT_NEAR(res1, calc1.count_expr(), eps);

	try {
		Calculator calc2(lgn_str2);
		double exc = calc2.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for lgn: less or equal 0"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for lgn: less or equal 0)";
    }
}

TEST_F(Degree, degree) {
	Calculator calc1(str1);
	Calculator calc2(str2);
	Calculator calc3(str3);
	Calculator calc4(str4);
	Calculator calc5(str5);

	double res1 = pow(12, 3);
	double res2 = pow(12.3, 4);
	double res3 = pow(2, 3.4);
	double res4 = pow(12, -3.4);
	double res5 = pow(-5, 3);
	
	EXPECT_NEAR(res1, calc1.count_expr(), eps);
	EXPECT_NEAR(res2, calc2.count_expr(), eps);
	EXPECT_NEAR(res3, calc3.count_expr(), eps);
	EXPECT_NEAR(res4, calc4.count_expr(), eps);
	EXPECT_NEAR(res5, calc5.count_expr(), eps);


	try {
		Calculator calc6(str6);
		double exc = calc6.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for operation '^': negative value in fractional degree"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for operation '^': negative value in fractional degree)";
    }

	Calculator calc7(str7);
	double res7_1 = -pow(2, 0.24);
	double res7_2 = calc7.count_expr();
	EXPECT_NEAR(res7_1, res7_2, eps);
}

TEST_F(Root, root) {
	Calculator calc1(str1);
	Calculator calc2(str2);
	Calculator calc3(str3);

	double res1 = pow(123, 1.0 / 4);
	double res2 = pow(123.4, 1.0 / 5);
	double res3 = -pow(123, 1.0 / 3);

	EXPECT_NEAR(res1, calc1.count_expr(), eps);
	EXPECT_NEAR(res2, calc2.count_expr(), eps);
	//EXPECT_NEAR(res3, calc3.count_expr(), eps);

	try {
		Calculator calc4(str4);
		double exc = calc4.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for root: negative root's degree"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for root: negative root's degree) in calculation\n";
    }

	try {
		Calculator calc5(str5);
		double exc = calc5.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid arguments for root: absolute root's degree for negative value"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid arguments for root: absolute root's degree for negative value)";
    }

	try {
		Calculator calc6(str6);
		double exc = calc6.count_expr();
		FAIL() << "Expected std::invalid_argument\n";
 	}
	catch (std::invalid_argument const & err) {
		EXPECT_EQ(err.what(), std::string("Invalid argument for root: fractional degree"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument(Invalid argument for root: fractional degree)";
    }
}


TEST_F(SeparatorsParenthesesTests, balanceOfSepAndParenth) {
	Calculator calc1(str1);
	Calculator calc2(str2);
	Calculator calc3(str3);
	Calculator calc4(str4);
	Calculator calc5(str5);

	double res1 = (1 + 2) * 3;
	double res2 = (1 + 2)*(3 + 4);
	double res3 = sin(1 + sqrt(8));
	double res4 = sin(12)*(1 + 2);
	double res5 = (1 + 7 * (2 + (5 + 6) * (7. / 8)));
	
	EXPECT_NEAR(res1, calc1.count_expr(), eps);
	EXPECT_NEAR(res2, calc2.count_expr(), eps);
	EXPECT_NEAR(res3, calc3.count_expr(), eps);
	EXPECT_NEAR(res4, calc4.count_expr(), eps);
	EXPECT_NEAR(res5, calc5.count_expr(), eps);

	for (int i = 0; i < exceptions.size(); i++) {
		try {
			std::string s = exceptions[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Skipped separator or parentheses mismatched"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Skipped separator or parentheses mismatched)";
    	}
	}
}

TEST_F(RepeatBinOp, minus) {
	Calculator calc(str1);
	int res = -(-5) - (-3 + 1);
	EXPECT_EQ(res, calc.count_expr());

	for (int i = 0; i < exceptions_minus.size(); i++) {
		try {
			std::string s = exceptions_minus[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Syntax error: double binary operator"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Syntax error: double binary operator)";
    	}
	}
}
TEST_F(RepeatBinOp, plus) {
	Calculator calc(str2);
	int res = -7;
	EXPECT_EQ(res, calc.count_expr());

	for (int i = 0; i < exceptions_plus.size(); i++) {
		try {
			std::string s = exceptions_plus[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Syntax error: double binary operator"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Syntax error: double binary operator)";
    	}
	}
}
TEST_F(RepeatBinOp, multiplication) {
	Calculator calc(str3);
	int res = -27;
	EXPECT_EQ(res, calc.count_expr());

	for (int i = 0; i < exceptions_mult.size(); i++) {
		try {
			std::string s = exceptions_mult[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Syntax error: double binary operator"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Syntax error: double binary operator)";
    	}
	}
}
TEST_F(RepeatBinOp, division) {
	Calculator calc(str4);
	int res = -5;
	EXPECT_EQ(res, calc.count_expr());

	for (int i = 0; i < exceptions_div.size(); i++) {
		try {
			std::string s = exceptions_div[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Syntax error: double binary operator"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Syntax error: double binary operator)";
    	}
	}
}
TEST_F(RepeatBinOp, other_combinations) {
	for (int i = 0; i < exceptions_other_combinations.size(); i++) {
		try {
			std::string s = exceptions_other_combinations[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Syntax error: double binary operator"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Syntax error: double binary operator)";
    	}
	}
}
TEST_F(NumberOfArguments, tests) {
	Calculator calc1(str1);
	Calculator calc2(str2);
	double res = -1;
	EXPECT_NEAR(res, calc1.count_expr(), eps);
	EXPECT_NEAR(res, calc2.count_expr(), eps);

	for (int i = 0; i < exceptions.size(); i++) {
		try {
			std::string s = exceptions[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Sytnax error in number of arguments"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Sytnax error in number of arguments)";
    	}
	}
}
TEST_F(UndefinedFunctions, tests) {
	for (int i = 0; i < exceptions.size(); i++) {
		try {
			std::string s = exceptions[i];
			Calculator calc(s);
			double exc = calc.count_expr();
			FAIL() << "Expected std::runtime_error in \"" << s << "\"" << endl;
 		}
		catch (std::runtime_error const & err) {
			EXPECT_EQ(err.what(), std::string("Undefined function name"));
    	}
    	catch(...) {
        	FAIL() << "Expected std::runtime_error(Undefined function name)";
    	}
	}
}
//EXPECT_DOUBLE_NIR_EQ
//EXPECT_ANY_THROW