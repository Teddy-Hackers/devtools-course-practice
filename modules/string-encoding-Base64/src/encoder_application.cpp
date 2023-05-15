// Copyright 2023 Yurin Evgeny

#include <vector>
#include "include/Encoder.h"
#include "include/encoder_application.h"

void EncoderApplication::help(const char *appname) {
    std::string builder;

    builder
            .append("It is a string encoder/decoder into base64.\n\n")
            .append("Please provide arguments in the following format:\n\n")
            .append("\t$ ")
            .append(appname)
            .append("decode/encode")
            .append("string to decode");

    m_message = std::move(builder);
}

bool EncoderApplication::validateArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }

    if (argc < 2) {
        m_message =
                std::string("Atleast 2 elements required")
                + argv[0]
                + "` to see help";
        return false;
    }

    if (argv[1] != "encode" || argv[1] != "decode") {
        m_message =
                std::string("Not correct argument. Should be decode/encode")
                + argv[0]
                + "` to see help";
        return false;
    }
    return true;
}

std::string EncoderApplication::operator()(int argc, const char **argv) {
    if (!validateArguments(argc, argv)) {
        return m_message;
    }

    bool encode = false;
    switch (argv[1]) {
        case "encode":
            encode = true;
            break;
        case "decode":
            encode = false;
            break;
    }

    Base64Encoder encoder;
    std::string result;
    std::string input = argv[2];

    if (encode) {
        result = encoder.strToBase64(input);
    } else {
        result = encoder.base64ToStr(input);
    }

    return result;
}
