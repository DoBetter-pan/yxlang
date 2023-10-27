/** 
 * @file driver.h
 * @brief Core driver
 * @author yingxue
 * @date 2023-10-26
 */

#ifndef YXLANG_DRIVER_H
#define YXLANG_DRIVER_H

#include <string>
#include <vector>

class YxlangContext;

namespace yxlang {

class Driver {
public:
    // Yxlang context
    Driver(class YxlangContext& calc);

    bool trace_scanning;
    bool trace_parsing;
    std::string streamname;

    bool parse_stream(std::istream& in, const std::string& sname = "stream input");
    bool parse_string(const std::string& input, const std::string& sname = "string stream");
    bool parse_file(const std::string& filename);

    void error(const class location& l, const std::string& m);
    void error(const std::string& m);

    class Scanner* lexer;
    class YxlangContext& calc;
};

} // namespace yxlang

#endif // YXLANG_DRIVER_H
