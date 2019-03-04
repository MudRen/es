//#pragma save_binary

// Room or condition with flame .
// Created by Ruby@Eastern.Stories (10/24/94)

#define EFFECT_NAME "flamezone"

void effect(object player);
varargs void remove_effect(object player, int silent);

// This is the effect of flamezone. Its data packet is simple:
// ({ <frequency>, <damage>, <duration> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	mixed *cond_data;

	// if the player is no longer in flamezone, remove effect.
	if( !environment(player)->query("flamezone") ) {
		remove_effect(player);
		return;
	}

	// if player can resist flame.
	if( player->query("resist_flame") || player->query_temp("resist_flame") ) return;

	cond_data = player->query("conditions/" + EFFECT_NAME );
//	cond_data[2]++;
//	if( !cond_data[2]%4 ) cond_data[1]++;
	player->receive_special_damage( "fire",cond_data[1],0 );
	tell_object(player, 
	    set_color("���ܵ������ڿգ�����ü������ȡ������罬...\n", "HIB", player)
		);
	tell_room( environment(player), 
		player->query("c_name") + "�ȵûӺ�����....\n",	player );
	player->set("conditions/" + EFFECT_NAME, cond_data);
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player, 
			set_color("������֮���ӿ�, �����������һ�������Ŀ���, �����������...\n","HIC",player)
			);
	player->delete("conditions/" + EFFECT_NAME );
}

varargs void apply_effect(object player, int frequency, int damage)
{
	mixed *cond_data;

	if( frequency < 1 ) frequency = 3;
	if( damage < 1 ) damage = 1;
	cond_data = player->query("conditions/" + EFFECT_NAME);
	if( !cond_data ) {
		tell_object( player, 
			"�����һ�����صĵط������ܶ������ܵ�����...\n"	);
		player->set("conditions/" + EFFECT_NAME, ({ frequency, damage}) );
	} else {
		if( frequency < cond_data[0] ) {
			cond_data[0] = frequency;
			tell_object( player, 
				"ȼ�յ������ƺ�Խ��Խ���ȣ���е����������ƽ� ...\n" );
		}
		if( damage > cond_data[1] ) cond_data[1] = damage;
		player->set("conditions/" + EFFECT_NAME, cond_data);
	}
}
