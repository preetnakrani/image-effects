
#include "stats.h"

stats::stats(PNG & im){

// YOUR CODE HERE!!

unsigned int widthIm = im.width(); 
unsigned int heightIm = im.height();

for (unsigned int i = 0; i < widthIm; i++) {

    vector<long> sumRy;
    vector<long> sumGy;
    vector<long> sumBy;

    vector<long> sumsqRy;
    vector<long> sumsqGy;
    vector<long> sumsqBy;

    for (unsigned int j = 0; j < heightIm; j++) {

        long summedR = 0;
        long summedG = 0;
        long summedB = 0;

        long summedsqR = 0;
        long summedsqG = 0;
        long summedsqB = 0;

        for ( unsigned int k = 0; k <= i; k++) {
            for (unsigned int l = 0; l <= j; l++) {

                summedR = summedR + im.getPixel(k,l)->r;
                summedG = summedG + im.getPixel(k,l)->g;
                summedB = summedB + im.getPixel(k,l)->b;

                summedsqR = ((im.getPixel(k,l)->r) * (im.getPixel(k,l)->r)) + summedsqR;
                summedsqG = ((im.getPixel(k,l)->g) * (im.getPixel(k,l)->g)) + summedsqG;
                summedsqB = ((im.getPixel(k,l)->b) * (im.getPixel(k,l)->b)) + summedsqB;
            }
        }

        sumRy.push_back(summedR);
        sumGy.push_back(summedG);
        sumBy.push_back(summedB);

        sumsqRy.push_back(summedsqR);
        sumsqGy.push_back(summedsqG);
        sumsqBy.push_back(summedsqB);
          
    }

    sumRed.push_back(sumRy);
    sumGreen.push_back(sumGy);
    sumBlue.push_back(sumBy);

    sumsqRed.push_back(sumsqRy);
    sumsqGreen.push_back(sumsqGy);
    sumsqBlue.push_back(sumsqBy);

}


// unsigned int widthIm = im.width(); 
// unsigned int heightIm = im.height();

// for (unsigned int i = 0; i < widthIm; i++) {

//     vector<long> sumRy;
//     vector<long> sumGy;
//     vector<long> sumBy;

//     vector<long> sumsqRy;
//     vector<long> sumsqGy;
//     vector<long> sumsqBy;

//     for (unsigned int j = 0; j < heightIm; j++) {

//         sumRy.push_back(0);
//         sumGy.push_back(0);
//         sumBy.push_back(0);

//         sumsqRy.push_back(0);
//         sumsqGy.push_back(0);
//         sumsqBy.push_back(0);
//     }

//     sumRed.push_back(sumRy);
//     sumGreen.push_back(sumGy);
//     sumBlue.push_back(sumBy);

//     sumsqRed.push_back(sumsqRy);
//     sumsqGreen.push_back(sumsqGy);
//     sumsqBlue.push_back(sumsqBy);

// }

// for (unsigned int k = 0; k < widthIm; ++k) {

//     for (unsigned int l = 0; l < heightIm; ++l) {

//         if (k != 0 && l != 0) {

//             sumRed[k][l] = sumRed[k][l-1] + sumRed[k-1][l] - sumRed[k-1][l-1] + im.getPixel(k,l)->r;
//             sumGreen[k][l] = sumGreen[k][l-1] + sumGreen[k-1][l] - sumGreen[k-1][l-1] + im.getPixel(k,l)->g;
//             sumBlue[k][l] = sumBlue[k][l-1] + sumBlue[k-1][l] - sumBlue[k-1][l-1] + im.getPixel(k,l)->b; 

//             sumsqRed[k][l] = sumsqRed[k][l-1] + sumsqRed[k-1][l] - sumsqRed[k-1][l-1] + ((im.getPixel(k,l)->r) *  (im.getPixel(k,l)->r));
//             sumsqGreen[k][l] = sumsqGreen[k][l-1] + sumsqGreen[k-1][l] - sumsqGreen[k-1][l-1] + ((im.getPixel(k,l)->g) *  (im.getPixel(k,l)->g));
//             sumsqBlue[k][l] = sumsqBlue[k][l-1] + sumsqBlue[k-1][l] - sumsqBlue[k-1][l-1] + ((im.getPixel(k,l)->b) *  (im.getPixel(k,l)->b)); 

//         } else if (k == 0 && l != 0) {

//             sumRed[k][l] = im.getPixel(k,l)->r + sumRed[k][l-1];
//             sumGreen[k][l] = im.getPixel(k,l)->g + sumGreen[k][l-1];
//             sumBlue[k][l] = im.getPixel(k,l)->b + sumBlue[k][l-1];

//             sumsqRed[k][l] = ((im.getPixel(k,l)->r) *  (im.getPixel(k,l)->r)) + sumsqRed[k][l-1];
//             sumsqGreen[k][l] = ((im.getPixel(k,l)->g) *  (im.getPixel(k,l)->g)) + sumsqGreen[k][l-1];
//             sumsqBlue[k][l] = ((im.getPixel(k,l)->b) *  (im.getPixel(k,l)->b)) + sumsqBlue[k][l-1];

//         } else if (l == 0 && k != 0) {

//             sumRed[k][l] = im.getPixel(k,l)->r + sumRed[k-1][l];
//             sumGreen[k][l] = im.getPixel(k,l)->r + sumGreen[k-1][l];
//             sumBlue[k][l] = im.getPixel(k,l)->r + sumBlue[k-1][l];

//             sumsqRed[k][l] = ((im.getPixel(k,l)->r) *  (im.getPixel(k,l)->r)) + sumsqRed[k-1][l];
//             sumsqGreen[k][l] = ((im.getPixel(k,l)->g) *  (im.getPixel(k,l)->g)) + sumsqGreen[k-1][l];
//             sumsqBlue[k][l] = ((im.getPixel(k,l)->b) *  (im.getPixel(k,l)->b)) + sumsqBlue[k-1][l];
            
//         } else {

//             sumRed[k][l] = im.getPixel(k,l)->r;
//             sumGreen[k][l] = im.getPixel(k,l)->g;
//             sumBlue[k][l] = im.getPixel(k,l)->b;

//             sumsqRed[k][l] = ((im.getPixel(k,l)->r) * (im.getPixel(k,l)->r)) + sumsqGreen[k-1][l];
//             sumsqGreen[k][l] = ((im.getPixel(k,l)->g) * (im.getPixel(k,l)->g)) + sumsqGreen[k-1][l];
//             sumsqBlue[k][l] = ((im.getPixel(k,l)->b) * (im.getPixel(k,l)->b)) + sumsqGreen[k-1][l];

//         }
//     }
// }









// for (unsigned int m = 0; m < widthIm; m++) {

//     vector<long> sumsqRy;
//     vector<long> sumsqGy;
//     vector<long> sumsqBy;

//     for (unsigned int n = 0; n < heightIm; n++) {

//         long summedsqR = 0;
//         long summedsqG = 0;
//         long summedsqB = 0;

//         for ( unsigned int o = 0; o <= m; o++) {
//             for (unsigned int r = 0; r <= n; r++) {

//                 summedsqR = summedsqR + sumRed[o][r];
//                 summedsqG = summedsqG + sumGreen[o][r];
//                 summedsqB = summedsqB + sumBlue[o][r];
//             }
//         }

//         sumsqRy.push_back(summedsqR);
//         sumsqGy.push_back(summedsqG);
//         sumsqBy.push_back(summedsqB);

//     }

//     sumsqRed.push_back(sumsqRy);
//     sumsqGreen.push_back(sumsqGy);
//     sumsqBlue.push_back(sumsqBy);


// }

}

