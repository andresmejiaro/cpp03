/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:23:10 by amejia            #+#    #+#             */
/*   Updated: 2023/06/25 23:27:02 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H	
# define CLAPTRAP_H
# include <iostream>

class ClapTrap{
protected:
	std::string			_name;
	unsigned int		_hitPoints;
	unsigned int		_energyPoints;
	int					_attackDamage;
	static int			_NbClapTrap;
	static	ClapTrap	*_created[100];					
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator= (const ClapTrap &other);
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName() const;
	int			getHitPoints() const;
	int			getEnergyPoints() const;
	int			getAttackDamage() const;
};

#endif