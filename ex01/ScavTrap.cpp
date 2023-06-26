/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:41:02 by amejia            #+#    #+#             */
/*   Updated: 2023/06/26 23:48:11 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	set_ad();
	set_hp();
	set_ep();
	std::cout << "ScavTrap Deployed" << std::endl;
}


ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	std::cout << "ScavTrap Deployed" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destroyed" << std::endl;
}


void	ScavTrap::guardGate(){
	if (this ->_energyPoints > 0){
		this->_guardGate = 1;
		this->_energyPoints--;
		std::cout << this->_name << ": is guarding a gate" << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target){
	if (this->_hitPoints > 0 && this->_energyPoints  > 0){
		std::cout << this->_name << " makes an ammazing attack against " << 
			target << " for "	<<
			this->_attackDamage << " for points of damage" << std::endl;
		this->_energyPoints--;
		for(int i = 0; i < 100; i++){
			if (_created[i] != NULL && (*_created[i]).getName() == target)
				(*_created[i]).takeDamage(this->_attackDamage);
		}
	}		
}

void	ScavTrap::set_hp(){
	this->_hitPoints = 100;	
}

void	ScavTrap::set_ep(){
	this->_energyPoints = 50;
}

void	ScavTrap::set_ad(){
	this->_attackDamage = 20;	
}