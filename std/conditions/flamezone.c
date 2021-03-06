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
	    set_color("四周的烈焰腾空，你觉得肌肤炽热、汗出如浆...\n", "HIB", player)
		);
	tell_room( environment(player), 
		player->query("c_name") + "热得挥汗如雨....\n",	player );
	player->set("conditions/" + EFFECT_NAME, cond_data);
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player, 
			set_color("从烈焰之中逃开, 你深深的吸了一口清凉的空气, 觉得舒服多了...\n","HIC",player)
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
			"你进入一个奇特的地方，四周都是熊熊的烈焰...\n"	);
		player->set("conditions/" + EFFECT_NAME, ({ frequency, damage}) );
	} else {
		if( frequency < cond_data[0] ) {
			cond_data[0] = frequency;
			tell_object( player, 
				"燃烧的烈焰似乎越来越炽热，你感到死亡渐渐逼近 ...\n" );
		}
		if( damage > cond_data[1] ) cond_data[1] = damage;
		player->set("conditions/" + EFFECT_NAME, cond_data);
	}
}
