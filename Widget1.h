#pragma once
#include "WidgetFamily.h"

class Widget1 : public WidgetFamily
{
public:
	Widget1(
		const int& partNumber,
		const int& id,
		const double& length,
		const double& width,
		const double& midLength,
		const double& height,
		const double& midHeight,
		const double& holeSize1,
		const double& holePosition1,
		const double& holeDepth1,
		const double& holeSize2,
		const double& holePosition2,
		const double& holeDepth2);
		//std::ostream& canvas);

	int getId() const override;
	int getPartNumber() const override;
	const double& getLength() const override;
	const double& getWidth() const override;
	const double& getMidLength() const override;
	const double& getHeight() const override;
	const double& getMidHeight() const override;
	const double& getHoleSize1() const override;
	const double& getHolePosition1() const override;
	const double& getHoleDepth1() const override;
	const double& getHoleSize2() const override;
	const double& getHolePosition2() const override;
	const double& getHoleDepth2() const override;
	//void draw() const override;

	//void stream(std::ostream& os) const override;

private:
	int id;
	int partNumber;
	double length;
	double width;
	double midLength;
	double height;
	double midHeight;
	double holeSize1;
	double holePosition1;
	double holeDepth1;
	double holeSize2;
	double holePosition2;
	double holeDepth2;
	//std::ostream* myCanvas;
};