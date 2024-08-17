#ifndef PAINT
#define PAINT
#include"bscs23115_allshapes.h"
class paint
{
private:
	int thickness{};
	cv::Scalar clr{};
	const ln topbrdr;
	const ln btmbrdr;
	vector<shape*> shapes{};
	char shp{};
	cv::Mat cnvs{};
	int cnvsh{};
	int cnvsw{};
	static void handleMouseEventWrapper(int event, int x, int y, int flags, void* param);
	void setcnvs(int = 500, int = 500);
	void handleMouseEvents(int event, int x, int y, int flags);
	int k{};
	void savecanvas();
	void clearcanvas();
public:
	paint(int = 1, int = 1, int = 1, cv::Scalar = cv::Scalar(0, 0, 0),
		const ln top = ln(cv::Point{ 0,10 }, cv::Point{ 500,10 }, 3, cv::Scalar(0, 0, 0)),
		const ln bt = ln(cv::Point{ 0,490 }, cv::Point{ 500,490 }, 3, cv::Scalar(0, 0, 0)));
	void run();
};
#endif PAINT