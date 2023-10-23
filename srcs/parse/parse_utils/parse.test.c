#include "parse_utils.h"
#include "vector.h"
#include <stdio.h>

void parser_tester_vector(const char *str, int expect_success, t_vector expect_val, int (parser)(const char *, t_vector))
{
	t_vector v;
	const int is_failed = parser(str, v);
	const char *result;

	if (expect_success && !is_failed && are_values_same(expect_val[0], v[0]) && are_values_same(expect_val[1], v[1]) && are_values_same(expect_val[2], v[2]))
		result = "ok.";
	else if (!expect_success && is_failed)
		result = "ok.";
	else
		result = "fail.";
	if (!is_failed)
		printf("%s\t [%s] parsed as {%f,%f,%f}\n", result, str, v[0], v[1], v[2]);
	else
		printf("%s\t [%s] not parsed\n", result, str);
}

void parser_tester_real(const char *str, int expect_success, t_real expect_val, int (parser)(const char *, t_real *))
{
	t_real real;
	const int is_failed = parser(str, &real);
	const char *result;

	if (expect_success && !is_failed && are_values_same(expect_val, real))
		result = "ok.";
	else if (!expect_success && is_failed)
		result = "ok.";
	else
		result = "fail.";
	if (!is_failed)
		printf("%s\t [%s] parsed as {%f}\n", result, str, real);
	else
		printf("%s\t [%s] not parsed\n", result, str);
}

void test_parse_real_number()
{
	printf("test : parse_real_number\n");
	parser_tester_real("12", 1, 12.0, parse_real_number);
	parser_tester_real("0.12", 1, 0.12, parse_real_number);
	parser_tester_real("12.12", 1, 12.12, parse_real_number);
	parser_tester_real("12.12.", 0, 0, parse_real_number);
	parser_tester_real(".12.12", 0, 0, parse_real_number);
	parser_tester_real("12..12", 0, 0, parse_real_number);
	parser_tester_real(".12", 0, 0, parse_real_number);
	parser_tester_real("12.", 0, 0, parse_real_number);
	parser_tester_real(".", 0, 0, parse_real_number);
	parser_tester_real("-12", 1, -12.0, parse_real_number);
	parser_tester_real("-0.12", 1, -0.12, parse_real_number);
	parser_tester_real("-12.12", 1, -12.12, parse_real_number);
	parser_tester_real("-12.12.", 0, 0, parse_real_number);
	parser_tester_real("-.12.12", 0, 0, parse_real_number);
	parser_tester_real("-12..12", 0, 0, parse_real_number);
	parser_tester_real("-.12", 0, 0, parse_real_number);
	parser_tester_real("-12.", 0, 0, parse_real_number);
	parser_tester_real("-.", 0, 0, parse_real_number);
}

