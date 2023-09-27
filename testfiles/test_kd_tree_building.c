#include "libft.h"
#include "object.h"
#include "tree.h"
#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OBJECTS 10

// 각 오브젝트의 속성 값 범위를 위한 임의의 상수
#define MAX_RADIUS 10.0
#define MAX_HEIGHT 10.0
#define MAX_POS 100.0

// 랜덤 벡터 생성 함수
void	random_vector(t_vector vec)
{
	vec[0] = (rand() % (int)(MAX_POS * 2)) - MAX_POS;
	vec[1] = (rand() % (int)(MAX_POS * 2)) - MAX_POS;
	vec[2] = (rand() % (int)(MAX_POS * 2)) - MAX_POS;
}

t_list	*create_random_objects()
{
	srand(time(NULL)); // 랜덤 시드 초기화

	t_list *obj_list = NULL;
	for (int i = 0; i < NUM_OBJECTS; ++i)
	{
		t_object *obj = malloc(sizeof(t_object));
		if (!obj)
		{
			clean_object_list(obj_list);
			return (NULL);
		}

		t_vector temp_pos;
		t_vector temp_normal;
		int obj_type = rand() % 4; // 0: sphere, 1: plane, 2: cylinder, 3: cone
		switch (obj_type)
		{
		case 0: // sphere
			random_vector(temp_pos);
			init_sphere(obj, temp_pos, rand() % (int)MAX_RADIUS);
			break ;
		case 1: // plane
			random_vector(temp_pos);
			random_vector(temp_normal);
			init_plane(obj, temp_pos, temp_normal, rand() % (int)MAX_RADIUS);
			break ;
		case 2: // cylinder
			random_vector(temp_pos);
			random_vector(temp_normal);
			init_cylinder(obj, temp_pos, temp_normal, rand() % (int)MAX_RADIUS);
			break ;
		case 3: // cone
			random_vector(temp_pos);
			random_vector(temp_normal);
			init_cone(obj, temp_pos, temp_normal, rand() % (int)MAX_RADIUS);
			break ;
		}

		ft_lstadd_back(&obj_list, ft_lstnew(obj));
	}

	return (obj_list);
}

int	main(void)
{

	t_list *obj_list = create_random_objects();
	if (!obj_list)
	{
		printf("Failed to create objects.\n");
		return (1);
	}

	printf("\n");
	printf("[OBJECT LIST]===================================================================\n");
	print_object_list(obj_list);

	t_tree *root = init_tree(obj_list);
	if (!root)
	{
		printf("Failed to initialize tree.\n");
		clean_object_list(obj_list);
		return (1);
	}

	printf("[Root Node]=====================================================================\n");
	print_tree(root);

	if (build_tree(root) != 0)
	{
		printf("Failed to build tree.\n");
		remove_tree(&root);
		return (1);
	}

	printf("[k-d tree]======================================================================\n");
	print_tree(root);
	printf("\n");

	remove_tree(&root);
	return (0);
}
