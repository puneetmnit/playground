/**@file	playground/Algorithms/lib/utils.h
 * @author	puneet
 * @version	704
 * @date
 * 	Created:	Thu Jun  2 00:22:35 2016 \n
 * 	Last Update:	Thu Jun  2 00:22:35 2016
 *
 */
#ifndef _PLAYGROUND_ALGORITHMS_LIB_UTILS_H__
#define _PLAYGROUND_ALGORITHMS_LIB_UTILS_H__

#include <algorithm>
#include <iterator>
#include <random> 


namespace utils
{
    template<typename Iter, typename Engine = std::default_random_engine, typename Distribution = std::uniform_int_distribution<typename std::iterator_traits<Iter>::value_type>>
    void random_fill(Iter beg, Iter end, typename std::iterator_traits<Iter>::value_type min, typename std::iterator_traits<Iter>::value_type max)
    {
        Distribution dist(min, max);

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        Engine generator(seed);

        generate(beg, end, [&](){ return dist(generator); });
    } 


}// namespace utils

     
#endif // _PLAYGROUND_ALGORITHMS_LIB_UTILS_H__
