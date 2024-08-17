
#include"bscs23115_arrowln.h"

int arrowln::count = 0;
arrowln::arrowln(cv::Point s, cv::Point e, int t, cv::Scalar c)
{
	count++;
	setstart(s);
	setend(e);
	setthick(t);
	setclr(c);
}
void arrowln::draw(cv::Mat& wname)
{
	cv::arrowedLine(wname, getstart(), getend(), getclr(), getthick());
}

int arrowln::getcount()
{
	return count;
}
arrowln::~arrowln()
{
	count--;
}
