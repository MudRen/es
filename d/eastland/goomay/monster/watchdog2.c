#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "watchdog", "���ǹ�" );
	add( "id", ({ "dog" }) );
	set_short( "a watchdog", "���ǹ�" );
	set_long(
		"This is a big , terrible watchdog, it is looking at you now .\n",
		"����һֻ�׶�Ĵ��ǹ���ר�ŶԸ���Щ���ܻ�ӭ���ˣ��������������㿴��\n"
	);
        set("unit","ֻ");
        set_natural_armor( 30, 10 );
        set_natural_weapon( 7, 7, 12 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );

	set_c_limbs( ({ "����", "ǰ��", "ͷ��", "β��", "����" }) );
	set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
	set_skill( "dodge", 60 );
	set( "chat_chance", 15 );
	set( "att_chat_output", ({
		"���ǹ������������С�\n",
		"���ǹ��˵������ϡ�\n"
	}) );
#include <replace_mob.h>
}