void	test_parse_normal_vector()
{
	printf("test : parse_normalized_vector\n");
	parser_tester_vector("1,0,0", 1, (t_vector){1,0,0}, parse_normalized_vector);
	parser_tester_vector("1.0,0,0", 1, (t_vector){1,0,0}, parse_normalized_vector);
	parser_tester_vector("0,1,0", 1, (t_vector){0,1,0}, parse_normalized_vector);
	parser_tester_vector("0,1.0,0", 1, (t_vector){0,1,0}, parse_normalized_vector);
	parser_tester_vector("0,0,1", 1, (t_vector){0,0,1}, parse_normalized_vector);
	parser_tester_vector("0.333333,0.666666,0.666666", 1, (t_vector){0.333333,0.666666,0.666666}, parse_normalized_vector);
	parser_tester_vector("0,0,1.0", 1, (t_vector){0,0,1.0}, parse_normalized_vector);
	parser_tester_vector("1,2,3.3", 0, (t_vector){1,2,3.3}, parse_normalized_vector);
	parser_tester_vector("1,2.2,3", 0, (t_vector){1,2.2,3}, parse_normalized_vector);
	parser_tester_vector("1.1,2,3", 0, (t_vector){1.1,2,3}, parse_normalized_vector);
	parser_tester_vector(",1,2,3", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector("1,,2,3", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector("1,,3", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector(",,", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector(".,.,.", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector("1.,2.,3.", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector(".1,.2,.3", 0, (t_vector){1,2,3}, parse_normalized_vector);
	parser_tester_vector("1,.11.2,1.3", 0, (t_vector){1,2,3}, parse_normalized_vector);
}

void	test_parse_vector()
{
	printf("test : parse_vector\n");
	parser_tester_vector("1,2,3", 1, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector("1,2,3.3", 1, (t_vector){1,2,3.3}, parse_vector);
	parser_tester_vector("1,2.2,3", 1, (t_vector){1,2.2,3}, parse_vector);
	parser_tester_vector("1.1,2,3", 1, (t_vector){1.1,2,3}, parse_vector);
	parser_tester_vector("0.333333,0.666666,0.666666", 1, (t_vector){0.333333,0.666666,0.666666}, parse_vector);
	parser_tester_vector(",1,2,3", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector("1,,2,3", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector("1,,3", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector(",,", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector(".,.,.", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector("1.,2.,3.", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector(".1,.2,.3", 0, (t_vector){1,2,3}, parse_vector);
	parser_tester_vector("1,.11.2,1.3", 0, (t_vector){1,2,3}, parse_vector);
}

void	test_parse_rgb()
{
	printf("test : parse_rgb\n");
	parser_tester_vector("1,2,3", 1, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector("1,2,3.3", 1, (t_vector){1,2,3.3}, parse_rgb);
	parser_tester_vector("1,2.2,3", 1, (t_vector){1,2.2,3}, parse_rgb);
	parser_tester_vector("1.1,2,3", 1, (t_vector){1.1,2,3}, parse_rgb);
	parser_tester_vector("0.333333,0.666666,0.666666", 1, (t_vector){0.333333,0.666666,0.666666}, parse_rgb);
	parser_tester_vector(",1,2,3", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector("1,,2,3", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector("1,,3", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector(",,", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector(".,.,.", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector("1.,2.,3.", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector(".1,.2,.3", 0, (t_vector){1,2,3}, parse_rgb);
	parser_tester_vector("1,.11.2,1.3", 0, (t_vector){1,2,3}, parse_rgb);
}

void test_parse_degree()
{
	printf("test : parse_degree\n");
	parser_tester_real("0", 1, 0.0, parse_degree);
	parser_tester_real("0.0", 1, 0.0, parse_degree);
	parser_tester_real("180", 1, 180.0, parse_degree);
	parser_tester_real("180.0", 1, 180.0, parse_degree);
	parser_tester_real("-0.1", 0, 0, parse_degree);
	parser_tester_real("-1", 0, 0, parse_degree);
	parser_tester_real("-10", 0, 0, parse_degree);
	parser_tester_real("181", 0, 0, parse_degree);
	parser_tester_real("180.1", 0, 0, parse_degree);
	parser_tester_real("-180", 0, 0, parse_degree);
	parser_tester_real("-180.1", 0, 0, parse_degree);
	parser_tester_real("0a0", 0, 0, parse_degree);
}

void test_parse_ratio()
{
	printf("test : parse_ratio\n");
	parser_tester_real("0", 1, 0.0, parse_ratio);
	parser_tester_real("0.0", 1, 0.0, parse_ratio);
	parser_tester_real("1", 1, 1.0, parse_ratio);
	parser_tester_real("0.2", 1, 0.2, parse_ratio);
	parser_tester_real("1.0", 1, 1.0, parse_ratio);
	parser_tester_real("-0.1", 0, 0, parse_ratio);
	parser_tester_real("-1", 0, 0, parse_ratio);
	parser_tester_real("-10", 0, 0, parse_ratio);
	parser_tester_real("2", 0, 0, parse_ratio);
	parser_tester_real("1.1", 0, 0, parse_ratio);
	parser_tester_real("-180.1", 0, 0, parse_ratio);
	parser_tester_real("0a0", 0, 0, parse_ratio);
}

int main()
{
	test_parse_real_number();
	test_parse_vector();
	test_parse_degree();
	test_parse_ratio();
	test_parse_normal_vector();
	test_parse_rgb();
	test_parse_ratio();
	return (0);
}