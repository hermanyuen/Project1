#include "WidgetCalculations.h"
#include "Widget1.h"
#include "Widget2.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include <array>
#include <algorithm>

WidgetCalculations::WidgetCalculations(std::string fileName) {
    std::ifstream file(fileName);
    std::string line{};
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string substring{};
        std::vector<double> substrings{};
        //std::cout << line<<"\n";
        
        while (std::getline(iss, substring, ',')) {
            //std::cout << substring << "\n";
            substrings.push_back(stod(substring));
        }
        if ((int)substrings[1] == 1) {
            std::shared_ptr<Widget1> partObj(new Widget1((int)
                (substrings[0]), (int)substrings[1],
                substrings[2], substrings[3], substrings[4],
                substrings[5], substrings[6], substrings[7],
                substrings[8], substrings[9], substrings[10],
                substrings[11], substrings[12]));
                widgetList.push_back(partObj);
        }
        else {
            std::shared_ptr<Widget2> partObj(new Widget2((int)
                (substrings[0]), (int)substrings[1],
                substrings[2], substrings[3], substrings[4],
                substrings[5], substrings[6], substrings[7],
                substrings[8], substrings[9], substrings[10],
                substrings[11], substrings[12]));
                widgetList.push_back(partObj);
        }
        substrings.clear();
    }
}

double WidgetCalculations::getAverage(int selectIndex) {
    double total = 0;
    for (auto& widgets : widgetList) {
        /*partID = widgets.get()->getId();
        std::cout << partID << "\n";*/
        switch (selectIndex) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            total += widgets.get()->getLength();
            break;
        case 4:
            total += widgets.get()->getWidth();
            break;
        case 5:
            total += widgets.get()->getMidLength();
            break;
        case 6:
            total += widgets.get()->getHeight();
            break;
        case 7:
            total += widgets.get()->getMidHeight();
            break;
        case 8:
            total += widgets.get()->getHoleSize1();
            break;
        case 9:
            total += widgets.get()->getHolePosition1();
            break;
        case 10:
            total += widgets.get()->getHoleDepth1();
            break;
        case 11:
            total += widgets.get()->getHoleSize2();
            break;
        case 12:
            total += widgets.get()->getHolePosition2();
            break;
        case 13:
            total += widgets.get()->getHoleDepth2();
            break;
        }
    }
    return total/widgetList.size();
}

double WidgetCalculations::getSTD(int selectIndex) {
    double total = 0;
    double average = getAverage(selectIndex);
    for (auto& widgets : widgetList) {
        switch (selectIndex) {
        case 3:
            total += pow(widgets.get()->getLength() - average,2);
            break;
        case 4:
            total += pow(widgets.get()->getWidth() - average, 2);
            break;
        case 5:
            total += pow(widgets.get()->getMidLength() - average, 2);
            break;
        case 6:
            total += pow(widgets.get()->getHeight()- average, 2);
            break;
        case 7:
            total += pow(widgets.get()->getMidHeight() - average, 2);
            break;
        case 8:
            total += pow(widgets.get()->getHoleSize1() - average, 2);
            break;
        case 9:
            total += pow(widgets.get()->getHolePosition1() - average, 2);
            break;
        case 10:
            total += pow(widgets.get()->getHoleDepth1() - average, 2);
            break;
        case 11:
            total += pow(widgets.get()->getHoleSize2() - average, 2);
            break;
        case 12:
            total += pow(widgets.get()->getHolePosition2() - average, 2);
            break;
        case 13:
            total += pow(widgets.get()->getHoleDepth2() - average, 2);
            break;
        }
    }
    return sqrt(total / widgetList.size());
}

