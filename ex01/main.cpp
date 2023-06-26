/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:09:31 by amejia            #+#    #+#             */
/*   Updated: 2023/06/26 19:27:47 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void){
	ScavTrap	Itchy("Itchy");
	ClapTrap	Scratchy("Scratchy");

	Itchy.guardGate();	
	Itchy.attack("Scratchy");
	Scratchy.beRepaired(10);
}