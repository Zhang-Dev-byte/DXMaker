#pragma once
#include <memory>
#ifdef DX_BUILD_DLL
#define DX_API __declspec(dllexport)
#else
#define DX_API __declspec(dllimport)
#endif // DX_BUILD_DLL

namespace DX {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}