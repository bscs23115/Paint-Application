#include"bscs23115_rec.h"

int rec::count = 0;
rec::rec(cv::Point s, cv::Point e, int t, cv::Scalar c)
{
	count++;
	setstart(s);
	setend(e);
	setthick(t);
	setclr(c);
}

void rec::draw(cv::Mat& wname)
{
	cv::rectangle(wname, getstart(), getend(), getclr(), getthick());
}
rec::~rec()
{
	count--;
}
int rec::getcount()
{
	return count;
}