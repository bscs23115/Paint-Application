#include"bscs23115_ln.h"


int ln::count = 0;
ln::ln(cv::Point s, cv::Point e, int t, cv::Scalar c)
{
	count++;
	setstart(s);
	setend(e);
	setthick(t);
	setclr(c);
}
void ln::draw(cv::Mat& wname)
{
	cv::line(wname, getstart(), getend(), getclr(), getthick());
}
ln::~ln()
{
	count--;
}
int ln::getcount()
{
	return count;
}