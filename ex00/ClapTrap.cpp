/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:52:22 by amejia            #+#    #+#             */
/*   Updated: 2023/06/26 19:15:50 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("hidden"), _hitPoints(10), _energyPoints(10), 
	_attackDamage(0){
	if (_NbClapTrap < 100)
		_created[_NbClapTrap] = this;
	_NbClapTrap++;
	std::cout << "ClapTrap Deployed" << std::endl;
}


ClapTrap::ClapTrap(std::string newname): _name(newname), _hitPoints(10), 
	_energyPoints(10), _attackDamage(0){
	if (_NbClapTrap < 100)
		_created[_NbClapTrap] = this;
	_NbClapTrap++;
	std::cout << "ClapTrap Deployed" << std::endl;
}

ClapTrap::~ClapTrap(){
	for(int i = 0; i < 100; i++){
		if (_created[i] == this)
			_created[i] = 0;
	}
	std::cout << "ClapTrap Destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other.getName()),
	_hitPoints(other.getHitPoints()), _energyPoints(other.getEnergyPoints()),
	_attackDamage(other.getAttackDamage()){
	if (_NbClapTrap < 100)
		_created[_NbClapTrap] = this;
	_NbClapTrap++;
	std::cout << "ClapTrap Copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	std::cout << "ClapTrap equalized" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target){
	if (this->_hitPoints > 0 && this->_energyPoints  > 0){
		std::cout << this->_name << " attacks " << target << " for "	<<
			this->_attackDamage << " points of damage" << std::endl;
		this->_energyPoints--;
		for(int i = 0; i < 100; i++){
			if (_created[i] != NULL && (*_created[i]).getName() == target)
				(*_created[i]).takeDamage(this->_attackDamage);
		}
	}		
}

void	ClapTrap::takeDamage(unsigned int amount){
	this->_hitPoints -= amount;
	std::cout << this->_name << " takes " << amount	<<
		" points of damage" << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints > 0 && this->_hitPoints > 0){
		std::cout << this->_name << " repairs itself for  " <<
			amount << " points of damage" << std::endl;
	}
}

std::string	ClapTrap::getName() const{
	return (this->_name);
}

int	ClapTrap::getHitPoints() const{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage() const{
	return (this->_attackDamage);
}

int	ClapTrap::_NbClapTrap = 0;
ClapTrap *ClapTrap::_created[100] = {nullptr};