// Copyright 2019 the donut authors. See AUTHORS.md

#include "GameCommands.h"
#include <iostream>
#include <fmt/format.h>

namespace Donut
{
	void GameCommands::HelloWorld()
	{
		std::cout << "hellooooooooooo new york!!!!\n";
	}

	void GameCommands::LoadP3DFile(const std::string& param0, const std::string& param1 /*= ""*/)
	{
		if (param1.empty())
		{
			//std::cout << fmt::format("LoadP3DFile({0})\n", param0);
		}
		else
		{
			//std::cout << fmt::format("LoadP3DFile({0}, {1})\n", param0, param1);
		}
	}

	void GameCommands::SetParticleTexture(int32_t param0, const std::string& param1) {}
	void GameCommands::BindReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, int32_t param4, int32_t param5 /*= 0*/, const std::string& param6 /*= ""*/) {}
	void GameCommands::SetCarAttributes(const std::string& param0, float param1, float param2, float param3, float param4) {}
	void GameCommands::SetTotalGags(int32_t param0, int32_t param1) {}
	void GameCommands::SelectMission(const std::string& param0) {}
	void GameCommands::SetMissionResetPlayerInCar(const std::string& param0) {}
	void GameCommands::SetDynaLoadData(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::UsePedGroup(int32_t param0) {}
	void GameCommands::AddStage(const std::string& param0 /*= ""*/, const std::string& param1 /*= ""*/, const std::string& param2 /*= ""*/) {}
	void GameCommands::SetPresentationBitmap(const std::string& param0) {}
	void GameCommands::SetStageMessageIndex(int32_t param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::AddObjective(const std::string& param0, const std::string& param1 /*= ""*/, const std::string& param2 /*= ""*/) {}
	void GameCommands::SetObjTargetVehicle(const std::string& param0) {}
	void GameCommands::CloseObjective(int32_t param0 /*= 0*/) {}
	void GameCommands::CloseStage(int32_t param0 /*= 0*/) {}
	void GameCommands::RESET_TO_HERE(int32_t param0 /*= 0*/) {}
	void GameCommands::SetHUDIcon(const std::string& param0) {}
	void GameCommands::AddCollectible(const std::string& param0, const std::string& param1 /*= ""*/, const std::string& param2 /*= ""*/, const std::string& param3 /*= ""*/) {}
	void GameCommands::SetStageTime(int32_t param0) {}
	void GameCommands::AddCondition(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::CloseCondition(int32_t param0 /*= 0*/) {}
	void GameCommands::ShowStageComplete(int32_t param0 /*= 0*/) {}
	void GameCommands::AddNPC(const std::string& param0, const std::string& param1, const std::string& param2 /*= ""*/) {}
	void GameCommands::SetDestination(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::SetCollectibleEffect(const std::string& param0) {}
	void GameCommands::AddStageTime(int32_t param0) {}
	void GameCommands::AddObjectiveNPCWaypoint(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetTalkToTarget(const std::string& param0, int32_t param1 /*= 0*/, float param2 /*= 0.0f*/, const std::string& param3 /*= ""*/) {}
	void GameCommands::SetDialogueInfo(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3) {}
	void GameCommands::SetCamBestSide(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::CloseMission(int32_t param0 /*= 0*/) {}
	void GameCommands::PlacePlayerCar(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetMaxTraffic(int32_t param0) {}
	void GameCommands::AddStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4 /*= ""*/) {}
	void GameCommands::AddStageWaypoint(const std::string& param0) {}
	void GameCommands::SetRaceLaps(int32_t param0) {}
	void GameCommands::SetDemoLoopTime(int64_t param0) {}
	void GameCommands::AddStageMusicChange(int32_t param0 /*= 0*/) {}
	void GameCommands::LoadDisposableCar(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::AddMission(const std::string& param0) {}
	void GameCommands::ClearGagBindings(int32_t param0 /*= 0*/) {}
	void GameCommands::GagBegin(const std::string& param0) {}
	void GameCommands::GagSetInterior(const std::string& param0) {}
	void GameCommands::GagSetCycle(const std::string& param0) {}
	void GameCommands::GagSetPosition(const std::string& param0) {}
	void GameCommands::GagSetPosition(float param0, float param1, float param2) {}
	void GameCommands::GagSetRandom(int32_t param0) {}
	void GameCommands::GagSetSound(const std::string& param0) {}
	void GameCommands::GagSetTrigger(const std::string& param0, const std::string& param1, float param2) {}
	void GameCommands::GagSetTrigger(const std::string& param0, float param1, float param2, float param3, float param4) {}
	void GameCommands::GagEnd(int32_t param0 /*= 0*/) {}
	void GameCommands::GagSetSparkle(int32_t param0) {}
	void GameCommands::GagSetPersist(int32_t param0) {}
	void GameCommands::GagSetCoins(int32_t param0, float param1) {}
	void GameCommands::GagSetAnimCollision(int32_t param0) {}
	void GameCommands::GagSetIntro(int32_t param0) {}
	void GameCommands::GagSetOutro(int32_t param0) {}
	void GameCommands::GagSetCameraShake(float param0, int32_t param1, float param2) {}
	void GameCommands::GagPlayFMV(const std::string& param0) {}
	void GameCommands::EnableTutorialMode(const std::string& param0) {}
	void GameCommands::InitLevelPlayerVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 /*= ""*/) {}
	void GameCommands::AddCharacter(const std::string& param0, const std::string& param1) {}
	void GameCommands::CreateChaseManager(const std::string& param0, const std::string& param1, int32_t param2) {}
	void GameCommands::SetHitAndRunDecay(float param0) {}
	void GameCommands::SetNumChaseCars(const std::string& param0) {}
	void GameCommands::AddNPCCharacterBonusMission(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, int32_t param6, const std::string& param7 /*= ""*/) {}
	void GameCommands::AddBonusMissionNPCWaypoint(const std::string& param0, const std::string& param1) {}
	void GameCommands::AddAmbientCharacter(const std::string& param0, const std::string& param1, float param2) {}
	void GameCommands::AddAmbientNPCWaypoint(const std::string& param0, const std::string& param1) {}
	void GameCommands::AddPurchaseCarReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, float param4, const std::string& param5) {}
	void GameCommands::AddPurchaseCarNPCWaypoint(const std::string& param0, const std::string& param1) {}
	void GameCommands::CreateTrafficGroup(int32_t param0) {}
	void GameCommands::AddTrafficModel(const std::string& param0, int32_t param1, int32_t param2 /*= 0*/) {}
	void GameCommands::CloseTrafficGroup(int32_t param0 /*= 0*/) {}
	void GameCommands::CreatePedGroup(int32_t param0) {}
	void GameCommands::AddPed(const std::string& param0, int32_t param1) {}
	void GameCommands::ClosePedGroup(int32_t param0 /*= 0*/) {}
	void GameCommands::PreallocateActors(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetProjectileStats(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::AddSpawnPointByLocatorScript(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5) {}
	void GameCommands::AddBehaviour(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 /*= ""*/, const std::string& param4 /*= ""*/, const std::string& param5 /*= ""*/, const std::string& param6 /*= ""*/) {}
	void GameCommands::SetActorRotationSpeed(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetAnimatedCameraName(const std::string& param0) {}
	void GameCommands::SetAnimCamMulticontName(const std::string& param0) {}
	void GameCommands::SetCoinFee(int32_t param0) {}
	void GameCommands::PutMFPlayerInCar(int32_t param0 /*= 0*/) {}
	void GameCommands::StartCountdown(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::AddToCountdownSequence(const std::string& param0, int32_t param1) {}
	void GameCommands::UseElapsedTime(int32_t param0 /*= 0*/) {}
	void GameCommands::SetRaceEnteryFee(int32_t param0) {}
	void GameCommands::SetParTime(int32_t param0) {}
	void GameCommands::SetCondMinHealth(float param0) {}
	void GameCommands::SetCondTargetVehicle(const std::string& param0) {}
	void GameCommands::SetCondTime(int32_t param0) {}
	void GameCommands::AddBonusMission(const std::string& param0) {}
	void GameCommands::AddTeleportDest(const std::string& param0, float param1, float param2, float param3, const std::string& param4) {}
	void GameCommands::AddVehicleSelectInfo(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::SuppressDriver(const std::string& param0) {}
	void GameCommands::SetBonusMissionDialoguePos(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
	void GameCommands::SetConversationCam(int32_t param0, const std::string& param1, const std::string& param2 /*= ""*/) {}
	void GameCommands::ClearAmbientAnimations(const std::string& param0) {}
	void GameCommands::AddAmbientNpcAnimation(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::AddAmbientPcAnimation(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::SetCoinDrawable(const std::string& param0) {}
	void GameCommands::AmbientAnimationRandomize(int32_t param0, int32_t param1) {}
	void GameCommands::TurnGotoDialogOff(int32_t param0 /*= 0*/) {}
	void GameCommands::SetCompletionDialog(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::SetMissionResetPlayerOutCar(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetMissionStartCameraName(const std::string& param0) {}
	void GameCommands::SetMissionStartMulticontName(const std::string& param0) {}
	void GameCommands::SetInitialWalk(const std::string& param0) {}
	void GameCommands::SetDialoguePositions(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3 /*= 0*/) {}
	void GameCommands::ActivateVehicle(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::SetStageMusicAlwaysOn(int32_t param0 /*= 0*/) {}
	void GameCommands::SetNumValidFailureHints(int32_t param0) {}
	void GameCommands::SetVehicleAIParams(const std::string& param0, int32_t param1, int32_t param2) {}
	void GameCommands::StageStartMusicEvent(const std::string& param0) {}
	void GameCommands::AllowMissionAbort(const std::string& param0) {}
	void GameCommands::MustActionTrigger(int32_t param0 /*= 0*/) {}
	void GameCommands::SetStageAITargetCatchupParams(const std::string& param0, int32_t param1, int32_t param2) {}
	void GameCommands::SetFollowDistances(int32_t param0, int32_t param1) {}
	void GameCommands::SetFadeOut(float param0) {}
	void GameCommands::StayInBlack(int32_t param0 /*= 0*/) {}
	void GameCommands::AddStageCharacter(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
	void GameCommands::SetDurationTime(float param0) {}
	void GameCommands::SetFMVInfo(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::SetForcedCar(int32_t param0 /*= 0*/) {}
	void GameCommands::SwapInDefaultCar(int32_t param0 /*= 0*/) {}
	void GameCommands::SetSwapDefaultCarLocator(const std::string& param0) {}
	void GameCommands::SetSwapForcedCarLocator(const std::string& param0) {}
	void GameCommands::SetSwapPlayerLocator(const std::string& param0) {}
	void GameCommands::StreetRacePropsLoad(const std::string& param0) {}
	void GameCommands::StreetRacePropsUnload(const std::string& param0) {}
	void GameCommands::SetStageAIRaceCatchupParams(const std::string& param0, int32_t param1, float param2, float param3, float param4) {}
	void GameCommands::DisableHitAndRun(int32_t param0 /*= 0*/) {}
	void GameCommands::NoTrafficForStage(int32_t param0 /*= 0*/) {}
	void GameCommands::SetConditionPosition(int32_t param0) {}
	void GameCommands::AddSafeZone(const std::string& param0, int32_t param1) {}
	void GameCommands::AddGagBinding(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3, const std::string& param4) {}
	void GameCommands::SetPostLevelFMV(const std::string& param0) {}
	void GameCommands::SetHitNRun(int32_t param0 /*= 0*/) {}
	void GameCommands::SetObjDistance(int32_t param0) {}
	void GameCommands::SetMusicState(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetIrisWipe(float param0) {}
	void GameCommands::RemoveDriver(const std::string& param0) {}
	void GameCommands::RemoveNPC(const std::string& param0) {}
	void GameCommands::AddDriver(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetCharacterToHide(const std::string& param0) {}
	void GameCommands::SetLevelOver(int32_t param0 /*= 0*/) {}
	void GameCommands::GagCheckCollCards(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
	void GameCommands::GagCheckMovie(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
	void GameCommands::GagSetSoundLoadDistances(int32_t param0, int32_t param1) {}
	void GameCommands::BindCollectibleTo(int32_t param0, int32_t param1) {}
	void GameCommands::AddShield(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetStatepropShadow(const std::string& param0, const std::string& param1) {}
	void GameCommands::AddFlyingActorByLocator(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
	void GameCommands::AddCollectibleStateProp(const std::string& param0, const std::string& param1, int32_t param2) {}
	void GameCommands::SetPickupTarget(const std::string& param0) {}
	void GameCommands::SetObjTargetBoss(const std::string& param0) {}
	void GameCommands::AllowRockOut(int32_t param0 /*= 0*/) {}
	void GameCommands::ShowHUD(const std::string& param0) {}
	void GameCommands::SetGameOver(int32_t param0 /*= 0*/) {}
	void GameCommands::GoToPsScreenWhenDone(int32_t param0 /*= 0*/) {}
	void GameCommands::SetMass(float param0) {}
	void GameCommands::SetGasScale(float param0) {}
	void GameCommands::SetSlipGasScale(float param0) {}
	void GameCommands::SetBrakeScale(float param0) {}
	void GameCommands::SetTopSpeedKmh(float param0) {}
	void GameCommands::SetMaxWheelTurnAngle(float param0) {}
	void GameCommands::SetHighSpeedSteeringDrop(float param0) {}
	void GameCommands::SetTireGrip(float param0) {}
	void GameCommands::SetNormalSteering(float param0) {}
	void GameCommands::SetSlipSteering(float param0) {}
	void GameCommands::SetEBrakeEffect(float param0) {}
	void GameCommands::SetSlipSteeringNoEBrake(float param0) {}
	void GameCommands::SetSlipEffectNoEBrake(float param0) {}
	void GameCommands::SetCMOffsetX(float param0) {}
	void GameCommands::SetCMOffsetY(float param0) {}
	void GameCommands::SetCMOffsetZ(float param0) {}
	void GameCommands::SetSuspensionLimit(float param0) {}
	void GameCommands::SetSpringK(float param0) {}
	void GameCommands::SetDamperC(float param0) {}
	void GameCommands::SetSuspensionYOffset(float param0) {}
	void GameCommands::SetHitPoints(float param0) {}
	void GameCommands::SetBurnoutRange(float param0) {}
	void GameCommands::SetMaxSpeedBurstTime(float param0) {}
	void GameCommands::SetDonutTorque(float param0) {}
	void GameCommands::SetWeebleOffset(float param0) {}
	void GameCommands::SetWheelieRange(float param0) {}
	void GameCommands::SetWheelieOffsetY(float param0) {}
	void GameCommands::SetWheelieOffsetZ(float param0) {}
	void GameCommands::SetShadowAdjustments(float param0, float param1, float param2, float param3, float param4, float param5, float param6, float param7) {}
	void GameCommands::SetCharactersVisible(int32_t param0) {}
	void GameCommands::SetIrisTransition(int32_t param0) {}
	void GameCommands::SetCharacterScale(float param0) {}
	void GameCommands::SetGamblingOdds(float param0) {}
	void GameCommands::SetDriver(const std::string& param0) {}
	void GameCommands::SetHasDoors(int32_t param0) {}
	void GameCommands::SetShininess(float param0) {}
	void GameCommands::SetHighRoof(int32_t param0) {}
	void GameCommands::SetHighSpeedGasScale(float param0) {}
	void GameCommands::SetGasScaleSpeedThreshold(float param0) {}
	void GameCommands::SetAllowSeatSlide(int32_t param0) {}
	void GameCommands::ClearVehicleSelectInfo(const std::string& param0, const std::string& param1 /*= ""*/, const std::string& param2 /*= ""*/) {}
	void GameCommands::AddFlyingActor(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
	void GameCommands::SetCollisionAttributes(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
	void GameCommands::AddSpawnPoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, const std::string& param6, const std::string& param7) {}
	void GameCommands::GagSetWeight(const std::string& param0) {}
	void GameCommands::GagSetLoadDistances(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetTotalWasps(const std::string& param0, const std::string& param1) {}
	void GameCommands::AddGlobalProp(const std::string& param0) {}
	void GameCommands::EnableHitAndRun(const std::string& param0 /*= ""*/) {}
	void GameCommands::SetHitAndRunMeter(const std::string& param0) {}
	void GameCommands::SetChaseSpawnRate(const std::string& param0, const std::string& param1) {}
	void GameCommands::KillAllChaseAI(const std::string& param0) {}
	void GameCommands::ResetHitAndRun(const std::string& param0 /*= ""*/) {}
	void GameCommands::SetHitAndRunDecayInterior(const std::string& param0) {}
	void GameCommands::SetMissionNameIndex(const std::string& param0) {}
	void GameCommands::AddBonusObjective(const std::string& param0, const std::string& param1 /*= ""*/) {}
	void GameCommands::AttachStatePropCollectible(const std::string& param0, const std::string& param1) {}
	void GameCommands::MoveStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::SetStageCamera(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::SetBonusMissionStart(const std::string& param0 /*= ""*/) {}
	void GameCommands::PlacePlayerAtLocatorName(const std::string& param0) {}
	void GameCommands::msPlacePlayerCarAtLocatorName(const std::string& param0) {}
	void GameCommands::ClearTrafficForStage(const std::string& param0 /*= ""*/) {}
	void GameCommands::SetStageAIEvadeCatchupParams(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::AllowUserDump(const std::string& param0 /*= ""*/) {}
	void GameCommands::SetVehicleToLoad(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::SetConversationCamName(const std::string& param0) {}
	void GameCommands::SetConversationCamPcName(const std::string& param0) {}
	void GameCommands::SetConversationCamNpcName(const std::string& param0) {}
	void GameCommands::SetConversationCamDistance(const std::string& param0, const std::string& param1) {}
	void GameCommands::CharacterIsChild(const std::string& param0) {}
	void GameCommands::SetCarStartCamera(const std::string& param0) {}
	void GameCommands::SetPlayerCarName(const std::string& param0, const std::string& param1) {}
	void GameCommands::SetRespawnRate(const std::string& param0, const std::string& param1) {}
	void GameCommands::ActivateTrigger(const std::string& param0) {}
	void GameCommands::DeactivateTrigger(const std::string& param0) {}
	void GameCommands::CreateAnimPhysObject(const std::string& param0, const std::string& param1) {}
	void GameCommands::CreateActionEventTrigger(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
	void GameCommands::LinkActionToObjectJoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
	void GameCommands::LinkActionToObject(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
	void GameCommands::SetCharacterPosition(const std::string& param0, const std::string& param1, const std::string& param2) {}
	void GameCommands::ResetCharacter(const std::string& param0, const std::string& param1) {}
}
