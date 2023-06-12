// Copyright 2023 Rezchikov Dmitrii

#include "../include/bilinear_interpolation.h"

// void BilinearInterpolator::printMtx( std::vector<std::vector<int>> & src ){
//     std::cout << "=======\n";
//     for ( const auto & v : src ){
//         for ( const auto & x : v){
//             std::cout << x << " ";
//         }
//         std::cout << "\n";
//     }
//     std::cout << "=======\n";
// }

void BilinearInterpolator::findNearest(int oldVecSize, int newVecSize,
                                    int coord, int factor, int * l, int * r) {
    *l = floor(
        static_cast<double>(coord) / static_cast<double>(factor)) * factor;
    *r = ceil(
        static_cast<double>(coord) / static_cast<double>(factor)) * factor;
}

void BilinearInterpolator::linearInterpolationH(
    std::vector<std::vector<int>> * mtx, int yCoord, int l, int r, int point) {
    if ( r == l ) {
        return;
    }
    double denominator = (r - l);
    double lWeight = (r - point) / denominator,
            rWeight = (point - l) / denominator;
    (*mtx)[yCoord][point] =
    round((*mtx)[yCoord][l] * lWeight + ((*mtx)[yCoord][r] * rWeight));
}
void BilinearInterpolator::linearInterpolationV(
    std::vector<std::vector<int>> * mtx, int xCoord, int l, int r, int point) {
    double denominator = (r - l);
    double lWeight = (r - point) / denominator,
            rWeight = (point - l) / denominator;
    (*mtx)[point][xCoord] =
    round((*mtx)[l][xCoord] * lWeight + ((*mtx)[r][xCoord] * rWeight));
}

void BilinearInterpolator::bilinearInterpolation(
                            std::vector<std::vector<int>> * oldMatrix,
                            std::vector<std::vector<int>> * newMatrix,
                            int yCoord, int xCoord, int factor) {
    int l, r;
    findNearest(oldMatrix->size(), newMatrix->size(), yCoord, factor, &l, &r);
    int l1, r1;
    findNearest((*oldMatrix)[l].size(), (*newMatrix)[l].size(),
                xCoord, factor, &l1, &r1);
    if ( l == r && l1 == r1 ) {
        return;
    }
    linearInterpolationH(newMatrix, l, l1, r1, xCoord);
    if (l != r) {
        findNearest((*oldMatrix)[r].size(), (*newMatrix)[r].size(),
                    xCoord, factor, &l1, &r1);
        linearInterpolationH(newMatrix, r, l1, r1, xCoord);
        linearInterpolationV(newMatrix, xCoord, l, r, yCoord);
    }
}

void BilinearInterpolator::bilinearInterpolation(
                            std::vector<std::vector<int>> * oldMatrix,
                            std::vector<std::vector<int>> * newMatrix,
                            int factor) {
    for ( auto i = 0; i < (*newMatrix).size(); ++i ) {
        for ( auto j = 0; j < (*newMatrix)[i].size(); ++j ) {
            bilinearInterpolation(oldMatrix, newMatrix, i, j, factor);
        }
    }

    // printMtx(newMatrix);
}
