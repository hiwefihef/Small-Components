
#include "Inventory.h"

#include "Blueprint/DragDropOperation.h"
#include "Inventory/InventoryComponent.h"
#include "Inventory/InventoryGameStateBase.h"
#include "Items/ItemObject.h"

void UInventory::InitializeInventory(UInventoryComponent* inventoryComponent, float tileSize)
{
	InventoryComponent = inventoryComponent;
	TileSize = tileSize;
}

bool UInventory::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	UItemObject* ItemObject = Cast<UItemObject>(InOperation->Payload);
	AInventoryGameStateBase* InventoryGameState = GetWorld()->GetGameState<AInventoryGameStateBase>();
	if (ItemObject != nullptr && InventoryGameState != nullptr)
	{
		InventoryGameState->SpawnItemFromActor(InventoryComponent->GetOwner(), ItemObject, true);
	}

	return true;
}
