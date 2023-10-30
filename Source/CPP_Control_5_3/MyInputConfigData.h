#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "MyInputConfigData.generated.h"


UCLASS()
class CPP_CONTROL_5_3_API UMyInputConfigData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* InputMove;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* InputLook;


};