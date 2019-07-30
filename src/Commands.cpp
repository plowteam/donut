#include "Commands.h"
#include <iostream>
#include <fmt/format.h>

namespace Donut
{
    void Commands::Run(const std::string& name, const std::string& params)
    {
        NamedCommands.at(name).sig(params);
    }

    static void LoadP3DFile(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetParticleTexture(int32_t param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void BindReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, int32_t param4, int32_t param5 = 0, const std::string& param6 = "") { std::cout << fmt::format("{0} {1} {2} {3} {4} {5} {6}", param0, param1, param2, param3, param4, param5, param6) << std::endl; }
    static void SetCarAttributes(const std::string& param0, float param1, float param2, float param3, float param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void SetTotalGags(int32_t param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SelectMission(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMissionResetPlayerInCar(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetDynaLoadData(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void UsePedGroup(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddStage(int32_t param0, const std::string& param1 = "", const std::string& param2 = "") { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetPresentationBitmap(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetStageMessageIndex(int32_t param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddObjective(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "") { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetObjTargetVehicle(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void CloseObjective(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void CloseStage(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void RESET_TO_HERE(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHUDIcon(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddCollectible(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "", const std::string& param3 = "") { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void SetStageTime(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddCondition(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void CloseCondition(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void ShowStageComplete(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddNPC(const std::string& param0, const std::string& param1, int32_t param2 = 0) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetDestination(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetCollectibleEffect(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddStageTime(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddObjectiveNPCWaypoint(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetTalkToTarget(const std::string& param0, int32_t param1 = 0, float param2 = 0.0f, const std::string& param3 = "") { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void SetDialogueInfo(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3) { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void SetCamBestSide(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void CloseMission(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void PlacePlayerCar(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetMaxTraffic(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4 = "") { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void AddStageWaypoint(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetRaceLaps(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetDemoLoopTime(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddStageMusicChange(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void LoadDisposableCar(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void AddMission(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void ClearGagBindings(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagBegin(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetInterior(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetCycle(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetPosition(float param0, float param1 = 0.0f, float param2 = 0.0f) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void GagSetRandom(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetSound(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetTrigger(const std::string& param0, float param1, float param2, float param3 = 0.0f, float param4 = 0.0f) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void GagEnd(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetSparkle(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetPersist(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetCoins(int32_t param0, float param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void GagSetAnimCollision(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetIntro(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetOutro(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetCameraShake(float param0, int32_t param1, float param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void GagPlayFMV(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void EnableTutorialMode(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void InitLevelPlayerVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 = "") { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void AddCharacter(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void CreateChaseManager(const std::string& param0, const std::string& param1, int32_t param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetHitAndRunDecay(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetNumChaseCars(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddNPCCharacterBonusMission(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, int32_t param6, const std::string& param7 = "") { std::cout << fmt::format("{0} {1} {2} {3} {4} {5} {6} {7}", param0, param1, param2, param3, param4, param5, param6, param7) << std::endl; }
    static void AddBonusMissionNPCWaypoint(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddAmbientCharacter(const std::string& param0, const std::string& param1, float param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void AddAmbientNPCWaypoint(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddPurchaseCarReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, float param4, const std::string& param5) { std::cout << fmt::format("{0} {1} {2} {3} {4} {5}", param0, param1, param2, param3, param4, param5) << std::endl; }
    static void AddPurchaseCarNPCWaypoint(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void CreateTrafficGroup(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddTrafficModel(const std::string& param0, int32_t param1, int32_t param2 = 0) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void CloseTrafficGroup(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void CreatePedGroup(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddPed(const std::string& param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void ClosePedGroup(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void PreallocateActors(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetProjectileStats(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void AddSpawnPointByLocatorScript(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5) { std::cout << fmt::format("{0} {1} {2} {3} {4} {5}", param0, param1, param2, param3, param4, param5) << std::endl; }
    static void AddBehaviour(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 = "", const std::string& param4 = "", const std::string& param5 = "", const std::string& param6 = "") { std::cout << fmt::format("{0} {1} {2} {3} {4} {5} {6}", param0, param1, param2, param3, param4, param5, param6) << std::endl; }
    static void SetActorRotationSpeed(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetAnimatedCameraName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetAnimCamMulticontName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCoinFee(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void PutMFPlayerInCar(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void StartCountdown(int32_t param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddToCountdownSequence(const std::string& param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void UseElapsedTime(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetRaceEnteryFee(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetParTime(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCondMinHealth(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCondTargetVehicle(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCondTime(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddBonusMission(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddTeleportDest(const std::string& param0, float param1, float param2, float param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void AddVehicleSelectInfo(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SuppressDriver(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetBonusMissionDialoguePos(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void SetConversationCam(int32_t param0, const std::string& param1, const std::string& param2 = "") { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void ClearAmbientAnimations(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddAmbientNpcAnimation(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddAmbientPcAnimation(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetCoinDrawable(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AmbientAnimationRandomize(int32_t param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void TurnGotoDialogOff(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCompletionDialog(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetMissionResetPlayerOutCar(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetMissionStartCameraName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMissionStartMulticontName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetInitialWalk(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetDialoguePositions(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3 = 0) { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void ActivateVehicle(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetStageMusicAlwaysOn(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetNumValidFailureHints(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetVehicleAIParams(const std::string& param0, int32_t param1, int32_t param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void StageStartMusicEvent(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AllowMissionAbort(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void MustActionTrigger(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetStageAITargetCatchupParams(const std::string& param0, int32_t param1, int32_t param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetFollowDistances(int32_t param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetFadeOut(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void StayInBlack(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddStageCharacter(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void SetDurationTime(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetFMVInfo(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetForcedCar(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SwapInDefaultCar(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSwapDefaultCarLocator(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSwapForcedCarLocator(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSwapPlayerLocator(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void StreetRacePropsLoad(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void StreetRacePropsUnload(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetStageAIRaceCatchupParams(const std::string& param0, int32_t param1, float param2, float param3, float param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void DisableHitAndRun(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void NoTrafficForStage(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetConditionPosition(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddSafeZone(const std::string& param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddGagBinding(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void SetPostLevelFMV(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHitNRun(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetObjDistance(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMusicState(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetIrisWipe(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void RemoveDriver(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void RemoveNPC(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddDriver(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetCharacterToHide(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetLevelOver(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagCheckCollCards(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void GagCheckMovie(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void GagSetSoundLoadDistances(int32_t param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void BindCollectibleTo(int32_t param0, int32_t param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddShield(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetStatepropShadow(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddFlyingActorByLocator(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void AddCollectibleStateProp(const std::string& param0, const std::string& param1, int32_t param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetPickupTarget(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetObjTargetBoss(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AllowRockOut(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void ShowHUD(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetGameOver(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GoToPsScreenWhenDone(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMass(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetGasScale(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSlipGasScale(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetBrakeScale(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetTopSpeedKmh(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMaxWheelTurnAngle(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHighSpeedSteeringDrop(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetTireGrip(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetNormalSteering(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSlipSteering(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetEBrakeEffect(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSlipSteeringNoEBrake(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSlipEffectNoEBrake(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCMOffsetX(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCMOffsetY(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCMOffsetZ(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSuspensionLimit(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSpringK(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetDamperC(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetSuspensionYOffset(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHitPoints(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetBurnoutRange(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMaxSpeedBurstTime(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetDonutTorque(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetWeebleOffset(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetWheelieRange(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetWheelieOffsetY(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetWheelieOffsetZ(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetShadowAdjustments(float param0, float param1, float param2, float param3, float param4, float param5, float param6, float param7) { std::cout << fmt::format("{0} {1} {2} {3} {4} {5} {6} {7}", param0, param1, param2, param3, param4, param5, param6, param7) << std::endl; }
    static void SetCharactersVisible(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetIrisTransition(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCharacterScale(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetGamblingOdds(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetDriver(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHasDoors(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetShininess(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHighRoof(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHighSpeedGasScale(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetGasScaleSpeedThreshold(float param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetAllowSeatSlide(int32_t param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void ClearVehicleSelectInfo(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "") { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void AddFlyingActor(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void SetCollisionAttributes(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) { std::cout << fmt::format("{0} {1} {2} {3}", param0, param1, param2, param3) << std::endl; }
    static void AddSpawnPoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, const std::string& param6, const std::string& param7) { std::cout << fmt::format("{0} {1} {2} {3} {4} {5} {6} {7}", param0, param1, param2, param3, param4, param5, param6, param7) << std::endl; }
    static void GagSetWeight(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void GagSetLoadDistances(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetTotalWasps(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AddGlobalProp(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void EnableHitAndRun(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHitAndRunMeter(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetChaseSpawnRate(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void KillAllChaseAI(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void ResetHitAndRun(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetHitAndRunDecayInterior(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetMissionNameIndex(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void AddBonusObjective(const std::string& param0, const std::string& param1 = "") { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void AttachStatePropCollectible(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void MoveStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetStageCamera(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetBonusMissionStart(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void PlacePlayerAtLocatorName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void msPlacePlayerCarAtLocatorName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void ClearTrafficForStage(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetStageAIEvadeCatchupParams(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void AllowUserDump(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetVehicleToLoad(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void SetConversationCamName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetConversationCamPcName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetConversationCamNpcName(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetConversationCamDistance(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void CharacterIsChild(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetCarStartCamera(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void SetPlayerCarName(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void SetRespawnRate(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void ActivateTrigger(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void DeactivateTrigger(const std::string& param0) { std::cout << fmt::format("{0}", param0) << std::endl; }
    static void CreateAnimPhysObject(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }
    static void CreateActionEventTrigger(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void LinkActionToObjectJoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void LinkActionToObject(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) { std::cout << fmt::format("{0} {1} {2} {3} {4}", param0, param1, param2, param3, param4) << std::endl; }
    static void SetCharacterPosition(const std::string& param0, const std::string& param1, const std::string& param2) { std::cout << fmt::format("{0} {1} {2}", param0, param1, param2) << std::endl; }
    static void ResetCharacter(const std::string& param0, const std::string& param1) { std::cout << fmt::format("{0} {1}", param0, param1) << std::endl; }


    static bool TryReadString(const char* data, size_t length, std::string& value, size_t& pos)
    {
        bool open = false;

        for (size_t i = 0; i < length; ++i, ++pos)
        {
            char c = data[i];
            if (c == ' ' && !open) continue;
            if (c == '"')
            {
                if (open) return true;
                else { open = true; continue; }
            }

            if (!open) return false;

            value.push_back(c);
        }

        return false;
    }

    static bool TryReadInt(const char* data, size_t length, int32_t& value, size_t& pos)
    {
        bool begin = false;
        std::string valueString = "";

        for (size_t i = 0; i < length; ++i, ++pos)
        {
            char c = data[i];;
            if (c == ' ')
            {
                if (begin) break;
                else continue;
            }

            if (!isdigit(c))
            {
                if (begin) break;
                else if (c != '-') return false;
            }

            begin = true;
            valueString.push_back(c);
        }

        if (valueString.empty()) return false;

        value = atoi(valueString.c_str());

        return true;
    }

    static bool TryReadFloat(const char* data, size_t length, float& value, size_t& pos)
    {
        bool begin = false;
        bool hasDecimal = false;
        std::string valueString = "";

        for (size_t i = 0; i < length; ++i, ++pos)
        {
            char c = data[i];;
            if (c == ' ')
            {
                if (begin) break;
                else continue;
            }

            if (!isdigit(c))
            {
                if (begin)
                {
                    if (c != '.') break;
                    else
                    {
                        if (hasDecimal) return false;
                        hasDecimal = true;
                    }
                }
                else if (c != '-') return false;
            }

            begin = true;
            valueString.push_back(c);
        }

        if (valueString.empty()) return false;

        value = (float)atof(valueString.c_str());

        return true;
    }

    static bool SkipWhitespace(char c, size_t& pos, size_t length, size_t paramIndex)
    {
        if (c == ' ') pos++;
        else if (c == ',' && pos < length - 1) pos++;
        else if (paramIndex > 0) return false;
        return true;
    }

    static void Command_LoadP3DFile(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        LoadP3DFile(param0, param1);
    }

    static void Command_SetParticleTexture(const std::string& params)
    {
        int32_t param0 = 0;
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetParticleTexture(param0, param1);
    }

    static void Command_BindReward(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        int32_t param4 = 0;
        int32_t param5 = 0;
        std::string param6 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadInt(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadInt(&params[i], length - i, param5, i)) return; paramIndex++; break; }
                case 6: { if (!TryReadString(&params[i], length - i, param6, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        BindReward(param0, param1, param2, param3, param4, param5, param6);
    }

    static void Command_SetCarAttributes(const std::string& params)
    {
        std::string param0 = "";
        float param1 = 0.0f;
        float param2 = 0.0f;
        float param3 = 0.0f;
        float param4 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadFloat(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadFloat(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadFloat(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        SetCarAttributes(param0, param1, param2, param3, param4);
    }

    static void Command_SetTotalGags(const std::string& params)
    {
        int32_t param0 = 0;
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetTotalGags(param0, param1);
    }

    static void Command_SelectMission(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SelectMission(param0);
    }

    static void Command_SetMissionResetPlayerInCar(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMissionResetPlayerInCar(param0);
    }

    static void Command_SetDynaLoadData(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDynaLoadData(param0, param1);
    }

    static void Command_UsePedGroup(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        UsePedGroup(param0);
    }

    static void Command_AddStage(const std::string& params)
    {
        int32_t param0 = 0;
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddStage(param0, param1, param2);
    }

    static void Command_SetPresentationBitmap(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetPresentationBitmap(param0);
    }

    static void Command_SetStageMessageIndex(const std::string& params)
    {
        int32_t param0 = 0;
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetStageMessageIndex(param0, param1);
    }

    static void Command_AddObjective(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddObjective(param0, param1, param2);
    }

    static void Command_SetObjTargetVehicle(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetObjTargetVehicle(param0);
    }

    static void Command_CloseObjective(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CloseObjective(param0);
    }

    static void Command_CloseStage(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CloseStage(param0);
    }

    static void Command_RESET_TO_HERE(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        RESET_TO_HERE(param0);
    }

    static void Command_SetHUDIcon(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHUDIcon(param0);
    }

    static void Command_AddCollectible(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddCollectible(param0, param1, param2, param3);
    }

    static void Command_SetStageTime(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetStageTime(param0);
    }

    static void Command_AddCondition(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddCondition(param0, param1);
    }

    static void Command_CloseCondition(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CloseCondition(param0);
    }

    static void Command_ShowStageComplete(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ShowStageComplete(param0);
    }

    static void Command_AddNPC(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        int32_t param2 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadInt(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddNPC(param0, param1, param2);
    }

    static void Command_SetDestination(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDestination(param0, param1);
    }

    static void Command_SetCollectibleEffect(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCollectibleEffect(param0);
    }

    static void Command_AddStageTime(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddStageTime(param0);
    }

    static void Command_AddObjectiveNPCWaypoint(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddObjectiveNPCWaypoint(param0, param1);
    }

    static void Command_SetTalkToTarget(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;
        float param2 = 0.0f;
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetTalkToTarget(param0, param1, param2, param3);
    }

    static void Command_SetDialogueInfo(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        int32_t param3 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadInt(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 4) return;

        SetDialogueInfo(param0, param1, param2, param3);
    }

    static void Command_SetCamBestSide(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCamBestSide(param0, param1);
    }

    static void Command_CloseMission(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CloseMission(param0);
    }

    static void Command_PlacePlayerCar(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        PlacePlayerCar(param0, param1);
    }

    static void Command_SetMaxTraffic(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMaxTraffic(param0);
    }

    static void Command_AddStageVehicle(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 4) return;

        AddStageVehicle(param0, param1, param2, param3, param4);
    }

    static void Command_AddStageWaypoint(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddStageWaypoint(param0);
    }

    static void Command_SetRaceLaps(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetRaceLaps(param0);
    }

    static void Command_SetDemoLoopTime(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDemoLoopTime(param0);
    }

    static void Command_AddStageMusicChange(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddStageMusicChange(param0);
    }

    static void Command_LoadDisposableCar(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        LoadDisposableCar(param0, param1, param2);
    }

    static void Command_AddMission(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddMission(param0);
    }

    static void Command_ClearGagBindings(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ClearGagBindings(param0);
    }

    static void Command_GagBegin(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagBegin(param0);
    }

    static void Command_GagSetInterior(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetInterior(param0);
    }

    static void Command_GagSetCycle(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetCycle(param0);
    }

    static void Command_GagSetPosition(const std::string& params)
    {
        float param0 = 0.0f;
        float param1 = 0.0f;
        float param2 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadFloat(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetPosition(param0, param1, param2);
    }

    static void Command_GagSetRandom(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetRandom(param0);
    }

    static void Command_GagSetSound(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetSound(param0);
    }

    static void Command_GagSetTrigger(const std::string& params)
    {
        std::string param0 = "";
        float param1 = 0.0f;
        float param2 = 0.0f;
        float param3 = 0.0f;
        float param4 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadFloat(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadFloat(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadFloat(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        GagSetTrigger(param0, param1, param2, param3, param4);
    }

    static void Command_GagEnd(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagEnd(param0);
    }

    static void Command_GagSetSparkle(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetSparkle(param0);
    }

    static void Command_GagSetPersist(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetPersist(param0);
    }

    static void Command_GagSetCoins(const std::string& params)
    {
        int32_t param0 = 0;
        float param1 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadFloat(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        GagSetCoins(param0, param1);
    }

    static void Command_GagSetAnimCollision(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetAnimCollision(param0);
    }

    static void Command_GagSetIntro(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetIntro(param0);
    }

    static void Command_GagSetOutro(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetOutro(param0);
    }

    static void Command_GagSetCameraShake(const std::string& params)
    {
        float param0 = 0.0f;
        int32_t param1 = 0;
        float param2 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        GagSetCameraShake(param0, param1, param2);
    }

    static void Command_GagPlayFMV(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagPlayFMV(param0);
    }

    static void Command_EnableTutorialMode(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        EnableTutorialMode(param0);
    }

    static void Command_InitLevelPlayerVehicle(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        InitLevelPlayerVehicle(param0, param1, param2, param3);
    }

    static void Command_AddCharacter(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddCharacter(param0, param1);
    }

    static void Command_CreateChaseManager(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        int32_t param2 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadInt(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        CreateChaseManager(param0, param1, param2);
    }

    static void Command_SetHitAndRunDecay(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHitAndRunDecay(param0);
    }

    static void Command_SetNumChaseCars(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetNumChaseCars(param0);
    }

    static void Command_AddNPCCharacterBonusMission(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";
        std::string param5 = "";
        int32_t param6 = 0;
        std::string param7 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadString(&params[i], length - i, param5, i)) return; paramIndex++; break; }
                case 6: { if (!TryReadInt(&params[i], length - i, param6, i)) return; paramIndex++; break; }
                case 7: { if (!TryReadString(&params[i], length - i, param7, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 7) return;

        AddNPCCharacterBonusMission(param0, param1, param2, param3, param4, param5, param6, param7);
    }

    static void Command_AddBonusMissionNPCWaypoint(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddBonusMissionNPCWaypoint(param0, param1);
    }

    static void Command_AddAmbientCharacter(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        float param2 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        AddAmbientCharacter(param0, param1, param2);
    }

    static void Command_AddAmbientNPCWaypoint(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddAmbientNPCWaypoint(param0, param1);
    }

    static void Command_AddPurchaseCarReward(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        float param4 = 0.0f;
        std::string param5 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadFloat(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadString(&params[i], length - i, param5, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 6) return;

        AddPurchaseCarReward(param0, param1, param2, param3, param4, param5);
    }

    static void Command_AddPurchaseCarNPCWaypoint(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddPurchaseCarNPCWaypoint(param0, param1);
    }

    static void Command_CreateTrafficGroup(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CreateTrafficGroup(param0);
    }

    static void Command_AddTrafficModel(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;
        int32_t param2 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadInt(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddTrafficModel(param0, param1, param2);
    }

    static void Command_CloseTrafficGroup(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CloseTrafficGroup(param0);
    }

    static void Command_CreatePedGroup(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CreatePedGroup(param0);
    }

    static void Command_AddPed(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddPed(param0, param1);
    }

    static void Command_ClosePedGroup(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ClosePedGroup(param0);
    }

    static void Command_PreallocateActors(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        PreallocateActors(param0, param1);
    }

    static void Command_SetProjectileStats(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetProjectileStats(param0, param1, param2);
    }

    static void Command_AddSpawnPointByLocatorScript(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";
        std::string param5 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadString(&params[i], length - i, param5, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 6) return;

        AddSpawnPointByLocatorScript(param0, param1, param2, param3, param4, param5);
    }

    static void Command_AddBehaviour(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";
        std::string param5 = "";
        std::string param6 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadString(&params[i], length - i, param5, i)) return; paramIndex++; break; }
                case 6: { if (!TryReadString(&params[i], length - i, param6, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        AddBehaviour(param0, param1, param2, param3, param4, param5, param6);
    }

    static void Command_SetActorRotationSpeed(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetActorRotationSpeed(param0, param1);
    }

    static void Command_SetAnimatedCameraName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetAnimatedCameraName(param0);
    }

    static void Command_SetAnimCamMulticontName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetAnimCamMulticontName(param0);
    }

    static void Command_SetCoinFee(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCoinFee(param0);
    }

    static void Command_PutMFPlayerInCar(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        PutMFPlayerInCar(param0);
    }

    static void Command_StartCountdown(const std::string& params)
    {
        int32_t param0 = 0;
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        StartCountdown(param0, param1);
    }

    static void Command_AddToCountdownSequence(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddToCountdownSequence(param0, param1);
    }

    static void Command_UseElapsedTime(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        UseElapsedTime(param0);
    }

    static void Command_SetRaceEnteryFee(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetRaceEnteryFee(param0);
    }

    static void Command_SetParTime(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetParTime(param0);
    }

    static void Command_SetCondMinHealth(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCondMinHealth(param0);
    }

    static void Command_SetCondTargetVehicle(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCondTargetVehicle(param0);
    }

    static void Command_SetCondTime(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCondTime(param0);
    }

    static void Command_AddBonusMission(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddBonusMission(param0);
    }

    static void Command_AddTeleportDest(const std::string& params)
    {
        std::string param0 = "";
        float param1 = 0.0f;
        float param2 = 0.0f;
        float param3 = 0.0f;
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadFloat(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadFloat(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        AddTeleportDest(param0, param1, param2, param3, param4);
    }

    static void Command_AddVehicleSelectInfo(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        AddVehicleSelectInfo(param0, param1, param2);
    }

    static void Command_SuppressDriver(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SuppressDriver(param0);
    }

    static void Command_SetBonusMissionDialoguePos(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 4) return;

        SetBonusMissionDialoguePos(param0, param1, param2, param3);
    }

    static void Command_SetConversationCam(const std::string& params)
    {
        int32_t param0 = 0;
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetConversationCam(param0, param1, param2);
    }

    static void Command_ClearAmbientAnimations(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ClearAmbientAnimations(param0);
    }

    static void Command_AddAmbientNpcAnimation(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddAmbientNpcAnimation(param0, param1);
    }

    static void Command_AddAmbientPcAnimation(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddAmbientPcAnimation(param0, param1);
    }

    static void Command_SetCoinDrawable(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCoinDrawable(param0);
    }

    static void Command_AmbientAnimationRandomize(const std::string& params)
    {
        int32_t param0 = 0;
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AmbientAnimationRandomize(param0, param1);
    }

    static void Command_TurnGotoDialogOff(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        TurnGotoDialogOff(param0);
    }

    static void Command_SetCompletionDialog(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCompletionDialog(param0, param1);
    }

    static void Command_SetMissionResetPlayerOutCar(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetMissionResetPlayerOutCar(param0, param1);
    }

    static void Command_SetMissionStartCameraName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMissionStartCameraName(param0);
    }

    static void Command_SetMissionStartMulticontName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMissionStartMulticontName(param0);
    }

    static void Command_SetInitialWalk(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetInitialWalk(param0);
    }

    static void Command_SetDialoguePositions(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        int32_t param3 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadInt(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetDialoguePositions(param0, param1, param2, param3);
    }

    static void Command_ActivateVehicle(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        ActivateVehicle(param0, param1, param2);
    }

    static void Command_SetStageMusicAlwaysOn(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetStageMusicAlwaysOn(param0);
    }

    static void Command_SetNumValidFailureHints(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetNumValidFailureHints(param0);
    }

    static void Command_SetVehicleAIParams(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;
        int32_t param2 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadInt(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetVehicleAIParams(param0, param1, param2);
    }

    static void Command_StageStartMusicEvent(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        StageStartMusicEvent(param0);
    }

    static void Command_AllowMissionAbort(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AllowMissionAbort(param0);
    }

    static void Command_MustActionTrigger(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        MustActionTrigger(param0);
    }

    static void Command_SetStageAITargetCatchupParams(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;
        int32_t param2 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadInt(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetStageAITargetCatchupParams(param0, param1, param2);
    }

    static void Command_SetFollowDistances(const std::string& params)
    {
        int32_t param0 = 0;
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetFollowDistances(param0, param1);
    }

    static void Command_SetFadeOut(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetFadeOut(param0);
    }

    static void Command_StayInBlack(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        StayInBlack(param0);
    }

    static void Command_AddStageCharacter(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        AddStageCharacter(param0, param1, param2, param3, param4);
    }

    static void Command_SetDurationTime(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDurationTime(param0);
    }

    static void Command_SetFMVInfo(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetFMVInfo(param0, param1);
    }

    static void Command_SetForcedCar(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetForcedCar(param0);
    }

    static void Command_SwapInDefaultCar(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SwapInDefaultCar(param0);
    }

    static void Command_SetSwapDefaultCarLocator(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSwapDefaultCarLocator(param0);
    }

    static void Command_SetSwapForcedCarLocator(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSwapForcedCarLocator(param0);
    }

    static void Command_SetSwapPlayerLocator(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSwapPlayerLocator(param0);
    }

    static void Command_StreetRacePropsLoad(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        StreetRacePropsLoad(param0);
    }

    static void Command_StreetRacePropsUnload(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        StreetRacePropsUnload(param0);
    }

    static void Command_SetStageAIRaceCatchupParams(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;
        float param2 = 0.0f;
        float param3 = 0.0f;
        float param4 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadFloat(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadFloat(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        SetStageAIRaceCatchupParams(param0, param1, param2, param3, param4);
    }

    static void Command_DisableHitAndRun(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        DisableHitAndRun(param0);
    }

    static void Command_NoTrafficForStage(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        NoTrafficForStage(param0);
    }

    static void Command_SetConditionPosition(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetConditionPosition(param0);
    }

    static void Command_AddSafeZone(const std::string& params)
    {
        std::string param0 = "";
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddSafeZone(param0, param1);
    }

    static void Command_AddGagBinding(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        int32_t param3 = 0;
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadInt(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        AddGagBinding(param0, param1, param2, param3, param4);
    }

    static void Command_SetPostLevelFMV(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetPostLevelFMV(param0);
    }

    static void Command_SetHitNRun(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHitNRun(param0);
    }

    static void Command_SetObjDistance(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetObjDistance(param0);
    }

    static void Command_SetMusicState(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetMusicState(param0, param1);
    }

    static void Command_SetIrisWipe(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetIrisWipe(param0);
    }

    static void Command_RemoveDriver(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        RemoveDriver(param0);
    }

    static void Command_RemoveNPC(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        RemoveNPC(param0);
    }

    static void Command_AddDriver(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddDriver(param0, param1);
    }

    static void Command_SetCharacterToHide(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCharacterToHide(param0);
    }

    static void Command_SetLevelOver(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetLevelOver(param0);
    }

    static void Command_GagCheckCollCards(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        GagCheckCollCards(param0, param1, param2, param3, param4);
    }

    static void Command_GagCheckMovie(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 4) return;

        GagCheckMovie(param0, param1, param2, param3);
    }

    static void Command_GagSetSoundLoadDistances(const std::string& params)
    {
        int32_t param0 = 0;
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        GagSetSoundLoadDistances(param0, param1);
    }

    static void Command_BindCollectibleTo(const std::string& params)
    {
        int32_t param0 = 0;
        int32_t param1 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadInt(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        BindCollectibleTo(param0, param1);
    }

    static void Command_AddShield(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AddShield(param0, param1);
    }

    static void Command_SetStatepropShadow(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetStatepropShadow(param0, param1);
    }

    static void Command_AddFlyingActorByLocator(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 4) return;

        AddFlyingActorByLocator(param0, param1, param2, param3);
    }

    static void Command_AddCollectibleStateProp(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        int32_t param2 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadInt(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        AddCollectibleStateProp(param0, param1, param2);
    }

    static void Command_SetPickupTarget(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetPickupTarget(param0);
    }

    static void Command_SetObjTargetBoss(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetObjTargetBoss(param0);
    }

    static void Command_AllowRockOut(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AllowRockOut(param0);
    }

    static void Command_ShowHUD(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ShowHUD(param0);
    }

    static void Command_SetGameOver(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetGameOver(param0);
    }

    static void Command_GoToPsScreenWhenDone(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GoToPsScreenWhenDone(param0);
    }

    static void Command_SetMass(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMass(param0);
    }

    static void Command_SetGasScale(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetGasScale(param0);
    }

    static void Command_SetSlipGasScale(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSlipGasScale(param0);
    }

    static void Command_SetBrakeScale(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetBrakeScale(param0);
    }

    static void Command_SetTopSpeedKmh(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetTopSpeedKmh(param0);
    }

    static void Command_SetMaxWheelTurnAngle(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMaxWheelTurnAngle(param0);
    }

    static void Command_SetHighSpeedSteeringDrop(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHighSpeedSteeringDrop(param0);
    }

    static void Command_SetTireGrip(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetTireGrip(param0);
    }

    static void Command_SetNormalSteering(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetNormalSteering(param0);
    }

    static void Command_SetSlipSteering(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSlipSteering(param0);
    }

    static void Command_SetEBrakeEffect(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetEBrakeEffect(param0);
    }

    static void Command_SetSlipSteeringNoEBrake(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSlipSteeringNoEBrake(param0);
    }

    static void Command_SetSlipEffectNoEBrake(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSlipEffectNoEBrake(param0);
    }

    static void Command_SetCMOffsetX(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCMOffsetX(param0);
    }

    static void Command_SetCMOffsetY(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCMOffsetY(param0);
    }

    static void Command_SetCMOffsetZ(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCMOffsetZ(param0);
    }

    static void Command_SetSuspensionLimit(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSuspensionLimit(param0);
    }

    static void Command_SetSpringK(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSpringK(param0);
    }

    static void Command_SetDamperC(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDamperC(param0);
    }

    static void Command_SetSuspensionYOffset(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetSuspensionYOffset(param0);
    }

    static void Command_SetHitPoints(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHitPoints(param0);
    }

    static void Command_SetBurnoutRange(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetBurnoutRange(param0);
    }

    static void Command_SetMaxSpeedBurstTime(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMaxSpeedBurstTime(param0);
    }

    static void Command_SetDonutTorque(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDonutTorque(param0);
    }

    static void Command_SetWeebleOffset(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetWeebleOffset(param0);
    }

    static void Command_SetWheelieRange(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetWheelieRange(param0);
    }

    static void Command_SetWheelieOffsetY(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetWheelieOffsetY(param0);
    }

    static void Command_SetWheelieOffsetZ(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetWheelieOffsetZ(param0);
    }

    static void Command_SetShadowAdjustments(const std::string& params)
    {
        float param0 = 0.0f;
        float param1 = 0.0f;
        float param2 = 0.0f;
        float param3 = 0.0f;
        float param4 = 0.0f;
        float param5 = 0.0f;
        float param6 = 0.0f;
        float param7 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadFloat(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadFloat(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadFloat(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadFloat(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadFloat(&params[i], length - i, param5, i)) return; paramIndex++; break; }
                case 6: { if (!TryReadFloat(&params[i], length - i, param6, i)) return; paramIndex++; break; }
                case 7: { if (!TryReadFloat(&params[i], length - i, param7, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 8) return;

        SetShadowAdjustments(param0, param1, param2, param3, param4, param5, param6, param7);
    }

    static void Command_SetCharactersVisible(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCharactersVisible(param0);
    }

    static void Command_SetIrisTransition(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetIrisTransition(param0);
    }

    static void Command_SetCharacterScale(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCharacterScale(param0);
    }

    static void Command_SetGamblingOdds(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetGamblingOdds(param0);
    }

    static void Command_SetDriver(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetDriver(param0);
    }

    static void Command_SetHasDoors(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHasDoors(param0);
    }

    static void Command_SetShininess(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetShininess(param0);
    }

    static void Command_SetHighRoof(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHighRoof(param0);
    }

    static void Command_SetHighSpeedGasScale(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHighSpeedGasScale(param0);
    }

    static void Command_SetGasScaleSpeedThreshold(const std::string& params)
    {
        float param0 = 0.0f;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadFloat(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetGasScaleSpeedThreshold(param0);
    }

    static void Command_SetAllowSeatSlide(const std::string& params)
    {
        int32_t param0 = 0;

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadInt(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetAllowSeatSlide(param0);
    }

    static void Command_ClearVehicleSelectInfo(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ClearVehicleSelectInfo(param0, param1, param2);
    }

    static void Command_AddFlyingActor(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        AddFlyingActor(param0, param1, param2, param3, param4);
    }

    static void Command_SetCollisionAttributes(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 4) return;

        SetCollisionAttributes(param0, param1, param2, param3);
    }

    static void Command_AddSpawnPoint(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";
        std::string param5 = "";
        std::string param6 = "";
        std::string param7 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
                case 5: { if (!TryReadString(&params[i], length - i, param5, i)) return; paramIndex++; break; }
                case 6: { if (!TryReadString(&params[i], length - i, param6, i)) return; paramIndex++; break; }
                case 7: { if (!TryReadString(&params[i], length - i, param7, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 8) return;

        AddSpawnPoint(param0, param1, param2, param3, param4, param5, param6, param7);
    }

    static void Command_GagSetWeight(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        GagSetWeight(param0);
    }

    static void Command_GagSetLoadDistances(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        GagSetLoadDistances(param0, param1);
    }

    static void Command_SetTotalWasps(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetTotalWasps(param0, param1);
    }

    static void Command_AddGlobalProp(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddGlobalProp(param0);
    }

    static void Command_EnableHitAndRun(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        EnableHitAndRun(param0);
    }

    static void Command_SetHitAndRunMeter(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHitAndRunMeter(param0);
    }

    static void Command_SetChaseSpawnRate(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetChaseSpawnRate(param0, param1);
    }

    static void Command_KillAllChaseAI(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        KillAllChaseAI(param0);
    }

    static void Command_ResetHitAndRun(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ResetHitAndRun(param0);
    }

    static void Command_SetHitAndRunDecayInterior(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetHitAndRunDecayInterior(param0);
    }

    static void Command_SetMissionNameIndex(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetMissionNameIndex(param0);
    }

    static void Command_AddBonusObjective(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AddBonusObjective(param0, param1);
    }

    static void Command_AttachStatePropCollectible(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        AttachStatePropCollectible(param0, param1);
    }

    static void Command_MoveStageVehicle(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        MoveStageVehicle(param0, param1, param2);
    }

    static void Command_SetStageCamera(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetStageCamera(param0, param1, param2);
    }

    static void Command_SetBonusMissionStart(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetBonusMissionStart(param0);
    }

    static void Command_PlacePlayerAtLocatorName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        PlacePlayerAtLocatorName(param0);
    }

    static void Command_msPlacePlayerCarAtLocatorName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        msPlacePlayerCarAtLocatorName(param0);
    }

    static void Command_ClearTrafficForStage(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ClearTrafficForStage(param0);
    }

    static void Command_SetStageAIEvadeCatchupParams(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetStageAIEvadeCatchupParams(param0, param1, param2);
    }

    static void Command_AllowUserDump(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        AllowUserDump(param0);
    }

    static void Command_SetVehicleToLoad(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetVehicleToLoad(param0, param1, param2);
    }

    static void Command_SetConversationCamName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetConversationCamName(param0);
    }

    static void Command_SetConversationCamPcName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetConversationCamPcName(param0);
    }

    static void Command_SetConversationCamNpcName(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetConversationCamNpcName(param0);
    }

    static void Command_SetConversationCamDistance(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetConversationCamDistance(param0, param1);
    }

    static void Command_CharacterIsChild(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        CharacterIsChild(param0);
    }

    static void Command_SetCarStartCamera(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        SetCarStartCamera(param0);
    }

    static void Command_SetPlayerCarName(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetPlayerCarName(param0, param1);
    }

    static void Command_SetRespawnRate(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        SetRespawnRate(param0, param1);
    }

    static void Command_ActivateTrigger(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        ActivateTrigger(param0);
    }

    static void Command_DeactivateTrigger(const std::string& params)
    {
        std::string param0 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 1) return;

        DeactivateTrigger(param0);
    }

    static void Command_CreateAnimPhysObject(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        CreateAnimPhysObject(param0, param1);
    }

    static void Command_CreateActionEventTrigger(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        CreateActionEventTrigger(param0, param1, param2, param3, param4);
    }

    static void Command_LinkActionToObjectJoint(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        LinkActionToObjectJoint(param0, param1, param2, param3, param4);
    }

    static void Command_LinkActionToObject(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";
        std::string param3 = "";
        std::string param4 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
                case 3: { if (!TryReadString(&params[i], length - i, param3, i)) return; paramIndex++; break; }
                case 4: { if (!TryReadString(&params[i], length - i, param4, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 5) return;

        LinkActionToObject(param0, param1, param2, param3, param4);
    }

    static void Command_SetCharacterPosition(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";
        std::string param2 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
                case 2: { if (!TryReadString(&params[i], length - i, param2, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 3) return;

        SetCharacterPosition(param0, param1, param2);
    }

    static void Command_ResetCharacter(const std::string& params)
    {
        std::string param0 = "";
        std::string param1 = "";

        size_t paramIndex = 0;
        size_t length = params.length();
        for (size_t i = 0; i < length; ++i)
        {
            if (!SkipWhitespace(params[i], i, length, paramIndex)) return;
            if (i == length) break;

            switch (paramIndex)
            {
                case 0: { if (!TryReadString(&params[i], length - i, param0, i)) return; paramIndex++; break; }
                case 1: { if (!TryReadString(&params[i], length - i, param1, i)) return; paramIndex++; break; }
            }
        }

        if (paramIndex < 2) return;

        ResetCharacter(param0, param1);
    }

    std::unordered_map<std::string, Command> Commands::NamedCommands =
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
