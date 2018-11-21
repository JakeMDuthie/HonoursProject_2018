#ifndef _BASESHADER_H_
#define _BASESHADER_H_

#include <d3d12.h>
#include <D3Dcompiler.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <fstream>

using namespace std;
using namespace DirectX;


class BaseShader
{
protected:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

public:
	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}

	void operator delete(void* p)
	{
		_mm_free(p);
	}

	BaseShader(ID3D12Device* device, HWND hwnd);
	~BaseShader();

	//virtual void render(ID3D12DeviceContext* deviceContext, int vertexCount);

protected:
	virtual void initShader(WCHAR*, WCHAR*) = 0;
	void loadVertexShader(WCHAR* filename);
	//void loadHullShader(WCHAR* filename);
	//void loadDomainShader(WCHAR* filename);
	//void loadGeometryShader(WCHAR* filename);
	void loadPixelShader(WCHAR* filename);

protected:
	ID3D12Device* renderer;
	HWND hwnd;

	ID3DBlob*	vertexShader,
				*pixelShader,
				*hullShader,
				*domainShader,
				*geometryShader;
	//ID3D11InputLayout* layout;
	//ID3D11Buffer* matrixBuffer;
	//ID3D11SamplerState* sampleState;
};

#endif