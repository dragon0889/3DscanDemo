#pragma once

#include "FaceTrackingRenderer.h"

class FaceTrackingRenderer2D : public FaceTrackingRenderer
{
public:
	FaceTrackingRenderer2D(HWND window);
	virtual ~FaceTrackingRenderer2D();

	void DrawBitmap(PXCCapture::Sample* sample);
	void CalcDistances();
	void Reset();

private:
	void DrawDistances();
	void DrawGraphics(PXCFaceData* faceOutput);
	void DrawLandmark(PXCFaceData::Face* trackedFace);
	void DrawLocation(PXCFaceData::Face* trackedFace);
	void DrawPoseAndPulse(PXCFaceData::Face* trackedFace, const int faceId);
	void DrawExpressions(PXCFaceData::Face* trackedFace, const int faceId);		
	void DrawRecognition(PXCFaceData::Face* trackedFace, const int faceId);

	double CalculateDistance(PXCPoint3DF32 p1, PXCPoint3DF32 p2);

	double currHeadWidthAvg;
	double currNoseBridgeAvg;
	double currEyesCenterAvg;

	double headWidthAvg;
	double noseBridgeAvg;
	double eyesCenterAvg;

	int frameNum;
};

