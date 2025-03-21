﻿#include "BarrageContactListener.h"
#include "BarrageDispatch.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "BarrageContactEvent.h"

using namespace JPH;

	ValidateResult BarrageContactListener::OnContactValidate(const Body& inBody1, const Body& inBody2, RVec3Arg inBaseOffset,
												 const CollideShapeResult& inCollisionResult)
	{
		// Allows you to ignore a contact before it is created (using layers to not make objects collide is cheaper!)
		return ValidateResult::AcceptAllContactsForThisBodyPair;
	}

	void BarrageContactListener::OnContactAdded(const Body& inBody1, const Body& inBody2, const ContactManifold& inManifold,
								ContactSettings& ioSettings)
	{
		TRACE_CPUPROFILER_EVENT_SCOPE_STR("Report Contact");
		if (UBarrageDispatch::SelfPtr)
		{
			UBarrageDispatch::SelfPtr->HandleContactAdded(inBody1, inBody2, inManifold, ioSettings);
		}
	}

	void BarrageContactListener::OnContactPersisted(const Body& inBody1, const Body& inBody2, const ContactManifold& inManifold,
									ContactSettings& ioSettings)
	{
		// TODO: Honestly, this event fires way too often and we don't really need it so... let's just not for now

		/**
		if (BarrageDispatch.IsValid())
		{
			BarrageDispatch->HandleContactPersisted(inBody1, inBody2, inManifold, ioSettings);
		}
		**/
	}
	
	void BarrageContactListener::OnContactRemoved(const SubShapeIDPair& inSubShapePair)
	{
		if (UBarrageDispatch::SelfPtr)
		{
			UBarrageDispatch::SelfPtr->HandleContactRemoved(inSubShapePair);
		}
	}
