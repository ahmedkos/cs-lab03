#pragma once
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
void find_minmax(const vector<double>&data, double &Min, double &Max);
void svg_begin();
void svg_end();
void svg_rect(double x, double y, double width, double height, string _fill);
void svg_text(double left, double baseline, string text);
void show_histogram_svg(const vector<int>&bins);

