//#pragma save_binary

// Desertzone condition.
// Created by Oldcat@Eastern.Stories (03/4/95)

#define EFFECT_NAME "desert"
#define LIMIT 20
#define DIE_LIMIT 25 

void special_effect(object player, int long);
void effect(object player);
varargs void remove_effect(object player, int silent);

// This is the effect of underwater. Its data packet is simple:
// ({ <frequency>, <damage>, <duration> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	mixed *cond_data;

	// if the player is no longer in desert zone, remove effect.
	if( !environment(player)->query("desert") ) {
		remove_effect(player);
		return;
	}

	// if player can resist suffocation.
	if( player->query("resist_desert") || player->query_temp("resist_desert") ) return;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	cond_data[2]++;
	if( !cond_data[2]%4 ) cond_data[1]++;
	player->receive_damage( cond_data[1] );
	tell_object(player, 
	    set_color("在沙漠中, 你感到口乾舌燥, 头昏眼花,.....\n", "HIY", player));
	tell_room( environment(player),
		player->query("c_name") + "因缺水, 似乎快要撑不住了....\n",
		player );
	if( cond_data[2] > DIE_LIMIT ) special_effect(player, 1);
	else if( cond_data[2] > LIMIT ) special_effect(player, 0);
	player->set("conditions/" + EFFECT_NAME, cond_data);
}

void special_effect(object player, int die) 
{
	if( die ) {
        tell_object(player, 
            set_color("你长时间缺乏水分维持你的身体机能, 终於导致死亡!!\n",
            "HIY",player));
        player->receive_damage(player->query("max_hp"), 0);
	} else
	    tell_object(player,
			set_color("注意! 你快要因缺水而死了!!\n","HIY",player));
	return;
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player, 
			set_color("离开沙漠, 你终於深深的吸了一口气, 觉得舒服多了...\n","HIC",player));
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
			set_color("你进入了沙漠之中。\n","HIY",player));
		player->set("conditions/" + EFFECT_NAME, ({ frequency, damage, 0 }) );
	} else {
		if( frequency < cond_data[0] ) {
			cond_data[0] = frequency;
			tell_object( player, 
	set_color("你感到嘴唇和喉咙越来越乾, 彷佛就要裂开了。\n","HIY",player));
		}
		if( damage > cond_data[1] ) cond_data[1] = damage;
		player->set("conditions/" + EFFECT_NAME, cond_data);
	}
}
