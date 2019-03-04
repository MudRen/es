//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )

// Created by Annihilator@Eastern.Stories (12-26-93)

#define EFFECT_NAME "slow"

void effect(object player);
void remove_effect(object player);
// This function may vary with different conditions
void apply_effect(object player, int frequency, int difference);

// This is the effect of slow. Its data packet is simple:
// ({ <frequency>, <difference> })
// Notice we must maintain the difference everytime the effect() is called.
void effect(object player)
{
	int skill;
	mixed *cond_data;
        int dex;
        int s, load,max_load;
	string msg;
        
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !sizeof(cond_data)==2 ) return;
	tell_object(player,
		set_color("�������ļ�����΢����,�������ὩӲ�ˡ�\n","HIY",player));
	msg = player->query_temp("poison_msg");
	if ( msg )
		tell_room(environment(player),sprintf(msg,player->query("c_name")),player);
	cond_data[1]--;
	player->set( "conditions/" + EFFECT_NAME, cond_data );
	player->add("slow",-1);

        load = (int)player->query("load");
        max_load = (int)player->query("max_load");
        s = (int)player->query_perm_stat("dex");
        if ( load >=( max_load * 9 /10 ) && !player->query_temp("mounting")) 
           s -= s*( 10000*load - 9000*max_load)*5/(10000*max_load); 

	if ( s == (int)player->query_stat("dex"))
		player->modify_stat("dex",-(int)player->query("slow"));
	else
		player->modify_stat("dex",1);
	if( cond_data[1]<1 ) remove_effect( player );

}

void remove_effect(object player)
{
	tell_object(player, 
		set_color("����úö��� ....\n","HIC",player));
	player->delete("slow");
	player->delete("conditions/" + EFFECT_NAME );
	player->delete_temp("poison_msg");
}

void apply_effect(object player, int frequency, int difference)
{
	mixed *cond_data;
        int dex;
        
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data ) {
		tell_object(player, 
			    set_color("�����ȫ���⽩Ӳ,��·���е�����!!\n"
			              ,"HIR",player));
		player->set( "conditions/" + EFFECT_NAME, ({ frequency, difference }) );
	        player->modify_stat("dex",-difference);
		player->set("slow",difference);
	} else {
		cond_data[0]++;
		cond_data[1]++;
		tell_object(player,
		set_color("��е�������ӽ�Ӳ,�����ֶ������⣡\n","HIM",player));
		player->set( "conditions/" + EFFECT_NAME, cond_data );
		player->add("slow",1);
		player->modify_stat("dex",-1);
	}
}
