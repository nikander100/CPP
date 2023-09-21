/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:06:25 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/21 18:59:17 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class AAnimal {
public:
	AAnimal();
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();
	// Assignment Operator
	AAnimal &operator = (const AAnimal &right);

	virtual void makeSound() const = 0;

	// Getters
	std::string getType() const;

protected:
	std::string type;
};

#endif
