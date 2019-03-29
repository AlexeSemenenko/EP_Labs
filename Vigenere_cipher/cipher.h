#pragma once

#include <string>

void create_square(std::string square[27][27]);
std::string create_key(std::string to_encrypt, std::string keyword);
std::string encrypt(std::string to_encrypt, std::string key, std::string square[27][27]);