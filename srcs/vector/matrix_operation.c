/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:05:56 by bena              #+#    #+#             */
/*   Updated: 2023/11/02 05:27:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_real	vec_product_mat_column(t_vector vec, t_matrix mat, int column)
{
	return (vec[0] * mat[0][column]
		+ vec[1] * mat[1][column]
		+ vec[2] * mat[2][column]);
}

void	mat_product(t_matrix buffer, t_matrix a, t_matrix b)
{
	int	row;
	int	column;

	row = 0;
	while (row < 3)
	{
		column = 0;
		while (column < 3)
		{
			buffer[row][column] = vec_product_mat_column(a[row], b, column);
			column++;
		}
		row++;
	}
}

void	mat_product_vector(t_vector buffer, t_matrix mat, t_vector vec)
{
	t_vector temp;

	temp[0] = vec_dot_product(mat[0], vec);
	temp[1] = vec_dot_product(mat[1], vec);
	temp[2] = vec_dot_product(mat[2], vec);
	vec_copy(buffer, temp);
}

void	set_rotation_matrix_phi(t_matrix buffer,
				t_real sinphi, t_real cosphi)
{
	buffer[0][0] = cosphi;
	buffer[0][1] = 0;
	buffer[0][2] = sinphi;
	buffer[1][0] = 0;
	buffer[1][1] = 1;
	buffer[1][2] = 0;
	buffer[2][0] = -sinphi;
	buffer[2][1] = 0;
	buffer[2][2] = cosphi;
}

void	set_rotation_matrix_theta(t_matrix buffer,
				t_real sintheta, t_real costheta)
{
	buffer[0][0] = costheta;
	buffer[0][1] = -sintheta;
	buffer[0][2] = 0;
	buffer[1][0] = sintheta;
	buffer[1][1] = costheta;
	buffer[1][2] = 0;
	buffer[2][0] = 0;
	buffer[2][1] = 0;
	buffer[2][2] = 1;
}
