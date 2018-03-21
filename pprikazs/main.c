/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:09:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/21 15:17:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct stutu
{
	int aa;
	int bb;
};

struct unestruct
{
	int a;
	int b;
	struct stutu tutu;	
};

#include <stdio.h>

int main() {
	 	struct unestruct str1 = { 1, 2, { 25, 35 } };
	 	struct unestruct str2 = { 1, 2, { 35 } };

		(void)str1;
		(void)str2;
		printf("%d, %d, %d, %d\n", (str1.a), (str1.b), (str1.tutu.aa), (str1.tutu.bb));
		printf("%d, %d, %d, %d\n", (str2.a), (str2.b), (str2.tutu.aa), (str2.tutu.bb));


		return (0);
}
