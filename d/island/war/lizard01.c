#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(10);
	set_name( "Lizardman Soldier", "������ʿ��" );
	add( "id", ({ "lizardman","soldier" }) );
	set_short( "Lizardman Soldier", "������ʿ��" );
	set_long(@LONG
�㿴��һλ������ս����ʿ��������ɵ��ɵ�������ӣ��ֻ���ͣ�ط�
����������������һλ���ˡ�
LONG
		);
	set( "unit","��" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment", -300 );
	set_natural_weapon( 10,6,14 );
	set( "wealth/silver",20 );
	set( "justice",5 );
	set( "killer",1 );
	set( "pursuing",1 );
	set( "speed",30 );
	set_perm_stat( "str",12 );
	set_perm_stat( "dex",14 );
	set_skill( "shortblade",50 );
	set_skill( "parry",50 );
	set( "chat_chance",20 );
	set( "att_chat_output",({
	"\n������ʿ����У�������ң��Ҳ���ɱ���㣡��\n\n",
	"\n������ʿ��˵�����������������Ͷ���ɣ��Ҳ����˺���ģ���\n\n" }) );
	wield_weapon( IWARO"shortsword" );
	equip_armor( IWARO"cloth2" );
	equip_armor( IWARO"kepi" );
}


