//
//  VboWaveRenderer.hpp
//  example-simple
//
//  Created by Hana on 2018/05/22.
//
//

#ifndef VboWaveRenderer_hpp
#define VboWaveRenderer_hpp

#include "ofMain.h"
#include "VboRendererConfig.h"

static constexpr float VBOWAVE_DIVISION = 1024.0;
static constexpr float VBOWAVE_DIVISION_RECIPRO = 1 / VBOWAVE_DIVISION;
static constexpr int VBOWAVE_VERTS_MAX = VBOWAVE_DIVISION + 2;
static constexpr int VBOWAVE_INDICES_MAX = VBOWAVE_VERTS_MAX * 2;

class VboWave {
public:
    VboWave();
    inline void setup() {
        setScreenSize();
        resetCount();
        initVbo();
    }

    inline void setup(float w, float h) {
        setScreenSize(w, h);
        resetCount();
        initVbo();
    }

    inline void setScreenSize() {
        width = ofGetWidth();
        height = ofGetHeight();
    }
    
    inline void setScreenSize(float w, float h) {
        width = w;
        height = h;
    }

    inline void setColor(ofFloatColor _color) {
        color = _color;
    }

    inline void setColor(float brightness, float alpha = 1.0) {
        color = ofFloatColor(brightness, alpha);
    }

    void set(float x1, float y1, float x2, float y2, float freq, float amplitude, float phase, float thick);
    void draw();

private:
    void initVbo();
    void addVertex(ofVec2f pos);
    void addColor(ofFloatColor color);
    void addIndex(ofIndexType index);
    void resetCount();

    ofFloatColor color;
    float width, height, lineWidth;
    vbo_count_t counter;

    ofVbo vbo;
    std::array<glm::vec2, VBOWAVE_VERTS_MAX> verts;
    std::array<ofFloatColor, VBOWAVE_VERTS_MAX> colors;
    std::array<ofIndexType, VBOWAVE_INDICES_MAX> indices;
    
};

class VboWaveRenderer {
public:
    VboWaveRenderer();
    void setup();
    void setup(float w, float h);
    void setScreenSize();
    void setScreenSize(float w, float h);
    
    
    void setColor(ofFloatColor _color) {
        color = _color;
    }

    void setColor(float brightness, float alpha = 1.0) {
        color = ofFloatColor(brightness, alpha);
    }

    void wave(float x1, float y1, float x2, float y2, float freq, float amplitude, float phase, float thick);
    void draw();


private:
    int waveCount;
    float width, height;
    ofFloatColor color;

    VboWave vboWave[VBOWAVE_NUM_MAX];

};

#endif /* VboWaveRenderer_hpp */
