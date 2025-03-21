#pragma once


#include "Engine.h"

#include "Kismet2/KismetEditorUtilities.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

DECLARE_LOG_CATEGORY_EXTERN(MyGameEditor, All, All)

class FArtilleryEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
private:
    /**
     * Define all of our default events for this Editor
     */
    void PrepareAutoGeneratedDefaultEvents();
    
    /**
     * Simplify Registering default events with a macro
     * @param Class    - Name of the UObject or AActor class
     * @param FuncName - Name of the Event of Function to register
     */
#define RegisterDefaultEvent(Class, FuncName) \
(FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, Class::StaticClass(), GET_FUNCTION_NAME_CHECKED(Class, FuncName)))

};