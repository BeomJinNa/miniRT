#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "object.h"

void test_vec_size() {
    t_vector test_vec = {3, 4, 0};
    assert(fabs(vec_size(test_vec) - 5.0) < 1e-6);
}

void test_vec_dot_product() {
    t_vector vec1 = {1, 2, 3};
    t_vector vec2 = {4, 5, 6};
    assert(fabs(vec_dot_product(vec1, vec2) - 32) < 1e-6);
}

void test_vec_add_scalar() {
    t_vector vec1 = {1, 2, 3};
    t_real scalar = 2;
    t_vector result;
    vec_add_scalar(result, vec1, scalar);
    assert(result[0] == 3 && result[1] == 4 && result[2] == 5);
}

// 다른 벡터 연산 테스트 함수들...

void test_init_sphere() {
    t_object obj;
    t_vector position = {1, 1, 1};
    t_real radius = 3;
    init_sphere(&obj, position, radius);
    assert(obj.type == M_OBJECT_TYPE_SPHERE);
    assert(obj.u_data.sphere.radius == 3);
    // ... 다른 속성들에 대한 assert ...
}

// 다른 init 함수들에 대한 테스트 ...

int main() {
    test_vec_size();
    test_vec_dot_product();
    test_vec_add_scalar();
    // ... 다른 벡터 연산 테스트 함수 호출 ...

    test_init_sphere();
    // ... 다른 init 함수 테스트 호출 ...

    printf("All tests passed!\n");
    return 0;
}
