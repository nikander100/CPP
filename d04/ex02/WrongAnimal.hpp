/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 18:20:28 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/12 18:29:12 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();
	// Assignment Operator
	WrongAnimal &operator = (const WrongAnimal &right);

	void makeSound() const;

	// Getters
	std::string getType() const;

protected:
	std::string type;
};

#endif
