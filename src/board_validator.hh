#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>
#include <iostream>
#include <algorithm>

#include "board.hh"

class BoardValidator
{
    public:
        static bool isValid(Board board);
        static bool isSolvable(Board board);
        static bool isComplete(Board board);

        static bool isValid(nlohmann::json board, nlohmann::json schema);
        static bool isSolvable(nlohmann::json board);
        static bool isComplete(nlohmann::json board);
};