// Copyright Brian Medendorp 2016

#include "BuildingEscape.h"
#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"))
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get player viewpoint this tick
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(Location, Rotation);

	// Log out received data
	// UE_LOG(LogTemp, Warning, TEXT("Location: %s - Rotation: %s"), *Location.ToString(), *Rotation.ToString())

	FVector LineTraceEnd = Location + Rotation.Vector() * Reach;
	// Draw red line to visualize in world
	DrawDebugLine(
		GetWorld(),
		Location,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	// Ray-cast out to reach distance

	// See what we hit


}

