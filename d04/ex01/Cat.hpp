/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 18:17:34 by nvan-der      #+#    #+#                 */
/*   Updated: 2024/02/21 17:11:28 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &copy);
	~Cat();
	// Assignment Operator
	Cat &operator = (const Cat &right);

	void makeSound() const;
	Brain *getBrain() const;

private:
	Brain *_brain;
};

#endif
