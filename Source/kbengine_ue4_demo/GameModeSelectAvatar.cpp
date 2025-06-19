// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModeSelectAvatar.h"
#include "kbengine_ue4_demo.h"
#include "KBEnginePlugins/Engine/KBEngine.h"

AGameModeSelectAvatar::AGameModeSelectAvatar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGameModeSelectAvatar::installEvents()
{
	Super::installEvents();

	// select-avatars(register by scripts)
	KBENGINE_REGISTER_EVENT("onReqAvatarList", onReqAvatarList);
	KBENGINE_REGISTER_EVENT("onCreateAvatarResult", onCreateAvatarResult);
	KBENGINE_REGISTER_EVENT("onRemoveAvatar", onRemoveAvatar);

	// begin enterworld
	// ����¼�����ʱ������Ҫ�л���ͼ����Ϸ�����ͼ
	KBENGINE_REGISTER_EVENT("addSpaceGeometryMapping", addSpaceGeometryMapping);
}

void AGameModeSelectAvatar::onReqAvatarList_Implementation(const UKBEventData* pEventData)
{
}

void AGameModeSelectAvatar::onCreateAvatarResult_Implementation(const UKBEventData* pEventData)
{
}

void AGameModeSelectAvatar::onRemoveAvatar_Implementation(const UKBEventData* pEventData)
{
}

void AGameModeSelectAvatar::addSpaceGeometryMapping_Implementation(const UKBEventData* pEventData)
{

}

void AGameModeSelectAvatar::reqCreateAvatar(uint8 roleType, const FString& name)
{
	// ����Accountʵ��ע���˸��¼��� �����ʱAccountʵ�������ô��Ȼ��ִ�е����¼� 
	UKBEventData_reqCreateAvatar* pEventData = NewObject<UKBEventData_reqCreateAvatar>();
	pEventData->roleType = roleType;
	pEventData->name = name;
	KBENGINE_EVENT_FIRE("reqCreateAvatar", pEventData);
}

void AGameModeSelectAvatar::reqRemoveAvatar(const FAVATAR_INFOS& avatarInfos)
{
	// ����Accountʵ��ע���˸��¼��� �����ʱAccountʵ�������ô��Ȼ��ִ�е����¼� 
	UKBEventData_reqRemoveAvatar* pEventData = NewObject<UKBEventData_reqRemoveAvatar>();
	pEventData->avatarInfos = avatarInfos;
	KBENGINE_EVENT_FIRE("reqRemoveAvatar", pEventData);
}

void AGameModeSelectAvatar::selectAvatarGame(const FAVATAR_INFOS& avatarInfos)
{
	// ����Accountʵ��ע���˸��¼��� �����ʱAccountʵ�������ô��Ȼ��ִ�е����¼� 
	UKBEventData_selectAvatarGame* pEventData = NewObject<UKBEventData_selectAvatarGame>();
	pEventData->avatarInfos = avatarInfos;
	KBENGINE_EVENT_FIRE("selectAvatarGame", pEventData);
}

