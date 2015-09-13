#include <qgl.h>

#include "waveform/renderers/glvsynctestrenderer.h"

#include "waveform/renderers/waveformwidgetrenderer.h"
#include "waveform/waveform.h"
#include "waveform/waveformwidgetfactory.h"
#include "util/performancetimer.h"

GLVSyncTestRenderer::GLVSyncTestRenderer(
        WaveformWidgetRenderer* waveformWidgetRenderer)
    : WaveformRendererSignalBase(waveformWidgetRenderer),
      m_drawcount(0) {
}

GLVSyncTestRenderer::~GLVSyncTestRenderer() {
}

void GLVSyncTestRenderer::onSetup(const QDomNode &node) {
    Q_UNUSED(node);
}

inline void setPoint(QPointF& point, qreal x, qreal y) {
    point.setX(x);
    point.setY(y);
}

void GLVSyncTestRenderer::draw(QPainter* painter, QPaintEvent* /*event*/) {

    PerformanceTimer timer;
    //int t5, t6, t7, t8, t9, t10, t11, t12, t13;


    timer.start();

    TrackPointer pTrack = m_waveformRenderer->getTrackInfo();
    if (!pTrack) {
        return;
    }

    ConstWaveformPointer waveform = pTrack->getWaveform();
    if (waveform.isNull()) {
        return;
    }

    const int dataSize = waveform->getDataSize();
    if (dataSize <= 1) {
        return;
    }

    const WaveformData* data = waveform->data();
    if (data == NULL) {
        return;
    }

    double firstVisualIndex = m_waveformRenderer->getFirstDisplayedPosition() * dataSize;
    double lastVisualIndex = m_waveformRenderer->getLastDisplayedPosition() * dataSize;

    const int firstIndex = int(firstVisualIndex + 0.5);
    firstVisualIndex = firstIndex - firstIndex % 2;

    const int lastIndex = int(lastVisualIndex + 0.5);
    lastVisualIndex = lastIndex + lastIndex % 2;

    //t5 = timer.restart(); // 910

    // Reset device for native painting
    painter->beginNativePainting();

    //t6 = timer.restart(); // 29,150

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //  Removed Unsupported OpenGL functions, so that Mixxx can run on OpenGL-ES systems -- amvanbaren 9/2015
    //  TODO(XXX) Rewrite OpenGL code in glvsynctestrenderer.cpp to support
    //  the new OpenGL syntax or use Qt instead

    //t12 = timer.restart(); // 22,426
    painter->endNativePainting();

    //t13 = timer.restart(); // 1,430

    //qDebug() << t5 << t6 << t7 << t8 << t9 << t10 << t11 << t12 << t13;

    //qDebug() << timer.restart(); // 129,498
}