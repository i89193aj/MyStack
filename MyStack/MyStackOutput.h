#pragma once
#define BUILDING_DLL
#ifdef BUILDING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
extern "C" {
    /*�o�̬O��Output���̥]��func��A�i�H�γo�Ӥ覡�إ�dll���~����!(�Ա��i�H��MyLinklist�A���̦���ڥ]�@����c#��)*/
}

