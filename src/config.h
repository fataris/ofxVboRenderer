//
//  config.h
//  example-simple
//
//  Created by Hana on 2018/04/25.
//
//

#ifndef config_h
#define config_h

struct vbo_count_t {
    int num;
    int vertex = 0;
    int color = 0;
    int index = 0;
};

constexpr int VBOCIRCLE_NUM_MAX = 1024;
constexpr int VBOTRIANGLE_NUM_MAX = 512;
constexpr int RECTANGLE_NUM_MAX = 512;

#endif /* config_h */
