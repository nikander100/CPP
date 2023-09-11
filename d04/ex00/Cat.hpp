/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:17:34 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/11 18:26:23 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	// Assignment Operator
	Cat &operator = (const Cat &right);

	void makeSound() const;

private:
	// data

};

#endif
