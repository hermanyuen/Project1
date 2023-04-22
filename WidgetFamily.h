#pragma once
#include <ostream>
class WidgetFamily
{
public:
    WidgetFamily() = default;

    virtual ~WidgetFamily() = default;
    virtual int getId() const = 0;
    virtual int getPartNumber() const = 0;
	virtual const double& getLength() const = 0;
	virtual const double& getWidth() const = 0;
	virtual const double& getMidLength() const = 0;
	virtual const double& getHeight() const = 0;
	virtual const double& getMidHeight() const = 0;
	virtual const double& getHoleSize1() const = 0;
	virtual const double& getHolePosition1() const = 0;
	virtual const double& getHoleDepth1() const = 0;
	virtual const double& getHoleSize2() const = 0;
	virtual const double& getHolePosition2() const = 0;
	virtual const double& getHoleDepth2() const = 0;
    //virtual WidgetFamily& operator=(const WidgetFamily& rhs) const = 0;
    //virtual void draw() const = 0;

    //virtual void draw() const = 0;

    //virtual void stream(std::ostream& os) const = 0;
};

