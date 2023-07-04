#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
vector<double>input_numbers(size_t count){
    vector<double>dataS(count);
    cerr << "Enter all your numbers with \'_\' between:" << endl;
    for (size_t i = 0;i < count;i++) {
        cin >> dataS[i];
    }
    return dataS;
}
void find_minmax(const vector<double>&data, double &Min, double &Max){
    Min = Max = data[0];
    for (double x : data) {
        if (x < Min) Min = x;
        if (x > Max) Max = x;
    }
}
vector<int> make_histogram(size_t bins_quantity,const vector<double>&data){
    vector<int>bins(bins_quantity);
    double Min, Max;
    find_minmax(data,Min,Max);
    double bin_size = (Max - Min) / bins_quantity;

    for (size_t i = 0;i < data.size();i++) {
        bool flag = false;
        for (size_t j = 0; (j < bins_quantity - 1) && !flag;j++) {
            auto low = Min + j * bin_size;
            auto high = Min + (j + 1) * bin_size;
            if ((low <= data[i]) && (data[i] < high)) {
                bins[j]++;
                flag = true;
            }
        }

        if (!flag) {
            bins[bins_quantity - 1]++;
        }
    }
    return bins;
}

void show_histogram_text(const vector<int>& bins) {

    int mostAsterisk = 0;
    for (int i = 0,temp=0;i < bins.size();i++) {
        if (bins[i] > MAX_ASTERISK && bins[i]>temp)
            mostAsterisk = temp = bins[i];
    }

    for (int i = 0;i < bins.size();i++) {
        size_t asteriksCount = 0;
        if (bins[i] < 100) cout << ' ';
        if (bins[i] < 10) cout << ' ';
        cout << bins[i] << '|';
        if (mostAsterisk != 0){
            asteriksCount = MAX_ASTERISK * (static_cast<double>(bins[i]) / mostAsterisk);
            for (int j = 0;j < asteriksCount;j++) {
                if(i!=0 && bins[i]>bins[i-1] && (j==static_cast<size_t>(MAX_ASTERISK * (static_cast<double>(bins[i-1]) / mostAsterisk))-1)){
                    cout << '^';
                }
                else if(i!=bins.size()-1 && bins[i]>bins[i+1] && (j==static_cast<size_t>(MAX_ASTERISK * (static_cast<double>(bins[i+1]) / mostAsterisk))-1)){
                    cout << 'v';
                }
                else
                    cout << '*';
            }
            cout << endl;
        }
        else{
            asteriksCount = bins[i];
            for (int j = 0;j < asteriksCount;j++) {
                if(i!=0 && bins[i]>bins[i-1] && (j==bins[i-1]-1)){
                    cout << '^';
                }
                else if(i!=bins.size()-1 && bins[i]>bins[i+1] && (j==bins[i+1]-1)){
                    cout << 'v';
                }
                else
                    cout << '*';
            }
            cout << endl;
        }
    }
}

int main()
{
    size_t number_quantity;
    size_t bins_quantity;


    cerr << "Enter quantity of numbers = ";
    cin >> number_quantity;
    const auto data = input_numbers(number_quantity);

    cerr << "Enter quantity of bins = ";
    cin >> bins_quantity;
    const vector<int> bins = make_histogram(bins_quantity,data);
    show_histogram_text(bins);



}
