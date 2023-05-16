// Copyright 2023 Mitin Roman
#include <vector>
#include <string>
#include <cinttypes>

class gronsfeld_cipher_t
{
    constexpr static uint8_t alphabet_size = 'z' - 'a' + 1;

    std::vector<uint8_t> key;

    std::string code_impl(const std::string& to_code, bool is_code);
public:
    gronsfeld_cipher_t(const std::vector<uint8_t>& new_key);
    
    std::string code(const std::string& to_code);
    std::string decode(const std::string& to_decode);
};