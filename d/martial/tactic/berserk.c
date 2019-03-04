// This is a tactic server object which is called from execute_attack()
// Please DON'T DO TOO MANY THINGS in these apply functions because they
// are called during a heart_beat cycle.

#define UNVALID_TYPES ({ "polearm", "whip" })
// This function returns 1 if the player can use the tactic.
int can_use_tactic(object player)
{
	object weap;
	string type;

	if( !weap=player->query("weapon1") ) return 1;
	if( !type=weap->query("type") || member_array(type, UNVALID_TYPES)>=0 )
		return notify_fail( can_read_chinese()?
			"������������ʺ�����ս����\n":
			"You can't use such tactic with your weapon.\n" );
	return 1;
}

// victim=0: Damage you can made
// victim=1: Damage you'll receive
varargs int modify_damage(int damage, int victim)
{
	if( !victim ) return damage/4;
	return damage/8;
}

// victim=0: Victim's parry apply
// victim=1: Your parry apply
varargs int modify_parry(int parry, int victim)
{
	if( !victim ) return -parry/3;
	return -parry/6;
}

// victim=0: Victim's block apply
// victim=1: Your block apply
varargs int modify_block(int block, int victim)
{
	if( !victim ) return  -block/2;
	// You'll never try to block while berserking - Annihilator.
	return -block;
}

// victim=0: Victim's dodge apply
// victim=1: Your dodge apply
varargs int modify_dodge(int dodge, int victim)
{
	if( !victim ) return dodge/2;
	// You'll never try to dodge while berserking - Annihilator.
	return -dodge;
}
