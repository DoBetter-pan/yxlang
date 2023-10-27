/** 
 * @file expression.cc
 * @brief calc expression 
 * @author yingxue
 * @date 2023-10-26
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>
#include "expression.h"

YxlangNode::variablemap_type YxlangNode::variables;

YxlangNode::functionmap_type YxlangNode::functions;
