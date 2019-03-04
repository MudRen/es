#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	::create();
	set_level(8);
	set_name( "Yan san", "�ϲ�" );
	add( "id", ({ "monk","san","yan" }) );
	set_short( "�ϲ�" );
	set_long(@C_LONG
���ϻ޾������������е����Ἰ��, �ϲν����ʮ����, ��˵ԭ����
���������, ��Ϊ���ú�����, ���Բ���, ֻ�ó��ҡ�����ֻ������
����������, Ƣ��Ҳ��̫�á�
C_LONG
	);
	set( "unit", "��" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment",  300 );
	set( "max_fp", 400 );
	set("force_effect",2);
	set( "force_points", 400 );
	set_natural_weapon( 0, 2, 5 );
	set( "wealth/silver", 50 );
	set( "pursuing", 1 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 13 );
	set_skill( "longblade", 50 );
	set_skill( "parry", 30 );
	set("attack_skill",CLASS"tai_zuo");
	set("gonfus/tai_zuo",30);
	wield_weapon( SAULIN_OBJ"iron_blade" );
}

void help_me_saulin(object who, object victim)
{
	object *tmp;

	if( who->id("bonze") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"�ϲ�ͦ����" + who->query("c_name") + "��\n",
		this_object() );
}
