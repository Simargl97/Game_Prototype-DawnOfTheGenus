// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/Helpers/MDataTableHelper.h"

const FString FMDataTableHelper::ContextString((TEXT("DataTable")));

TArray<FName> FMDataTableHelper::GetRowNames(const UDataTable* DataTable)
{
	check(DataTable);
	return DataTable->GetRowNames();
}

bool FMDataTableHelper::RowExists(const UDataTable* DataTable, const FName& RowName)
{
	check(DataTable);
	return DataTable->GetRowNames().Contains(RowName);
}
