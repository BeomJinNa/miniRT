#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "image.h"

// 패턴을 위한 도우미 함수들
t_pixel8	diagonal_pattern(int x, int y, int width, int height)
{
	int			  avg = (width + height) / 2;
	unsigned char value = (unsigned char)(((x + y) * 255) / (2 * avg));

	return (t_pixel8){255, value, value, 255 - value};
}

t_pixel8	circle_pattern(int x, int y, int width, int height)
{
	int			  centerX = width / 2;
	int			  centerY = height / 2;
	int			  distance = (int)sqrt((x - centerX) * (x - centerX) +
									   (y - centerY) * (y - centerY));
	unsigned char value =
		(unsigned char)((distance * 255) /
						(sqrt(centerX * centerX + centerY * centerY)));

	return (t_pixel8){255, value, 255 - value, value};
}

t_pixel8	stripe_pattern(int x, int y, int width, int height)
{
	int stripeWidth = 5;

	if ((x / stripeWidth) % 2 == 0)
		return (t_pixel8){255, 255, 0, 0};
	else
		return (t_pixel8){255, 0, 0, 255};
}

t_pixel8	simple_gradient_pattern(int x, int y, int width, int height)
{
	unsigned char value = (rand() % 2 == 0)
							  ? (unsigned char)((x * 255) / width)
							  : (unsigned char)((y * 255) / height);

	return (t_pixel8){255, value, value, value};
}

t_pixel8	simple_stripe_pattern(int x, int y, int width, int height)
{
	int stripeWidth = 5;

	if (rand() % 2 == 0)
	{
		if ((x / stripeWidth) % 2 == 0)
			return (t_pixel8){255, 255, 255, 255};
		else
			return (t_pixel8){255, 0, 0, 0};
	}
	else
		if ((y / stripeWidth) % 2 == 0)
			return (t_pixel8){255, 255, 255, 255};
		else
			return (t_pixel8){255, 0, 0, 0};
}

t_pixel8	generate_patterned_pixel(int x, int y, int width, int height,
								  int patternType)
{
	switch (patternType)
	{
	case 0:
		return diagonal_pattern(x, y, width, height);
	case 1:
		return circle_pattern(x, y, width, height);
	case 2:
		return stripe_pattern(x, y, width, height);
	case 3:
		return simple_gradient_pattern(x, y, width, height);
	case 4:
		return simple_stripe_pattern(x, y, width, height);
	default:
		return (t_pixel8){255, 255, 255, 255}; // 흰색
	}
}

// ANSI escape를 사용하여 픽셀 색상을 설정
void	set_pixel_color(t_pixel8 pixel)
{
	printf("\x1B[48;2;%d;%d;%dm", pixel.red, pixel.green, pixel.blue);
}

// ANSI escape를 사용하여 색상을 리셋
void	reset_color()
{
	printf("\x1B[0m");
}

// 이미지를 콘솔에 출력
void	print_image(t_image8 *image)
{
	for (int i = 0; i < image->size_height; i++)
	{
		for (int j = 0; j < image->size_width; j++)
		{
			t_pixel8 pixel = image->data[get_index(i, j, image)];
			set_pixel_color(pixel);
			printf("  "); // 각 픽셀에 대해 2개의 공백을 출력
		}
		reset_color();
		printf("\n");
	}
}

// ANSI escape 코드를 사용하여 텍스트 스타일과 색상을 설정하는 도우미 함수
void	set_text_style(int bold, int color)
{
	printf("\x1B[%d;3%dm", bold, color);
}

int	main()
{
	const int NUM_TESTS = 20;
	t_image8  sources[NUM_TESTS];
	t_image8  buffers[NUM_TESTS];

	// 난수 초기화
	srand(time(NULL));

	for (int t = 0; t < NUM_TESTS; t++)
	{
		int patternTypeForImage =
			rand() % 5; // 전체 이미지에 대한 패턴 한 번 선택

		// 원본 이미지 크기 랜덤 생성 (1~30 범위로 설정)
		sources[t].size_width = (rand() % 30) + 1;
		sources[t].size_height = (rand() % 30) + 1;
		sources[t].data = (t_pixel8 *)malloc(
			sizeof(t_pixel8) * sources[t].size_width * sources[t].size_height);

		// 원본 이미지 데이터 랜덤 생성
		for (int i = 0; i < sources[t].size_height; i++)
			for (int j = 0; j < sources[t].size_width; j++)
				sources[t].data[i * sources[t].size_width + j] =
					generate_patterned_pixel(j, i, sources[t].size_width,
											 sources[t].size_height,
											 patternTypeForImage);

		// 변경할 이미지 크기 랜덤 생성 (1~30 범위로 설정)
		buffers[t].size_width = (rand() % 30) + 1;
		buffers[t].size_height = (rand() % 30) + 1;
		buffers[t].data = (t_pixel8 *)malloc(
			sizeof(t_pixel8) * buffers[t].size_width * buffers[t].size_height);
	}

	for (int t = 0; t < NUM_TESTS; t++)
	{
		// 테스트 번호를 노란색, 굵은 글씨체로 출력
		set_text_style(1, 3); // 1은 굵은 텍스트, 3은 노란색
		printf("=============== Test %d ===============\n", t + 1);
		reset_color();

		set_text_style(1, 7); // 1은 굵은 텍스트, 7은 흰색
		printf("Original Image (%dx%d):\n", sources[t].size_width,
			   sources[t].size_height);
		reset_color();

		print_image(&sources[t]);

		resize_image8(&buffers[t], &sources[t]);

		set_text_style(1, 7); // 1은 굵은 텍스트, 7은 흰색
		printf("\nResized Image (%dx%d):\n", buffers[t].size_width,
			   buffers[t].size_height);
		reset_color();

		print_image(&buffers[t]);
		printf("\n\n");
	}

	for (int t = 0; t < NUM_TESTS; t++)
	{
		free(sources[t].data);
		free(buffers[t].data);
	}

	return (0);
}