//I don't have a good way to record nominal numbers...
//I think I need to add const nominal numbers to each widget object
//and pull them back into this getCp function.
double WidgetCalculations::getCp(int selectIndex) {
    double std = getSTD(selectIndex);
    if (std == 0) {
        std = -1;
        //std::cout << "Standard deviation can not be 0" << "\n";
    }
    double xxTolerance = 0.05;
    double xxxTolerance = 0.100;
    double lsl{};// = nominal - 0.100;
    double usl{}; //= nominal + 0.100;
    
    switch (selectIndex) { //cutting corners by setting nominal values here

    case 3:
        lsl = 6 - xxxTolerance;
        usl = 6 + xxxTolerance;
        break;;
    case 4:
        lsl = 4 - xxxTolerance;
        usl = 4 + xxxTolerance;
        break;
    case 5:
        lsl = 4 - xxxTolerance;
        usl = 4 + xxxTolerance;
        break;
    case 6:
        lsl = 3 - xxxTolerance;
        usl = 3 + xxxTolerance;
        break;
    case 7:
        lsl = 1 - xxxTolerance;
        usl = 1 + xxxTolerance;
        break;
    case 8:
        lsl = 1 - xxxTolerance;
        usl = 1 + xxxTolerance;
        break;
    case 9:
        lsl = 1 - xxxTolerance;
        usl = 1 + xxxTolerance;
        break;
    case 10:
        lsl = 0.75 - xxTolerance;
        usl = 0.75 + xxTolerance;
        break;
    case 11:
        lsl = 1 - xxxTolerance;
        usl = 1 + xxxTolerance;
        break;
    case 12:
        lsl = 3 - xxxTolerance;
        usl = 3 + xxxTolerance;
        break;
    case 13:
        lsl = 0.75 - xxTolerance;
        usl = 0.75 + xxTolerance;
        break;
    }
    return (usl-lsl)/(6*std);
}
double WidgetCalculations::getDefectPercent(int selectIndex) {
    auto arr = getDefectCount();
    double percent = (arr[selectIndex] / static_cast<double>(getSize()))*100;
    return percent;
}
std::array<int,13> WidgetCalculations::getDefectCount() {
    std::array<int, 13> arr = {};
    for (auto& widgets : widgetList) {
        if (widgets.get()->getLength() > 6 + 0.100 || widgets.get()->getLength() < 6 - 0.100) {
            arr[2]++;
             }
        if (widgets.get()->getWidth() > 4 + 0.100 || widgets.get()->getWidth() < 4 - 0.100) {
            arr[3]++;
        }
        if (widgets.get()->getMidLength() > 4 + 0.100 || widgets.get()->getMidLength() < 4 - 0.100) {
            arr[4]++;
        }
        if (widgets.get()->getHeight() > 3 + 0.100 || widgets.get()->getHeight() < 3 - 0.100) {
            arr[5]++;
        }
        if (widgets.get()->getMidHeight() > 1 + 0.100 || widgets.get()->getMidHeight() < 1 - 0.100) {
            arr[6]++;
        }
        if (widgets.get()->getHoleSize1() > 1 + 0.100 || widgets.get()->getHoleSize1() < 1 - 0.100) {
            arr[7]++;
        }
        if (widgets.get()->getHolePosition1() > 1 + 0.100 || widgets.get()->getHolePosition1() < 1 - 0.100) {
            arr[8]++;
        }
        if (widgets.get()->getHoleDepth1() > 0.75 + 0.05 || widgets.get()->getHoleDepth1() < 0.75 - 0.05) {
            arr[9]++;
        }
        if (widgets.get()->getHoleSize2() > 1 + 0.100 || widgets.get()->getHoleSize2() < 1 - 0.100) {
            arr[10]++;
        }
        if (widgets.get()->getHolePosition2() > 3 + 0.100 || widgets.get()->getHolePosition2() < 3 - 0.100) {
            arr[11]++;
        }
        if (widgets.get()->getHoleDepth2() > 0.75 + 0.05 || widgets.get()->getHoleDepth2() < 0.75 - 0.05) {
            arr[12]++;
        }
        
    }
    return arr;
}
//Process: Sorting method by defect count
//output: defect count by array index
//source: https://www.geeksforgeeks.org/keep-track-of-previous-indexes-after-sorting-a-vector-in-c-stl/
std::array<int, 13> WidgetCalculations::paretoList() {
    auto arr = getDefectCount();
    std::array<int, 13> arr2 = {};
    std::vector<std::pair<int, int> > vp;
    for (int i = 0; i < getDefectCount().size(); ++i) {
        vp.push_back(std::make_pair(arr[i], i));
    }

    // Sorting pair vector
    sort(vp.begin(), vp.end());

    // Displaying sorted element
    // with previous indexes
    // corresponding to each element
    int vpSize = vp.size();
    for (int i = 0; i < vpSize; i++) {
        arr2[i] = vp[vpSize-1-i].second;
            //vp[i].first
    }
    return arr2;
}

