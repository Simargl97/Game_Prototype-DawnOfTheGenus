// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Animations/Notifies/MStepAnimNotify.h"
#include "Kismet/GameplayStatics.h"

void UMStepAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	FHitResult OutHit;
	if (LineTrace(MeshComp, OutHit))
	{
		const UPhysicalMaterial* PhysicalMaterial = OutHit.PhysMaterial.Get();
		USoundBase* Sound = Sounds.Contains(PhysicalMaterial) ? Sounds[PhysicalMaterial] : DefaultSound;
		UGameplayStatics::PlaySoundAtLocation(MeshComp, Sound, OutHit.Location);
	}
}

bool UMStepAnimNotify::LineTrace(const USkeletalMeshComponent* MeshComp, FHitResult& OutHit) const
{
	check(MeshComp);
	check(MeshComp->GetWorld());

	const FVector StartLocation = MeshComp->GetSocketLocation(SocketName);
	const FVector EndLocation = StartLocation + FVector::DownVector * TraceDistance;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(MeshComp->GetOwner());
	Params.bReturnPhysicalMaterial = true;

	return MeshComp->GetWorld()->LineTraceSingleByChannel(OutHit, StartLocation, EndLocation, ECC_Visibility, Params);
}