#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "abacus", "����" );
	add( "id", ({ "counter" }) );
	set_short( "����" );
	set_long(
		"����һ���ںڵ����̣�ֻ��һ����ҵ�õģ�������������������\n"
	);
	set( "unit", "��" );
	set( "weight", 100 );
	setup_weapon( "blunt", 25, 10, 20 );
	set( "value", ({ 20, "gold" }) );
        set_c_verbs(({"%s����%s","%s����%s","%sײ��%s"}));

}
