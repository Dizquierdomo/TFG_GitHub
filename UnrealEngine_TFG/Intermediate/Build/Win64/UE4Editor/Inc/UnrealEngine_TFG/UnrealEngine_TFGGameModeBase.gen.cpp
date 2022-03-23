// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealEngine_TFG/UnrealEngine_TFGGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealEngine_TFGGameModeBase() {}
// Cross Module References
	UNREALENGINE_TFG_API UClass* Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_NoRegister();
	UNREALENGINE_TFG_API UClass* Z_Construct_UClass_AUnrealEngine_TFGGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_UnrealEngine_TFG();
// End Cross Module References
	void AUnrealEngine_TFGGameModeBase::StaticRegisterNativesAUnrealEngine_TFGGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_NoRegister()
	{
		return AUnrealEngine_TFGGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealEngine_TFG,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "UnrealEngine_TFGGameModeBase.h" },
		{ "ModuleRelativePath", "UnrealEngine_TFGGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnrealEngine_TFGGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::ClassParams = {
		&AUnrealEngine_TFGGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AUnrealEngine_TFGGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AUnrealEngine_TFGGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AUnrealEngine_TFGGameModeBase, 2797783136);
	template<> UNREALENGINE_TFG_API UClass* StaticClass<AUnrealEngine_TFGGameModeBase>()
	{
		return AUnrealEngine_TFGGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AUnrealEngine_TFGGameModeBase(Z_Construct_UClass_AUnrealEngine_TFGGameModeBase, &AUnrealEngine_TFGGameModeBase::StaticClass, TEXT("/Script/UnrealEngine_TFG"), TEXT("AUnrealEngine_TFGGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealEngine_TFGGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
