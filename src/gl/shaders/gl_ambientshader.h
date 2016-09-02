#ifndef __GL_AMBIENTSHADER_H
#define __GL_AMBIENTSHADER_H

#include "gl_shaderprogram.h"

class FLinearDepthShader
{
public:
	void Bind();

	FBufferedUniformSampler DepthTexture;
	FBufferedUniform1f LinearizeDepthA;
	FBufferedUniform1f LinearizeDepthB;
	FBufferedUniform1f InverseDepthRangeA;
	FBufferedUniform1f InverseDepthRangeB;

private:
	FShaderProgram mShader;
};

class FSSAOShader
{
public:
	void Bind();

	FBufferedUniformSampler DepthTexture;
	FBufferedUniformSampler RandomTexture;
	FBufferedUniform2f UVToViewA;
	FBufferedUniform2f UVToViewB;
	FBufferedUniform2f InvFullResolution;
	FBufferedUniform1f NDotVBias;
	FBufferedUniform1f NegInvR2;
	FBufferedUniform1f RadiusToScreen;
	FBufferedUniform1f AOMultiplier;
	FBufferedUniform1f AOStrength;

private:
	FShaderProgram mShader;
};

class FDepthBlurShader
{
public:
	void Bind(bool vertical);

	FBufferedUniformSampler AODepthTexture[2];
	FBufferedUniform1f BlurSharpness[2];
	FBufferedUniform2f InvFullResolution[2];
	FBufferedUniform1f PowExponent[2];

private:
	FShaderProgram mShader[2];
};

class FSSAOCombineShader
{
public:
	void Bind();

	FBufferedUniformSampler AODepthTexture;

private:
	FShaderProgram mShader;
};

#endif