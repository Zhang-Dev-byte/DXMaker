#pragma once
#include "DXMaker/Core.h"
#ifdef DX_PLATFORM_WINDOWS
#include <Windows.h>
#include <windowsx.h>
#endif // DX_PLATFORM_WINDOWS
#ifdef __cplusplus
#include <string>
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <queue>
#include <wrl.h>
namespace wrl = Microsoft::WRL;
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")
#endif