void WidgetCalculations::streamReport(std::ostream& os) {
    auto arr = getDefectCount();
    os << "WIDGET DATA ANALYSIS" << "\n";
    os << "Header: ";
    for (int i = 0; i < paretoList().size(); ++i) {
        os << header(i) << ", ";
    }
    os << "\n\n" << "Defect Count for each Characteristic: ";
    for (int defectCount : arr) {
        os << defectCount << ", ";
    }
    os << "\n" << "Pareto by Defect (value: characteristic index): ";
    for (int defectIndex : paretoList()) {
        os << defectIndex << ", ";
    }
    os << "\n\n" << "Details on top Defect: Column" << paretoList()[0] << ": "
        << header(paretoList()[0])<< "\n";
    os << "Average Value: " << getAverage(paretoList()[0]) << "\n";
    os << "Standard Deviation: " << getSTD(paretoList()[0]) << "\n";
    os << "Cp (Capability Index): " << getCp(paretoList()[0]) << "\n";
    os << "Defect Percentage: " << getDefectPercent(paretoList()[0]) << "%\n";
    os << "\n\n";
}

std::string WidgetCalculations::header(int selectedIndex) const{
    std::string headerTitle;
    switch (++selectedIndex) {
    case 1:
        headerTitle = "partNumber";
        break;
    case 2:
        headerTitle = "id";
        break;
    case 3:
        headerTitle = "length";
        break;
    case 4:
        headerTitle = "width";
        break;
    case 5:
        headerTitle = "midLength";
        break;
    case 6:
        headerTitle = "height";
        break;
    case 7:
        headerTitle = "midHeight";
        break;
    case 8:
        headerTitle = "holeSize1";
        break;
    case 9:
        headerTitle = "holePosition1";
        break;
    case 10:
        headerTitle = "holeDepth1";
        break;
    case 11:
        headerTitle = "holeSize2";
        break;
    case 12:
        headerTitle = "holePosition2";
        break;
    case 13:
        headerTitle = "holeDepth2";
        break;
    }
    return headerTitle;
}

void WidgetCalculations::swap(WidgetCalculations& other) noexcept
{
    widgetList.swap(other.widgetList);
}

// insert the value at index. The array must expand to accommodate the new element. 
void WidgetCalculations::put(size_t index, WidgetFamily& value)
{
    if (widgetList.size() <= index)
    {
        widgetList.resize(index + 1);
    }

    *widgetList[index] = value;
}

// returns the element at index.
WidgetFamily& WidgetCalculations::get(size_t index) const
{
    return *widgetList[index];
}

// removes the data at array the specified index. The array must contract.
void WidgetCalculations::remove(size_t index)
{
    if (widgetList.empty())
    {
        return;
    }

    for (auto i = index; i < widgetList.size() - 1; ++i)
    {
        widgetList[i] = widgetList[i + 1];
    }

    widgetList.resize(widgetList.size() - 1);
}

WidgetFamily& WidgetCalculations::operator[](size_t index)
{
    return *widgetList[index];
}

//WidgetFamily WidgetCalculations::operator[](size_t index) const
//{
//    return *widgetList[index];
//}

size_t WidgetCalculations::getSize() const
{
    return widgetList.size();
}

void WidgetCalculations::clear()
{
    widgetList.clear();
}