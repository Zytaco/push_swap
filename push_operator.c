
#include "checker.h"

/*
** action	inverse		i
** sa		sa			0
** sb		sb			1
** ss		ss			2
** pa		pb			3
** pb		pa			4
** ra		rra			5
** rb		rrb			6
** rr		rrr			7
** rra		ra			8
** rrb		rb			9
** rrr		rr			10
*/

void	do_operation(t_tack a, t_tack b, int i)
{
	if (i == 0)
		operate("sa", a, b);
	else if (i == 1)
		operate("sb", a, b);
	else if (i == 2)
		operate("ss", a, b);
	else if (i == 3)
		operate("pa", a, b);
	else if (i == 4)
		operate("pb", a, b);
	else if (i == 5)
		operate("ra", a, b);
	else if (i == 6)
		operate("rb", a, b);
	else if (i == 7)
		operate("rr", a, b);
	else if (i == 8)
		operate("rra", a, b);
	else if (i == 9)
		operate("rrb", a, b);
	else if (i == 10)
		operate("rrr", a, b);
}

void	undo_operation(t_tack a, t_tack b, int i)
{
	if (i == 0)
		operate("sa", a, b);
	else if (i == 1)
		operate("sb", a, b);
	else if (i == 2)
		operate("ss", a, b);
	else if (i == 3)
		operate("pb", a, b);
	else if (i == 4)
		operate("pa", a, b);
	else if (i == 5)
		operate("rra", a, b);
	else if (i == 6)
		operate("rrb", a, b);
	else if (i == 7)
		operate("rrr", a, b);
	else if (i == 8)
		operate("ra", a, b);
	else if (i == 9)
		operate("rb", a, b);
	else if (i == 10)
		operate("rr", a, b);
}
