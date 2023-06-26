/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:33:51 by amejia            #+#    #+#             */
/*   Updated: 2023/06/26 23:46:01 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CPP
# define SCAVTRAP_CPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
protected:
	bool	_guardGate;
	void	set_hp();
	void	set_ep();
	void	set_ad();	
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator= (const ScavTrap &other);
	void 	guardGate();	
	void	attack(const std::string& target);
};

#endif