#include <Commands.h>
#include <iostream>
#include <fmt/format.h>

namespace Donut
{
    static void LoadP3DFile(const std::string& param0, const std::string& param1 = "") {}
    static void SetParticleTexture(int32_t param0, const std::string& param1) {}
    static void BindReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, int32_t param4, int32_t param5 = 0, const std::string& param6 = "") {}
    static void SetCarAttributes(const std::string& param0, float param1, float param2, float param3, float param4) {}
    static void SetTotalGags(int32_t param0, int32_t param1) {}
    static void SelectMission(const std::string& param0) {}
    static void SetMissionResetPlayerInCar(const std::string& param0) {}
    static void SetDynaLoadData(const std::string& param0, const std::string& param1 = "") {}
    static void UsePedGroup(int32_t param0) {}
    static void AddStage(const std::string& param0 = "", const std::string& param1 = "", const std::string& param2 = "") {}
    static void SetPresentationBitmap(const std::string& param0) {}
    static void SetStageMessageIndex(int32_t param0, const std::string& param1 = "") {}
    static void AddObjective(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "") {}
    static void SetObjTargetVehicle(const std::string& param0) {}
    static void CloseObjective(int32_t param0 = 0) {}
    static void CloseStage(int32_t param0 = 0) {}
    static void RESET_TO_HERE(int32_t param0 = 0) {}
    static void SetHUDIcon(const std::string& param0) {}
    static void AddCollectible(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "", const std::string& param3 = "") {}
    static void SetStageTime(int32_t param0) {}
    static void AddCondition(const std::string& param0, const std::string& param1 = "") {}
    static void CloseCondition(int32_t param0 = 0) {}
    static void ShowStageComplete(int32_t param0 = 0) {}
    static void AddNPC(const std::string& param0, const std::string& param1, const std::string& param2 = "") {}
    static void SetDestination(const std::string& param0, const std::string& param1 = "") {}
    static void SetCollectibleEffect(const std::string& param0) {}
    static void AddStageTime(int32_t param0) {}
    static void AddObjectiveNPCWaypoint(const std::string& param0, const std::string& param1) {}
    static void SetTalkToTarget(const std::string& param0, int32_t param1 = 0, float param2 = 0.0f, const std::string& param3 = "") {}
    static void SetDialogueInfo(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3) {}
    static void SetCamBestSide(const std::string& param0, const std::string& param1 = "") {}
    static void CloseMission(int32_t param0 = 0) {}
    static void PlacePlayerCar(const std::string& param0, const std::string& param1) {}
    static void SetMaxTraffic(int32_t param0) {}
    static void AddStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4 = "") {}
    static void AddStageWaypoint(const std::string& param0) {}
    static void SetRaceLaps(int32_t param0) {}
    static void SetDemoLoopTime(int64_t param0) {}
    static void AddStageMusicChange(int32_t param0 = 0) {}
    static void LoadDisposableCar(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void AddMission(const std::string& param0) {}
    static void ClearGagBindings(int32_t param0 = 0) {}
    static void GagBegin(const std::string& param0) {}
    static void GagSetInterior(const std::string& param0) {}
    static void GagSetCycle(const std::string& param0) {}
    static void GagSetPosition(const std::string& param0) {}
    static void GagSetPosition(float param0, float param1, float param2) {}
    static void GagSetRandom(int32_t param0) {}
    static void GagSetSound(const std::string& param0) {}
    static void GagSetTrigger(const std::string& param0, const std::string& param1, float param2) {}
    static void GagSetTrigger(const std::string& param0, float param1, float param2, float param3, float param4) {}
    static void GagEnd(int32_t param0 = 0) {}
    static void GagSetSparkle(int32_t param0) {}
    static void GagSetPersist(int32_t param0) {}
    static void GagSetCoins(int32_t param0, float param1) {}
    static void GagSetAnimCollision(int32_t param0) {}
    static void GagSetIntro(int32_t param0) {}
    static void GagSetOutro(int32_t param0) {}
    static void GagSetCameraShake(float param0, int32_t param1, float param2) {}
    static void GagPlayFMV(const std::string& param0) {}
    static void EnableTutorialMode(const std::string& param0) {}
    static void InitLevelPlayerVehicle(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 = "") {}
    static void AddCharacter(const std::string& param0, const std::string& param1) {}
    static void CreateChaseManager(const std::string& param0, const std::string& param1, int32_t param2) {}
    static void SetHitAndRunDecay(float param0) {}
    static void SetNumChaseCars(const std::string& param0) {}
    static void AddNPCCharacterBonusMission(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, int32_t param6, const std::string& param7 = "") {}
    static void AddBonusMissionNPCWaypoint(const std::string& param0, const std::string& param1) {}
    static void AddAmbientCharacter(const std::string& param0, const std::string& param1, float param2) {}
    static void AddAmbientNPCWaypoint(const std::string& param0, const std::string& param1) {}
    static void AddPurchaseCarReward(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, float param4, const std::string& param5) {}
    static void AddPurchaseCarNPCWaypoint(const std::string& param0, const std::string& param1) {}
    static void CreateTrafficGroup(int32_t param0) {}
    static void AddTrafficModel(const std::string& param0, int32_t param1, int32_t param2 = 0) {}
    static void CloseTrafficGroup(int32_t param0 = 0) {}
    static void CreatePedGroup(int32_t param0) {}
    static void AddPed(const std::string& param0, int32_t param1) {}
    static void ClosePedGroup(int32_t param0 = 0) {}
    static void PreallocateActors(const std::string& param0, const std::string& param1) {}
    static void SetProjectileStats(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void AddSpawnPointByLocatorScript(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5) {}
    static void AddBehaviour(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3 = "", const std::string& param4 = "", const std::string& param5 = "", const std::string& param6 = "") {}
    static void SetActorRotationSpeed(const std::string& param0, const std::string& param1) {}
    static void SetAnimatedCameraName(const std::string& param0) {}
    static void SetAnimCamMulticontName(const std::string& param0) {}
    static void SetCoinFee(int32_t param0) {}
    static void PutMFPlayerInCar(int32_t param0 = 0) {}
    static void StartCountdown(const std::string& param0, const std::string& param1 = "") {}
    static void AddToCountdownSequence(const std::string& param0, int32_t param1) {}
    static void UseElapsedTime(int32_t param0 = 0) {}
    static void SetRaceEnteryFee(int32_t param0) {}
    static void SetParTime(int32_t param0) {}
    static void SetCondMinHealth(float param0) {}
    static void SetCondTargetVehicle(const std::string& param0) {}
    static void SetCondTime(int32_t param0) {}
    static void AddBonusMission(const std::string& param0) {}
    static void AddTeleportDest(const std::string& param0, float param1, float param2, float param3, const std::string& param4) {}
    static void AddVehicleSelectInfo(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void SuppressDriver(const std::string& param0) {}
    static void SetBonusMissionDialoguePos(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
    static void SetConversationCam(int32_t param0, const std::string& param1, const std::string& param2 = "") {}
    static void ClearAmbientAnimations(const std::string& param0) {}
    static void AddAmbientNpcAnimation(const std::string& param0, const std::string& param1 = "") {}
    static void AddAmbientPcAnimation(const std::string& param0, const std::string& param1 = "") {}
    static void SetCoinDrawable(const std::string& param0) {}
    static void AmbientAnimationRandomize(int32_t param0, int32_t param1) {}
    static void TurnGotoDialogOff(int32_t param0 = 0) {}
    static void SetCompletionDialog(const std::string& param0, const std::string& param1 = "") {}
    static void SetMissionResetPlayerOutCar(const std::string& param0, const std::string& param1) {}
    static void SetMissionStartCameraName(const std::string& param0) {}
    static void SetMissionStartMulticontName(const std::string& param0) {}
    static void SetInitialWalk(const std::string& param0) {}
    static void SetDialoguePositions(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3 = 0) {}
    static void ActivateVehicle(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void SetStageMusicAlwaysOn(int32_t param0 = 0) {}
    static void SetNumValidFailureHints(int32_t param0) {}
    static void SetVehicleAIParams(const std::string& param0, int32_t param1, int32_t param2) {}
    static void StageStartMusicEvent(const std::string& param0) {}
    static void AllowMissionAbort(const std::string& param0) {}
    static void MustActionTrigger(int32_t param0 = 0) {}
    static void SetStageAITargetCatchupParams(const std::string& param0, int32_t param1, int32_t param2) {}
    static void SetFollowDistances(int32_t param0, int32_t param1) {}
    static void SetFadeOut(float param0) {}
    static void StayInBlack(int32_t param0 = 0) {}
    static void AddStageCharacter(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
    static void SetDurationTime(float param0) {}
    static void SetFMVInfo(const std::string& param0, const std::string& param1 = "") {}
    static void SetForcedCar(int32_t param0 = 0) {}
    static void SwapInDefaultCar(int32_t param0 = 0) {}
    static void SetSwapDefaultCarLocator(const std::string& param0) {}
    static void SetSwapForcedCarLocator(const std::string& param0) {}
    static void SetSwapPlayerLocator(const std::string& param0) {}
    static void StreetRacePropsLoad(const std::string& param0) {}
    static void StreetRacePropsUnload(const std::string& param0) {}
    static void SetStageAIRaceCatchupParams(const std::string& param0, int32_t param1, float param2, float param3, float param4) {}
    static void DisableHitAndRun(int32_t param0 = 0) {}
    static void NoTrafficForStage(int32_t param0 = 0) {}
    static void SetConditionPosition(int32_t param0) {}
    static void AddSafeZone(const std::string& param0, int32_t param1) {}
    static void AddGagBinding(const std::string& param0, const std::string& param1, const std::string& param2, int32_t param3, const std::string& param4) {}
    static void SetPostLevelFMV(const std::string& param0) {}
    static void SetHitNRun(int32_t param0 = 0) {}
    static void SetObjDistance(int32_t param0) {}
    static void SetMusicState(const std::string& param0, const std::string& param1) {}
    static void SetIrisWipe(float param0) {}
    static void RemoveDriver(const std::string& param0) {}
    static void RemoveNPC(const std::string& param0) {}
    static void AddDriver(const std::string& param0, const std::string& param1) {}
    static void SetCharacterToHide(const std::string& param0) {}
    static void SetLevelOver(int32_t param0 = 0) {}
    static void GagCheckCollCards(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
    static void GagCheckMovie(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
    static void GagSetSoundLoadDistances(int32_t param0, int32_t param1) {}
    static void BindCollectibleTo(int32_t param0, int32_t param1) {}
    static void AddShield(const std::string& param0, const std::string& param1) {}
    static void SetStatepropShadow(const std::string& param0, const std::string& param1) {}
    static void AddFlyingActorByLocator(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
    static void AddCollectibleStateProp(const std::string& param0, const std::string& param1, int32_t param2) {}
    static void SetPickupTarget(const std::string& param0) {}
    static void SetObjTargetBoss(const std::string& param0) {}
    static void AllowRockOut(int32_t param0 = 0) {}
    static void ShowHUD(const std::string& param0) {}
    static void SetGameOver(int32_t param0 = 0) {}
    static void GoToPsScreenWhenDone(int32_t param0 = 0) {}
    static void SetMass(float param0) {}
    static void SetGasScale(float param0) {}
    static void SetSlipGasScale(float param0) {}
    static void SetBrakeScale(float param0) {}
    static void SetTopSpeedKmh(float param0) {}
    static void SetMaxWheelTurnAngle(float param0) {}
    static void SetHighSpeedSteeringDrop(float param0) {}
    static void SetTireGrip(float param0) {}
    static void SetNormalSteering(float param0) {}
    static void SetSlipSteering(float param0) {}
    static void SetEBrakeEffect(float param0) {}
    static void SetSlipSteeringNoEBrake(float param0) {}
    static void SetSlipEffectNoEBrake(float param0) {}
    static void SetCMOffsetX(float param0) {}
    static void SetCMOffsetY(float param0) {}
    static void SetCMOffsetZ(float param0) {}
    static void SetSuspensionLimit(float param0) {}
    static void SetSpringK(float param0) {}
    static void SetDamperC(float param0) {}
    static void SetSuspensionYOffset(float param0) {}
    static void SetHitPoints(float param0) {}
    static void SetBurnoutRange(float param0) {}
    static void SetMaxSpeedBurstTime(float param0) {}
    static void SetDonutTorque(float param0) {}
    static void SetWeebleOffset(float param0) {}
    static void SetWheelieRange(float param0) {}
    static void SetWheelieOffsetY(float param0) {}
    static void SetWheelieOffsetZ(float param0) {}
    static void SetShadowAdjustments(float param0, float param1, float param2, float param3, float param4, float param5, float param6, float param7) {}
    static void SetCharactersVisible(int32_t param0) {}
    static void SetIrisTransition(int32_t param0) {}
    static void SetCharacterScale(float param0) {}
    static void SetGamblingOdds(float param0) {}
    static void SetDriver(const std::string& param0) {}
    static void SetHasDoors(int32_t param0) {}
    static void SetShininess(float param0) {}
    static void SetHighRoof(int32_t param0) {}
    static void SetHighSpeedGasScale(float param0) {}
    static void SetGasScaleSpeedThreshold(float param0) {}
    static void SetAllowSeatSlide(int32_t param0) {}
    static void ClearVehicleSelectInfo(const std::string& param0, const std::string& param1 = "", const std::string& param2 = "") {}
    static void AddFlyingActor(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
    static void SetCollisionAttributes(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3) {}
    static void AddSpawnPoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4, const std::string& param5, const std::string& param6, const std::string& param7) {}
    static void GagSetWeight(const std::string& param0) {}
    static void GagSetLoadDistances(const std::string& param0, const std::string& param1) {}
    static void SetTotalWasps(const std::string& param0, const std::string& param1) {}
    static void AddGlobalProp(const std::string& param0) {}
    static void EnableHitAndRun(const std::string& param0 = "") {}
    static void SetHitAndRunMeter(const std::string& param0) {}
    static void SetChaseSpawnRate(const std::string& param0, const std::string& param1) {}
    static void KillAllChaseAI(const std::string& param0) {}
    static void ResetHitAndRun(const std::string& param0 = "") {}
    static void SetHitAndRunDecayInterior(const std::string& param0) {}
    static void SetMissionNameIndex(const std::string& param0) {}
    static void AddBonusObjective(const std::string& param0, const std::string& param1 = "") {}
    static void AttachStatePropCollectible(const std::string& param0, const std::string& param1) {}
    static void MoveStageVehicle(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void SetStageCamera(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void SetBonusMissionStart(const std::string& param0 = "") {}
    static void PlacePlayerAtLocatorName(const std::string& param0) {}
    static void msPlacePlayerCarAtLocatorName(const std::string& param0) {}
    static void ClearTrafficForStage(const std::string& param0 = "") {}
    static void SetStageAIEvadeCatchupParams(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void AllowUserDump(const std::string& param0 = "") {}
    static void SetVehicleToLoad(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void SetConversationCamName(const std::string& param0) {}
    static void SetConversationCamPcName(const std::string& param0) {}
    static void SetConversationCamNpcName(const std::string& param0) {}
    static void SetConversationCamDistance(const std::string& param0, const std::string& param1) {}
    static void CharacterIsChild(const std::string& param0) {}
    static void SetCarStartCamera(const std::string& param0) {}
    static void SetPlayerCarName(const std::string& param0, const std::string& param1) {}
    static void SetRespawnRate(const std::string& param0, const std::string& param1) {}
    static void ActivateTrigger(const std::string& param0) {}
    static void DeactivateTrigger(const std::string& param0) {}
    static void CreateAnimPhysObject(const std::string& param0, const std::string& param1) {}
    static void CreateActionEventTrigger(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
    static void LinkActionToObjectJoint(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
    static void LinkActionToObject(const std::string& param0, const std::string& param1, const std::string& param2, const std::string& param3, const std::string& param4) {}
    static void SetCharacterPosition(const std::string& param0, const std::string& param1, const std::string& param2) {}
    static void ResetCharacter(const std::string& param0, const std::string& param1) {}

    static bool Command_LoadP3DFile(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];
        const auto& param1 = (numParams > 1) ? splits[1] : "";

        LoadP3DFile(param0, param1);
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

        SetParticleTexture(param0, param1);
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

        BindReward(param0, param1, param2, param3, param4, param5, param6);
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

        SetCarAttributes(param0, param1, param2, param3, param4);
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

        SetTotalGags(param0, param1);
        return true;
    }

    static bool Command_SelectMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SelectMission(param0);
        return true;
    }

    static bool Command_SetMissionResetPlayerInCar(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetMissionResetPlayerInCar(param0);
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

        SetDynaLoadData(param0, param1);
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

        UsePedGroup(param0);
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

        AddStage(param0, param1, param2);
        return true;
    }

    static bool Command_SetPresentationBitmap(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetPresentationBitmap(param0);
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

        SetStageMessageIndex(param0, param1);
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

        AddObjective(param0, param1, param2);
        return true;
    }

    static bool Command_SetObjTargetVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetObjTargetVehicle(param0);
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

        CloseObjective(param0);
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

        CloseStage(param0);
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

        RESET_TO_HERE(param0);
        return true;
    }

    static bool Command_SetHUDIcon(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetHUDIcon(param0);
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

        AddCollectible(param0, param1, param2, param3);
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

        SetStageTime(param0);
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

        AddCondition(param0, param1);
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

        CloseCondition(param0);
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

        ShowStageComplete(param0);
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

        AddNPC(param0, param1, param2);
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

        SetDestination(param0, param1);
        return true;
    }

    static bool Command_SetCollectibleEffect(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetCollectibleEffect(param0);
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

        AddStageTime(param0);
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

        AddObjectiveNPCWaypoint(param0, param1);
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

        SetTalkToTarget(param0, param1, param2, param3);
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

        SetDialogueInfo(param0, param1, param2, param3);
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

        SetCamBestSide(param0, param1);
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

        CloseMission(param0);
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

        PlacePlayerCar(param0, param1);
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

        SetMaxTraffic(param0);
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

        AddStageVehicle(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_AddStageWaypoint(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        AddStageWaypoint(param0);
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

        SetRaceLaps(param0);
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

        SetDemoLoopTime(param0);
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

        AddStageMusicChange(param0);
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

        LoadDisposableCar(param0, param1, param2);
        return true;
    }

    static bool Command_AddMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        AddMission(param0);
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

        ClearGagBindings(param0);
        return true;
    }

    static bool Command_GagBegin(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        GagBegin(param0);
        return true;
    }

    static bool Command_GagSetInterior(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        GagSetInterior(param0);
        return true;
    }

    static bool Command_GagSetCycle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        GagSetCycle(param0);
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

                GagSetPosition(param0);
                return true;
            }
            case 3:
            {
                float param0; if (!Commands::StringToFloat(splits[0], param0)) return false;
                float param1; if (!Commands::StringToFloat(splits[1], param1)) return false;
                float param2; if (!Commands::StringToFloat(splits[2], param2)) return false;

                GagSetPosition(param0, param1, param2);
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

        GagSetRandom(param0);
        return true;
    }

    static bool Command_GagSetSound(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        GagSetSound(param0);
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

                GagSetTrigger(param0, param1, param2);
                return true;
            }
            case 5:
            {
                const auto& param0 = splits[0];
                float param1; if (!Commands::StringToFloat(splits[1], param1)) return false;
                float param2; if (!Commands::StringToFloat(splits[2], param2)) return false;
                float param3; if (!Commands::StringToFloat(splits[3], param3)) return false;
                float param4; if (!Commands::StringToFloat(splits[4], param4)) return false;

                GagSetTrigger(param0, param1, param2, param3, param4);
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

        GagEnd(param0);
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

        GagSetSparkle(param0);
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

        GagSetPersist(param0);
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

        GagSetCoins(param0, param1);
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

        GagSetAnimCollision(param0);
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

        GagSetIntro(param0);
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

        GagSetOutro(param0);
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

        GagSetCameraShake(param0, param1, param2);
        return true;
    }

    static bool Command_GagPlayFMV(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        GagPlayFMV(param0);
        return true;
    }

    static bool Command_EnableTutorialMode(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        EnableTutorialMode(param0);
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

        InitLevelPlayerVehicle(param0, param1, param2, param3);
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

        AddCharacter(param0, param1);
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

        CreateChaseManager(param0, param1, param2);
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

        SetHitAndRunDecay(param0);
        return true;
    }

    static bool Command_SetNumChaseCars(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetNumChaseCars(param0);
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

        AddNPCCharacterBonusMission(param0, param1, param2, param3, param4, param5, param6, param7);
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

        AddBonusMissionNPCWaypoint(param0, param1);
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

        AddAmbientCharacter(param0, param1, param2);
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

        AddAmbientNPCWaypoint(param0, param1);
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

        AddPurchaseCarReward(param0, param1, param2, param3, param4, param5);
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

        AddPurchaseCarNPCWaypoint(param0, param1);
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

        CreateTrafficGroup(param0);
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

        AddTrafficModel(param0, param1, param2);
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

        CloseTrafficGroup(param0);
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

        CreatePedGroup(param0);
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

        AddPed(param0, param1);
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

        ClosePedGroup(param0);
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

        PreallocateActors(param0, param1);
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

        SetProjectileStats(param0, param1, param2);
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

        AddSpawnPointByLocatorScript(param0, param1, param2, param3, param4, param5);
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

        AddBehaviour(param0, param1, param2, param3, param4, param5, param6);
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

        SetActorRotationSpeed(param0, param1);
        return true;
    }

    static bool Command_SetAnimatedCameraName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetAnimatedCameraName(param0);
        return true;
    }

    static bool Command_SetAnimCamMulticontName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetAnimCamMulticontName(param0);
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

        SetCoinFee(param0);
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

        PutMFPlayerInCar(param0);
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

        StartCountdown(param0, param1);
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

        AddToCountdownSequence(param0, param1);
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

        UseElapsedTime(param0);
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

        SetRaceEnteryFee(param0);
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

        SetParTime(param0);
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

        SetCondMinHealth(param0);
        return true;
    }

    static bool Command_SetCondTargetVehicle(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetCondTargetVehicle(param0);
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

        SetCondTime(param0);
        return true;
    }

    static bool Command_AddBonusMission(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        AddBonusMission(param0);
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

        AddTeleportDest(param0, param1, param2, param3, param4);
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

        AddVehicleSelectInfo(param0, param1, param2);
        return true;
    }

    static bool Command_SuppressDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SuppressDriver(param0);
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

        SetBonusMissionDialoguePos(param0, param1, param2, param3);
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

        SetConversationCam(param0, param1, param2);
        return true;
    }

    static bool Command_ClearAmbientAnimations(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        ClearAmbientAnimations(param0);
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

        AddAmbientNpcAnimation(param0, param1);
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

        AddAmbientPcAnimation(param0, param1);
        return true;
    }

    static bool Command_SetCoinDrawable(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetCoinDrawable(param0);
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

        AmbientAnimationRandomize(param0, param1);
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

        TurnGotoDialogOff(param0);
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

        SetCompletionDialog(param0, param1);
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

        SetMissionResetPlayerOutCar(param0, param1);
        return true;
    }

    static bool Command_SetMissionStartCameraName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetMissionStartCameraName(param0);
        return true;
    }

    static bool Command_SetMissionStartMulticontName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetMissionStartMulticontName(param0);
        return true;
    }

    static bool Command_SetInitialWalk(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetInitialWalk(param0);
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

        SetDialoguePositions(param0, param1, param2, param3);
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

        ActivateVehicle(param0, param1, param2);
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

        SetStageMusicAlwaysOn(param0);
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

        SetNumValidFailureHints(param0);
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

        SetVehicleAIParams(param0, param1, param2);
        return true;
    }

    static bool Command_StageStartMusicEvent(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        StageStartMusicEvent(param0);
        return true;
    }

    static bool Command_AllowMissionAbort(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        AllowMissionAbort(param0);
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

        MustActionTrigger(param0);
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

        SetStageAITargetCatchupParams(param0, param1, param2);
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

        SetFollowDistances(param0, param1);
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

        SetFadeOut(param0);
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

        StayInBlack(param0);
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

        AddStageCharacter(param0, param1, param2, param3, param4);
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

        SetDurationTime(param0);
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

        SetFMVInfo(param0, param1);
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

        SetForcedCar(param0);
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

        SwapInDefaultCar(param0);
        return true;
    }

    static bool Command_SetSwapDefaultCarLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetSwapDefaultCarLocator(param0);
        return true;
    }

    static bool Command_SetSwapForcedCarLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetSwapForcedCarLocator(param0);
        return true;
    }

    static bool Command_SetSwapPlayerLocator(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetSwapPlayerLocator(param0);
        return true;
    }

    static bool Command_StreetRacePropsLoad(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        StreetRacePropsLoad(param0);
        return true;
    }

    static bool Command_StreetRacePropsUnload(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        StreetRacePropsUnload(param0);
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

        SetStageAIRaceCatchupParams(param0, param1, param2, param3, param4);
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

        DisableHitAndRun(param0);
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

        NoTrafficForStage(param0);
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

        SetConditionPosition(param0);
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

        AddSafeZone(param0, param1);
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

        AddGagBinding(param0, param1, param2, param3, param4);
        return true;
    }

    static bool Command_SetPostLevelFMV(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetPostLevelFMV(param0);
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

        SetHitNRun(param0);
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

        SetObjDistance(param0);
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

        SetMusicState(param0, param1);
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

        SetIrisWipe(param0);
        return true;
    }

    static bool Command_RemoveDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        RemoveDriver(param0);
        return true;
    }

    static bool Command_RemoveNPC(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        RemoveNPC(param0);
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

        AddDriver(param0, param1);
        return true;
    }

    static bool Command_SetCharacterToHide(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetCharacterToHide(param0);
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

        SetLevelOver(param0);
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

        GagCheckCollCards(param0, param1, param2, param3, param4);
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

        GagCheckMovie(param0, param1, param2, param3);
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

        GagSetSoundLoadDistances(param0, param1);
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

        BindCollectibleTo(param0, param1);
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

        AddShield(param0, param1);
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

        SetStatepropShadow(param0, param1);
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

        AddFlyingActorByLocator(param0, param1, param2, param3);
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

        AddCollectibleStateProp(param0, param1, param2);
        return true;
    }

    static bool Command_SetPickupTarget(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetPickupTarget(param0);
        return true;
    }

    static bool Command_SetObjTargetBoss(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetObjTargetBoss(param0);
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

        AllowRockOut(param0);
        return true;
    }

    static bool Command_ShowHUD(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        ShowHUD(param0);
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

        SetGameOver(param0);
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

        GoToPsScreenWhenDone(param0);
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

        SetMass(param0);
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

        SetGasScale(param0);
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

        SetSlipGasScale(param0);
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

        SetBrakeScale(param0);
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

        SetTopSpeedKmh(param0);
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

        SetMaxWheelTurnAngle(param0);
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

        SetHighSpeedSteeringDrop(param0);
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

        SetTireGrip(param0);
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

        SetNormalSteering(param0);
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

        SetSlipSteering(param0);
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

        SetEBrakeEffect(param0);
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

        SetSlipSteeringNoEBrake(param0);
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

        SetSlipEffectNoEBrake(param0);
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

        SetCMOffsetX(param0);
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

        SetCMOffsetY(param0);
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

        SetCMOffsetZ(param0);
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

        SetSuspensionLimit(param0);
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

        SetSpringK(param0);
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

        SetDamperC(param0);
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

        SetSuspensionYOffset(param0);
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

        SetHitPoints(param0);
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

        SetBurnoutRange(param0);
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

        SetMaxSpeedBurstTime(param0);
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

        SetDonutTorque(param0);
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

        SetWeebleOffset(param0);
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

        SetWheelieRange(param0);
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

        SetWheelieOffsetY(param0);
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

        SetWheelieOffsetZ(param0);
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

        SetShadowAdjustments(param0, param1, param2, param3, param4, param5, param6, param7);
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

        SetCharactersVisible(param0);
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

        SetIrisTransition(param0);
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

        SetCharacterScale(param0);
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

        SetGamblingOdds(param0);
        return true;
    }

    static bool Command_SetDriver(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetDriver(param0);
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

        SetHasDoors(param0);
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

        SetShininess(param0);
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

        SetHighRoof(param0);
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

        SetHighSpeedGasScale(param0);
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

        SetGasScaleSpeedThreshold(param0);
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

        SetAllowSeatSlide(param0);
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

        ClearVehicleSelectInfo(param0, param1, param2);
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

        AddFlyingActor(param0, param1, param2, param3, param4);
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

        SetCollisionAttributes(param0, param1, param2, param3);
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

        AddSpawnPoint(param0, param1, param2, param3, param4, param5, param6, param7);
        return true;
    }

    static bool Command_GagSetWeight(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        GagSetWeight(param0);
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

        GagSetLoadDistances(param0, param1);
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

        SetTotalWasps(param0, param1);
        return true;
    }

    static bool Command_AddGlobalProp(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        AddGlobalProp(param0);
        return true;
    }

    static bool Command_EnableHitAndRun(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        EnableHitAndRun(param0);
        return true;
    }

    static bool Command_SetHitAndRunMeter(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetHitAndRunMeter(param0);
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

        SetChaseSpawnRate(param0, param1);
        return true;
    }

    static bool Command_KillAllChaseAI(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        KillAllChaseAI(param0);
        return true;
    }

    static bool Command_ResetHitAndRun(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        ResetHitAndRun(param0);
        return true;
    }

    static bool Command_SetHitAndRunDecayInterior(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetHitAndRunDecayInterior(param0);
        return true;
    }

    static bool Command_SetMissionNameIndex(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetMissionNameIndex(param0);
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

        AddBonusObjective(param0, param1);
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

        AttachStatePropCollectible(param0, param1);
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

        MoveStageVehicle(param0, param1, param2);
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

        SetStageCamera(param0, param1, param2);
        return true;
    }

    static bool Command_SetBonusMissionStart(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        SetBonusMissionStart(param0);
        return true;
    }

    static bool Command_PlacePlayerAtLocatorName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        PlacePlayerAtLocatorName(param0);
        return true;
    }

    static bool Command_msPlacePlayerCarAtLocatorName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        msPlacePlayerCarAtLocatorName(param0);
        return true;
    }

    static bool Command_ClearTrafficForStage(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        ClearTrafficForStage(param0);
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

        SetStageAIEvadeCatchupParams(param0, param1, param2);
        return true;
    }

    static bool Command_AllowUserDump(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();

        const auto& param0 = (numParams > 0) ? splits[0] : "";

        AllowUserDump(param0);
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

        SetVehicleToLoad(param0, param1, param2);
        return true;
    }

    static bool Command_SetConversationCamName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetConversationCamName(param0);
        return true;
    }

    static bool Command_SetConversationCamPcName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetConversationCamPcName(param0);
        return true;
    }

    static bool Command_SetConversationCamNpcName(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetConversationCamNpcName(param0);
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

        SetConversationCamDistance(param0, param1);
        return true;
    }

    static bool Command_CharacterIsChild(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        CharacterIsChild(param0);
        return true;
    }

    static bool Command_SetCarStartCamera(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        SetCarStartCamera(param0);
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

        SetPlayerCarName(param0, param1);
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

        SetRespawnRate(param0, param1);
        return true;
    }

    static bool Command_ActivateTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        ActivateTrigger(param0);
        return true;
    }

    static bool Command_DeactivateTrigger(const std::string& params)
    {
        std::vector<std::string> splits;
        if (!Commands::SplitParams(params, splits)) return false;

        size_t numParams = splits.size();
        if (numParams < 1) return false;

        const auto& param0 = splits[0];

        DeactivateTrigger(param0);
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

        CreateAnimPhysObject(param0, param1);
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

        CreateActionEventTrigger(param0, param1, param2, param3, param4);
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

        LinkActionToObjectJoint(param0, param1, param2, param3, param4);
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

        LinkActionToObject(param0, param1, param2, param3, param4);
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

        SetCharacterPosition(param0, param1, param2);
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

        ResetCharacter(param0, param1);
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
