/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:20:04 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/03/28 19:13:14 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &copy);
	~Dog();
	// Assignment Operator
	Dog &operator = (const Dog &right);

	void makeSound() const;
	const Brain *getBrain() const;

private:
	Brain *_brain;
};

#endif
