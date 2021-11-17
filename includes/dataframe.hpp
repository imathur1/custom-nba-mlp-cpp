#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class DataFrame {
public:
    DataFrame();
    DataFrame(std::string filename);
    DataFrame(std::vector<std::vector<std::string>> v);

    void ReadCSV(std::string filename);
    void ConvertEmptyToInt(std::string column);
    void FillEmpty(std::string column, std::string value);
    void DropColumns(std::vector<std::string> cols);
    void DropRowsWithEmptyData();
    DataFrame GetColumn(std::string column);
    void ConvertToNumber();
    void Normalize();
// private:
    int indexOf(std::vector<std::string> v, std::string s);

    std::vector<std::string> col_names_;
    std::vector<std::vector<std::string>> data_;
    std::vector<std::vector<double>> inputs_;
};

#endif