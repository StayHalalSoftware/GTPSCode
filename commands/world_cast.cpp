/* Paste this code on sendChat part (for GTOS CPP user) */

else if (str.substr(0, 7) == "/wcast ") // Credit to StayHalal#8705
{
  string wcast_msg = str.substr(7, cch.length() - 7 - 1);
  WorldInfo* wrld = GetPlyersWorld(peer);
  PlayerInfo* pData = getPeerData(peer);
  if (pData->rawName == wrld->owner) // Make the command only can be used for world owner
  {
    for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
      if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
      if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == pData->currentWorld)
      {
        Player::OnAddNotification(peer, "`2WORLD CAST`0 from `2" + pData->tankIDName + "`0 : " + wcast_msg + "", "audio/achievement.wav", "interface/atomic_button.rttex");
      }
    }
  }
}
