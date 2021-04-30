#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class Sample
{
public:
	
	Sample(); 
	~Sample();

	static int	getNbInst(); // nonmember func

private:

	static int	_nbInst; //nonmember attr
};

#endif