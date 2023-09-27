/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-der <nvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/22 18:59:25 by nvan-der      #+#    #+#                 */
/*   Updated: 2023/09/27 19:53:15 by nvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &right);
		void learnMateria(AMateria *);
		AMateria* createMateria(const std::string &type);
	
	private:
		AMateria *_materia[4];
};
