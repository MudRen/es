//#pragma save_binary

// Suffocation condition.
// Created by Echobomber@Eastern.Stories (04/27/94)

#define EFFECT_NAME "suffocation"
#define WARNING      5
#define DIE_LIMIT   20

void special_effect(object player, int long);
void effect(object player);
varargs void remove_effect(object player, int silent);

// This is the effect of underwater. Its data packet is simple:
// ({ <frequency>, <damage>, <die_limit>, <duration> })
// Notice we must maintain the duration everytime the effect() is called.
void effect(object player)
{
	mixed *cond_data;

	// if the environment is no longer suffocated, remove effect.
	if( !environment(player)->query("suffocated") ) {
		remove_effect(player);
		return;
	}

	// if player can resist suffocation.
	if( player->query("resist_suffocation") ||
		player->query_temp("resist_suffocation") ) return;

	cond_data = player->query("conditions/" + EFFECT_NAME );
	cond_data[3]++;

	if( !cond_data[3]%3 ) cond_data[1]++;
	player->receive_damage( cond_data[1] );
	tell_object(player, 
	    set_color("��е���������.....\n", "HIB", player) );
	tell_room( environment(player), 
		player->query("c_name") + "�ƺ���Ҫ��Ϣ��....\n",
		player );
	if( cond_data[3] > cond_data[2] ) special_effect(player, 1);
	else if( cond_data[3]+WARNING > cond_data[2] ) special_effect(player, 0);
	player->set("conditions/" + EFFECT_NAME, cond_data);
}

void special_effect(object player, int die) 
{
	if( die ) {
        tell_object(player, 
            set_color("��ȱ������ά������������, ��춵�������!!\n",
            "HIR",player) );
        player->receive_damage(player->query("max_hp"), 0);
	} else
	    tell_object(player, 
			set_color("ע��! ���Ҫ��Ϣ������!!\n","HIB",player) );
	return;
}

varargs void remove_effect(object player, int silent)
{
	if( !silent )
		tell_object(player, 
			set_color("��������������һ����, �����������...\n","HIC",player)	
			);
	player->delete("conditions/" + EFFECT_NAME );
}

varargs void apply_effect(object player, int frequency, int damage, int limit)
{
	mixed *cond_data;

	if( frequency < 1 ) frequency = 3;
	if( damage < 1 ) damage = 1;
	if( limit < 1 ) limit = DIE_LIMIT;
	cond_data = player->query("conditions/" + EFFECT_NAME);
	if( !cond_data )
		player->set("conditions/" + EFFECT_NAME, ({ frequency, damage, limit, 0 }) );
	else {
		if( frequency < cond_data[0] ) cond_data[0] = frequency;
		if( damage > cond_data[1] ) cond_data[1] = damage;
		if( limit < cond_data[2] ) cond_data[2] = limit;
		player->set("conditions/" + EFFECT_NAME, cond_data);
	}
}
