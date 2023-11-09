// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/MAnimalCharacter.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/Components/MHealthComponent.h"
#include "Core/Components/MInteractWidgetComponent.h"
#include "Core/Components/MInventoryComponent.h"
#include "Core/Interfaces/MInventory.h"
#include "Core/Interfaces/MItemRowName.h"
#include "Core/Helpers/MHelperFunctions.h"

AMAnimalCharacter::AMAnimalCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationYaw = false;

	check(GetCharacterMovement());
	GetCharacterMovement()->bOrientRotationToMovement = true;

	BlockCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BlockCOllision"));
	check(BlockCollision);
	BlockCollision->SetupAttachment(GetRootComponent());

	InteractWidgetComponent = CreateDefaultSubobject <UMInteractWidgetComponent>(TEXT("InteractWidgetComponent"));
	check(InteractWidgetComponent);
	InteractWidgetComponent->SetupAttachment(GetMesh());
	
	AudioComponent = CreateDefaultSubobject <UAudioComponent>(TEXT("AudioComponent"));
	check(AudioComponent);
	AudioComponent->SetupAttachment(GetRootComponent());
}

void AMAnimalCharacter::Interact(AActor* OtherActor)
{
	check(HealthComponent)
		if (HealthComponent->IsDead())
		{
			IMInventory* OtherInventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(OtherActor);
			OtherInventory->TransferFromInventory(InventoryComponent);

			const TArray<AActor*>& Arrows = GetAddedArrows();
			for (AActor* Actor : Arrows)
			{
				if (!IsValid(Actor)) continue;

				if (const IMItemRowName* InItemRowName = Cast<IMItemRowName>(Actor))
				{
					OtherInventory->AddItem(InItemRowName->GetRowName());
					Actor->Destroy();
				}
			}
			Destroy();
		}
}

void AMAnimalCharacter::OnEnter()
{
	check(HealthComponent);
	if (HealthComponent->IsDead())
	{
		check(InteractWidgetComponent);
		InteractWidgetComponent->SetVisibility(true);
	}
}

void AMAnimalCharacter::OnLeave()
{
	check(InteractWidgetComponent);
	InteractWidgetComponent->SetVisibility(false);
}

void AMAnimalCharacter::Dead()
{
	Super::Dead();
	check(BlockCollision);
	check(GetController());
	BlockCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetController()->Destroy();
	
}