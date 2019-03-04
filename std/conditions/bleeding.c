//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)

#define EFFECT_NAME "bleeding"

varargs void remove_effect(object player, int silent);
void effect(object player);

// This is the effect of bleeding. Its data packet is simple:
// ({ <frequency>, <duration>, <damage> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	mixed *cond_data;
	int da;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	da=cond_data[2];
	da -= da*(int)player->query("aim_difficulty/vascular")/100;
	player->receive_damage( da );
	tell_object(player,
		set_color("����˿�����Ѫ��ֹ����þ���ֹѪ ....\n","HIR")
		       );
	tell_room( environment(player), 
		player->query("c_name") + "���˿������ϵ�������Ѫ ....\n",
		player );
	cond_data[1]--;
	player->set( "conditions/" + EFFECT_NAME, cond_data );
	if( cond_data[1]<1 ) remove_effect( player );
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player,
			set_color("����˿�ֹͣ��Ѫ�� ....\n","HIC")
		);
	player->delete("conditions/" + EFFECT_NAME );
}

void apply_effect(object player, int duration, int damage)
{
	mixed *cond_data;

	// Monster can set unbleeding 
    if ( player->query("unbleeding") && player->query("npc") ) return;
	
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data ) {
		player->set( "conditions/" + EFFECT_NAME, ({ 2, duration, damage }) );
	} else {
		// Extend the duration if new bleeding is longer
		if( duration > cond_data[1] ) cond_data[1] = duration;

		// Enlarge the damage if new damage is larger
		if( damage > cond_data[2] ) cond_data[2] = damage;
		// IF not monster, increase damage by 1
		else if( userp(player) ) cond_data[2]++;
		player->set( "conditions/" + EFFECT_NAME, cond_data );
	}
}
