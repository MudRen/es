#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "little crab", "С�з" );
	add( "id", ({ "crab" }) );
   set_short( "С�з" );
	set_long(
		"��ֻ�з��Ȼ��С���������ɳ̲Ҳ���㹻�������еĵط���\n"
	);
	set( "natural_armor_class", 12 );
	set( "unit", "ֻ" );
	set_c_verbs( ({ "%s�����Ĵ�����%sһ��" }) );
	set_c_limbs( ({ "����", "Ӳ��" }) );
}
