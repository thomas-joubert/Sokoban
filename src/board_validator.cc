#include "board_validator.hh"

bool BoardValidator::isValid(Board board)
{
    (void) board;
    return false;
}

bool BoardValidator::isSolvable(Board board)
{
    (void) board;
    return false;
}

bool BoardValidator::isComplete(Board board)
{
    (void) board;
    return false;
}

bool BoardValidator::isValid(nlohmann::json board, nlohmann::json schema)
{
    nlohmann::json_schema::json_validator validator;

    try {
        validator.set_root_schema(schema);
    } catch (const std::exception &e) {
        std::cerr << "Validation of schema failed: " << e.what() << "\n";
        return false;
    }

    try {
        validator.validate(board);
    }
    catch (const std::exception &e) {
        std::cerr << "Validation of json failed: " << e.what() << "\n";
        return false;
    }

    size_t height;
    size_t width;
    std::vector<std::vector<short>> rows;

    try {
        height = board["height"];
        width = board["width"];
        rows = board["rows"].get<std::vector<std::vector<short>>>();
    }
    catch (const std::exception &e) {
        std::cerr << "Extraction of json failed: " << e.what() << "\n";
        return false;
    }

    if (rows.size() != height)
    {
        std::cerr << "Invalid height, expected " << height << ", got " << rows.size() << std::endl;
        return false;
    }

    for (std::vector<short> line : rows)
    {
        if (line.size() != width)
        {
            std::cerr << "Invalid length on row: [";
            std::copy(line.begin(), line.end(), std::ostream_iterator<char>(std::cout, ","));
            std::cout << "]" << ", expected " << width << ", got " << line.size() <<std::endl;

            return false;
        }
    }

    std::cerr << "Board is valid\n";
    return true;
}

bool BoardValidator::isSolvable(nlohmann::json board)
{
    (void) board;
    return false;
}

bool BoardValidator::isComplete(nlohmann::json board)
{
    (void) board;
    return false;
}