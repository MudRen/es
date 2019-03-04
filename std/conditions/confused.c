//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)
// Modified by Annihilator@Eastern.Stories (09-08-94)

#define EFFECT_NAME "confused"

void effect(object player);
void remove_effect(object player);
// This function may vary with different conditions
void apply_effect(object player, int duration, int damage);

// This is the effect of simple_poison. Its data packet is simple:
// ({ <frequency>, <duration>, <damage> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	int skill;
	mixed *cond_data;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !sizeof(cond_data)==3 ) return;
	player->receive_special_damage( "mental", cond_data[2] );
	tell_object(player, can_read_chinese(player)?
		set_color("���������һ�Ż��ң�������ʲ�᲻֪���Ķ����ڿС�����....\n","HIM",player):
		"You feel confused, with unknown pain ....\n");
	cond_data[1]--;
	player->set( "conditions/" + EFFECT_NAME, cond_data );
	if( cond_data[1]<1 ) remove_effect( player );
}

void remove_effect(object player)
{
	tell_object(player, can_read_chinese()?
		set_color("������������Ѷ��� ....\n","HIC",player):
		"You feel no more confused .... \n");
	player->delete("conditions/" + EFFECT_NAME );
	player->delete_temp("confused");
}

void apply_effect(object player, int duration, int damage)
{
	mixed *cond_data;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data ) {
		tell_object(player, can_read_chinese(player)?
			set_color("�����һ��������ת�����ӿ�ʼ���ò�̫�Ծ���\n","HIM",player):
			"You are confused!\n");
		player->set( "conditions/" + EFFECT_NAME, ({ 6, duration, damage }) );
	} else {
		if( duration > cond_data[1] ) cond_data[1] = duration;
		if( damage > cond_data[2] ) cond_data[2] = damage;
		else if( userp(player) ) cond_data[2]++;
		tell_object(player, can_read_chinese(player)?
			set_color("��������˼·Խ��Խ�ң�һ�ж����Ծ���\n","HIM",player):
			"You feel confused!\n");
		player->set( "conditions/" + EFFECT_NAME, cond_data );
	}
	// added by Kyoko, make player can't go to the dir he wants.
	player->set_temp("confused", 1);
}
