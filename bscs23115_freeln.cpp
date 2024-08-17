#include"bscs23115_freeln.h"

int freeln::count = 0;
freeln::freeln(cv::Point s, cv::Point e, int t, cv::Scalar c)
{
	count++;
	setstart(s);
	setend(e);
	setthick(t);
	setclr(c);
}
void freeln::draw(cv::Mat& wname)
{
	mvc.push_back(getend());
	for (int i = 1; i < mvc.size(); i++)
	{
		cv::line(wname, mvc.at(i - 1), mvc.at(i), getclr(), getthick());
	}
}

int freeln::getcount()
{
	return count;
}
freeln::~freeln()
{
	count--;

}
