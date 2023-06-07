﻿// Implementations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CATCH.h"
#include <iostream>
#include "CATCH.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <vector>
using namespace std;

class FileData
{
public:
    FileData() {
    }

    double times[16];
    double r1[16][3];
    double r2[16][3];
    double v1[16][3];
    double v2[16][3];

    void ReadData(string fname = "LEMUR_COSMOS_CONST.csv") {
        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file(fname, ios::in);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
        else
            cout << "Could not open the file\n";

        for (int r = 0; r < 17; r++) {
            times[r] = stod(content.at(r).at(0));
        }

        for (int r = 0; r < 17; r++) {
            for (int c = 1; c <= 3; c++) {
                r1[c - 1][r] = stod(content.at(r).at(c));
            }
        }

        for (int r = 0; r < 17; r++) {
            for (int c = 4; c <= 6; c++) {
                v1[c - 4][r] = stod(content.at(r).at(c));
            }
        }

        for (int r = 0; r < 17; r++) {
            for (int c = 7; c <= 10; c++) {
                r2[c - 7][r] = stod(content.at(r).at(c));
            }
        }

        for (int r = 0; r < 17; r++) {
            for (int c = 11; c <= 13; c++) {
                v2[c - 11][r] = stod(content.at(r).at(c));
            }
        }
    }
};


