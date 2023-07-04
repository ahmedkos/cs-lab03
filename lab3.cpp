#include "lab3.h"
void find_minmax(const vector<double>&data, double &Min, double &Max){
    if(data.size()==0) return;
    Min = Max = data[0];
    for (double x : data) {
        if (x < Min) Min = x;
        if (x > Max) Max = x;
    }
}
void svg_begin(){
    cout << "<?xml version='1.0' encoding='UTF-8' ?>\n" <<
    "<svg " << "width='" <<IMAGE_WIDTH <<"' height='"<<
    IMAGE_HEIGHT <<"' viewBox='0 0 "<<IMAGE_WIDTH <<' '<<
    IMAGE_HEIGHT << "' xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_end(){
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text){
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}
void svg_rect(double x, double y, double width, double height, string _fill){
    cout << "<rect x='"<<x<<"' y='"<< y<<"' width='"<<width<<"' height='"<<height<<"' fill='"<<_fill <<"' />";
}
void show_histogram_svg(const vector<int>&bins){
    svg_begin();
    double top =0;
    int i=0;
    vector<string>fill_color={"#17f3df","#5e2129","#102878"};
    for(auto bin : bins){
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT,top+TEXT_BASELINE,to_string(bin));
        svg_rect(TEXT_WIDTH,top,bin_width,BIN_HEIGHT,fill_color[i++]);
        top+=BIN_HEIGHT;
    }

    svg_end();
}
