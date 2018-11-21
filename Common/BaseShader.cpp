#include "BaseShader.h"

// Store pointer to render device and handle to window.
BaseShader::BaseShader(ID3D12Device* device, HWND lhwnd)
{
	renderer = device;
	hwnd = hwnd;
}


BaseShader::~BaseShader()
{
}
