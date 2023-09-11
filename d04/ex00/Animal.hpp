/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:06:25 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/11 18:25:43 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

class Animal {
public:
	Animal();
	Animal(const Animal &copy);
	~Animal();
	// Assignment Operator
	Animal &operator = (const Animal &right);

	void makeSound() const;

	// Getters
	std::string getType() const;

protected:
	std::string type;

private:
	// data

};

#endif
