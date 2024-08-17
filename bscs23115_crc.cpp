#include"bscs23115_crc.h"

int crc::count = 0;
void crc::draw(cv::Mat& wname)
{
	count++;
	int midofx = (getend().x + getstart().x) / 2;
	int midofy = (getend().y + getstart().y) / 2;
	int distancex = getend().x - midofx;
	int distancey = getend().y - midofy;
	int rad = sqrt((distancex * distancex) + (distancey * distancey));
	cv::circle(wname, cv::Point(midofx, midofy), rad, getclr(), getthick());
}
crc::crc(cv::Point a, cv::Point b, int t, cv::Scalar c)
{
	setstart(a);
	setend(b);
	setthick(t);
	setclr(c);
}

int crc::getcount()
{
	return count;
}
crc::~crc()
{
	count--;
}
