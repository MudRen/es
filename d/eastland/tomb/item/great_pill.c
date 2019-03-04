#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "great pill", "��ת��" );
	add( "id", ({ "pill" }) );
	set_short( "��ת��" );
	set_long(
		"����һ�Ž�ɫ�ĵ�ҩ����һ�ɷҷ�����ζ��\n"
	);
	set( "unit", "��" );
	set( "weight", 1 );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "eat_pill","eat" );
}

int eat_pill(string str)
{
	object player,ob;
	int i,chinese_mode;
    
    	player = this_player();
    	chinese_mode = can_read_chinese(player);
    
	if ( !str || str=="") 
       		return 0;  
	if ( str == "pill" && present( "great pill", player ) )
	   {	   
		write( 
		"����˵�ҩ�ᣬ����ȫ��������ǧ��ë�ף���һ���泩��\n"
		);
		player->set("hit_points", (int)player->query("max_hp") );
		player->set("spell_points", (int)player->query("max_sp") );
		player->set("talk_points", (int)player->query("max_tp") );
		player->set("force_points", (int)player->query("max_fp") );
		player->set("medication_resistance", 0);
		remove();
		return 1; }
	else return 0;
}