long stats::getSum(char channel, pair<int,int> ul, pair<int,int> lr){

// YOUR CODE HERE!!
vector<vector<long>> v;
if (channel == 'r') {
    v = sumRed;
} else if (channel == 'g') {
    v = sumGreen;
} else {
    v = sumBlue;
}

if (ul.first != 0 && ul.second != 0) {
    return v[lr.first][lr.second] - v[lr.first][ul.second-1] - v[ul.first-1][lr.second] + v[ul.first-1][ul.second-1];
} else if (ul.first == 0 && ul.second != 0) {
    return v[lr.first][lr.second] - v[ul.first][ul.second-1];
} else if (ul.second == 0 && ul.first != 0) {
    return v[lr.first][lr.second] - v[ul.first-1][ul.second];
} else {
    return v[lr.first][lr.second];
}



}

long stats::getSumSq(char channel, pair<int,int> ul, pair<int,int> lr){

// YOUR CODE HERE!!
vector<vector<long>> v;
if (channel == 'r') {
    v = sumsqRed;
} else if (channel == 'g') {
    v = sumsqGreen;
} else {
    v = sumsqBlue;
}

if (ul.first != 0 && ul.second != 0) {
    return v[lr.first][lr.second] - v[lr.first][ul.second-1] - v[ul.first-1][lr.second] + v[ul.first-1][ul.second-1];
} else if (ul.first == 0 && ul.second != 0) {
    return v[lr.first][lr.second] - v[ul.first][ul.second-1];
} else if (ul.second == 0 && ul.first!= 0) {
    return v[lr.first][lr.second] - v[ul.first-1][ul.second];
} else {
    return v[lr.first][lr.second];
}


}

long stats::rectArea(pair<int,int> ul, pair<int,int> lr){

// YOUR CODE HERE!!
// long ret = ((lr.first)-(ul.first)) * ((lr.second)-(ul.second));
// return ret;

return ((lr.first+1)-(ul.first)) * ((lr.second+1)-(ul.second));

}

// given a rectangle, compute its sum of squared deviations from mean, over all color channels.
long stats::getScore(pair<int,int> ul, pair<int,int> lr){

// YOUR CODE HERE!!

long squaredSumR = getSumSq('r', ul, lr);
long squaredSumG = getSumSq('g', ul, lr);
long squaredSumB = getSumSq('b', ul, lr);

long sumsqdaR = (getSum('r', ul, lr) * getSum('r', ul, lr))/rectArea(ul, lr);
long sumsqdaG = (getSum('g', ul, lr) * getSum('g', ul, lr))/rectArea(ul, lr);
long sumsqdaB = (getSum('b', ul, lr) * getSum('b', ul, lr))/rectArea(ul, lr);



long varR = squaredSumR - sumsqdaR;
long varG = squaredSumG - sumsqdaG;
long varB = squaredSumB - sumsqdaB;

// RGBAPixel p = getAvg(ul, lr);

// long varR = squaredSumR - (((p.r) * (p.r))/rectArea(ul, lr));
// long varG = squaredSumG - (((p.g) * (p.g))/rectArea(ul, lr));
// long varB = squaredSumB - (((p.b) * (p.b))/rectArea(ul, lr));

return (varR + varG + varB);




}
		
RGBAPixel stats::getAvg(pair<int,int> ul, pair<int,int> lr){

// YOUR CODE HERE!!

long red = getSum('r', ul, lr);
int redAvg = red/rectArea(ul, lr);

long green = getSum('g', ul, lr);
int greenAvg = green/rectArea(ul, lr);

long blue = getSum('b', ul, lr);
int blueAvg = blue/rectArea(ul, lr);

RGBAPixel ret(redAvg, greenAvg, blueAvg);
return ret;

}
