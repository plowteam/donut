#include <Commands.h>
#include <iostream>
#include <fmt/format.h>

namespace Donut
{
    static void Impl_LoadP3DFile(const std::string& param0, const std::string& param1 = "") { GameCommands::LoadP3DFile(param0, param1); }
    static void Impl_SetParticleTexture(int32_t param0, const std::string& param1) { GameCommands::SetParticleTexture(param0, param1); }
    static void Impl_BindReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, int32_t param4, int32_t param5 = 0, const std::string& param6 = "") { GameCommands::BindReward(param0, param1, param2, param3, param4, param5, param6); }
    static void Impl_SetCarAttributes(const std::string& param0, float param1, float param2, float param3, float param4) { GameCommands::SetCarAttributes(param0, param1, param2, param3, param4); }
    static void Impl_SetTotalGags(int32_t param0, int32_t param1) { GameCommands::SetTotalGags(param0, param1); }
    static void Impl_SelectMission(const std::string& param0) { GameCommands::SelectMission(param0); }
    static void Impl_SetMissionResetPlayerInCar(const std::string& param0) { GameCommands::SetMissionResetPlayerInCar(param0); }
    static void Impl_SetDynaLoadData(const std::string& param0, const std::string& param1 = "") { GameCommands::SetDynaLoadData(param0, param1); }
    static void Impl_UsePedGroup(int32_t param0) { GameCommands::UsePedGroup(param0); }
    static void Impl_AddStage(const std::string& param0 = "", const std::string& param1 = "", const std::string& param2 = "") { GameCommands::AddStage(param0, param1, param2); }
    static void Impl_SetPresentationBitmap(const std::string& param0) { GameCommands::SetPresentationBitmap(param0); }
    static void Impl_SetStageMessageIndex(int32_t param0, const std::string& param1 = "") { GameCommands::SetStageMessageIndex(param0, param1); }
    static void Impl_AddObjective(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "") { GameCommands::AddObjective(param0, param1, param2); }
    static void Impl_SetObjTargetVehicle(const std::string& param0) { GameCommands::SetObjTargetVehicle(param0); }
    static void Impl_CloseObjective(int32_t param0 = 0) { GameCommands::CloseObjective(param0); }
    static void Impl_CloseStage(int32_t param0 = 0) { GameCommands::CloseStage(param0); }
    static void Impl_RESET_TO_HERE(int32_t param0 = 0) { GameCommands::RESET_TO_HERE(param0); }
    static void Impl_SetHUDIcon(const std::string& param0) { GameCommands::SetHUDIcon(param0); }
    static void Impl_AddCollectible(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "", const std::string& param3 = "") { GameCommands::AddCollectible(param0, param1, param2, param3); }
    static void Impl_SetStageTime(int32_t param0) { GameCommands::SetStageTime(param0); }
    static void Impl_AddCondition(const std::string& param0, const std::string& param1 = "") { GameCommands::AddCondition(param0, param1); }
    static void Impl_CloseCondition(int32_t param0 = 0) { GameCommands::CloseCondition(param0); }
    static void Impl_ShowStageComplete(int32_t param0 = 0) { GameCommands::ShowStageComplete(param0); }
    static void Impl_AddNPC(const std::string& param0, const std::string& param1, const std::string& param2 = "") { GameCommands::AddNPC(param0, param1, param2); }
    static void Impl_SetDestination(const std::string& param0, const std::string& param1 = "") { GameCommands::SetDestination(param0, param1); }
    static void Impl_SetCollectibleEffect(const std::string& param0) { GameCommands::SetCollectibleEffect(param0); }
    static void Impl_AddStageTime(int32_t param0) { GameCommands::AddStageTime(param0); }
    static void Impl_AddObjectiveNPCWaypoint(const std::string& param0, const std::string& param1) { GameCommands::AddObjectiveNPCWaypoint(param0, param1); }
    static void Impl_SetTalkToTarget(const std::string& param0, int32_t param1 = 0, float param2 = 0.0f, const std::string& param3 = "") { GameCommands::SetTalkToTarget(param0, param1, param2, param3); }
    static void Impl_SetDialogueInfo(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3) { GameCommands::SetDialogueInfo(param0, param1, param2, param3); }
    static void Impl_SetCamBestSide(const std::string& param0, const std::string& param1 = "") { GameCommands::SetCamBestSide(param0, param1); }
    static void Impl_CloseMission(int32_t param0 = 0) { GameCommands::CloseMission(param0); }
    static void Impl_PlacePlayerCar(const std::string& param0, const std::string& param1) { GameCommands::PlacePlayerCar(param0, param1); }
    static void Impl_SetMaxTraffic(int32_t param0) { GameCommands::SetMaxTraffic(param0); }
    static void Impl_AddStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4 = "") { GameCommands::AddStageVehicle(param0, param1, param2, param3, param4); }
    static void Impl_AddStageWaypoint(const std::string& param0) { GameCommands::AddStageWaypoint(param0); }
    static void Impl_SetRaceLaps(int32_t param0) { GameCommands::SetRaceLaps(param0); }
    static void Impl_SetDemoLoopTime(int64_t param0) { GameCommands::SetDemoLoopTime(param0); }
    static void Impl_AddStageMusicChange(int32_t param0 = 0) { GameCommands::AddStageMusicChange(param0); }
    static void Impl_LoadDisposableCar(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::LoadDisposableCar(param0, param1, param2); }
    static void Impl_AddMission(const std::string& param0) { GameCommands::AddMission(param0); }
    static void Impl_ClearGagBindings(int32_t param0 = 0) { GameCommands::ClearGagBindings(param0); }
    static void Impl_GagBegin(const std::string& param0) { GameCommands::GagBegin(param0); }
    static void Impl_GagSetInterior(const std::string& param0) { GameCommands::GagSetInterior(param0); }
    static void Impl_GagSetCycle(const std::string& param0) { GameCommands::GagSetCycle(param0); }
    static void Impl_GagSetPosition(const std::string& param0) { GameCommands::GagSetPosition(param0); }
    static void Impl_GagSetPosition(float param0, float param1, float param2) { GameCommands::GagSetPosition(param0, param1, param2); }
    static void Impl_GagSetRandom(int32_t param0) { GameCommands::GagSetRandom(param0); }
    static void Impl_GagSetSound(const std::string& param0) { GameCommands::GagSetSound(param0); }
    static void Impl_GagSetTrigger(const std::string& param0, const std::string& param1, float param2) { GameCommands::GagSetTrigger(param0, param1, param2); }
    static void Impl_GagSetTrigger(const std::string& param0, float param1, float param2, float param3, float param4) { GameCommands::GagSetTrigger(param0, param1, param2, param3, param4); }
    static void Impl_GagEnd(int32_t param0 = 0) { GameCommands::GagEnd(param0); }
    static void Impl_GagSetSparkle(int32_t param0) { GameCommands::GagSetSparkle(param0); }
    static void Impl_GagSetPersist(int32_t param0) { GameCommands::GagSetPersist(param0); }
    static void Impl_GagSetCoins(int32_t param0, float param1) { GameCommands::GagSetCoins(param0, param1); }
    static void Impl_GagSetAnimCollision(int32_t param0) { GameCommands::GagSetAnimCollision(param0); }
    static void Impl_GagSetIntro(int32_t param0) { GameCommands::GagSetIntro(param0); }
    static void Impl_GagSetOutro(int32_t param0) { GameCommands::GagSetOutro(param0); }
    static void Impl_GagSetCameraShake(float param0, int32_t param1, float param2) { GameCommands::GagSetCameraShake(param0, param1, param2); }
    static void Impl_GagPlayFMV(const std::string& param0) { GameCommands::GagPlayFMV(param0); }
    static void Impl_EnableTutorialMode(const std::string& param0) { GameCommands::EnableTutorialMode(param0); }
    static void Impl_InitLevelPlayerVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 = "") { GameCommands::InitLevelPlayerVehicle(param0, param1, param2, param3); }
    static void Impl_AddCharacter(const std::string& param0, const std::string& param1) { GameCommands::AddCharacter(param0, param1); }
    static void Impl_CreateChaseManager(const std::string& param0, const std::string& param1, int32_t param2) { GameCommands::CreateChaseManager(param0, param1, param2); }
    static void Impl_SetHitAndRunDecay(float param0) { GameCommands::SetHitAndRunDecay(param0); }
    static void Impl_SetNumChaseCars(const std::string& param0) { GameCommands::SetNumChaseCars(param0); }
    static void Impl_AddNPCCharacterBonusMission(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, int32_t param6, const std::string& param7 = "") { GameCommands::AddNPCCharacterBonusMission(param0, param1, param2, param3, param4, param5, param6, param7); }
    static void Impl_AddBonusMissionNPCWaypoint(const std::string& param0, const std::string& param1) { GameCommands::AddBonusMissionNPCWaypoint(param0, param1); }
    static void Impl_AddAmbientCharacter(const std::string& param0, const std::string& param1, float param2) { GameCommands::AddAmbientCharacter(param0, param1, param2); }
    static void Impl_AddAmbientNPCWaypoint(const std::string& param0, const std::string& param1) { GameCommands::AddAmbientNPCWaypoint(param0, param1); }
    static void Impl_AddPurchaseCarReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, float param4, const std::string& param5) { GameCommands::AddPurchaseCarReward(param0, param1, param2, param3, param4, param5); }
    static void Impl_AddPurchaseCarNPCWaypoint(const std::string& param0, const std::string& param1) { GameCommands::AddPurchaseCarNPCWaypoint(param0, param1); }
    static void Impl_CreateTrafficGroup(int32_t param0) { GameCommands::CreateTrafficGroup(param0); }
    static void Impl_AddTrafficModel(const std::string& param0, int32_t param1, int32_t param2 = 0) { GameCommands::AddTrafficModel(param0, param1, param2); }
    static void Impl_CloseTrafficGroup(int32_t param0 = 0) { GameCommands::CloseTrafficGroup(param0); }
    static void Impl_CreatePedGroup(int32_t param0) { GameCommands::CreatePedGroup(param0); }
    static void Impl_AddPed(const std::string& param0, int32_t param1) { GameCommands::AddPed(param0, param1); }
    static void Impl_ClosePedGroup(int32_t param0 = 0) { GameCommands::ClosePedGroup(param0); }
    static void Impl_PreallocateActors(const std::string& param0, const std::string& param1) { GameCommands::PreallocateActors(param0, param1); }
    static void Impl_SetProjectileStats(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::SetProjectileStats(param0, param1, param2); }
    static void Impl_AddSpawnPointByLocatorScript(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5) { GameCommands::AddSpawnPointByLocatorScript(param0, param1, param2, param3, param4, param5); }
    static void Impl_AddBehaviour(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 = "", const std::string& param4 = "", const std::string& param5 = "", const std::string& param6 = "") { GameCommands::AddBehaviour(param0, param1, param2, param3, param4, param5, param6); }
    static void Impl_SetActorRotationSpeed(const std::string& param0, const std::string& param1) { GameCommands::SetActorRotationSpeed(param0, param1); }
    static void Impl_SetAnimatedCameraName(const std::string& param0) { GameCommands::SetAnimatedCameraName(param0); }
    static void Impl_SetAnimCamMulticontName(const std::string& param0) { GameCommands::SetAnimCamMulticontName(param0); }
    static void Impl_SetCoinFee(int32_t param0) { GameCommands::SetCoinFee(param0); }
    static void Impl_PutMFPlayerInCar(int32_t param0 = 0) { GameCommands::PutMFPlayerInCar(param0); }
    static void Impl_StartCountdown(const std::string& param0, const std::string& param1 = "") { GameCommands::StartCountdown(param0, param1); }
    static void Impl_AddToCountdownSequence(const std::string& param0, int32_t param1) { GameCommands::AddToCountdownSequence(param0, param1); }
    static void Impl_UseElapsedTime(int32_t param0 = 0) { GameCommands::UseElapsedTime(param0); }
    static void Impl_SetRaceEnteryFee(int32_t param0) { GameCommands::SetRaceEnteryFee(param0); }
    static void Impl_SetParTime(int32_t param0) { GameCommands::SetParTime(param0); }
    static void Impl_SetCondMinHealth(float param0) { GameCommands::SetCondMinHealth(param0); }
    static void Impl_SetCondTargetVehicle(const std::string& param0) { GameCommands::SetCondTargetVehicle(param0); }
    static void Impl_SetCondTime(int32_t param0) { GameCommands::SetCondTime(param0); }
    static void Impl_AddBonusMission(const std::string& param0) { GameCommands::AddBonusMission(param0); }
    static void Impl_AddTeleportDest(const std::string& param0, float param1, float param2, float param3, const std::string& param4) { GameCommands::AddTeleportDest(param0, param1, param2, param3, param4); }
    static void Impl_AddVehicleSelectInfo(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::AddVehicleSelectInfo(param0, param1, param2); }
    static void Impl_SuppressDriver(const std::string& param0) { GameCommands::SuppressDriver(param0); }
    static void Impl_SetBonusMissionDialoguePos(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { GameCommands::SetBonusMissionDialoguePos(param0, param1, param2, param3); }
    static void Impl_SetConversationCam(int32_t param0, const std::string& param1, const std::string& param2 = "") { GameCommands::SetConversationCam(param0, param1, param2); }
    static void Impl_ClearAmbientAnimations(const std::string& param0) { GameCommands::ClearAmbientAnimations(param0); }
    static void Impl_AddAmbientNpcAnimation(const std::string& param0, const std::string& param1 = "") { GameCommands::AddAmbientNpcAnimation(param0, param1); }
    static void Impl_AddAmbientPcAnimation(const std::string& param0, const std::string& param1 = "") { GameCommands::AddAmbientPcAnimation(param0, param1); }
    static void Impl_SetCoinDrawable(const std::string& param0) { GameCommands::SetCoinDrawable(param0); }
    static void Impl_AmbientAnimationRandomize(int32_t param0, int32_t param1) { GameCommands::AmbientAnimationRandomize(param0, param1); }
    static void Impl_TurnGotoDialogOff(int32_t param0 = 0) { GameCommands::TurnGotoDialogOff(param0); }
    static void Impl_SetCompletionDialog(const std::string& param0, const std::string& param1 = "") { GameCommands::SetCompletionDialog(param0, param1); }
    static void Impl_SetMissionResetPlayerOutCar(const std::string& param0, const std::string& param1) { GameCommands::SetMissionResetPlayerOutCar(param0, param1); }
    static void Impl_SetMissionStartCameraName(const std::string& param0) { GameCommands::SetMissionStartCameraName(param0); }
    static void Impl_SetMissionStartMulticontName(const std::string& param0) { GameCommands::SetMissionStartMulticontName(param0); }
    static void Impl_SetInitialWalk(const std::string& param0) { GameCommands::SetInitialWalk(param0); }
    static void Impl_SetDialoguePositions(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3 = 0) { GameCommands::SetDialoguePositions(param0, param1, param2, param3); }
    static void Impl_ActivateVehicle(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::ActivateVehicle(param0, param1, param2); }
    static void Impl_SetStageMusicAlwaysOn(int32_t param0 = 0) { GameCommands::SetStageMusicAlwaysOn(param0); }
    static void Impl_SetNumValidFailureHints(int32_t param0) { GameCommands::SetNumValidFailureHints(param0); }
    static void Impl_SetVehicleAIParams(const std::string& param0, int32_t param1, int32_t param2) { GameCommands::SetVehicleAIParams(param0, param1, param2); }
    static void Impl_StageStartMusicEvent(const std::string& param0) { GameCommands::StageStartMusicEvent(param0); }
    static void Impl_AllowMissionAbort(const std::string& param0) { GameCommands::AllowMissionAbort(param0); }
    static void Impl_MustActionTrigger(int32_t param0 = 0) { GameCommands::MustActionTrigger(param0); }
    static void Impl_SetStageAITargetCatchupParams(const std::string& param0, int32_t param1, int32_t param2) { GameCommands::SetStageAITargetCatchupParams(param0, param1, param2); }
    static void Impl_SetFollowDistances(int32_t param0, int32_t param1) { GameCommands::SetFollowDistances(param0, param1); }
    static void Impl_SetFadeOut(float param0) { GameCommands::SetFadeOut(param0); }
    static void Impl_StayInBlack(int32_t param0 = 0) { GameCommands::StayInBlack(param0); }
    static void Impl_AddStageCharacter(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { GameCommands::AddStageCharacter(param0, param1, param2, param3, param4); }
    static void Impl_SetDurationTime(float param0) { GameCommands::SetDurationTime(param0); }
    static void Impl_SetFMVInfo(const std::string& param0, const std::string& param1 = "") { GameCommands::SetFMVInfo(param0, param1); }
    static void Impl_SetForcedCar(int32_t param0 = 0) { GameCommands::SetForcedCar(param0); }
    static void Impl_SwapInDefaultCar(int32_t param0 = 0) { GameCommands::SwapInDefaultCar(param0); }
    static void Impl_SetSwapDefaultCarLocator(const std::string& param0) { GameCommands::SetSwapDefaultCarLocator(param0); }
    static void Impl_SetSwapForcedCarLocator(const std::string& param0) { GameCommands::SetSwapForcedCarLocator(param0); }
    static void Impl_SetSwapPlayerLocator(const std::string& param0) { GameCommands::SetSwapPlayerLocator(param0); }
    static void Impl_StreetRacePropsLoad(const std::string& param0) { GameCommands::StreetRacePropsLoad(param0); }
    static void Impl_StreetRacePropsUnload(const std::string& param0) { GameCommands::StreetRacePropsUnload(param0); }
    static void Impl_SetStageAIRaceCatchupParams(const std::string& param0, int32_t param1, float param2, float param3, float param4) { GameCommands::SetStageAIRaceCatchupParams(param0, param1, param2, param3, param4); }
    static void Impl_DisableHitAndRun(int32_t param0 = 0) { GameCommands::DisableHitAndRun(param0); }
    static void Impl_NoTrafficForStage(int32_t param0 = 0) { GameCommands::NoTrafficForStage(param0); }
    static void Impl_SetConditionPosition(int32_t param0) { GameCommands::SetConditionPosition(param0); }
    static void Impl_AddSafeZone(const std::string& param0, int32_t param1) { GameCommands::AddSafeZone(param0, param1); }
    static void Impl_AddGagBinding(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3, const std::string& param4) { GameCommands::AddGagBinding(param0, param1, param2, param3, param4); }
    static void Impl_SetPostLevelFMV(const std::string& param0) { GameCommands::SetPostLevelFMV(param0); }
    static void Impl_SetHitNRun(int32_t param0 = 0) { GameCommands::SetHitNRun(param0); }
    static void Impl_SetObjDistance(int32_t param0) { GameCommands::SetObjDistance(param0); }
    static void Impl_SetMusicState(const std::string& param0, const std::string& param1) { GameCommands::SetMusicState(param0, param1); }
    static void Impl_SetIrisWipe(float param0) { GameCommands::SetIrisWipe(param0); }
    static void Impl_RemoveDriver(const std::string& param0) { GameCommands::RemoveDriver(param0); }
    static void Impl_RemoveNPC(const std::string& param0) { GameCommands::RemoveNPC(param0); }
    static void Impl_AddDriver(const std::string& param0, const std::string& param1) { GameCommands::AddDriver(param0, param1); }
    static void Impl_SetCharacterToHide(const std::string& param0) { GameCommands::SetCharacterToHide(param0); }
    static void Impl_SetLevelOver(int32_t param0 = 0) { GameCommands::SetLevelOver(param0); }
    static void Impl_GagCheckCollCards(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { GameCommands::GagCheckCollCards(param0, param1, param2, param3, param4); }
    static void Impl_GagCheckMovie(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { GameCommands::GagCheckMovie(param0, param1, param2, param3); }
    static void Impl_GagSetSoundLoadDistances(int32_t param0, int32_t param1) { GameCommands::GagSetSoundLoadDistances(param0, param1); }
    static void Impl_BindCollectibleTo(int32_t param0, int32_t param1) { GameCommands::BindCollectibleTo(param0, param1); }
    static void Impl_AddShield(const std::string& param0, const std::string& param1) { GameCommands::AddShield(param0, param1); }
    static void Impl_SetStatepropShadow(const std::string& param0, const std::string& param1) { GameCommands::SetStatepropShadow(param0, param1); }
    static void Impl_AddFlyingActorByLocator(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { GameCommands::AddFlyingActorByLocator(param0, param1, param2, param3); }
    static void Impl_AddCollectibleStateProp(const std::string& param0, const std::string& param1, int32_t param2) { GameCommands::AddCollectibleStateProp(param0, param1, param2); }
    static void Impl_SetPickupTarget(const std::string& param0) { GameCommands::SetPickupTarget(param0); }
    static void Impl_SetObjTargetBoss(const std::string& param0) { GameCommands::SetObjTargetBoss(param0); }
    static void Impl_AllowRockOut(int32_t param0 = 0) { GameCommands::AllowRockOut(param0); }
    static void Impl_ShowHUD(const std::string& param0) { GameCommands::ShowHUD(param0); }
    static void Impl_SetGameOver(int32_t param0 = 0) { GameCommands::SetGameOver(param0); }
    static void Impl_GoToPsScreenWhenDone(int32_t param0 = 0) { GameCommands::GoToPsScreenWhenDone(param0); }
    static void Impl_SetMass(float param0) { GameCommands::SetMass(param0); }
    static void Impl_SetGasScale(float param0) { GameCommands::SetGasScale(param0); }
    static void Impl_SetSlipGasScale(float param0) { GameCommands::SetSlipGasScale(param0); }
    static void Impl_SetBrakeScale(float param0) { GameCommands::SetBrakeScale(param0); }
    static void Impl_SetTopSpeedKmh(float param0) { GameCommands::SetTopSpeedKmh(param0); }
    static void Impl_SetMaxWheelTurnAngle(float param0) { GameCommands::SetMaxWheelTurnAngle(param0); }
    static void Impl_SetHighSpeedSteeringDrop(float param0) { GameCommands::SetHighSpeedSteeringDrop(param0); }
    static void Impl_SetTireGrip(float param0) { GameCommands::SetTireGrip(param0); }
    static void Impl_SetNormalSteering(float param0) { GameCommands::SetNormalSteering(param0); }
    static void Impl_SetSlipSteering(float param0) { GameCommands::SetSlipSteering(param0); }
    static void Impl_SetEBrakeEffect(float param0) { GameCommands::SetEBrakeEffect(param0); }
    static void Impl_SetSlipSteeringNoEBrake(float param0) { GameCommands::SetSlipSteeringNoEBrake(param0); }
    static void Impl_SetSlipEffectNoEBrake(float param0) { GameCommands::SetSlipEffectNoEBrake(param0); }
    static void Impl_SetCMOffsetX(float param0) { GameCommands::SetCMOffsetX(param0); }
    static void Impl_SetCMOffsetY(float param0) { GameCommands::SetCMOffsetY(param0); }
    static void Impl_SetCMOffsetZ(float param0) { GameCommands::SetCMOffsetZ(param0); }
    static void Impl_SetSuspensionLimit(float param0) { GameCommands::SetSuspensionLimit(param0); }
    static void Impl_SetSpringK(float param0) { GameCommands::SetSpringK(param0); }
    static void Impl_SetDamperC(float param0) { GameCommands::SetDamperC(param0); }
    static void Impl_SetSuspensionYOffset(float param0) { GameCommands::SetSuspensionYOffset(param0); }
    static void Impl_SetHitPoints(float param0) { GameCommands::SetHitPoints(param0); }
    static void Impl_SetBurnoutRange(float param0) { GameCommands::SetBurnoutRange(param0); }
    static void Impl_SetMaxSpeedBurstTime(float param0) { GameCommands::SetMaxSpeedBurstTime(param0); }
    static void Impl_SetDonutTorque(float param0) { GameCommands::SetDonutTorque(param0); }
    static void Impl_SetWeebleOffset(float param0) { GameCommands::SetWeebleOffset(param0); }
    static void Impl_SetWheelieRange(float param0) { GameCommands::SetWheelieRange(param0); }
    static void Impl_SetWheelieOffsetY(float param0) { GameCommands::SetWheelieOffsetY(param0); }
    static void Impl_SetWheelieOffsetZ(float param0) { GameCommands::SetWheelieOffsetZ(param0); }
    static void Impl_SetShadowAdjustments(float param0, float param1, float param2, float param3, float param4, float param5, float param6, float param7) { GameCommands::SetShadowAdjustments(param0, param1, param2, param3, param4, param5, param6, param7); }
    static void Impl_SetCharactersVisible(int32_t param0) { GameCommands::SetCharactersVisible(param0); }
    static void Impl_SetIrisTransition(int32_t param0) { GameCommands::SetIrisTransition(param0); }
    static void Impl_SetCharacterScale(float param0) { GameCommands::SetCharacterScale(param0); }
    static void Impl_SetGamblingOdds(float param0) { GameCommands::SetGamblingOdds(param0); }
    static void Impl_SetDriver(const std::string& param0) { GameCommands::SetDriver(param0); }
    static void Impl_SetHasDoors(int32_t param0) { GameCommands::SetHasDoors(param0); }
    static void Impl_SetShininess(float param0) { GameCommands::SetShininess(param0); }
    static void Impl_SetHighRoof(int32_t param0) { GameCommands::SetHighRoof(param0); }
    static void Impl_SetHighSpeedGasScale(float param0) { GameCommands::SetHighSpeedGasScale(param0); }
    static void Impl_SetGasScaleSpeedThreshold(float param0) { GameCommands::SetGasScaleSpeedThreshold(param0); }
    static void Impl_SetAllowSeatSlide(int32_t param0) { GameCommands::SetAllowSeatSlide(param0); }
    static void Impl_ClearVehicleSelectInfo(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "") { GameCommands::ClearVehicleSelectInfo(param0, param1, param2); }
    static void Impl_AddFlyingActor(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { GameCommands::AddFlyingActor(param0, param1, param2, param3, param4); }
    static void Impl_SetCollisionAttributes(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { GameCommands::SetCollisionAttributes(param0, param1, param2, param3); }
    static void Impl_AddSpawnPoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, const std::string& param6, const std::string& param7) { GameCommands::AddSpawnPoint(param0, param1, param2, param3, param4, param5, param6, param7); }
    static void Impl_GagSetWeight(const std::string& param0) { GameCommands::GagSetWeight(param0); }
    static void Impl_GagSetLoadDistances(const std::string& param0, const std::string& param1) { GameCommands::GagSetLoadDistances(param0, param1); }
    static void Impl_SetTotalWasps(const std::string& param0, const std::string& param1) { GameCommands::SetTotalWasps(param0, param1); }
    static void Impl_AddGlobalProp(const std::string& param0) { GameCommands::AddGlobalProp(param0); }
    static void Impl_EnableHitAndRun(const std::string& param0 = "") { GameCommands::EnableHitAndRun(param0); }
    static void Impl_SetHitAndRunMeter(const std::string& param0) { GameCommands::SetHitAndRunMeter(param0); }
    static void Impl_SetChaseSpawnRate(const std::string& param0, const std::string& param1) { GameCommands::SetChaseSpawnRate(param0, param1); }
    static void Impl_KillAllChaseAI(const std::string& param0) { GameCommands::KillAllChaseAI(param0); }
    static void Impl_ResetHitAndRun(const std::string& param0 = "") { GameCommands::ResetHitAndRun(param0); }
    static void Impl_SetHitAndRunDecayInterior(const std::string& param0) { GameCommands::SetHitAndRunDecayInterior(param0); }
    static void Impl_SetMissionNameIndex(const std::string& param0) { GameCommands::SetMissionNameIndex(param0); }
    static void Impl_AddBonusObjective(const std::string& param0, const std::string& param1 = "") { GameCommands::AddBonusObjective(param0, param1); }
    static void Impl_AttachStatePropCollectible(const std::string& param0, const std::string& param1) { GameCommands::AttachStatePropCollectible(param0, param1); }
    static void Impl_MoveStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::MoveStageVehicle(param0, param1, param2); }
    static void Impl_SetStageCamera(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::SetStageCamera(param0, param1, param2); }
    static void Impl_SetBonusMissionStart(const std::string& param0 = "") { GameCommands::SetBonusMissionStart(param0); }
    static void Impl_PlacePlayerAtLocatorName(const std::string& param0) { GameCommands::PlacePlayerAtLocatorName(param0); }
    static void Impl_msPlacePlayerCarAtLocatorName(const std::string& param0) { GameCommands::msPlacePlayerCarAtLocatorName(param0); }
    static void Impl_ClearTrafficForStage(const std::string& param0 = "") { GameCommands::ClearTrafficForStage(param0); }
    static void Impl_SetStageAIEvadeCatchupParams(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::SetStageAIEvadeCatchupParams(param0, param1, param2); }
    static void Impl_AllowUserDump(const std::string& param0 = "") { GameCommands::AllowUserDump(param0); }
    static void Impl_SetVehicleToLoad(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::SetVehicleToLoad(param0, param1, param2); }
    static void Impl_SetConversationCamName(const std::string& param0) { GameCommands::SetConversationCamName(param0); }
    static void Impl_SetConversationCamPcName(const std::string& param0) { GameCommands::SetConversationCamPcName(param0); }
    static void Impl_SetConversationCamNpcName(const std::string& param0) { GameCommands::SetConversationCamNpcName(param0); }
    static void Impl_SetConversationCamDistance(const std::string& param0, const std::string& param1) { GameCommands::SetConversationCamDistance(param0, param1); }
    static void Impl_CharacterIsChild(const std::string& param0) { GameCommands::CharacterIsChild(param0); }
    static void Impl_SetCarStartCamera(const std::string& param0) { GameCommands::SetCarStartCamera(param0); }
    static void Impl_SetPlayerCarName(const std::string& param0, const std::string& param1) { GameCommands::SetPlayerCarName(param0, param1); }
    static void Impl_SetRespawnRate(const std::string& param0, const std::string& param1) { GameCommands::SetRespawnRate(param0, param1); }
    static void Impl_ActivateTrigger(const std::string& param0) { GameCommands::ActivateTrigger(param0); }
    static void Impl_DeactivateTrigger(const std::string& param0) { GameCommands::DeactivateTrigger(param0); }
    static void Impl_CreateAnimPhysObject(const std::string& param0, const std::string& param1) { GameCommands::CreateAnimPhysObject(param0, param1); }
    static void Impl_CreateActionEventTrigger(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { GameCommands::CreateActionEventTrigger(param0, param1, param2, param3, param4); }
    static void Impl_LinkActionToObjectJoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { GameCommands::LinkActionToObjectJoint(param0, param1, param2, param3, param4); }
    static void Impl_LinkActionToObject(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { GameCommands::LinkActionToObject(param0, param1, param2, param3, param4); }
    static void Impl_SetCharacterPosition(const std::string& param0, const std::string& param1, const std::string& param2) { GameCommands::SetCharacterPosition(param0, param1, param2); }
    static void Impl_ResetCharacter(const std::string& param0, const std::string& param1) { GameCommands::ResetCharacter(param0, param1); }

    static bool Command_LoadP3DFile(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_LoadP3DFile(param0, param1);
        return true;
    }

    static bool Command_SetParticleTexture(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        const auto& param1 = splits[1];

        Impl_SetParticleTexture(param0, param1);
        return true;
    }

    static bool Command_BindReward(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        int32_t param4;
        if (!Commands::StringToInt(splits[4], param4)) return false;
        int32_t param5 = 0;
        if (numParams > 5)
            if (!Commands::StringToInt(splits[5], param5)) return false;
        const auto& param6 = (numParams > 6) ? splits[6] : "";

        Impl_BindReward(param0, param1, param2, param3, param4, param5, param6);
        return true;
    }

    static bool Command_SetCarAttributes(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        float param1;
        if (!Commands::StringToFloat(splits[1], param1)) return false;
        float param2;
        if (!Commands::StringToFloat(splits[2], param2)) return false;
        float param3;
        if (!Commands::StringToFloat(splits[3], param3)) return false;
        float param4;
        if (!Commands::StringToFloat(splits[4], param4)) return false;

        Impl_SetCarAttributes(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_SetTotalGags(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_SetTotalGags(param0, param1);
        return true;
    }

    static bool Command_SelectMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SelectMission(param0);
        return true;
    }

    static bool Command_SetMissionResetPlayerInCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetMissionResetPlayerInCar(param0);
        return true;
    }

    static bool Command_SetDynaLoadData(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_SetDynaLoadData(param0, param1);
        return true;
    }

    static bool Command_UsePedGroup(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_UsePedGroup(param0);
        return true;
    }

    static bool Command_AddStage(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";
        const auto& param1 = (numParams > 1) ? splits[1] : "";
        const auto& param2 = (numParams > 2) ? splits[2] : "";

        Impl_AddStage(param0, param1, param2);
        return true;
    }

    static bool Command_SetPresentationBitmap(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetPresentationBitmap(param0);
        return true;
    }

    static bool Command_SetStageMessageIndex(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_SetStageMessageIndex(param0, param1);
        return true;
    }

    static bool Command_AddObjective(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";
        const auto& param2 = (numParams > 2) ? splits[2] : "";

        Impl_AddObjective(param0, param1, param2);
        return true;
    }

    static bool Command_SetObjTargetVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetObjTargetVehicle(param0);
        return true;
    }

    static bool Command_CloseObjective(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CloseObjective(param0);
        return true;
    }

    static bool Command_CloseStage(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CloseStage(param0);
        return true;
    }

    static bool Command_RESET_TO_HERE(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_RESET_TO_HERE(param0);
        return true;
    }

    static bool Command_SetHUDIcon(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetHUDIcon(param0);
        return true;
    }

    static bool Command_AddCollectible(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";
        const auto& param2 = (numParams > 2) ? splits[2] : "";
        const auto& param3 = (numParams > 3) ? splits[3] : "";

        Impl_AddCollectible(param0, param1, param2, param3);
        return true;
    }

    static bool Command_SetStageTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetStageTime(param0);
        return true;
    }

    static bool Command_AddCondition(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_AddCondition(param0, param1);
        return true;
    }

    static bool Command_CloseCondition(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CloseCondition(param0);
        return true;
    }

    static bool Command_ShowStageComplete(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_ShowStageComplete(param0);
        return true;
    }

    static bool Command_AddNPC(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = (numParams > 2) ? splits[2] : "";

        Impl_AddNPC(param0, param1, param2);
        return true;
    }

    static bool Command_SetDestination(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_SetDestination(param0, param1);
        return true;
    }

    static bool Command_SetCollectibleEffect(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetCollectibleEffect(param0);
        return true;
    }

    static bool Command_AddStageTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_AddStageTime(param0);
        return true;
    }

    static bool Command_AddObjectiveNPCWaypoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddObjectiveNPCWaypoint(param0, param1);
        return true;
    }

    static bool Command_SetTalkToTarget(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        int32_t param1 = 0;
        if (numParams > 1)
            if (!Commands::StringToInt(splits[1], param1)) return false;
        float param2 = 0.0f;
        if (numParams > 2)
            if (!Commands::StringToFloat(splits[2], param2)) return false;
        const auto& param3 = (numParams > 3) ? splits[3] : "";

        Impl_SetTalkToTarget(param0, param1, param2, param3);
        return true;
    }

    static bool Command_SetDialogueInfo(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 4) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        int32_t param3;
        if (!Commands::StringToInt(splits[3], param3)) return false;

        Impl_SetDialogueInfo(param0, param1, param2, param3);
        return true;
    }

    static bool Command_SetCamBestSide(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_SetCamBestSide(param0, param1);
        return true;
    }

    static bool Command_CloseMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CloseMission(param0);
        return true;
    }

    static bool Command_PlacePlayerCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_PlacePlayerCar(param0, param1);
        return true;
    }

    static bool Command_SetMaxTraffic(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetMaxTraffic(param0);
        return true;
    }

    static bool Command_AddStageVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 4) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = (numParams > 4) ? splits[4] : "";

        Impl_AddStageVehicle(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_AddStageWaypoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_AddStageWaypoint(param0);
        return true;
    }

    static bool Command_SetRaceLaps(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetRaceLaps(param0);
        return true;
    }

    static bool Command_SetDemoLoopTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int64_t param0;
        if (!Commands::StringToInt64(splits[0], param0)) return false;

        Impl_SetDemoLoopTime(param0);
        return true;
    }

    static bool Command_AddStageMusicChange(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_AddStageMusicChange(param0);
        return true;
    }

    static bool Command_LoadDisposableCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_LoadDisposableCar(param0, param1, param2);
        return true;
    }

    static bool Command_AddMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_AddMission(param0);
        return true;
    }

    static bool Command_ClearGagBindings(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_ClearGagBindings(param0);
        return true;
    }

    static bool Command_GagBegin(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_GagBegin(param0);
        return true;
    }

    static bool Command_GagSetInterior(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_GagSetInterior(param0);
        return true;
    }

    static bool Command_GagSetCycle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_GagSetCycle(param0);
        return true;
    }

    static bool Command_GagSetPosition(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        switch (numParams)
        {
            case 1:
            {
                const auto& param0 = splits[0];

                Impl_GagSetPosition(param0);
                return true;
            }
            case 3:
            {
                float param0; if (!Commands::StringToFloat(splits[0], param0)) return false;
                float param1; if (!Commands::StringToFloat(splits[1], param1)) return false;
                float param2; if (!Commands::StringToFloat(splits[2], param2)) return false;

                Impl_GagSetPosition(param0, param1, param2);
                return true;
            }
        }

        return false;
    }

    static bool Command_GagSetRandom(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagSetRandom(param0);
        return true;
    }

    static bool Command_GagSetSound(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_GagSetSound(param0);
        return true;
    }

    static bool Command_GagSetTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        switch (numParams)
        {
            case 3:
            {
                const auto& param0 = splits[0];
                const auto& param1 = splits[1];
                float param2; if (!Commands::StringToFloat(splits[2], param2)) return false;

                Impl_GagSetTrigger(param0, param1, param2);
                return true;
            }
            case 5:
            {
                const auto& param0 = splits[0];
                float param1; if (!Commands::StringToFloat(splits[1], param1)) return false;
                float param2; if (!Commands::StringToFloat(splits[2], param2)) return false;
                float param3; if (!Commands::StringToFloat(splits[3], param3)) return false;
                float param4; if (!Commands::StringToFloat(splits[4], param4)) return false;

                Impl_GagSetTrigger(param0, param1, param2, param3, param4);
                return true;
            }
        }

        return false;
    }

    static bool Command_GagEnd(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagEnd(param0);
        return true;
    }

    static bool Command_GagSetSparkle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagSetSparkle(param0);
        return true;
    }

    static bool Command_GagSetPersist(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagSetPersist(param0);
        return true;
    }

    static bool Command_GagSetCoins(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        float param1;
        if (!Commands::StringToFloat(splits[1], param1)) return false;

        Impl_GagSetCoins(param0, param1);
        return true;
    }

    static bool Command_GagSetAnimCollision(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagSetAnimCollision(param0);
        return true;
    }

    static bool Command_GagSetIntro(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagSetIntro(param0);
        return true;
    }

    static bool Command_GagSetOutro(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GagSetOutro(param0);
        return true;
    }

    static bool Command_GagSetCameraShake(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;
        float param2;
        if (!Commands::StringToFloat(splits[2], param2)) return false;

        Impl_GagSetCameraShake(param0, param1, param2);
        return true;
    }

    static bool Command_GagPlayFMV(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_GagPlayFMV(param0);
        return true;
    }

    static bool Command_EnableTutorialMode(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_EnableTutorialMode(param0);
        return true;
    }

    static bool Command_InitLevelPlayerVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = (numParams > 3) ? splits[3] : "";

        Impl_InitLevelPlayerVehicle(param0, param1, param2, param3);
        return true;
    }

    static bool Command_AddCharacter(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddCharacter(param0, param1);
        return true;
    }

    static bool Command_CreateChaseManager(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        int32_t param2;
        if (!Commands::StringToInt(splits[2], param2)) return false;

        Impl_CreateChaseManager(param0, param1, param2);
        return true;
    }

    static bool Command_SetHitAndRunDecay(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetHitAndRunDecay(param0);
        return true;
    }

    static bool Command_SetNumChaseCars(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetNumChaseCars(param0);
        return true;
    }

    static bool Command_AddNPCCharacterBonusMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 7) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];
        const auto& param5 = splits[5];
        int32_t param6;
        if (!Commands::StringToInt(splits[6], param6)) return false;
        const auto& param7 = (numParams > 7) ? splits[7] : "";

        Impl_AddNPCCharacterBonusMission(param0, param1, param2, param3, param4, param5, param6, param7);
        return true;
    }

    static bool Command_AddBonusMissionNPCWaypoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddBonusMissionNPCWaypoint(param0, param1);
        return true;
    }

    static bool Command_AddAmbientCharacter(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        float param2;
        if (!Commands::StringToFloat(splits[2], param2)) return false;

        Impl_AddAmbientCharacter(param0, param1, param2);
        return true;
    }

    static bool Command_AddAmbientNPCWaypoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddAmbientNPCWaypoint(param0, param1);
        return true;
    }

    static bool Command_AddPurchaseCarReward(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 6) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        float param4;
        if (!Commands::StringToFloat(splits[4], param4)) return false;
        const auto& param5 = splits[5];

        Impl_AddPurchaseCarReward(param0, param1, param2, param3, param4, param5);
        return true;
    }

    static bool Command_AddPurchaseCarNPCWaypoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddPurchaseCarNPCWaypoint(param0, param1);
        return true;
    }

    static bool Command_CreateTrafficGroup(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CreateTrafficGroup(param0);
        return true;
    }

    static bool Command_AddTrafficModel(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;
        int32_t param2 = 0;
        if (numParams > 2)
            if (!Commands::StringToInt(splits[2], param2)) return false;

        Impl_AddTrafficModel(param0, param1, param2);
        return true;
    }

    static bool Command_CloseTrafficGroup(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CloseTrafficGroup(param0);
        return true;
    }

    static bool Command_CreatePedGroup(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_CreatePedGroup(param0);
        return true;
    }

    static bool Command_AddPed(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_AddPed(param0, param1);
        return true;
    }

    static bool Command_ClosePedGroup(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_ClosePedGroup(param0);
        return true;
    }

    static bool Command_PreallocateActors(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_PreallocateActors(param0, param1);
        return true;
    }

    static bool Command_SetProjectileStats(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_SetProjectileStats(param0, param1, param2);
        return true;
    }

    static bool Command_AddSpawnPointByLocatorScript(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 6) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];
        const auto& param5 = splits[5];

        Impl_AddSpawnPointByLocatorScript(param0, param1, param2, param3, param4, param5);
        return true;
    }

    static bool Command_AddBehaviour(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = (numParams > 3) ? splits[3] : "";
        const auto& param4 = (numParams > 4) ? splits[4] : "";
        const auto& param5 = (numParams > 5) ? splits[5] : "";
        const auto& param6 = (numParams > 6) ? splits[6] : "";

        Impl_AddBehaviour(param0, param1, param2, param3, param4, param5, param6);
        return true;
    }

    static bool Command_SetActorRotationSpeed(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetActorRotationSpeed(param0, param1);
        return true;
    }

    static bool Command_SetAnimatedCameraName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetAnimatedCameraName(param0);
        return true;
    }

    static bool Command_SetAnimCamMulticontName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetAnimCamMulticontName(param0);
        return true;
    }

    static bool Command_SetCoinFee(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetCoinFee(param0);
        return true;
    }

    static bool Command_PutMFPlayerInCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_PutMFPlayerInCar(param0);
        return true;
    }

    static bool Command_StartCountdown(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_StartCountdown(param0, param1);
        return true;
    }

    static bool Command_AddToCountdownSequence(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_AddToCountdownSequence(param0, param1);
        return true;
    }

    static bool Command_UseElapsedTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_UseElapsedTime(param0);
        return true;
    }

    static bool Command_SetRaceEnteryFee(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetRaceEnteryFee(param0);
        return true;
    }

    static bool Command_SetParTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetParTime(param0);
        return true;
    }

    static bool Command_SetCondMinHealth(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetCondMinHealth(param0);
        return true;
    }

    static bool Command_SetCondTargetVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetCondTargetVehicle(param0);
        return true;
    }

    static bool Command_SetCondTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetCondTime(param0);
        return true;
    }

    static bool Command_AddBonusMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_AddBonusMission(param0);
        return true;
    }

    static bool Command_AddTeleportDest(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        float param1;
        if (!Commands::StringToFloat(splits[1], param1)) return false;
        float param2;
        if (!Commands::StringToFloat(splits[2], param2)) return false;
        float param3;
        if (!Commands::StringToFloat(splits[3], param3)) return false;
        const auto& param4 = splits[4];

        Impl_AddTeleportDest(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_AddVehicleSelectInfo(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_AddVehicleSelectInfo(param0, param1, param2);
        return true;
    }

    static bool Command_SuppressDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SuppressDriver(param0);
        return true;
    }

    static bool Command_SetBonusMissionDialoguePos(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 4) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];

        Impl_SetBonusMissionDialoguePos(param0, param1, param2, param3);
        return true;
    }

    static bool Command_SetConversationCam(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        const auto& param1 = splits[1];
        const auto& param2 = (numParams > 2) ? splits[2] : "";

        Impl_SetConversationCam(param0, param1, param2);
        return true;
    }

    static bool Command_ClearAmbientAnimations(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_ClearAmbientAnimations(param0);
        return true;
    }

    static bool Command_AddAmbientNpcAnimation(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_AddAmbientNpcAnimation(param0, param1);
        return true;
    }

    static bool Command_AddAmbientPcAnimation(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_AddAmbientPcAnimation(param0, param1);
        return true;
    }

    static bool Command_SetCoinDrawable(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetCoinDrawable(param0);
        return true;
    }

    static bool Command_AmbientAnimationRandomize(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_AmbientAnimationRandomize(param0, param1);
        return true;
    }

    static bool Command_TurnGotoDialogOff(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_TurnGotoDialogOff(param0);
        return true;
    }

    static bool Command_SetCompletionDialog(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_SetCompletionDialog(param0, param1);
        return true;
    }

    static bool Command_SetMissionResetPlayerOutCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetMissionResetPlayerOutCar(param0, param1);
        return true;
    }

    static bool Command_SetMissionStartCameraName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetMissionStartCameraName(param0);
        return true;
    }

    static bool Command_SetMissionStartMulticontName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetMissionStartMulticontName(param0);
        return true;
    }

    static bool Command_SetInitialWalk(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetInitialWalk(param0);
        return true;
    }

    static bool Command_SetDialoguePositions(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        int32_t param3 = 0;
        if (numParams > 3)
            if (!Commands::StringToInt(splits[3], param3)) return false;

        Impl_SetDialoguePositions(param0, param1, param2, param3);
        return true;
    }

    static bool Command_ActivateVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_ActivateVehicle(param0, param1, param2);
        return true;
    }

    static bool Command_SetStageMusicAlwaysOn(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetStageMusicAlwaysOn(param0);
        return true;
    }

    static bool Command_SetNumValidFailureHints(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetNumValidFailureHints(param0);
        return true;
    }

    static bool Command_SetVehicleAIParams(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;
        int32_t param2;
        if (!Commands::StringToInt(splits[2], param2)) return false;

        Impl_SetVehicleAIParams(param0, param1, param2);
        return true;
    }

    static bool Command_StageStartMusicEvent(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_StageStartMusicEvent(param0);
        return true;
    }

    static bool Command_AllowMissionAbort(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_AllowMissionAbort(param0);
        return true;
    }

    static bool Command_MustActionTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_MustActionTrigger(param0);
        return true;
    }

    static bool Command_SetStageAITargetCatchupParams(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;
        int32_t param2;
        if (!Commands::StringToInt(splits[2], param2)) return false;

        Impl_SetStageAITargetCatchupParams(param0, param1, param2);
        return true;
    }

    static bool Command_SetFollowDistances(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_SetFollowDistances(param0, param1);
        return true;
    }

    static bool Command_SetFadeOut(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetFadeOut(param0);
        return true;
    }

    static bool Command_StayInBlack(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_StayInBlack(param0);
        return true;
    }

    static bool Command_AddStageCharacter(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];

        Impl_AddStageCharacter(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_SetDurationTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetDurationTime(param0);
        return true;
    }

    static bool Command_SetFMVInfo(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_SetFMVInfo(param0, param1);
        return true;
    }

    static bool Command_SetForcedCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetForcedCar(param0);
        return true;
    }

    static bool Command_SwapInDefaultCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SwapInDefaultCar(param0);
        return true;
    }

    static bool Command_SetSwapDefaultCarLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetSwapDefaultCarLocator(param0);
        return true;
    }

    static bool Command_SetSwapForcedCarLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetSwapForcedCarLocator(param0);
        return true;
    }

    static bool Command_SetSwapPlayerLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetSwapPlayerLocator(param0);
        return true;
    }

    static bool Command_StreetRacePropsLoad(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_StreetRacePropsLoad(param0);
        return true;
    }

    static bool Command_StreetRacePropsUnload(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_StreetRacePropsUnload(param0);
        return true;
    }

    static bool Command_SetStageAIRaceCatchupParams(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;
        float param2;
        if (!Commands::StringToFloat(splits[2], param2)) return false;
        float param3;
        if (!Commands::StringToFloat(splits[3], param3)) return false;
        float param4;
        if (!Commands::StringToFloat(splits[4], param4)) return false;

        Impl_SetStageAIRaceCatchupParams(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_DisableHitAndRun(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_DisableHitAndRun(param0);
        return true;
    }

    static bool Command_NoTrafficForStage(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_NoTrafficForStage(param0);
        return true;
    }

    static bool Command_SetConditionPosition(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetConditionPosition(param0);
        return true;
    }

    static bool Command_AddSafeZone(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_AddSafeZone(param0, param1);
        return true;
    }

    static bool Command_AddGagBinding(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        int32_t param3;
        if (!Commands::StringToInt(splits[3], param3)) return false;
        const auto& param4 = splits[4];

        Impl_AddGagBinding(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_SetPostLevelFMV(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetPostLevelFMV(param0);
        return true;
    }

    static bool Command_SetHitNRun(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetHitNRun(param0);
        return true;
    }

    static bool Command_SetObjDistance(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetObjDistance(param0);
        return true;
    }

    static bool Command_SetMusicState(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetMusicState(param0, param1);
        return true;
    }

    static bool Command_SetIrisWipe(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetIrisWipe(param0);
        return true;
    }

    static bool Command_RemoveDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_RemoveDriver(param0);
        return true;
    }

    static bool Command_RemoveNPC(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_RemoveNPC(param0);
        return true;
    }

    static bool Command_AddDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddDriver(param0, param1);
        return true;
    }

    static bool Command_SetCharacterToHide(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetCharacterToHide(param0);
        return true;
    }

    static bool Command_SetLevelOver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetLevelOver(param0);
        return true;
    }

    static bool Command_GagCheckCollCards(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];

        Impl_GagCheckCollCards(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_GagCheckMovie(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 4) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];

        Impl_GagCheckMovie(param0, param1, param2, param3);
        return true;
    }

    static bool Command_GagSetSoundLoadDistances(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_GagSetSoundLoadDistances(param0, param1);
        return true;
    }

    static bool Command_BindCollectibleTo(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;
        int32_t param1;
        if (!Commands::StringToInt(splits[1], param1)) return false;

        Impl_BindCollectibleTo(param0, param1);
        return true;
    }

    static bool Command_AddShield(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AddShield(param0, param1);
        return true;
    }

    static bool Command_SetStatepropShadow(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetStatepropShadow(param0, param1);
        return true;
    }

    static bool Command_AddFlyingActorByLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 4) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];

        Impl_AddFlyingActorByLocator(param0, param1, param2, param3);
        return true;
    }

    static bool Command_AddCollectibleStateProp(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        int32_t param2;
        if (!Commands::StringToInt(splits[2], param2)) return false;

        Impl_AddCollectibleStateProp(param0, param1, param2);
        return true;
    }

    static bool Command_SetPickupTarget(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetPickupTarget(param0);
        return true;
    }

    static bool Command_SetObjTargetBoss(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetObjTargetBoss(param0);
        return true;
    }

    static bool Command_AllowRockOut(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_AllowRockOut(param0);
        return true;
    }

    static bool Command_ShowHUD(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_ShowHUD(param0);
        return true;
    }

    static bool Command_SetGameOver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetGameOver(param0);
        return true;
    }

    static bool Command_GoToPsScreenWhenDone(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        int32_t param0 = 0;
        if (numParams > 0)
            if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_GoToPsScreenWhenDone(param0);
        return true;
    }

    static bool Command_SetMass(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetMass(param0);
        return true;
    }

    static bool Command_SetGasScale(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetGasScale(param0);
        return true;
    }

    static bool Command_SetSlipGasScale(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSlipGasScale(param0);
        return true;
    }

    static bool Command_SetBrakeScale(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetBrakeScale(param0);
        return true;
    }

    static bool Command_SetTopSpeedKmh(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetTopSpeedKmh(param0);
        return true;
    }

    static bool Command_SetMaxWheelTurnAngle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetMaxWheelTurnAngle(param0);
        return true;
    }

    static bool Command_SetHighSpeedSteeringDrop(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetHighSpeedSteeringDrop(param0);
        return true;
    }

    static bool Command_SetTireGrip(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetTireGrip(param0);
        return true;
    }

    static bool Command_SetNormalSteering(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetNormalSteering(param0);
        return true;
    }

    static bool Command_SetSlipSteering(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSlipSteering(param0);
        return true;
    }

    static bool Command_SetEBrakeEffect(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetEBrakeEffect(param0);
        return true;
    }

    static bool Command_SetSlipSteeringNoEBrake(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSlipSteeringNoEBrake(param0);
        return true;
    }

    static bool Command_SetSlipEffectNoEBrake(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSlipEffectNoEBrake(param0);
        return true;
    }

    static bool Command_SetCMOffsetX(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetCMOffsetX(param0);
        return true;
    }

    static bool Command_SetCMOffsetY(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetCMOffsetY(param0);
        return true;
    }

    static bool Command_SetCMOffsetZ(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetCMOffsetZ(param0);
        return true;
    }

    static bool Command_SetSuspensionLimit(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSuspensionLimit(param0);
        return true;
    }

    static bool Command_SetSpringK(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSpringK(param0);
        return true;
    }

    static bool Command_SetDamperC(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetDamperC(param0);
        return true;
    }

    static bool Command_SetSuspensionYOffset(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetSuspensionYOffset(param0);
        return true;
    }

    static bool Command_SetHitPoints(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetHitPoints(param0);
        return true;
    }

    static bool Command_SetBurnoutRange(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetBurnoutRange(param0);
        return true;
    }

    static bool Command_SetMaxSpeedBurstTime(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetMaxSpeedBurstTime(param0);
        return true;
    }

    static bool Command_SetDonutTorque(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetDonutTorque(param0);
        return true;
    }

    static bool Command_SetWeebleOffset(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetWeebleOffset(param0);
        return true;
    }

    static bool Command_SetWheelieRange(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetWheelieRange(param0);
        return true;
    }

    static bool Command_SetWheelieOffsetY(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetWheelieOffsetY(param0);
        return true;
    }

    static bool Command_SetWheelieOffsetZ(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetWheelieOffsetZ(param0);
        return true;
    }

    static bool Command_SetShadowAdjustments(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 8) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;
        float param1;
        if (!Commands::StringToFloat(splits[1], param1)) return false;
        float param2;
        if (!Commands::StringToFloat(splits[2], param2)) return false;
        float param3;
        if (!Commands::StringToFloat(splits[3], param3)) return false;
        float param4;
        if (!Commands::StringToFloat(splits[4], param4)) return false;
        float param5;
        if (!Commands::StringToFloat(splits[5], param5)) return false;
        float param6;
        if (!Commands::StringToFloat(splits[6], param6)) return false;
        float param7;
        if (!Commands::StringToFloat(splits[7], param7)) return false;

        Impl_SetShadowAdjustments(param0, param1, param2, param3, param4, param5, param6, param7);
        return true;
    }

    static bool Command_SetCharactersVisible(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetCharactersVisible(param0);
        return true;
    }

    static bool Command_SetIrisTransition(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetIrisTransition(param0);
        return true;
    }

    static bool Command_SetCharacterScale(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetCharacterScale(param0);
        return true;
    }

    static bool Command_SetGamblingOdds(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetGamblingOdds(param0);
        return true;
    }

    static bool Command_SetDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetDriver(param0);
        return true;
    }

    static bool Command_SetHasDoors(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetHasDoors(param0);
        return true;
    }

    static bool Command_SetShininess(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetShininess(param0);
        return true;
    }

    static bool Command_SetHighRoof(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetHighRoof(param0);
        return true;
    }

    static bool Command_SetHighSpeedGasScale(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetHighSpeedGasScale(param0);
        return true;
    }

    static bool Command_SetGasScaleSpeedThreshold(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        float param0;
        if (!Commands::StringToFloat(splits[0], param0)) return false;

        Impl_SetGasScaleSpeedThreshold(param0);
        return true;
    }

    static bool Command_SetAllowSeatSlide(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        int32_t param0;
        if (!Commands::StringToInt(splits[0], param0)) return false;

        Impl_SetAllowSeatSlide(param0);
        return true;
    }

    static bool Command_ClearVehicleSelectInfo(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";
        const auto& param2 = (numParams > 2) ? splits[2] : "";

        Impl_ClearVehicleSelectInfo(param0, param1, param2);
        return true;
    }

    static bool Command_AddFlyingActor(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];

        Impl_AddFlyingActor(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_SetCollisionAttributes(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 4) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];

        Impl_SetCollisionAttributes(param0, param1, param2, param3);
        return true;
    }

    static bool Command_AddSpawnPoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 8) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];
        const auto& param5 = splits[5];
        const auto& param6 = splits[6];
        const auto& param7 = splits[7];

        Impl_AddSpawnPoint(param0, param1, param2, param3, param4, param5, param6, param7);
        return true;
    }

    static bool Command_GagSetWeight(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_GagSetWeight(param0);
        return true;
    }

    static bool Command_GagSetLoadDistances(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_GagSetLoadDistances(param0, param1);
        return true;
    }

    static bool Command_SetTotalWasps(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetTotalWasps(param0, param1);
        return true;
    }

    static bool Command_AddGlobalProp(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_AddGlobalProp(param0);
        return true;
    }

    static bool Command_EnableHitAndRun(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        Impl_EnableHitAndRun(param0);
        return true;
    }

    static bool Command_SetHitAndRunMeter(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetHitAndRunMeter(param0);
        return true;
    }

    static bool Command_SetChaseSpawnRate(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetChaseSpawnRate(param0, param1);
        return true;
    }

    static bool Command_KillAllChaseAI(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_KillAllChaseAI(param0);
        return true;
    }

    static bool Command_ResetHitAndRun(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        Impl_ResetHitAndRun(param0);
        return true;
    }

    static bool Command_SetHitAndRunDecayInterior(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetHitAndRunDecayInterior(param0);
        return true;
    }

    static bool Command_SetMissionNameIndex(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetMissionNameIndex(param0);
        return true;
    }

    static bool Command_AddBonusObjective(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        Impl_AddBonusObjective(param0, param1);
        return true;
    }

    static bool Command_AttachStatePropCollectible(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_AttachStatePropCollectible(param0, param1);
        return true;
    }

    static bool Command_MoveStageVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_MoveStageVehicle(param0, param1, param2);
        return true;
    }

    static bool Command_SetStageCamera(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_SetStageCamera(param0, param1, param2);
        return true;
    }

    static bool Command_SetBonusMissionStart(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        Impl_SetBonusMissionStart(param0);
        return true;
    }

    static bool Command_PlacePlayerAtLocatorName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_PlacePlayerAtLocatorName(param0);
        return true;
    }

    static bool Command_msPlacePlayerCarAtLocatorName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_msPlacePlayerCarAtLocatorName(param0);
        return true;
    }

    static bool Command_ClearTrafficForStage(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        Impl_ClearTrafficForStage(param0);
        return true;
    }

    static bool Command_SetStageAIEvadeCatchupParams(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_SetStageAIEvadeCatchupParams(param0, param1, param2);
        return true;
    }

    static bool Command_AllowUserDump(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        Impl_AllowUserDump(param0);
        return true;
    }

    static bool Command_SetVehicleToLoad(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_SetVehicleToLoad(param0, param1, param2);
        return true;
    }

    static bool Command_SetConversationCamName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetConversationCamName(param0);
        return true;
    }

    static bool Command_SetConversationCamPcName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetConversationCamPcName(param0);
        return true;
    }

    static bool Command_SetConversationCamNpcName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetConversationCamNpcName(param0);
        return true;
    }

    static bool Command_SetConversationCamDistance(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetConversationCamDistance(param0, param1);
        return true;
    }

    static bool Command_CharacterIsChild(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_CharacterIsChild(param0);
        return true;
    }

    static bool Command_SetCarStartCamera(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_SetCarStartCamera(param0);
        return true;
    }

    static bool Command_SetPlayerCarName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetPlayerCarName(param0, param1);
        return true;
    }

    static bool Command_SetRespawnRate(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_SetRespawnRate(param0, param1);
        return true;
    }

    static bool Command_ActivateTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_ActivateTrigger(param0);
        return true;
    }

    static bool Command_DeactivateTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        Impl_DeactivateTrigger(param0);
        return true;
    }

    static bool Command_CreateAnimPhysObject(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_CreateAnimPhysObject(param0, param1);
        return true;
    }

    static bool Command_CreateActionEventTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];

        Impl_CreateActionEventTrigger(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_LinkActionToObjectJoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];

        Impl_LinkActionToObjectJoint(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_LinkActionToObject(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 5) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];
        const auto& param3 = splits[3];
        const auto& param4 = splits[4];

        Impl_LinkActionToObject(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_SetCharacterPosition(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 3) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];
        const auto& param2 = splits[2];

        Impl_SetCharacterPosition(param0, param1, param2);
        return true;
    }

    static bool Command_ResetCharacter(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 2) return false;

        const auto& param0 = splits[0];
        const auto& param1 = splits[1];

        Impl_ResetCharacter(param0, param1);
        return true;
    }

    std::unordered_map<std::string, Command> Commands::_namedCommands =
    {
        { "LoadP3DFile", Command { &Command_LoadP3DFile, "None" } },
        { "SetParticleTexture", Command { &Command_SetParticleTexture, "None" } },
        { "BindReward", Command { &Command_BindReward, "None" } },
        { "SetCarAttributes", Command { &Command_SetCarAttributes, "None" } },
        { "SetTotalGags", Command { &Command_SetTotalGags, "None" } },
        { "SelectMission", Command { &Command_SelectMission, "None" } },
        { "SetMissionResetPlayerInCar", Command { &Command_SetMissionResetPlayerInCar, "None" } },
        { "SetDynaLoadData", Command { &Command_SetDynaLoadData, "None" } },
        { "UsePedGroup", Command { &Command_UsePedGroup, "None" } },
        { "AddStage", Command { &Command_AddStage, "None" } },
        { "SetPresentationBitmap", Command { &Command_SetPresentationBitmap, "None" } },
        { "SetStageMessageIndex", Command { &Command_SetStageMessageIndex, "None" } },
        { "AddObjective", Command { &Command_AddObjective, "None" } },
        { "SetObjTargetVehicle", Command { &Command_SetObjTargetVehicle, "None" } },
        { "CloseObjective", Command { &Command_CloseObjective, "None" } },
        { "CloseStage", Command { &Command_CloseStage, "None" } },
        { "RESET_TO_HERE", Command { &Command_RESET_TO_HERE, "None" } },
        { "SetHUDIcon", Command { &Command_SetHUDIcon, "None" } },
        { "AddCollectible", Command { &Command_AddCollectible, "None" } },
        { "SetStageTime", Command { &Command_SetStageTime, "None" } },
        { "AddCondition", Command { &Command_AddCondition, "None" } },
        { "CloseCondition", Command { &Command_CloseCondition, "None" } },
        { "ShowStageComplete", Command { &Command_ShowStageComplete, "None" } },
        { "AddNPC", Command { &Command_AddNPC, "None" } },
        { "SetDestination", Command { &Command_SetDestination, "None" } },
        { "SetCollectibleEffect", Command { &Command_SetCollectibleEffect, "None" } },
        { "AddStageTime", Command { &Command_AddStageTime, "None" } },
        { "AddObjectiveNPCWaypoint", Command { &Command_AddObjectiveNPCWaypoint, "None" } },
        { "SetTalkToTarget", Command { &Command_SetTalkToTarget, "None" } },
        { "SetDialogueInfo", Command { &Command_SetDialogueInfo, "None" } },
        { "SetCamBestSide", Command { &Command_SetCamBestSide, "None" } },
        { "CloseMission", Command { &Command_CloseMission, "None" } },
        { "PlacePlayerCar", Command { &Command_PlacePlayerCar, "None" } },
        { "SetMaxTraffic", Command { &Command_SetMaxTraffic, "None" } },
        { "AddStageVehicle", Command { &Command_AddStageVehicle, "None" } },
        { "AddStageWaypoint", Command { &Command_AddStageWaypoint, "None" } },
        { "SetRaceLaps", Command { &Command_SetRaceLaps, "None" } },
        { "SetDemoLoopTime", Command { &Command_SetDemoLoopTime, "None" } },
        { "AddStageMusicChange", Command { &Command_AddStageMusicChange, "None" } },
        { "LoadDisposableCar", Command { &Command_LoadDisposableCar, "None" } },
        { "AddMission", Command { &Command_AddMission, "None" } },
        { "ClearGagBindings", Command { &Command_ClearGagBindings, "ClearGagBindings();" } },
        { "GagBegin", Command { &Command_GagBegin, "None" } },
        { "GagSetInterior", Command { &Command_GagSetInterior, "None" } },
        { "GagSetCycle", Command { &Command_GagSetCycle, "None" } },
        { "GagSetPosition", Command { &Command_GagSetPosition, "None" } },
        { "GagSetRandom", Command { &Command_GagSetRandom, "None" } },
        { "GagSetSound", Command { &Command_GagSetSound, "None" } },
        { "GagSetTrigger", Command { &Command_GagSetTrigger, "None" } },
        { "GagEnd", Command { &Command_GagEnd, "None" } },
        { "GagSetSparkle", Command { &Command_GagSetSparkle, "None" } },
        { "GagSetPersist", Command { &Command_GagSetPersist, "None" } },
        { "GagSetCoins", Command { &Command_GagSetCoins, "None" } },
        { "GagSetAnimCollision", Command { &Command_GagSetAnimCollision, "None" } },
        { "GagSetIntro", Command { &Command_GagSetIntro, "None" } },
        { "GagSetOutro", Command { &Command_GagSetOutro, "None" } },
        { "GagSetCameraShake", Command { &Command_GagSetCameraShake, "None" } },
        { "GagPlayFMV", Command { &Command_GagPlayFMV, "Play FMV specified by file name" } },
        { "EnableTutorialMode", Command { &Command_EnableTutorialMode, "None" } },
        { "InitLevelPlayerVehicle", Command { &Command_InitLevelPlayerVehicle, "None" } },
        { "AddCharacter", Command { &Command_AddCharacter, "None" } },
        { "CreateChaseManager", Command { &Command_CreateChaseManager, "None" } },
        { "SetHitAndRunDecay", Command { &Command_SetHitAndRunDecay, "None" } },
        { "SetNumChaseCars", Command { &Command_SetNumChaseCars, "None" } },
        { "AddNPCCharacterBonusMission", Command { &Command_AddNPCCharacterBonusMission, "None" } },
        { "AddBonusMissionNPCWaypoint", Command { &Command_AddBonusMissionNPCWaypoint, "None" } },
        { "AddAmbientCharacter", Command { &Command_AddAmbientCharacter, "None" } },
        { "AddAmbientNPCWaypoint", Command { &Command_AddAmbientNPCWaypoint, "None" } },
        { "AddPurchaseCarReward", Command { &Command_AddPurchaseCarReward, "None" } },
        { "AddPurchaseCarNPCWaypoint", Command { &Command_AddPurchaseCarNPCWaypoint, "None" } },
        { "CreateTrafficGroup", Command { &Command_CreateTrafficGroup, "None" } },
        { "AddTrafficModel", Command { &Command_AddTrafficModel, "None" } },
        { "CloseTrafficGroup", Command { &Command_CloseTrafficGroup, "None" } },
        { "CreatePedGroup", Command { &Command_CreatePedGroup, "None" } },
        { "AddPed", Command { &Command_AddPed, "None" } },
        { "ClosePedGroup", Command { &Command_ClosePedGroup, "None" } },
        { "PreallocateActors", Command { &Command_PreallocateActors, "None" } },
        { "SetProjectileStats", Command { &Command_SetProjectileStats, "None" } },
        { "AddSpawnPointByLocatorScript", Command { &Command_AddSpawnPointByLocatorScript, "None" } },
        { "AddBehaviour", Command { &Command_AddBehaviour, "None" } },
        { "SetActorRotationSpeed", Command { &Command_SetActorRotationSpeed, "None" } },
        { "SetAnimatedCameraName", Command { &Command_SetAnimatedCameraName, "None" } },
        { "SetAnimCamMulticontName", Command { &Command_SetAnimCamMulticontName, "None" } },
        { "SetCoinFee", Command { &Command_SetCoinFee, "None" } },
        { "PutMFPlayerInCar", Command { &Command_PutMFPlayerInCar, "None" } },
        { "StartCountdown", Command { &Command_StartCountdown, "None" } },
        { "AddToCountdownSequence", Command { &Command_AddToCountdownSequence, "None" } },
        { "UseElapsedTime", Command { &Command_UseElapsedTime, "None" } },
        { "SetRaceEnteryFee", Command { &Command_SetRaceEnteryFee, "None" } },
        { "SetParTime", Command { &Command_SetParTime, "None" } },
        { "SetCondMinHealth", Command { &Command_SetCondMinHealth, "None" } },
        { "SetCondTargetVehicle", Command { &Command_SetCondTargetVehicle, "None" } },
        { "SetCondTime", Command { &Command_SetCondTime, "None" } },
        { "AddBonusMission", Command { &Command_AddBonusMission, "None" } },
        { "AddTeleportDest", Command { &Command_AddTeleportDest, "Set a valid location for a teleport" } },
        { "AddVehicleSelectInfo", Command { &Command_AddVehicleSelectInfo, "None" } },
        { "SuppressDriver", Command { &Command_SuppressDriver, "help your goddamn self" } },
        { "SetBonusMissionDialoguePos", Command { &Command_SetBonusMissionDialoguePos, "None" } },
        { "SetConversationCam", Command { &Command_SetConversationCam, "None" } },
        { "ClearAmbientAnimations", Command { &Command_ClearAmbientAnimations, "None" } },
        { "AddAmbientNpcAnimation", Command { &Command_AddAmbientNpcAnimation, "None" } },
        { "AddAmbientPcAnimation", Command { &Command_AddAmbientPcAnimation, "None" } },
        { "SetCoinDrawable", Command { &Command_SetCoinDrawable, "None" } },
        { "AmbientAnimationRandomize", Command { &Command_AmbientAnimationRandomize, "None" } },
        { "TurnGotoDialogOff", Command { &Command_TurnGotoDialogOff, "None" } },
        { "SetCompletionDialog", Command { &Command_SetCompletionDialog, "None" } },
        { "SetMissionResetPlayerOutCar", Command { &Command_SetMissionResetPlayerOutCar, "None" } },
        { "SetMissionStartCameraName", Command { &Command_SetMissionStartCameraName, "None" } },
        { "SetMissionStartMulticontName", Command { &Command_SetMissionStartMulticontName, "None" } },
        { "SetInitialWalk", Command { &Command_SetInitialWalk, "Set locator to walk to on startup" } },
        { "SetDialoguePositions", Command { &Command_SetDialoguePositions, "None" } },
        { "ActivateVehicle", Command { &Command_ActivateVehicle, "None" } },
        { "SetStageMusicAlwaysOn", Command { &Command_SetStageMusicAlwaysOn, "None" } },
        { "SetNumValidFailureHints", Command { &Command_SetNumValidFailureHints, "None" } },
        { "SetVehicleAIParams", Command { &Command_SetVehicleAIParams, "None" } },
        { "StageStartMusicEvent", Command { &Command_StageStartMusicEvent, "None" } },
        { "AllowMissionAbort", Command { &Command_AllowMissionAbort, "None" } },
        { "MustActionTrigger", Command { &Command_MustActionTrigger, "None" } },
        { "SetStageAITargetCatchupParams", Command { &Command_SetStageAITargetCatchupParams, "None" } },
        { "SetFollowDistances", Command { &Command_SetFollowDistances, "None" } },
        { "SetFadeOut", Command { &Command_SetFadeOut, "None" } },
        { "StayInBlack", Command { &Command_StayInBlack, "None" } },
        { "AddStageCharacter", Command { &Command_AddStageCharacter, "None" } },
        { "SetDurationTime", Command { &Command_SetDurationTime, "None" } },
        { "SetFMVInfo", Command { &Command_SetFMVInfo, "None" } },
        { "SetForcedCar", Command { &Command_SetForcedCar, "None" } },
        { "SwapInDefaultCar", Command { &Command_SwapInDefaultCar, "None" } },
        { "SetSwapDefaultCarLocator", Command { &Command_SetSwapDefaultCarLocator, "None" } },
        { "SetSwapForcedCarLocator", Command { &Command_SetSwapForcedCarLocator, "None" } },
        { "SetSwapPlayerLocator", Command { &Command_SetSwapPlayerLocator, "None" } },
        { "StreetRacePropsLoad", Command { &Command_StreetRacePropsLoad, "None" } },
        { "StreetRacePropsUnload", Command { &Command_StreetRacePropsUnload, "None" } },
        { "SetStageAIRaceCatchupParams", Command { &Command_SetStageAIRaceCatchupParams, "None" } },
        { "DisableHitAndRun", Command { &Command_DisableHitAndRun, "None" } },
        { "NoTrafficForStage", Command { &Command_NoTrafficForStage, "None" } },
        { "SetConditionPosition", Command { &Command_SetConditionPosition, "None" } },
        { "AddSafeZone", Command { &Command_AddSafeZone, "None" } },
        { "AddGagBinding", Command { &Command_AddGagBinding, "AddGagBinding(InteriorName, GagFileName, CycleMode, Weight, SoundResourceName);" } },
        { "SetPostLevelFMV", Command { &Command_SetPostLevelFMV, "None" } },
        { "SetHitNRun", Command { &Command_SetHitNRun, "None" } },
        { "SetObjDistance", Command { &Command_SetObjDistance, "None" } },
        { "SetMusicState", Command { &Command_SetMusicState, "None" } },
        { "SetIrisWipe", Command { &Command_SetIrisWipe, "None" } },
        { "RemoveDriver", Command { &Command_RemoveDriver, "None" } },
        { "RemoveNPC", Command { &Command_RemoveNPC, "None" } },
        { "AddDriver", Command { &Command_AddDriver, "None" } },
        { "SetCharacterToHide", Command { &Command_SetCharacterToHide, "None" } },
        { "SetLevelOver", Command { &Command_SetLevelOver, "None" } },
        { "GagCheckCollCards", Command { &Command_GagCheckCollCards, "None" } },
        { "GagCheckMovie", Command { &Command_GagCheckMovie, "None" } },
        { "GagSetSoundLoadDistances", Command { &Command_GagSetSoundLoadDistances, "None" } },
        { "BindCollectibleTo", Command { &Command_BindCollectibleTo, "None" } },
        { "AddShield", Command { &Command_AddShield, "None" } },
        { "SetStatepropShadow", Command { &Command_SetStatepropShadow, "None" } },
        { "AddFlyingActorByLocator", Command { &Command_AddFlyingActorByLocator, "None" } },
        { "AddCollectibleStateProp", Command { &Command_AddCollectibleStateProp, "None" } },
        { "SetPickupTarget", Command { &Command_SetPickupTarget, "None" } },
        { "SetObjTargetBoss", Command { &Command_SetObjTargetBoss, "None" } },
        { "AllowRockOut", Command { &Command_AllowRockOut, "None" } },
        { "ShowHUD", Command { &Command_ShowHUD, "None" } },
        { "SetGameOver", Command { &Command_SetGameOver, "None" } },
        { "GoToPsScreenWhenDone", Command { &Command_GoToPsScreenWhenDone, "None" } },
        { "SetMass", Command { &Command_SetMass, "help your goddamn self" } },
        { "SetGasScale", Command { &Command_SetGasScale, "help your goddamn self" } },
        { "SetSlipGasScale", Command { &Command_SetSlipGasScale, "help your goddamn self" } },
        { "SetBrakeScale", Command { &Command_SetBrakeScale, "help your goddamn self" } },
        { "SetTopSpeedKmh", Command { &Command_SetTopSpeedKmh, "help your goddamn self" } },
        { "SetMaxWheelTurnAngle", Command { &Command_SetMaxWheelTurnAngle, "help your goddamn self" } },
        { "SetHighSpeedSteeringDrop", Command { &Command_SetHighSpeedSteeringDrop, "help your goddamn self" } },
        { "SetTireGrip", Command { &Command_SetTireGrip, "help your goddamn self" } },
        { "SetNormalSteering", Command { &Command_SetNormalSteering, "help your goddamn self" } },
        { "SetSlipSteering", Command { &Command_SetSlipSteering, "help your goddamn self" } },
        { "SetEBrakeEffect", Command { &Command_SetEBrakeEffect, "help your goddamn self" } },
        { "SetSlipSteeringNoEBrake", Command { &Command_SetSlipSteeringNoEBrake, "help your goddamn self" } },
        { "SetSlipEffectNoEBrake", Command { &Command_SetSlipEffectNoEBrake, "help your goddamn self" } },
        { "SetCMOffsetX", Command { &Command_SetCMOffsetX, "help your goddamn self" } },
        { "SetCMOffsetY", Command { &Command_SetCMOffsetY, "help your goddamn self" } },
        { "SetCMOffsetZ", Command { &Command_SetCMOffsetZ, "help your goddamn self" } },
        { "SetSuspensionLimit", Command { &Command_SetSuspensionLimit, "help your goddamn self" } },
        { "SetSpringK", Command { &Command_SetSpringK, "help your goddamn self" } },
        { "SetDamperC", Command { &Command_SetDamperC, "help your goddamn self" } },
        { "SetSuspensionYOffset", Command { &Command_SetSuspensionYOffset, "help your goddamn self" } },
        { "SetHitPoints", Command { &Command_SetHitPoints, "help your goddamn self" } },
        { "SetBurnoutRange", Command { &Command_SetBurnoutRange, "help your goddamn self" } },
        { "SetMaxSpeedBurstTime", Command { &Command_SetMaxSpeedBurstTime, "help your goddamn self" } },
        { "SetDonutTorque", Command { &Command_SetDonutTorque, "help your goddamn self" } },
        { "SetWeebleOffset", Command { &Command_SetWeebleOffset, "help your goddamn self" } },
        { "SetWheelieRange", Command { &Command_SetWheelieRange, "help your goddamn self" } },
        { "SetWheelieOffsetY", Command { &Command_SetWheelieOffsetY, "help your goddamn self" } },
        { "SetWheelieOffsetZ", Command { &Command_SetWheelieOffsetZ, "help your goddamn self" } },
        { "SetShadowAdjustments", Command { &Command_SetShadowAdjustments, "Move the shadow points around" } },
        { "SetCharactersVisible", Command { &Command_SetCharactersVisible, "help your goddamn self" } },
        { "SetIrisTransition", Command { &Command_SetIrisTransition, "help your goddamn self" } },
        { "SetCharacterScale", Command { &Command_SetCharacterScale, "help your goddamn self" } },
        { "SetGamblingOdds", Command { &Command_SetGamblingOdds, "Set Gambling Odds" } },
        { "SetDriver", Command { &Command_SetDriver, "help your goddamn self" } },
        { "SetHasDoors", Command { &Command_SetHasDoors, "help your goddamn self" } },
        { "SetShininess", Command { &Command_SetShininess, "Set the environmental reflection 0 to 1" } },
        { "SetHighRoof", Command { &Command_SetHighRoof, "help your goddamn self" } },
        { "SetHighSpeedGasScale", Command { &Command_SetHighSpeedGasScale, "help your goddamn self" } },
        { "SetGasScaleSpeedThreshold", Command { &Command_SetGasScaleSpeedThreshold, "help your goddamn self" } },
        { "SetAllowSeatSlide", Command { &Command_SetAllowSeatSlide, "help your goddamn self" } },
        { "ClearVehicleSelectInfo", Command { &Command_ClearVehicleSelectInfo, "None" } },
        { "AddFlyingActor", Command { &Command_AddFlyingActor, "None" } },
        { "SetCollisionAttributes", Command { &Command_SetCollisionAttributes, "None" } },
        { "AddSpawnPoint", Command { &Command_AddSpawnPoint, "None" } },
        { "GagSetWeight", Command { &Command_GagSetWeight, "None" } },
        { "GagSetLoadDistances", Command { &Command_GagSetLoadDistances, "None" } },
        { "SetTotalWasps", Command { &Command_SetTotalWasps, "None" } },
        { "AddGlobalProp", Command { &Command_AddGlobalProp, "None" } },
        { "EnableHitAndRun", Command { &Command_EnableHitAndRun, "None" } },
        { "SetHitAndRunMeter", Command { &Command_SetHitAndRunMeter, "None" } },
        { "SetChaseSpawnRate", Command { &Command_SetChaseSpawnRate, "None" } },
        { "KillAllChaseAI", Command { &Command_KillAllChaseAI, "None" } },
        { "ResetHitAndRun", Command { &Command_ResetHitAndRun, "None" } },
        { "SetHitAndRunDecayInterior", Command { &Command_SetHitAndRunDecayInterior, "None" } },
        { "SetMissionNameIndex", Command { &Command_SetMissionNameIndex, "None" } },
        { "AddBonusObjective", Command { &Command_AddBonusObjective, "None" } },
        { "AttachStatePropCollectible", Command { &Command_AttachStatePropCollectible, "None" } },
        { "MoveStageVehicle", Command { &Command_MoveStageVehicle, "None" } },
        { "SetStageCamera", Command { &Command_SetStageCamera, "None" } },
        { "SetBonusMissionStart", Command { &Command_SetBonusMissionStart, "None" } },
        { "PlacePlayerAtLocatorName", Command { &Command_PlacePlayerAtLocatorName, "None" } },
        { "msPlacePlayerCarAtLocatorName", Command { &Command_msPlacePlayerCarAtLocatorName, "None" } },
        { "ClearTrafficForStage", Command { &Command_ClearTrafficForStage, "None" } },
        { "SetStageAIEvadeCatchupParams", Command { &Command_SetStageAIEvadeCatchupParams, "None" } },
        { "AllowUserDump", Command { &Command_AllowUserDump, "None" } },
        { "SetVehicleToLoad", Command { &Command_SetVehicleToLoad, "None" } },
        { "SetConversationCamName", Command { &Command_SetConversationCamName, "x" } },
        { "SetConversationCamPcName", Command { &Command_SetConversationCamPcName, "None" } },
        { "SetConversationCamNpcName", Command { &Command_SetConversationCamNpcName, "None" } },
        { "SetConversationCamDistance", Command { &Command_SetConversationCamDistance, "None" } },
        { "CharacterIsChild", Command { &Command_CharacterIsChild, "None" } },
        { "SetCarStartCamera", Command { &Command_SetCarStartCamera, "None" } },
        { "SetPlayerCarName", Command { &Command_SetPlayerCarName, "None" } },
        { "SetRespawnRate", Command { &Command_SetRespawnRate, "None" } },
        { "ActivateTrigger", Command { &Command_ActivateTrigger, "None" } },
        { "DeactivateTrigger", Command { &Command_DeactivateTrigger, "None" } },
        { "CreateAnimPhysObject", Command { &Command_CreateAnimPhysObject, "None" } },
        { "CreateActionEventTrigger", Command { &Command_CreateActionEventTrigger, "None" } },
        { "LinkActionToObjectJoint", Command { &Command_LinkActionToObjectJoint, "None" } },
        { "LinkActionToObject", Command { &Command_LinkActionToObject, "None" } },
        { "SetCharacterPosition", Command { &Command_SetCharacterPosition, "Sets the character position" } },
        { "ResetCharacter", Command { &Command_ResetCharacter, "Sets the character to the named locator" } },
    };
}
