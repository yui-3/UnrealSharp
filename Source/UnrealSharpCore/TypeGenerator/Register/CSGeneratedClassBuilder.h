﻿#pragma once

#include "CSGeneratedTypeBuilder.h"
#include "MetaData/CSClassMetaData.h"

class UNREALSHARPCORE_API FCSGeneratedClassBuilder : public TCSGeneratedTypeBuilder<FCSClassMetaData, UCSClass>
{
	
public:

	FCSGeneratedClassBuilder(const TSharedPtr<FCSClassMetaData>& InTypeMetaData);

	// TCSGeneratedTypeBuilder interface implementation
	virtual void RebuildType() override;
	virtual void UpdateType() override;
	virtual FName GetFieldName() const override;
	// End of implementation

	static UCSClass* GetFirstManagedClass(UClass* Class);
	static UClass* GetFirstNativeClass(UClass* Class);
	static UClass* GetFirstNonBlueprintClass(UClass* Class);

	static bool IsManagedType(const UClass* Class);
	static bool IsSkeletonType(const UClass* Class);
	static void ManagedObjectConstructor(const FObjectInitializer& ObjectInitializer);
	static void ImplementInterfaces(UClass* ManagedClass, const TArray<FName>& Interfaces);
	static void TryRegisterSubsystem(UClass* ManagedClass);
	static void SetConfigName(UClass* ManagedClass, const TSharedPtr<const FCSClassMetaData>& TypeMetaData);
	static void SetupDefaultTickSettings(UObject* DefaultObject, const UClass* Class);

private:
#if WITH_EDITOR
	void CreateClassEditor(UClass* SuperClass);
#endif
	void CreateClass(UClass* SuperClass);
	
	TMap<UClass*, UClass*> RedirectClasses;
};
