#include"bscs23115_paint.h"

char ch;
bool dr;
void paint::clearcanvas()
{
	cnvs = cv::Mat(cnvsh, cnvsw, CV_8UC3, cv::Scalar(255, 255, 255));
	for (int i = 0; i < shapes.size(); i++)
		delete shapes[i];

	shapes.resize(0);
}
void paint::savecanvas()
{
	try
	{
		cv::imwrite("paint.png", cnvs);
	}
	catch (...)
	{
		cout << "UNABLE TO SAVE IMAGE";
		throw "rafay";
	}
}
paint::paint(int t, int h, int w, cv::Scalar cl, const ln tp, const ln btm) :thickness(t), clr(cl), topbrdr(tp), btmbrdr(btm)
{
	thickness = t;
	clr = cl;
	setcnvs(h, w);
	cnvs = cv::Mat(cnvsh, cnvsw, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::namedWindow("My Paint", cv::WINDOW_NORMAL);
	cv::setMouseCallback("My Paint", paint::handleMouseEventWrapper, this);
	shp = '2';
}
void paint::handleMouseEventWrapper(int event, int x, int y, int flags, void* param)
{
	paint* app = static_cast<paint*>(param);
	app->handleMouseEvents(event, x, y, flags);
}
void paint::handleMouseEvents(int event, int x, int y, int flags)
{
	if (event == cv::EVENT_LBUTTONDOWN)
	{
		cv::Point p(x, y);
		if (shp == 49)
			shapes.push_back(new ln(p, p, thickness, clr));
		else if (shp == 50)
			shapes.push_back(new freeln(p, p, thickness, clr));
		else if (shp == 51)
			shapes.push_back(new rec(p, p, thickness, clr));
		else if (shp == 52)
			shapes.push_back(new crc(p, p, thickness, clr));
		else if (shp == 53)
			shapes.push_back(new arrowln(p, p, thickness, clr));
		dr = true;
	}
	else if (event == cv::EVENT_RBUTTONDOWN)
	{

	}
	else if (event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_FLAG_LBUTTON))
	{
		shapes.back()->setend(cv::Point(x, y));
	}
	else if (event == cv::EVENT_MOUSEMOVE && (flags & cv::EVENT_FLAG_RBUTTON))
	{
	}
	else if (event == cv::EVENT_LBUTTONUP)
	{
		dr = false;
	}
	else if (event == cv::EVENT_RBUTTONUP)
	{
	}
}
void paint::setcnvs(int h, int w)
{
	cnvsh = h;
	cnvsw = w;
}
void paint::run()
{
	while (1)
	{
		try {
			cv::line(cnvs, topbrdr.getstart(), topbrdr.getend(), topbrdr.getclr(), topbrdr.getthick());
			cv::line(cnvs, btmbrdr.getstart(), btmbrdr.getend(), btmbrdr.getclr(), btmbrdr.getthick());
			if (dr)
			{
				cv::Mat temp = cnvs.clone();
				shapes.back()->draw(temp);
				imshow("My Paint", temp);
			}
			else
			{
				if (shapes.size() > 0)
					shapes.back()->draw(cnvs);
				imshow("My Paint", cnvs);
			}
			char n = cv::waitKey(1);

			if (n == 49 || n == 50 || n == 51 || n == 52 || n == 53)
				shp = n;
			if (n == 'r')
			{
				clr[2] -= 10;
				if (clr[2] <= 0)
					clr[2] = 0;

			}
			else if (n == 'R')
			{
				clr[2] += 10;
				if (clr[2] >= 255)
					clr[2] = 255;
			}
			else if (n == 'g')
			{
				clr[1] -= 10;
				if (clr[1] <= 0)
					clr[1] = 0;
			}
			else if (n == 'G')
			{

				clr[1] += 10;
				if (clr[1] >= 255)
					clr[1] = 255;
			}
			else if (n == 'b')
			{

				clr[0] -= 10;
				if (clr[0] <= 0)
					clr[0] = 0;
			}
			else if (n == 'B')
			{
				clr[0] += 10;
				if (clr[0] >= 255)
					clr[0] = 255;
			}
			else if (n == 't')
			{
				if (thickness > 1)
					thickness -= 1;
			}
			if (n == 'T')
			{
				if (thickness < 5)
					thickness += 1;
			}
			if (n == 's' || n == 'S')
			{
				try
				{
					savecanvas();
				}
				catch (...)
				{
					clearcanvas();
					n = 27;
				}
			}
			if (n == 'c' || n == 'C')
			{
				clearcanvas();
			}
			if (n == 27)
				break;
		}
		catch (...)
		{
			clearcanvas();
			break;
		}
	}
}