int GetIndexInTime(double time)
{
    double times[16] = {
        0,
        30.69148012,
        121.4245555,
        268.2337554,
        464.7028134,
        702.2450887,
        970.4788441,
        1257.680977,
        1551.299377,
        1838.501511,
        2106.735266,
        2344.277541,
        2540.746599,
        2687.555799,
        2778.288875,
        2808.980355 };
    double diff = INFINITY;
    int index = 0;
    for (int j = 0; j < N; j++)
    {
        if (abs(times[j] - time) < diff)
        {
            index = j;
            diff = abs(times[j] - time);
        }
    }
    return index;
}
class TestFunctionR1 : public VectorFunction
{
public:
    TestFunctionR1()
    {

    }
    Vector3d getValue(int i)
    {
        Vector3d v;
        v(0) = r1[i][0];
        v(1) = r1[i][1];
        v(2) = r1[i][2];
        return v;
    }
    double r1[16][3] = {
        {2379.73995, -4993.028705, -4062.021947},
    {2284.921361, -4883.742595, -4245.360402},
    {1989.543878, -4528.046697, -4757.69855},
    {1470.341705 ,-3857.1909, -5482.311719},
    {717.2659872 ,-2803.381663, -6221.785721},
    {-235.0406312, -1357.57334, -6720.101964},
    {-1287.526485,	382.0215482, -6724.036202},
    {-2286.771015,	2203.381757, -6072.643775},
    {-3069.113854,	3834.197817, -4772.472173},
    {-3520.470075,	5037.686331, -3009.517298},
    {-3619.001533,	5700.581052, -1081.784709},
    {-3436.64092	,5864.376918,	711.7860125},
    {-3102.625615,	5688.719837,	2162.840182},
    {-2754.448727,	5377.86396,	3182.705808},
    {-2501.52031	,5112.688457,	3771.737699},
    {-2409.999309	,5010.927739,	3962.46579}
    };
};
class TestFunctionR2 : public VectorFunction
{
public:
    TestFunctionR2()
    {

    }
    Vector3d getValue(int i)
    {
        Vector3d v;
        v(0) = r2[i][0];
        v(1) = r2[i][1];
        v(2) = r2[i][2];
        return v;
    }
    double r2[16][3] = {
        {3947.797193, -5584.433021 ,-0.004451978},
    {3969.758675 ,-5564.136985,	232.3935712},
    {4007.327087 ,-5466.021466,	916.7862953},
    {3981.022309 ,-5189.142471,	2001.140901},
    {3779.3795 ,-4602.80553,	3363.176865},
    {3295.496468, -3603.019337,	4788.804399},
    {2475.168042 ,-2176.274178,	5991.72792},
    {1355.846735 ,-438.3931025,	6687.289931},
    {70.28903639,	1382.89453,	6694.951901},
    {-1195.345958,	3023.804555,	6013.389407},
    {-2270.065628,	4281.681059,	4821.079505},
    {-3055.932207,	5080.558855,	3401.97788},
    {-3546.28607	,5474.357177,	2042.981693},
    {-3802.519688	,5597.572917,	959.4590995},
    {-3910.099629	,5598.534456,	274.9766672},
    {-3937.430806	,5585.810221,	42.44686211}
    };
    double times[16] = {
        0,
        30.69148012,
        121.4245555,
        268.2337554,
        464.7028134,
        702.2450887,
        970.4788441,
        1257.680977,
        1551.299377,
        1838.501511,
        2106.735266,
        2344.277541,
        2540.746599,
        2687.555799,
        2778.288875,
        2808.980355 };
};
class TestFunctionV1 : public VectorFunction
{
public:
    TestFunctionV1()
    {

    }
    Vector3d getValue(int i)
    {
        Vector3d v;
        v(0) = v1[i][0];
        v(1) = v1[i][1];
        v(2) = v1[i][2];
        return v;
    }
private:
    double v1[16][3] = {
        {   -3.045023746,	3.467092898, -6.051761114},
    {-3.133214982,	3.653825705, -5.89425566},
    {-3.372180886,	4.17999468 ,-5.389518055},
    {-3.685294021,	4.938835165, -4.460221805},
    {-3.950433019,	5.746079406, -3.0377302},
    {-4.021184775,	6.356557082, -1.133557967},
    {-3.768356613,	6.518466435,	1.104931938},
    {-3.130777199,	6.057190852,	3.393741162},
    {-2.150105817,	4.951607911,	5.384807679},
    {-0.965316028,	3.356392587,	6.787687325},
    {0.236800668,	1.548277789,	7.478341946},
    {1.289887438 ,-0.17786661,	7.533638418},
    {2.096677915 ,-1.603251296,	7.177948677},
    {2.635887948 ,-2.622056426,	6.684436237},
    {2.934502969 ,-3.218071559,	6.288206794},
    {3.028809946 ,-3.412457111,	6.139281034}
    };
};
class TestFunctionV2 : public VectorFunction
{
public:
    TestFunctionV2()
    {

    }
    Vector3d getValue(int i)
    {
        Vector3d v;
        v(0) = v2[i][0];
        v(1) = v2[i][1];
        v(2) = v2[i][2];
        return v;
    }
private:
    double v2[16][3] = {
        {0.791299181,	0.554473015,	7.573554613},
    {0.639665043,	0.767986305,	7.569091168},
    {0.187742424,	1.392873573,	7.50380361},
    {-0.545231669,	2.370544106,	7.235317579},
    {-1.499038912,	3.574049345,	6.574163987},
    {-2.550911063,	4.794083544,	5.358770539},
    {-3.519726567,	5.764372812,	3.54381147},
    {-4.208233911,	6.234303389,	1.258736295},
    {-4.470258293,	6.060743806, -1.207147189},
    {-4.267888894,	5.268231786, -3.49895596},
    {-3.685360437,	4.040250338, -5.325158043},
    {-2.892207993,	2.646042971 ,-6.553113855},
    {-2.079218139,	1.346331943 ,-7.225461045},
    {-1.40356744	,0.328378816, -7.502277667},
    {-0.965726614, -0.307217335, -7.572553141},
    {-0.815122045, -0.521859856, -7.578662326}
    };
};

int main()
{


    CATCH c;
    TestFunctionR1 r1;
    TestFunctionR2 r2;
    TestFunctionV1 v1;
    TestFunctionV2 v2;
    double gamma = 2808.980355, tmax = 2808.980355;
    TCA tca = c.CatchAlgorithm(&r1, &r2, &v1, &v2, gamma, tmax);
    std::cout << "result:\nTime: " << tca.time << "\nDistance:" << tca.distance << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
