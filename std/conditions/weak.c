//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )

// Created by Annihilator@Eastern.Stories (12-26-93)

#define EFFECT_NAME "weak"

void effect(object player);
void remove_effect(object player);
// This function may vary with different conditions
void apply_effect(object player, int duration, int damage);

// This is the effect of str_poison. Its data packet is simple:
// ({ <frequency>, <difference> })
// Notice we must maintain the difference everytime the effect() is called.
void effect(object player)
{
	int skill;
	mixed *cond_data;
        int str;
	string msg;
        
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !sizeof(cond_data)==2 ) return;
	tell_object(player,
		set_color("���������������Իظ��ˡ�\n","HIY",player));
	msg = player->query_temp("poison_msg");
	if ( msg )
		tell_room(environment(player),sprintf(msg,player->query("c_name")),player);
	cond_data[1]--;
	player->set( "conditions/" + EFFECT_NAME, cond_data );
	player->add("weak",-1);
//	str=(int) ( player->query_perm_stat("str") ) -
//	    (int) ( player->query_stat("str") ) -(int) cond_data[1] ;
	if ( (int)player->query_stat("str") == (int)player->query_perm_stat("str"))
		player->modify_stat("str",-(int)player->query("weak"));
	else
		player->modify_stat("str",1);
	if( cond_data[1]<1 ) remove_effect( player );

}

void remove_effect(object player)
{
	tell_object(player, 
		set_color("����úö��� ....\n","HIC",player));
	player->delete("weak");
	player->delete("conditions/" + EFFECT_NAME );
	player->delete_temp("poison_msg");
}

void apply_effect(object player, int frequency, int difference)
{
	mixed *cond_data;
        int str;
        
	cond_data = player->query("conditions/" + EFFECT_NAME );
	if( !cond_data ) {
		tell_object(player, 
			    set_color("��ȫ����,ʹ��������!!\n","HIR",player));
		player->set( "conditions/" + EFFECT_NAME, ({ frequency, difference }) );
	        player->modify_stat("str",-difference);
		player->set("weak",difference);
	} else {
		cond_data[0]++;
		cond_data[1]++;
		tell_object(player,
		set_color("��е���ͷת���ƺ�Խ��Խû���ˣ�\n","HIM",player));
		player->set( "conditions/" + EFFECT_NAME, cond_data );
//		str=(int) (player->query_perm_stat("str")) -
//		    (int) (player->query_stat("str")) -(int) cond_data[1];
		player->add("weak",1);
		player->modify_stat("str",-1);
	}
}
