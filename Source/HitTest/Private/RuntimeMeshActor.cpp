// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeMeshActor.h"

// Sets default values
ARuntimeMeshActor::ARuntimeMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	RootComponent = ProceduralMesh;

	RootComponent->SetMobility(EComponentMobility::Movable);
}

// Called when the game starts or when spawned
void ARuntimeMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARuntimeMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARuntimeMeshActor::CreateCube(float Length)
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	
	Vertices.Add(FVector(0, 0, 0) * Length);  // 0
	Vertices.Add(FVector(1, 0, 0) * Length);  // 1
	Vertices.Add(FVector(1, 1, 0) * Length);  // 2
	Vertices.Add(FVector(0, 1, 0) * Length);  // 3
	Vertices.Add(FVector(0, 0, 1) * Length);  // 4
	Vertices.Add(FVector(1, 0, 1) * Length);  // 5
	Vertices.Add(FVector(1, 1, 1) * Length);  // 6
	Vertices.Add(FVector(0, 1, 1) * Length);  // 7

	Triangles.Add(0); Triangles.Add(2); Triangles.Add(1);  // 底面
	Triangles.Add(0); Triangles.Add(3); Triangles.Add(2);
	Triangles.Add(1); Triangles.Add(6); Triangles.Add(5);  // 正面
	Triangles.Add(1); Triangles.Add(2); Triangles.Add(6);
	Triangles.Add(5); Triangles.Add(7); Triangles.Add(4);  // 顶面
	Triangles.Add(5); Triangles.Add(6); Triangles.Add(7);
	Triangles.Add(4); Triangles.Add(3); Triangles.Add(0);  // 背面
	Triangles.Add(4); Triangles.Add(7); Triangles.Add(3);
	Triangles.Add(4); Triangles.Add(1); Triangles.Add(5);  // 左侧面
	Triangles.Add(4); Triangles.Add(0); Triangles.Add(1);
	Triangles.Add(3); Triangles.Add(6); Triangles.Add(2);  // 右侧面
	Triangles.Add(3); Triangles.Add(7); Triangles.Add(6);

	Normals.Init(FVector::ZeroVector, Vertices.Num());

	ProceduralMesh->CreateMeshSection(0, Vertices, Triangles, Normals, TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), true);

    UMaterialInterface* DefaultMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/defaultMat"));
	ProceduralMesh->SetMaterial(0, DefaultMaterial);
}


