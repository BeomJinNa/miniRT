#include "libft.h"
#include "stat.h"
#include "object.h"
#include "vector.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OBJECTS 4

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
	time_t	seed = time(NULL);
	srand(seed); // 랜덤 시드 초기화

	printf("seed : %ld\n", seed);
	t_list *obj_list = NULL;
	for (int i = 0; i < NUM_OBJECTS; ++i)
	{
		t_object *obj = malloc(sizeof(t_object));
		if (!obj)
		{
			ft_lstclear(&obj_list, NULL);
			return (NULL);
		}

		t_vector temp_pos;
		t_vector temp_normal;
		int obj_type = rand() % 4; // 0: sphere, 1: plane, 2: cylinder, 3: cone
		if (obj_type == 3)
			obj_type = 2;
		switch (obj_type)
		{
		case 0: // sphere
			random_vector(temp_pos);
			while (init_sphere(obj, temp_pos, rand() % (int)MAX_RADIUS))
				random_vector(temp_pos);
			break ;
		case 1: // plane
			random_vector(temp_pos);
			random_vector(temp_normal);
			while (init_plane(obj, temp_pos, temp_normal, rand() % (int)MAX_RADIUS))
			{
				random_vector(temp_pos);
				random_vector(temp_normal);
			}
			break ;
		case 2: // cylinder
			random_vector(temp_pos);
			random_vector(temp_normal);
			while (init_cylinder(obj, temp_pos, temp_normal, rand() % (int)MAX_RADIUS))
			{
				random_vector(temp_pos);
				random_vector(temp_normal);
			}
			break ;
		case 3: // cone
			random_vector(temp_pos);
			random_vector(temp_normal);
			while (init_cone(obj, temp_pos, temp_normal, rand() % (int)MAX_RADIUS))
			{
				random_vector(temp_pos);
				random_vector(temp_normal);
			}
			break ;
		}
		random_vector(temp_normal);
		if (temp_normal[0] < 0)
			temp_normal[0] = -temp_normal[0];
		if (temp_normal[1] < 0)
			temp_normal[1] = -temp_normal[1];
		if (temp_normal[2] < 0)
			temp_normal[2] = -temp_normal[2];
		vec_copy(obj->texture.reflectance, temp_normal);
		obj->texture.reflection_ratio = rand() % 1;


		ft_lstadd_back(&obj_list, ft_lstnew(obj));
	}

	return (obj_list);
}

t_list	*set_lights(void)
{
	t_list	*output;
	t_light	*node;

	output = NULL;
	node = (t_light *)malloc(sizeof(t_light));
	node->position[0] = 0;
	node->position[1] = 0;
	node->position[2] = 0;
	node->color[0] = 1;
	node->color[1] = 1;
	node->color[2] = 1;
	ft_lstadd_back(&output, ft_lstnew(node));
	return (output);
}

void	set_stat(t_stat *stat)
{
	stat->data.objects = create_random_objects();
	stat->data.lights = set_lights();
	stat->data.ambient[0] = 0.1;
	stat->data.ambient[1] = 0.1;
	stat->data.ambient[2] = 0.1;
	stat->data.cam.position[0] = 200.0f;
	stat->data.cam.position[1] = 0;
	stat->data.cam.position[2] = 0;
	stat->data.cam.normal_unit[0] = -1.0f;
	stat->data.cam.normal_unit[1] = 0;
	stat->data.cam.normal_unit[2] = 0;
	stat->data.cam.fov = 90.0f;
	stat->data.cam.image.size_height = 500;
	stat->data.cam.image.size_width = 800;
}
