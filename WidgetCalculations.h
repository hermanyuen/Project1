#pragma once
#include <vector>
#include "WidgetFamily.h"

class WidgetCalculations
{
public:
    WidgetCalculations() = default;
    WidgetCalculations(std::string fileName);

    //gets average of selected characteristic
    double getAverage(int selectIndex);

    // gets Standard deviation from selected characteristic
    double getSTD(int selectIndex);

    // get capability index Cp = (USL-LSL) / (6*STD)
    double getCp(int selectIndex);

    //Get Defectcount in list form
    std::array<int, 13> getDefectCount();

    //Get Pareto by characteristic index
    std::array<int, 13> paretoList();

    //Stream statistics in report format
    void streamReport(std::ostream& os);

    //Select header by column index
    std::string header(int selectedIndex) const;

    // insert the value at index. The array must expand to accommodate the new element. 
    void put(size_t index, WidgetFamily& value);

    // returns the element at index.
    WidgetFamily& get(size_t index) const;

    // removes the data at array the specified index. The array must contract.
    void remove(size_t index);

    WidgetFamily& operator[](size_t index);
    WidgetFamily operator[](size_t index) const;

    size_t getSize() const;
    void clear();

    void swap(WidgetCalculations& other) noexcept;
	//WidgetCalculations& 

private:
	//std::vector<WidgetFamily> widgetList;
    std::vector<std::shared_ptr<WidgetFamily>> widgetList;
};

