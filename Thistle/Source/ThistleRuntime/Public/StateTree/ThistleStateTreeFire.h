﻿#pragma once
#include "MassStateTreeSchema.h"
#include "StateTreeTaskBase.h"		//this defines the basic form of an actual tree task.
#include "StateTreeExecutionContext.h"
#include "ThistleBehavioralist.h"
#include "ThistleDispatch.h"
#include "ThistleStateTreeSchema.h"
#include "ThistleTypes.h"
#include "ThistleStateTreeCore.h"
#include "Components/StateTreeComponent.h"
#include "ThistleStateTreeFire.generated.h"

using namespace ThistleTypes;


USTRUCT()
struct THISTLERUNTIME_API FFireTurret : public FTTaskBase
{

	GENERATED_BODY()
	using FInstanceDataType = F_ArtilleryKeyInstanceData;

protected:
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;
	virtual const UStruct* GetInstanceDataType() const override { return FInstanceDataType::StaticStruct(); }
};
