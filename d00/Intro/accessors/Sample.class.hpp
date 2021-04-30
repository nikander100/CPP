#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class Sample
{
public:

	int	publicFoo;
	
	Sample(void); 
	~Sample(void);

	int		getFoo(void) const;
	void	setFoo(int v);

private:

	int		_foo;
};

#endif