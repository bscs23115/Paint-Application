#include"bscs23115_shape.h"

cv::Scalar shape::getclr()const
{
	return clr;
}
void shape::setthick(int t)
{
	thickness = t;
}
int shape::getthick() const
{
	return thickness;
}
void shape::setclr(cv::Scalar c)
{
	clr = c;
}
void shape::setstart(cv::Point s)
{
	start = s;
}
void shape::setend(cv::Point e)
{
	end = e;
}
cv::Point shape::getstart() const
{
	return start;
}
cv::Point shape::getend()const
{
	return end;
}


