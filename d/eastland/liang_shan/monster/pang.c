#include "../takeda.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(12);
	set_name("Pang", "����");
	add ("id", ({ "pang", "Pang" }) );
	set_short("����");
	set_long(
		"һ�����ֳ�����Ů�ˣ���Ϊ�޲���ȥ�����Գ���Թ����\n"
		"��ϴ�·��ĳ����ǣ���Ȼ��Ҷ���������������û�˸���\n"
		"������������ע�⵽�����Ҽ��ϳ���һ���ִ��ֺڵ��룬\n"  
		"�����һ���ë�����˾��ö��ģ����룬���������޲�\n"
		"��ȥ��ԭ��ɣ�\n");
	set_perm_stat("dex", 15);
	set_perm_stat("kar", 15);
	set_perm_stat("str", 15);
	set_skill( "dodge", 60 );
	set( "max_hp", 350 );
	set( "hit_points", 350 );
	set( "gender", "female" );
	set( "race", "daemon" );
	set( "alignment", -800 );
	set_natural_armor( 30, 15 );
	set_natural_weapon( 30, 10, 25 );
}

