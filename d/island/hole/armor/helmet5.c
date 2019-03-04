#include <../hole.h>

inherit ARMOR;
int no_pray;
void create()
{
	set_name( "Daemon Visor","��ħ����" );
	add( "id", ({ "visor" }) );
	set_short( "��ħ����" );
	set_long(@LONG
	а��ͽΪ��Ҫ�Ѷ�ħ�����������������������֡�
	��˵ֻҪ�������󣬾Ϳ��Ի�úڰ���������
LONG
		);
	set( "unit","��" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",6 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "evil":25 ]) );
	set( "value",({ 520,"silver" }) );
	no_pray=0;
}

void init(){ add_action( "do_beg","beg" ); }

int do_beg(string str)
{
	object obj,player;
	
	obj=this_object();
	player=this_player();
	
	if( obj->query( "equipped" ) ){
		if( no_pray==1 ) return notify_fail( "�������Ѿ�ʧȥ�����ˡ�\n" );
		if( !str || str!="ishige" ) return notify_fail( "���뿴��˭��а������磮��\n" );
		if( ((int)player->query( "alignment" )) < -1600 ) return notify_fail( "���Ѿ���а���ˡ�\n" );
		tell_object(player,set_color(
		"��ҧ��ָ�⽫��Ѫ������У�����Ĭ�����ٻ��ڰ�����������....\n"+
		"�������㷢�����ϳ�����а���������\n","HIY" ));
		player->set( "alignment",-1600 );
		player->add( "hit_points",-60 );
		no_pray=1;
		return 1;
	}
	else{
		tell_object( player,"�����ħ�򽻵����봩������а������\n" );
		return 1;
	}
}
